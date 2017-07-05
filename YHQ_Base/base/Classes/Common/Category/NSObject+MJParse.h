//
//  NSObject+MJParse.h
//  PocketClient
//
//  Created by admin on 16/3/21.
//  Copyright © 2016年 RZOL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MJExtension.h>
/**
 *  MJExtension 解析数组和字典需要是用不同的方法
 */
@interface NSObject (MJParse)

+ (id)parse:(id)resopnseObj;
@end
