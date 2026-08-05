//
//  FMPAdapterNativeAdAssets.h
//  FMPAdapter
//
//  Copyright © 2026 Digital Turbine. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// Identifies which native-ad asset a registered view represents.
///
/// Before calling `registerViewForInteraction:mediaView:iconView:clickableViews:`, set each view's
/// `tag` property to the matching value below. The SDK reads `view.tag` on tap to attribute the
/// click to the correct asset. Views left at the default tag (`0`) are not recognized and clicks
/// on them fall back to a generic origin, losing per-asset attribution.
typedef NS_ENUM(NSInteger, FMPAdapterNativeAdViewTag) {
    FMPAdapterNativeAdViewTagTitle       = 1,
    FMPAdapterNativeAdViewTagMediaView   = 2,
    FMPAdapterNativeAdViewTagIcon        = 4,
    FMPAdapterNativeAdViewTagDescription = 5,
    FMPAdapterNativeAdViewTagRating      = 6,
    FMPAdapterNativeAdViewTagCta         = 7,
    FMPAdapterNativeAdViewTagRoot        = 8,
};

@interface FMPAdapterNativeAdAssets : NSObject

@property (nonatomic, readonly, copy, nullable) NSString *adTitle;
@property (nonatomic, readonly, copy, nullable) NSString *adDescription;
@property (nonatomic, readonly, copy, nullable) NSString *callToActionText;
@property (nonatomic, readonly, strong, nullable) UIView *appIcon;
@property (nonatomic, readonly, strong, nonnull) UIView *mediaView;
@property (nonatomic, readonly, strong, nullable) NSNumber *rating;
@property (nonatomic, readonly, strong, nullable) NSNumber *mediaAspectRatio;

/// Registers the ad's views for click interaction.
///
/// Every view passed in — @c rootView, @c mediaView, @c iconView, and each entry of
/// @c clickableViews — must have its @c tag set to the matching @c FMPAdapterNativeAdViewTag value
/// before calling. Views left at the default tag (@c 0) are not recognized and clicks on them fall
/// back to a generic origin, losing per-asset attribution.
- (void)registerViewForInteraction:(nullable UIView *)rootView
                         mediaView:(nullable UIView *)mediaView
                          iconView:(nullable UIView *)iconView
                    clickableViews:(nullable NSArray<UIView *> *)clickableViews;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
