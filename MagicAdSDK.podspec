#
# Be sure to run `pod lib lint BaiduMobAdSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'MagicAdSDK'
  s.version          = '0.0.11'
  s.summary          = 'MagicAdSDK'
  s.description      = <<-DESC
  杰蛙广告SDK;
                       DESC

  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Magic' => 'Magic' }

  s.homepage         = 'https://github.com/harryjiang9787/MagicAdSDK.git'
  s.source           = { :git => 'https://github.com/harryjiang9787/MagicAdSDK.git', :tag => s.version.to_s }
  s.platform         = :ios, "10.0"  
  s.frameworks = 'AdSupport', 'CoreGraphics', 'UIKit', 'Foundation','AVFoundation', 'CoreTelephony', 'SystemConfiguration','WebKit','ImageIO','CoreFoundation','CoreLocation'
  s.libraries  = 'c++','sqlite3'
  s.static_framework = true
  
  s.vendored_frameworks = 'SDK/*.{xcframework,framework}'
  #s.resources = ['SDK/*.{bundle}']
  s.xcconfig = {
    'ENABLE_BITCODE' => 'NO', 
    'OTHER_LDFLAGS' =>'-ObjC'
  }
end
