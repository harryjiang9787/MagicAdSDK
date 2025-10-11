//
//  MagicAdDelegate.h
//  Pods
//
//  Created by Harry Jiang on 2025/10/10.
//

#ifndef MagicAdDelegate_h
#define MagicAdDelegate_h
#import <MagicAdSDK/MagicAdError.h>

@protocol MagicAdLoadDelegate <NSObject>
@optional
//广告缓存加载，可设置1-4条，如果设置数和缓存总数之和超过4，那么新缓存的数量为4减去已缓存的数量
-(void)onMgcAdCacheLoaded:(NSInteger)succCount;
-(void)onMgcAdCacheError:(MagicAdError *)err;
@end

@protocol MagicAdInitDelegate <NSObject>
@optional
-(void)onMagicAdInitSuccess;
-(void)onMagicAdInitError:(NSString *)msg;
@end

#endif /* MagicAdDelegate_h */
