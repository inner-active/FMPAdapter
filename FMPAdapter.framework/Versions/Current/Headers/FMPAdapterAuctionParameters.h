//
//  FMPAdapterAuctionParameters.h
//  FMPAdapter
//
//  Created by Fyber on 28/01/2020.
//  Copyright © 2020 Inneractive. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FMPAdapterAuctionParameters : NSObject

@property (nonatomic, copy, readonly, nullable) NSArray<NSNumber *> *apis;
@property (nonatomic, copy, readonly, nullable) NSArray<NSNumber *> *protocols;
@property (nonatomic, copy, readonly, nullable) NSArray<NSString *> *mimes;
@property (nonatomic, copy, readonly, nullable) NSString *language;
@property (nonatomic, copy, readonly, nullable) NSArray<NSString *> *inputLanguages;
@property (nonatomic, copy, readonly, nullable) NSString *deviceModel;
@property (nonatomic, copy, readonly, nullable) NSString *countryCode;
@property (nonatomic, copy, readonly, nullable) NSString *networkCode;
@property (nonatomic, copy, readonly, nullable) NSString *network;
@property (nonatomic, copy, readonly, nullable) NSString *carrier;
@property (nonatomic, copy, readonly, nullable) NSString *secure;
@property (nonatomic, readonly) NSInteger supportedTypes;

@end

NS_ASSUME_NONNULL_END
