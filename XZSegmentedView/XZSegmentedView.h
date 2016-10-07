//
//  XZSegmentedView.h
//  XZSegmentedView
//
//  Created by M. X. Z. on 2016/10/7.
//  Copyright © 2016年 mlibai. All rights reserved.
//

#import <UIKit/UIKit.h>

@class UITableView;

@protocol XZSegmentedViewDelegate, XZSegmentedViewDataSource;

@interface XZSegmentedView : UIView

@property (nonatomic, strong) __kindof UIView *leftView;
@property (nonatomic, strong) __kindof UIView *rightView;

@property (nonatomic) CGFloat estimatedItemWidth; // default 49.0

//@property (nonatomic, strong) UIImage *selectionIndicatorImage;
//@property (nonatomic, strong) UIImage *backgroundImage;
//@property (nonatomic, strong) UIImage *seperatorImage;

@property (nonatomic) NSInteger selectedIndex;

@property (nonatomic, weak) id<XZSegmentedViewDataSource> dataSource;
@property (nonatomic, weak) id<XZSegmentedViewDelegate> delegate;

- (void)setSelectedIndex:(NSInteger)selectedIndex animated:(BOOL)animated;

- (void)reloadData;
- (void)insertItemAtIndex:(NSInteger)index;
- (void)removeItemAtIndex:(NSInteger)index;

- (__kindof UIView *)viewForItemAtIndex:(NSInteger)index;

@end



@protocol XZSegment <NSObject>

@optional
- (void)setSelected:(BOOL)selected;
- (void)setHighlighted:(BOOL)highlighted;

@end

@protocol XZSegmentedViewDataSource <NSObject>

- (NSInteger)numberOfItemsInSegmentedView:(XZSegmentedView *)segmentedView;

@optional
- (__kindof UIView *)segmentedView:(XZSegmentedView *)segmentedView viewForItemAtIndex:(NSInteger)index reusingView:(__kindof UIView *)menuItemView;

@end

@protocol XZSegmentedViewDelegate <NSObject>

@optional
- (CGFloat)segmentedView:(XZSegmentedView *)segmentedView widthForMenuItemAtIndex:(NSInteger)index;
- (void)segmentedView:(XZSegmentedView *)segmentedView didSelectItemAtIndex:(NSInteger)index;

@end

@class UISegmentedControl;


@interface XZMenuView : XZSegmentedView

- (instancetype)initWithItems:(NSArray *)items; // items can be NSStrings or UIImages. control is automatically sized to fit content

@end



