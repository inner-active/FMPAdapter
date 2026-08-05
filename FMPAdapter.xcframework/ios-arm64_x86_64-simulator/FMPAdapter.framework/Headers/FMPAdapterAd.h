//
//  FMPAdapterAd.h
//  FMPAdapter
//
//  Created by Digital Turbine on 28/01/2020.
//  Copyright © 2022 Digital Turbine. All rights reserved.
//

#ifndef FMPAdapterAd_h
#define FMPAdapterAd_h

#import <UIKit/UIKit.h>

@class FMPAdapterAdData;
@class FMPAdapterNativeAdAssets;

#pragma mark - Adapter Side

@protocol FMPAdapterAd <NSObject>

@property (nonatomic, weak, nullable) id delegate;

@required
- (void)load:(nonnull FMPAdapterAdData *)adData;

@end

@protocol FMPAdapterBannerAdDelegate;
@protocol FMPAdapterBannerAd <FMPAdapterAd>

@required
@property (nonatomic, weak, nullable) id<FMPAdapterBannerAdDelegate> delegate; // override
@property (nonatomic, readonly) BOOL canRefresh;

@end

@protocol FMPAdapterFullscreenAdDelegate;
@protocol FMPAdapterFullscreenAd <FMPAdapterAd>

@required
@property (nonatomic, weak, nullable) id<FMPAdapterFullscreenAdDelegate> delegate; // override

- (BOOL)isAvailable;
- (void)showInViewController:(nullable UIViewController *)viewController;
 
@end

#pragma mark - Client Side

@protocol FMPAdapterAdDelegate <NSObject>

@required
- (void)adDidFailToLoad:(nullable NSError *)error;

- (void)adDidShow;
- (void)adDidFailToShow;
- (void)adDidClick;
- (void)adWillLeaveApplication;

@end

@protocol FMPAdapterBannerAdDelegate <FMPAdapterAdDelegate>

@required
- (UIViewController * _Nonnull)parentViewControllerForModalView;

- (void)adDidLoadView:(nonnull UIView *)view;
 
- (void)adDidResizeToFrame:(CGRect)frame;

- (void)adWillPresentModalView;
- (void)adDidDismissModalView;
 
@end

@protocol FMPAdapterFullscreenAdDelegate <FMPAdapterAdDelegate>
 
@required
- (void)adDidLoad;

- (void)adDidDismiss;
- (void)adDidComplete;
- (void)adDidFailToCompleteWithError:(nullable NSError *)error;
 
@end

#pragma mark - Native

@protocol FMPAdapterNativeAdDelegate;
@protocol FMPAdapterNativeAd <FMPAdapterAd>

@required
@property (nonatomic, weak, nullable) id<FMPAdapterNativeAdDelegate> delegate; // override
@property (nonatomic) BOOL muteVideo;

@end

@protocol FMPAdapterNativeAdDelegate <FMPAdapterAdDelegate>

@required
- (UIViewController * _Nonnull)parentViewControllerForNativeAd;
- (void)adDidLoadAssets:(nonnull FMPAdapterNativeAdAssets *)assets;

@optional
- (void)adDidExpire;
- (void)adWillPresentFullscreen;
- (void)adDidPresentFullscreen;
- (void)adWillDismissFullscreen;
- (void)adDidDismissFullscreen;
- (void)adVideoDidComplete;
- (void)adVideoDidFailWithError:(nonnull NSError *)error;

@end

#endif /* FMPAdapterAd_h */
