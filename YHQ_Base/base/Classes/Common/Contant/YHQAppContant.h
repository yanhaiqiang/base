
//
//  YHQAppContant.h
//  Wine
//
//  Created by admin on 2017/6/5.
//  Copyright © 2017年 judian. All rights reserved.
//

#ifndef YHQAppContant_h
#define YHQAppContant_h

/** 屏幕宽高 */
#define kScreenBounds [UIScreen mainScreen].bounds
#define KScreenWidth [[UIScreen mainScreen]bounds].size.width
#define KScreenHeight [[UIScreen mainScreen]bounds].size.height

/**屏幕适配*/
#define iPhone6Adaptive_width(a) (CGFloat)a * KScreenWidth / 375.0
#define iPhone6Adaptive_height(a) (CGFloat)a * KScreenHeight / 667.0

/** 系统版本 */
#define kDeviceSystemVersion [[UIDevice currentDevice] systemVersion]
#define iOS7_or_later [UIDevice currentDevice].systemVersion.floatValue >= 7.0
#define iOS8_or_later [UIDevice currentDevice].systemVersion.floatValue >= 8.0
#define iOS9_or_later [UIDevice currentDevice].systemVersion.floatValue >= 9.0

/** App版本 */
#define AppVersion [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleVersion"]

/**定义UIImage对象 */
#define IMAGE_NAMED(name)[UIImage imageNamed:name]

/**字体*/
#define BOLDSYSTEMFONT(FONTSIZE)[UIFont boldSystemFontOfSize:FONTSIZE]//加粗
#define SYSTEMFONT(FONTSIZE)[UIFont systemFontOfSize:FONTSIZE]
#define FONT(NAME,FONTSIZE)[UIFont fontWithName:(NAME)size:(FONTSIZE)]

//获取temp
#define kPathTemp NSTemporaryDirectory()
//获取沙盒 Document
#define kPathDocument [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
//获取沙盒 Cache
#define kPathCache [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]


//重写NSLog,Debug模式下打印日志和当前行数
#if DEBUG
#define NSLog(FORMAT, ...) fprintf(stderr,"\n控制器:%s line: %d content :%s\n", __FUNCTION__, __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
#define NSLog(FORMAT, ...) nil
#endif


//弱引用：
#ifndef weakify
#if DEBUG
#if __has_feature(objc_arc)
#define weakify(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
#else
#define weakify(object) autoreleasepool{} __block __typeof__(object) block##_##object = object;
#endif
#else
#if __has_feature(objc_arc)
#define weakify(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
#else
#define weakify(object) try{} @finally{} {} __block __typeof__(object) block##_##object = object;
#endif
#endif
#endif
//强引用：
#ifndef strongify
#if DEBUG
#if __has_feature(objc_arc)
#define strongify(object) autoreleasepool{} __typeof__(object) object = weak##_##object;
#else
#define strongify(object) autoreleasepool{} __typeof__(object) object = block##_##object;
#endif
#else
#if __has_feature(objc_arc)
#define strongify(object) try{} @finally{} __typeof__(object) object = weak##_##object;
#else
#define strongify(object) try{} @finally{} __typeof__(object) object = block##_##object;
#endif
#endif
#endif

#endif /* YHQAppContant_h */
