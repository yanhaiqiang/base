//
//  NSObject+Networking.h
//  JuDianApp
//
//  Created by 闫 强 on 16/2/1.
//  Copyright © 2016年 judian. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 请求类型:Get Post
 Get: 传递小型数据, 数据
 Post: 传递大型数据, 传zip/图片/音乐...
 具体使用哪个请求: 由服务器人员规定
 */
#define kCompletionHandle  completionHandle:(void(^)(id model, NSError *error))completionHandle;
@interface NSObject (Networking)

+ (id)GET:(NSString *)path parameters:(NSDictionary *)params kCompletionHandle

+ (id)POST:(NSString *)path parameters:(NSDictionary *)params kCompletionHandle


@end
