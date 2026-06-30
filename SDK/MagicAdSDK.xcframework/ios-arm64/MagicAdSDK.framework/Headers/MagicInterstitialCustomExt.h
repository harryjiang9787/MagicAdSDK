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

#endif /* MagicInterstitialCustomExt_h */
