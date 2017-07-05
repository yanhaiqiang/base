//
//  UILabel+YHQ.m
//  base
//
//  Created by admin on 2017/7/3.
//  Copyright © 2017年 judian. All rights reserved.
//

#import "UILabel+YHQ.h"

@implementation UILabel (YHQ)
+ (UILabel *)labelWithFont:(CGFloat)size textColor:(UIColor *)color {
    UILabel *label = [[UILabel alloc] init];
    label.font = [UIFont systemFontOfSize:size];
    label.textColor = color;
    label.textAlignment = NSTextAlignmentLeft;
    return label;
}
-(void) setText:(NSString *)text Font:(UIFont *)font withColor:(UIColor *)color Range:(NSRange)range
{
    NSMutableAttributedString *str = [[NSMutableAttributedString alloc] initWithString:text];
    [str addAttribute:NSForegroundColorAttributeName value:color range:range];
    [str addAttribute:NSFontAttributeName value:font range:NSMakeRange(0, text.length)];
    self.attributedText = str;
}

-(void) setText:(NSString *)text Font:(UIFont *)font withColor:(UIColor *)color Range:(NSRange)range withColor:(UIColor *)color1 Range:(NSRange)range1
{
    NSMutableAttributedString *str = [[NSMutableAttributedString alloc] initWithString:text];
    [str addAttribute:NSForegroundColorAttributeName value:color range:range];
    [str addAttribute:NSForegroundColorAttributeName value:color1 range:range1];
    [str addAttribute:NSFontAttributeName value:font range:NSMakeRange(0, text.length)];
    self.attributedText = str;
}
@end
