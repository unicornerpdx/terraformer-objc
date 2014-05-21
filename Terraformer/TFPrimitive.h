//
//  TFPrimitive.h
//  Terraformer
//
//  Created by Ryan Arana on 5/20/14.
//  Copyright (c) 2014 pdx.esri.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TFGeometry;
@class TFPolygon;

@protocol TFPrimitive <NSObject>

- (NSDictionary *)encodeJSON;
- (id <TFPrimitive>)decodeJSON:(NSDictionary *)geoJSON;

- (NSArray *)bbox;
- (NSArray *)envelope;
- (TFPolygon *)convexHull;
- (BOOL)contains:(TFGeometry *)geometry;
- (BOOL)within:(TFGeometry *)geometry;
- (BOOL)intersects:(TFGeometry *)geometry;

@end