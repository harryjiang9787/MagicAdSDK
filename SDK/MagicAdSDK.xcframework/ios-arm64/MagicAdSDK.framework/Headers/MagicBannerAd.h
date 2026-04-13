//
//  MagicBannerAd.h
//  MagicAdOS
//
//  Created by Harry Jiang on 8/5/25.
//

#import <Foundation/Foundation.h>
#import <MagicAdSDK/MagicAdError.h>
#import <UIKit/UIKit.h>
#import <MagicAdSDK/MagicAdDelegate.h>

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

//广告内跳落地页打开回调
-(void)onMgcBannerAdLandingPageStart:(MagicBannerAd *)bannerAd;

//广告内跳落地页关闭回调
-(void)onMgcBannerAdLandingPageClose:(MagicBannerAd *)bannerAd;
@end

@interface MagicBannerAd : NSObject

@property (nonatomic, assign)BOOL disableCache;

/**
 初始化
 **/
- (instancetype)initWithAdId:(NSString*)tagId size:(CGSize)size controller:(UIViewController * _Nullable)controller delegate:(id<MagicBannerAdDelegate> _Nullable)delegate;

/**
 初始化
 **/
- (instancetype)initWithAdId:(NSString*)tagId size:(CGSize)size extra:(NSDictionary<NSString *,NSString *> *)extra controller:(UIViewController * _Nullable)controller delegate:(id<MagicBannerAdDelegate> _Nullable)delegate;

/**
 重设ViewController
 */
- (void)resetViewController:(UIViewController *)controller;

/**
 重设代理
 */
- (void)resetDelegate:(id<MagicBannerAdDelegate> _Nullable)delegate;

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

/**
 有效缓存条数
 */
- (NSInteger) hasCache;

/**
 增加缓存
 广告缓存加载，可设置1-4条，如果设置数和缓存总数之和超过4，那么新缓存的数量为4减去已缓存的数量
 */
- (void) loadCache:(NSInteger)count delegate:(id<MagicAdLoadDelegate> _Nullable)delegate;

/**
 竞价失败回调
 winPrice 整数分
 reason
      * 101：出价低
      * 102：超时
      * 103：广告主被屏蔽
      * 104：文案被屏蔽
      * 105：素材被屏蔽
      * 106：媒体的其他原因
      * 107：内部问题或报错
 */
- (void) lossTracker:(NSInteger) winPrice reason:(NSString *)reason;

@end

NS_ASSUME_NONNULL_END
