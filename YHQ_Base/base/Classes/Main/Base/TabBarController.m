//
//  TabBarController.m
//  base
//
//  Created by admin on 2016/12/20.
//  Copyright © 2016年 judian. All rights reserved.
//

#import "TabBarController.h"
#import "BaseNavigationController.h"
#import "HomeViewController.h"


@interface TabBarController ()

@end

@implementation TabBarController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    //tabbar的背景色
    UIView *backView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, kScreen_width, 49)];
    backView.backgroundColor = [UIColor yellowColor];
    [[UITabBar appearance] insertSubview:backView atIndex:0];
    
    HomeViewController *viewCtrlLeft = [HomeViewController new];
    [self addChildViewController:viewCtrlLeft imageName:@"tabbar_home" title:@"左边"];
    
    HomeViewController *viewCtrlCenter = [HomeViewController new];
    [self addChildViewController:viewCtrlCenter imageName:@"tabbar_home" title:@"中间"];
    
    HomeViewController *viewCtrlRight = [HomeViewController new];
    [self addChildViewController:viewCtrlRight imageName:@"tabbar_home" title:@"右边"];
}

//添加子控制器,设置标题与图片
- (void)addChildViewController:(UIViewController *)childCtrl imageName:(NSString *)imageName title:(NSString *)title{
    
    //设置选中与未选中的图片-->指定一下渲染模式-->图片以原样的方式显示出来
    childCtrl.tabBarItem.image = [[UIImage imageNamed:imageName] imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
    childCtrl.tabBarItem.selectedImage = [[UIImage imageNamed:[NSString stringWithFormat:@"%@_selected",imageName]] imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
    //设置标题
    childCtrl.tabBarItem.title = title;
    //    childCtrl.tabBarItem.imageInsets = UIEdgeInsetsMake(5, 0, -5, 0);
    //指定一下属性
    NSMutableDictionary *dic = [NSMutableDictionary dictionary];
    dic[NSForegroundColorAttributeName] = DefaultRedColor;
    //指定字体
    //    dic[NSFontAttributeName] = [UIFont systemFontOfSize:16];
    
    //指定选中状态下文字颜色
    [childCtrl.tabBarItem setTitleTextAttributes:dic forState:UIControlStateSelected];
    
    BaseNavigationController *navCtrl = [[BaseNavigationController alloc] initWithRootViewController:childCtrl];
    [self addChildViewController:navCtrl];
   
}
@end
