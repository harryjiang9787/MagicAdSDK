//
//  MagicFeedAd.h
//  MagicAdOS
//
//  Created by Harry Jiang on 15/5/25.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MagicAdSDK/MagicAdError.h>

NS_ASSUME_NONNULL_BEGIN

@class MagicFeedAd;

#define MAGIC_AD_FEED_CACHE_COUNT 4

@protocol MagicFeedAdDelegate <NSObject>
@optional
//广告加载完成
-(void)onMgcFeedAdLoaded:(MagicFeedAd *)feedAd;

//广告加载失败
-(void)onMgcFeedAdError:(MagicFeedAd *)feedAd error:(MagicAdError *)err;

//广告点击后回调
-(void)onMgcFeedAdClick:(MagicFeedAd *)feedAd;

//广告按钮点击关闭后回调
-(void)onMgcFeedAdClose:(MagicFeedAd *)feedAd;

//广告展示回调
-(void)onMgcFeedAdShow:(MagicFeedAd *)feedAd;

//广告展示曝光回调
-(void)onMgcFeedAdDidExposure:(MagicFeedAd *)feedAd;

//广告隐藏回调
-(void)onMgcFeedAdHidden:(MagicFeedAd *)feedAd;

//广告数据回调
-(void)onMgcFeedAdData:(MagicFeedAd *)feedAd data:(NSDictionary *)data;

//广告缓存预加载，可设置1-4条，如果设置数和缓存总数之和超过4，那么新缓存的数量为4减去已缓存的数量
-(void)onMgcFeedAdCacheLoaded:(MagicFeedAd *)feedAd succCount:(NSInteger)succCount;
//广告缓存预加载失败
-(void)onMgcFeedAdCacheError:(MagicFeedAd *)feedAd error:(MagicAdError *)err;
@end

@interface MagicFeedAd : NSObject

@property (nonatomic, assign)BOOL disableCache;

/**
 初始化
 **/
- (instancetype)initWithAdId:(NSString*)tagId size:(CGSize)size controller:(UIViewController *)controller delegate:(id<MagicFeedAdDelegate>)delegate;

/**
 初始化
 **/
- (instancetype)initWithAdId:(NSString*)tagId size:(CGSize)size extra:(NSDictionary<NSString *,NSString *> *)extra controller:(UIViewController *)controller delegate:(id<MagicFeedAdDelegate>)delegate;

/**
 加载广告
 */
- (void)loadAd;

/**
 获取广告视图
 */
- (UIView *)getView;

/**
 是否是视频广告
 */
- (BOOL)isVideo;

/**
 视频是否正在播放
 */
- (BOOL)isPlaying;

/**
 暂停视频
 */
- (void)pauseVideo;

/**
 播放视频
 */
- (void)playVideo;

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
- (void) loadCache:(NSInteger)count;
@end

NS_ASSUME_NONNULL_END
