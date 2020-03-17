//
//  FMPAdapter.h
//  FMPAdapter
//
//  Created by Fyber on 22/01/2020.
//  Copyright © 2020 Inneractive. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "FMPAdapterAd.h"
#import "FMPAdapterAuctionParameters.h"
#import "FMPAdapterAdData.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger) {
    FMPLoggingLevelDisabled,
    FMPLoggingLevelError,
    FMPLoggingLevelInfo,
    FMPLoggingLevelDebug,
    FMPLoggingLevelVerbose
} FMPLoggingLevel;

@interface FMPAdapter : NSObject

/**
 *  @brief Singleton method, use for any instance call.
 */
+ (instancetype _Null_unspecified)sharedInstance;

- (void)initWithAppId:(nonnull NSString *)appId FairBidSDKVersion:(nonnull NSString *)version logLevel:(FMPLoggingLevel)logLevel;

- (nonnull NSString *)version;
- (nullable FMPAdapterAuctionParameters *)auctionParameters;
- (nonnull NSString *)userAgent;

- (id<FMPAdapterBannerAd>)bannerAd;
- (id<FMPAdapterFullscreenAd>)fullscreenAd;

@end

NS_ASSUME_NONNULL_END
