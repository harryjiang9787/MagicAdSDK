//
//  MagicInterstitialCustomExt.h
//  MagicAdOS
//
//  Created by Harry Jiang on 9/5/25.
//

#ifndef MagicInterstitialCustomExt_h
#define MagicInterstitialCustomExt_h
#import <Foundation/Foundation.h>

/**
 设置底价，默认1，单位是分/千次曝光
 */
extern NSString *const MagicInterstitialExtraBidFloorKey;

/**
 设置视频广告是否静音，默认是0静音，1为非静音
 */
extern NSString *const MagicInterstitialExtraVideoMuteKey;

/**
 是否手动关闭广告，默认0，0为finish后自动销毁，1为finish后不自动销毁，需要开发者在finish回调中手动调用destroy
 */
extern NSString *const MagicInterstitialExtraManualCloseKey;

/**
 是否点击后自动关闭广告，默认0不关闭，1为点击后自动关闭
 说明：
 - 点击后直接拉起其它App（非下载且打开成功）：立即关闭广告
 - 跳转App Store或内置落地页：打开页面时不关闭，页面关闭后再关闭
 */
extern NSString *const MagicInterstitialExtraClickCloseKey;

#endif /* MagicInterstitialCustomExt_h */
