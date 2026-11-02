#!/bin/bash
# 用 Xcode 26.6 发布 MagicAdSDK.podspec
#
# 背景：Xcode 27 / iOS 27.x SDK 的 MinimumDeploymentTarget 是 15.0，
# 而 podspec 的 s.platform 是 10.0，Xcode 27 会直接报错：
#   error: The iOS deployment target 'IPHONEOS_DEPLOYMENT_TARGET' is set to 10.0,
#          but the range of supported deployment target versions is 15.0 to 27.2.x.
# Xcode 26.6 / iOS 26.5 SDK 只是 warning，产物 MinimumOSVersion 仍然是 10.0。
#
# 用法：
#   ./push.sh                 # 先 lint 再 push
#   SKIP_LINT=1 ./push.sh     # 跳过 lint，直接 push
#   XCODE_APP=/Applications/Xcode_xx.app ./push.sh
set -euo pipefail

cd "$(dirname "$0")"

XCODE_APP="${XCODE_APP:-/Applications/Xcode26.6.app}"
if [ ! -d "$XCODE_APP/Contents/Developer" ]; then
  echo "未找到 $XCODE_APP" >&2
  echo "请安装 Xcode 26.6，或用 XCODE_APP=/Applications/Xcode_xx.app ./push.sh 指定" >&2
  exit 1
fi
export DEVELOPER_DIR="$XCODE_APP/Contents/Developer"

echo "使用 Xcode: $(xcodebuild -version | head -1)"
echo "DEVELOPER_DIR: $DEVELOPER_DIR"

if [ "${SKIP_LINT:-0}" != "1" ]; then
  echo ""
  echo ">>> pod spec lint MagicAdSDK.podspec --allow-warnings"
  pod spec lint MagicAdSDK.podspec --allow-warnings
fi

echo ""
echo ">>> pod trunk push MagicAdSDK.podspec --allow-warnings"
pod trunk push MagicAdSDK.podspec --allow-warnings "$@"
