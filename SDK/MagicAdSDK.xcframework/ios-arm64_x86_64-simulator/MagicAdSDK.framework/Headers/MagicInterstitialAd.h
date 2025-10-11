//
//  MagicInterstitialAd.h
//  MagicAdOS
//
//  Created by Harry Jiang on 9/5/25.
//

#import <Foundation/Foundation.h>
#import <MagicAdSDK/MagicAdError.h>
#import <UIKit/UIKit.h>
#import <MagicAdSDK/MagicAdDelegate.h>

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

//视频广告播放开始
-(void)onMgcInterstitialAdVideoStart:(MagicInterstitialAd *)interstitialAd;

//视频广告播放结束
-(void)onMgcInterstitialAdVideoEnd:(MagicInterstitialAd *)interstitialAd;

//视频广告播放报错
-(void)onMgcInterstitialAdVideoError:(MagicInterstitialAd *)interstitialAd code:(NSString *)code msg:(NSString *)msg;
@end

@interface MagicInterstitialAd : NSObject

@property (nonatomic, assign)BOOL disableCache;

/**
 初始化
 **/
- (instancetype)initWithAdId:(NSString*)tagId size:(CGSize)size controller:(UIViewController *)controller delegate:(id<MagicInterstitialAdDelegate> _Nullable)delegate;

/**
 初始化
 **/
- (instancetype)initWithAdId:(NSString*)tagId size:(CGSize)size extra:(NSDictionary<NSString *,NSString *> *)extra controller:(UIViewController *)controller delegate:(id<MagicInterstitialAdDelegate> _Nullable)delegate;

/**
 加载广告
 */
- (void)loadAd;

/**
 当前控制器添加展示
 */
- (void)show;

/**
 preset new Controller展示
 */
- (void)presentShow;

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

/**
 有效缓存条数
 */
- (NSInteger) hasCache;

/**
 增加缓存
 广告缓存加载，可设置1-4条，如果设置数和缓存总数之和超过4，那么新缓存的数量为4减去已缓存的数量
 */
- (void) loadCache:(NSInteger)count delegate:(id<MagicAdLoadDelegate> _Nullable)delegate;

@end

NS_ASSUME_NONNULL_END
