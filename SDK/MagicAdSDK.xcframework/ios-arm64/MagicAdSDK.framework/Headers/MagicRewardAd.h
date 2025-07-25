//
//  MagicRewardAd.h
//  MagicAdOS
//
//  Created by Harry Jiang on 7/5/25.
//

#import <Foundation/Foundation.h>
#import <MagicAdSDK/MagicAdError.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class MagicRewardAd;

@protocol MagicRewardAdDelegate <NSObject>
@optional
//广告加载完成
-(void)onMgcRewardAdLoaded:(MagicRewardAd *)rewardAd;

//广告加载失败
-(void)onMgcRewardAdError:(MagicRewardAd *)rewardAd error:(MagicAdError *)err;

//广告点击后回调
-(void)onMgcRewardAdClick:(MagicRewardAd *)rewardAd;

//广告点击关闭后回调
-(void)onMgcRewardAdClose:(MagicRewardAd *)rewardAd;

//广告展示展示回调
-(void)onMgcRewardAdShow:(MagicRewardAd *)rewardAd;

//广告展示曝光回调
-(void)onMgcRewardAdDidExposure:(MagicRewardAd *)rewardAd;

//广告隐藏回调
-(void)onMgcRewardAdHidden:(MagicRewardAd *)rewardAd;

//广告播放完成
-(void)onMgcRewardAdDidFinish:(MagicRewardAd *)rewardAd;

//广告数据回调
-(void)onMgcRewardAdData:(MagicRewardAd *)rewardAd data:(NSDictionary *)data;
@end

@interface MagicRewardAd : NSObject

/**
 初始化
 **/
- (instancetype)initWithAdId:(NSString*)tagId size:(CGSize)size controller:(UIViewController *)controller delegate:(id<MagicRewardAdDelegate>)delegate;

/**
 初始化
 extra 设置激励广告的激励值，广告成功回调后将返回
 **/
- (instancetype)initWithAdId:(NSString*)tagId size:(CGSize)size extra:(NSDictionary<NSString *,NSString *> *)extra controller:(UIViewController *)controller delegate:(id<MagicRewardAdDelegate>)delegate;

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
