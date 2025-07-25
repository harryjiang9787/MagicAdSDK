//
//  MagicFeedCustomExt.h
//  MagicAdOS
//
//  Created by Harry Jiang on 15/5/25.
//

#ifndef MagicFeedCustomExt_h
#define MagicFeedCustomExt_h
#import <Foundation/Foundation.h>

/**
 设置底价，默认1，单位是分/千次曝光
 */
extern NSString *const MagicFeedExtraBidFloorKey;


/**
 设置视频是否自动播放，默认自动播放，设置"0"将取消自动播放
 如果自动播放，pauseVideo、playVideo将失效，只有取消自动播放才可使用
 */
extern NSString *const MagicFeedExtraAutoPlayKey;

/**
 设置视频广告是否静音，默认是0静音，1为非静音
 */
extern NSString *const MagicFeedExtraVideoMuteKey;

#endif /* MagicFeedCustomExt_h */
