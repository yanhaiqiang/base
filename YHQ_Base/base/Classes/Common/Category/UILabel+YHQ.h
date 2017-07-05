//
//  UILabel+YHQ.h
//  base
//
//  Created by admin on 2017/7/3.
//  Copyright © 2017年 judian. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UILabel (YHQ)
+ (UILabel *)labelWithFont:(CGFloat)size textColor:(UIColor *)color;
// 设置文字 大小 颜色区间
-(void) setText:(NSString *)text Font:(UIFont *)font withColor:(UIColor *)color Range:(NSRange)range;

-(void) setText:(NSString *)text Font:(UIFont *)font withColor:(UIColor *)color Range:(NSRange)range withColor:(UIColor *)color1 Range:(NSRange)range1;
@end
