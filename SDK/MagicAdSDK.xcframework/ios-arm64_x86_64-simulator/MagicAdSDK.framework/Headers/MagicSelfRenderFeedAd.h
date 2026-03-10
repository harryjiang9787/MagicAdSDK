//
//  MagicSelfRenderFeedAd.h
//  MagicAdSDK
//
//  Created by Harry Jiang on 2026/3/9.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MagicAdSDK/MagicAdError.h>
#import <MagicAdSDK/MagicAdDelegate.h>
#import <MagicAdSDK/MagicSelfRenderFeedData.h>

NS_ASSUME_NONNULL_BEGIN

@class MagicSelfRenderFeedAd;

@protocol MagicSelfRenderFeedAdDelegate <NSObject>
@optional
//广告加载完成
-(void)onMgcSelfRenderFeedAdLoaded:(MagicSelfRenderFeedAd *)feedAd data:(MagicSelfRenderFeedData *)data;

//广告加载失败
-(void)onMgcSelfRenderFeedAdError:(MagicSelfRenderFeedAd *)feedAd error:(MagicAdError *)err;

@end

@interface MagicSelfRenderFeedAd : NSObject

@property (nonatomic, assign)BOOL disableCache;

/**
 初始化
 **/
- (instancetype)initWithAdId:(NSString*)tagId size:(CGSize)size controller:(UIViewController * _Nullable)controller delegate:(id<MagicSelfRenderFeedAdDelegate> _Nullable)delegate;

/**
 初始化
 **/
- (instancetype)initWithAdId:(NSString*)tagId size:(CGSize)size extra:(NSDictionary<NSString *,NSString *> *)extra controller:(UIViewController * _Nullable)controller delegate:(id<MagicSelfRenderFeedAdDelegate> _Nullable)delegate;

/**
 加载广告
 */
- (void)loadAd;

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
 销毁
 */
- (void)destroy;

/**
 增加缓存
 广告缓存加载，可设置1-4条，如果设置数和缓存总数之和超过4，那么新缓存的数量为4减去已缓存的数量
 */
- (void) loadCache:(NSInteger)count delegate:(id<MagicAdLoadDelegate> _Nullable)delegate;

@end

NS_ASSUME_NONNULL_END
