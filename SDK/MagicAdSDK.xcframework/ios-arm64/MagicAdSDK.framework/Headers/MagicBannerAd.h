//
//  MagicBannerAd.h
//  MagicAdOS
//
//  Created by Harry Jiang on 8/5/25.
//

#import <Foundation/Foundation.h>
#import <MagicAdSDK/MagicAdError.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class MagicBannerAd;

@protocol MagicBannerAdDelegate <NSObject>
@optional
//广告加载完成
-(void)onMgcBannerAdLoaded:(MagicBannerAd *)bannerAd;

//广告加载失败
-(void)onMgcBannerAdError:(MagicBannerAd *)bannerAd error:(MagicAdError *)err;

//广告点击后回调
-(void)onMgcBannerAdClick:(MagicBannerAd *)bannerAd;

//广告按钮点击后回调
-(void)onMgcBannerAdClose:(MagicBannerAd *)bannerAd;

//广告展示回调
-(void)onMgcBannerAdShow:(MagicBannerAd *)bannerAd;

//广告展示曝光回调
-(void)onMgcBannerAdDidExposure:(MagicBannerAd *)bannerAd;

//广告隐藏回调
-(void)onMgcBannerAdHidden:(MagicBannerAd *)bannerAd;

//广告数据回调
-(void)onMgcBannerAdData:(MagicBannerAd *)bannerAd data:(NSDictionary *)data;
@end

@interface MagicBannerAd : NSObject

/**
 初始化
 **/
- (instancetype)initWithAdId:(NSString*)tagId size:(CGSize)size controller:(UIViewController *)controller delegate:(id<MagicBannerAdDelegate>)delegate;

/**
 初始化
 **/
- (instancetype)initWithAdId:(NSString*)tagId size:(CGSize)size extra:(NSDictionary<NSString *,NSString *> *)extra controller:(UIViewController *)controller delegate:(id<MagicBannerAdDelegate>)delegate;

/**
 加载广告
 */
- (void)loadAd;
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
