//
//  NSObject+MJParse.m
//  PocketClient
//
//  Created by admin on 16/3/21.
//  Copyright © 2016年 RZOL. All rights reserved.
//

#import "NSObject+MJParse.h"

@implementation NSObject (MJParse)

//判断是字典还是数组
+ (id)parse:(id)resopnseObj {
    if ([resopnseObj isKindOfClass:[NSArray class]]) {
        return [self mj_objectArrayWithKeyValuesArray:resopnseObj];
    }
    if ([resopnseObj isKindOfClass:[NSDictionary class]]) {
        return [self mj_objectWithKeyValues:resopnseObj];
    }
    return resopnseObj;
}

@end
