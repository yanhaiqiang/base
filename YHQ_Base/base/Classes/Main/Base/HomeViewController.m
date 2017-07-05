//
//  HomeViewController.m
//  base
//
//  Created by admin on 2016/12/20.
//  Copyright © 2016年 judian. All rights reserved.
//

#import "HomeViewController.h"

@interface HomeViewController ()<UITableViewDelegate, UITableViewDataSource, UIScrollViewDelegate>

@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) UILabel *titleLabel;

@end

@implementation HomeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    

    self.tableView.rowHeight = 50;
    self.tableView.tableHeaderView = [UIView new];
}


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return 100;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *reuseID = @"testCell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:reuseID];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:reuseID];
    }
    
    UIScrollView *scrollView = [[UIScrollView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, 44)];
    scrollView.backgroundColor = [UIColor blueColor];
    [cell.contentView addSubview:scrollView];
    scrollView.contentSize = CGSizeMake(kScreenWidth * 2, 44);
    
    scrollView.userInteractionEnabled = YES;
    UITapGestureRecognizer *tap = [UITapGestureRecognizer bk_recognizerWithHandler:^(UIGestureRecognizer *sender, UIGestureRecognizerState state, CGPoint location) {
        [self tableView:tableView didSelectRowAtIndexPath:indexPath];
    }];
    [scrollView addGestureRecognizer:tap];
    
    UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 200, 50)];
    view.backgroundColor = [UIColor greenColor];
    [scrollView addSubview:view];
    
    
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
    button.backgroundColor = [UIColor redColor];
    button.frame = CGRectMake(0, 0, 100, 30);
    [view addSubview:button];
    
    [button addTarget:self action:@selector(click) forControlEvents:UIControlEventTouchUpInside];
    
    
    
    cell.textLabel.text = [NSString stringWithFormat:@"%ld", (long)indexPath.row];
    tableView.tableFooterView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 0, 1)];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    NSLog(@"%ld", (long)indexPath.row);
}

- (void)tap:(UIGestureRecognizer *)ges {
    NSLog(@"000000");
    
}

- (void)click {
    NSLog(@"999999");
}


- (UITableView *)tableView {
    if (!_tableView) {
        _tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, kScreenHeight) style:UITableViewStylePlain];
        _tableView.delegate = self;
        _tableView.dataSource = self;
        [self.view addSubview:_tableView];
    }
    return _tableView;
}


@end
