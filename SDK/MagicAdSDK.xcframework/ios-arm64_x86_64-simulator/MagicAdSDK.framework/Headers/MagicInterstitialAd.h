//
//  MagicInterstitialAd.h
//  MagicAdOS
//
//  Created by Harry Jiang on 9/5/25.
//

#import <Foundation/Foundation.h>
#import <MagicAdSDK/MagicAdError.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class MagicInterstitialAd;

@protocol MagicInterstitialAdDelegate <NSObject>
@optional
//广告加载完成
-(void)onMgcInterstitialAdLoaded:(MagicInterstitialAd *)interstitialAd;

//广告加载失败
-(void)onMgcInterstitialAdError:(MagicInterstitialAd *)interstitialAd error:(MagicAdError *)err;

//广告点击后回调
-(void)onMgcInterstitialAdClick:(MagicInterstitialAd *)interstitialAd;

//广告点击关闭后回调
-(void)onMgcInterstitialAdClose:(MagicInterstitialAd *)interstitialAd;

//广告展示展示回调
-(void)onMgcInterstitialAdShow:(MagicInterstitialAd *)interstitialAd;

//广告展示曝光回调
-(void)onMgcInterstitialAdDidExposure:(MagicInterstitialAd *)interstitialAd;

//广告隐藏回调
-(void)onMgcInterstitialAdHidden:(MagicInterstitialAd *)interstitialAd;

//广告数据回调
-(void)onMgcInterstitialAdData:(MagicInterstitialAd *)interstitialAd data:(NSDictionary *)data;

//广告播放完成
-(void)onMgcInterstitialAdDidFinish:(MagicInterstitialAd *)interstitialAd;
@end

@interface MagicInterstitialAd : NSObject

/**
 初始化
 **/
- (instancetype)initWithAdId:(NSString*)tagId size:(CGSize)size controller:(UIViewController *)controller delegate:(id<MagicInterstitialAdDelegate>)delegate;

/**
 初始化
 **/
- (instancetype)initWithAdId:(NSString*)tagId size:(CGSize)size extra:(NSDictionary<NSString *,NSString *> *)extra controller:(UIViewController *)controller delegate:(id<MagicInterstitialAdDelegate>)delegate;

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
