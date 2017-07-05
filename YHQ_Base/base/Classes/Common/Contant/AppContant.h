//
//  AppContant.h
//  base
//
//  Created by admin on 2016/12/20.
//  Copyright © 2016年 judian. All rights reserved.
//

#ifndef AppContant_h
#define AppContant_h

/** 屏幕宽高 */
#define kScreenBounds [UIScreen mainScreen].bounds
#define kScreen_width [UIScreen mainScreen].bounds.size.width
#define kScreen_height [UIScreen mainScreen].bounds.size.height

/**屏幕适配*/
#define iPhone5Adaptive_width  [UIScreen mainScreen].bounds.size.width/320
#define iPhone5Adaptive_height [UIScreen mainScreen].bounds.size.height/568

#define iPhone6Adaptive_width  [UIScreen mainScreen].bounds.size.width/375
#define iPhone6Adaptive_height [UIScreen mainScreen].bounds.size.height/667

/** 系统版本 */
#define kDeviceSystemVersion [[UIDevice currentDevice] systemVersion]
#define iOS7_or_later [UIDevice currentDevice].systemVersion.floatValue >= 7.0
#define iOS8_or_later [UIDevice currentDevice].systemVersion.floatValue >= 8.0
#define iOS9_or_later [UIDevice currentDevice].systemVersion.floatValue >= 9.0

/** App版本 */
#define AppVersion [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleVersion"]

//设置全局的颜色，方便修改
#define DefaultGrayColor UIColorHex(0x717171)
#define DefaultRedColor UIColorHex(0xcf292b)
#define DefaultBlueColor UIColorHex(0x0c5ffd)


/** 是否为空 */
#define checkNull(__X__)        (__X__) == (NSString *)[NSNull null] || (__X__) == nil ? @"" : [NSString stringWithFormat:@"%@", (__X__)]

//重写NSLog,Debug模式下打印日志和当前行数
#if DEBUG
#define NSLog(FORMAT, ...) fprintf(stderr,"\n控制器:%s line: %d content :%s\n", __FUNCTION__, __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
#define NSLog(FORMAT, ...) nil
#endif

//设置view圆角和边框
#define JDViewBorderRadius(View, Radius, Width, Color)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]

//获取temp
#define kPathTemp NSTemporaryDirectory()
//获取沙盒 Document
#define kPathDocument [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
//获取沙盒 Cache
#define kPathCache [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]

//字体
#ifndef SYSTEM_FONT
#define SYSTEM_FONT(__fontsize__)\
[UIFont systemFontOfSize:__fontsize__]
#endif

//图片
#ifndef IMAGE_NAMED
#define IMAGE_NAMED(__imageName__)\
[UIImage imageNamed:__imageName__]
#endif


#endif /* AppContant_h */
