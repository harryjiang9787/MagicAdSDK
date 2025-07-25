//
//  MagicSplashAd.h
//  MagicAdOS
//
//  Created by Harry Jiang on 28/4/25.
//

#import <Foundation/Foundation.h>
#import <MagicAdSDK/MagicAdError.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class MagicSplashAd;

@protocol MagicSplashAdDelegate <NSObject>
@optional
//广告加载完成
-(void)onMgcSplashAdLoaded:(MagicSplashAd *)splashAd;

//广告加载失败
-(void)onMgcSplashAdError:(MagicSplashAd *)splashAd error:(MagicAdError *)err;

//广告点击后回调
-(void)onMgcSplashAdClick:(MagicSplashAd *)splashAd;

//广告点击跳过后回调
-(void)onMgcSplashAdSkip:(MagicSplashAd *)splashAd;

//广告展示回调
-(void)onMgcSplashAdShow:(MagicSplashAd *)splashAd;

//广告真实曝光回调
-(void)onMgcSplashAdDidExposure:(MagicSplashAd *)splashAd;

//广告隐藏回调
-(void)onMgcSplashAdHidden:(MagicSplashAd *)splashAd;

//广告请求超时
-(void)onMgcSplashAdTimeOut:(MagicSplashAd *)splashAd;

//广告播放完成
-(void)onMgcSplashAdDidFinish:(MagicSplashAd *)splashAd;

//广告数据回调
-(void)onMgcSplashAdData:(MagicSplashAd *)splashAd data:(NSDictionary *)data;
@end

@interface MagicSplashAd : NSObject

/**
 初始化
 **/
- (instancetype)initWithAdId:(NSString*)tagId size:(CGSize)size controller:(UIViewController *)controller delegate:(id<MagicSplashAdDelegate>)delegate;

/**
 初始化
 **/
- (instancetype)initWithAdId:(NSString*)tagId size:(CGSize)size extra:(NSDictionary<NSString *,NSString *> *)extra controller:(UIViewController *)controller delegate:(id<MagicSplashAdDelegate>)delegate;

/**
 加载广告
 */
- (void)loadAd;

/**
 展示
 */
- (void)show;

/**
 获取广告视图
 */
- (UIView *)getView;

/**
 销毁广告
 */
- (void)destroy;

/**
 获取真实宽高
 */
- (CGSize)getADRealSize;

/**
 获取extra信息
 */
- (NSDictionary *)getExtraData;

/**
 获取tagId
 */
- (NSString *)getTagId;

/**
 获取竞价数据
 */
- (NSInteger)getBidPrice;

/**
 广告是否超时
 */
- (BOOL) isDataTimeout;

@end

NS_ASSUME_NONNULL_END
