#!/bin/bash
# 已注册用户的 CocoaPods 认证修复脚本

echo "=== 已注册用户 CocoaPods 认证修复 ==="

# 检查当前状态
echo "当前认证状态:"
pod trunk me 2>&1

# 询问用户信息
read -p "请输入你的注册邮箱: " EMAIL
read -p "请输入你的注册名字: " NAME

# 清理旧的凭证
echo "清理旧的认证信息..."
if [ -f ~/.netrc ]; then
    echo "备份旧的 .netrc 文件..."
    cp ~/.netrc ~/.netrc.backup.$(date +%Y%m%d_%H%M%S)
    rm ~/.netrc
fi

# 重新注册
echo "正在重新注册账号 $EMAIL ($NAME)..."
pod trunk register "$EMAIL" "$NAME" --description="重新验证-$(date +%Y%m%d)"

echo ""
echo "✓ 已发送验证邮件到 $EMAIL"
echo "请检查邮箱并点击验证链接"
echo "验证后，按回车键继续验证状态..."
read

# 验证登录状态
echo "验证登录状态..."
pod trunk me