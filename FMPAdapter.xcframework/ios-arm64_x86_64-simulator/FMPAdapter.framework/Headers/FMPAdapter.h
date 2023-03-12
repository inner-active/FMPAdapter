//
//  FMPAdapter.h
//  FMPAdapter
//
//  Created by Digital Turbine on 22/01/2020.
//  Copyright © 2022 Digital Turbine. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for FMPAdapter.
FOUNDATION_EXPORT double FMPAdapterVersionNumber;

//! Project version string for FMPAdapter.
FOUNDATION_EXPORT const unsigned char FMPAdapterVersionString[];

#import <FMPAdapter/FMPAdapterAd.h>
#import <FMPAdapter/FMPAdapterAuctionParameters.h>
#import <FMPAdapter/FMPAdapterAdData.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger) {
    FMPLoggingLevelDisabled,
    FMPLoggingLevelError,
    FMPLoggingLevelInfo,
    FMPLoggingLevelDebug,
    FMPLoggingLevelVerbose
} FMPLoggingLevel;

@interface FMPAdapter : NSObject

@property (nonatomic, getter=isMuted) BOOL muted;

/**
 *  @brief Singleton method, use for any instance call.
 */
+ (instancetype _Null_unspecified)sharedInstance;

- (void)initWithAppId:(nonnull NSString *)appId FairBidSDKVersion:(nonnull NSString *)version logLevel:(FMPLoggingLevel)logLevel;

- (nonnull NSString *)version;
- (nullable FMPAdapterAuctionParameters *)auctionParameters; // legacy
- (nullable FMPAdapterAuctionParameters *)auctionParameters:(nonnull NSString *)placementId;
- (nonnull NSString *)userAgent;

- (id<FMPAdapterBannerAd>)bannerAd;
- (id<FMPAdapterFullscreenAd>)fullscreenAd;

@end

NS_ASSUME_NONNULL_END
