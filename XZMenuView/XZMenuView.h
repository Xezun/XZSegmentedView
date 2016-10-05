//
//  XZMenuView.h
//  Demo
//
//  Created by M. X. Z. on 2016/10/5.
//  Copyright © 2016年 J. W. Z. All rights reserved.
//

#import <UIKit/UIKit.h>

@class UIPickerView, UITableView;

@protocol XZMenuViewDataSource, XZMenuViewDelegate;

@interface XZMenuView : UIView

@property (nonatomic, strong) __kindof UIView *leftView;
@property (nonatomic, strong) __kindof UIView *rightView;
@property (nonatomic) CGFloat minimumItemWidth; // default 49.0

@property (nonatomic) NSInteger selectedIndex;

@property (nonatomic, weak) id<XZMenuViewDataSource> dataSource;
@property (nonatomic, weak) id<XZMenuViewDelegate> delegate;

- (void)setSelectedIndex:(NSInteger)selectedIndex animated:(BOOL)animated;

- (void)reloadData;
- (void)insertItemAtIndex:(NSInteger)index;
- (void)removeItemAtIndex:(NSInteger)index;

- (__kindof UIView *)viewForItemAtIndex:(NSInteger)index;

@end

@protocol XZMenuItemView <NSObject>

@optional
- (void)setSelected:(BOOL)selected;
- (void)setHighlighted:(BOOL)highlighted;

@end

@protocol XZMenuViewDataSource <NSObject>

- (NSInteger)numberOfItemsInMenuView:(XZMenuView *)meunView;

@optional
- (NSString *)menuView:(XZMenuView *)menuView titleForMenuItemAtIndex:(NSInteger)index;
- (__kindof UIView *)menuView:(XZMenuView *)menuView viewForItemAtIndex:(NSInteger)index reusingView:(__kindof UIView *)menuItemView;

@end

@protocol XZMenuViewDelegate <NSObject>

@optional
- (CGFloat)menuView:(XZMenuView *)menuView widthForMenuItemAtIndex:(NSInteger)index;
- (void)menuView:(XZMenuView *)menuView didSelectItemAtIndex:(NSInteger)index;

@end
