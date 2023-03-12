//
//  FMPAdapterAdData.h
//  FMPAdapter
//
//  Created by Digital Turbine on 28/01/2020.
//  Copyright © 2022 Digital Turbine. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FMPAdapterAdData : NSObject

@property (nonatomic, strong, nonnull) NSString *spotID;
@property (nonatomic, getter=isFullscreen) BOOL fullscreen;
@property (nonatomic, getter=isRewarded) BOOL rewarded;

@property (nonatomic, copy, nonnull) NSDictionary *responseHeaders;
@property (nonatomic, copy, nonnull) NSDictionary *responseBody;

@end

NS_ASSUME_NONNULL_END
