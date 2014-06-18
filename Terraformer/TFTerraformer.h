//
//  TFTerraformer
//  Terraformer
//
//  Created by ryana on 6/16/14
//  Copyright (c) 2014 ESRI. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TFPrimitive;

/**
* A TFEncoder can take a `TFPrimitive` object and turn it into an `NSData` object.
*/
@protocol TFEncoder
+ (NSData *)encodePrimitive:(TFPrimitive *)primitive error:(NSError **)error;
@end

/**
* A TFDecoder can take an `NSData` object and turn it into a `TFPrimitive` object.
*/
@protocol TFDecoder
+ (TFPrimitive *)decode:(NSData *)data error:(NSError **)error;
@end

static NSString *const TFTerraformerErrorDomain = @"com.esri.pdx.Terraformer";
static NSInteger const kTFTerraformerParseError = 1;

@interface TFTerraformer : NSObject

@property (strong, nonatomic) Class<TFEncoder> encoder;
@property (strong, nonatomic) Class<TFDecoder> decoder;

/**
* The main initializer for a TFTerraformer object.
*
* @param encoder The encoder class to use to format the output of the convert method.
* @param decoder The decoder class to use to parse the input of the convert method.
*/
- (instancetype)initWithEncoder:(Class<TFEncoder>)encoder decoder:(Class<TFDecoder>)decoder;

/**
* Parses the given input using this instance's `TFDecoder` and converts it using
* the `TFEncoder`.
*/
- (NSData *)convert:(NSData *)input error:(NSError **)error;

/**
* Parses the given input and returns the `TFPrimitive` representation of it.
*/
- (TFPrimitive *)parse:(NSData *)input error:(NSError **)error;

@end