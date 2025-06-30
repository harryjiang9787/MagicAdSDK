//
//  LiAdManager.h
//  ADSDK
//
//  Created by jiangzhenwei on 2019/7/9.
//  Copyright © 2019 lishipin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MagicAdSDK/MagicAdError.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MagicAdCacheDelegate <NSObject>
@optional
//广告缓存加载，可设置1-4条，如果设置数和缓存总数之和超过4，那么新缓存的数量为4减去已缓存的数量
-(void)onMgcAdCacheLoaded:(NSInteger)succCount;
-(void)onMgcAdCacheError:(MagicAdError *)err;
@end

@interface MagicAdManager : NSObject

/**
 初始化
 **/
+ (void)initWithAppId:(NSString *)appId;

/**
 获取SDK版本号
 */
+ (NSString *)getSDKVersion;

/**
 支持小程序跳转需要设置
 微信appid和universal link链接
 同时集成微信openSDK和配置好universal link链接
 */
+ (void)setWXAppId:(NSString *)appid universalLink:(NSString *)universalLink;

@end

NS_ASSUME_NONNULL_END
