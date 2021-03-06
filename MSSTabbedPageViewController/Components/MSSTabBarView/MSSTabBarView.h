//
//  MSSTabBarView.h
//  TabbedPageViewController
//
//  Created by Merrick Sapsford on 13/01/2016.
//  Copyright © 2016 Merrick Sapsford. All rights reserved.
//

#import <UIKit/UIKit.h>

@class MSSTabBarView;
@protocol MSSTabBarViewDataSource <NSObject>

/**
 The tab titles to display in the tab bar.
 
 @param tabBarView
 The tab bar view.
 @return The array of tab titles.
 */
- (NSArray *)tabTitlesForTabBarView:(MSSTabBarView *)tabBarView;

@end

@protocol MSSTabBarViewDelegate <NSObject>

/**
 A tab has been selected.
 
 @param tabBarView
 The tab bar view.
 @param index
 The index of the selected tab.
 */
- (void)tabBarView:(MSSTabBarView *)tabBarView tabSelectedAtIndex:(NSInteger)index;

@end

@interface MSSTabBarView : UIView

/**
 The object that acts as the data source for the tab bar.
 */
@property (nonatomic, weak) id<MSSTabBarViewDataSource> dataSource;

/**
 The object that acts as a delegate for the tab bar.
 */
@property (nonatomic, weak) id<MSSTabBarViewDelegate> delegate;

/**
 The current tab offset of the tab bar.
 */
@property (nonatomic, assign) CGFloat tabOffset;

/**
 The expected number of tabs in the tab bar.
 */
@property (nonatomic, assign) NSInteger expectedTabCount;

/**
 The default index for the tab bar to display.
 */
@property (nonatomic, assign) NSInteger defaultTabIndex;

/**
 Whether the tab bar is currently animating a tab change transition.
 */
@property (nonatomic, assign, readonly, getter=isAnimatingTabChange) BOOL animatingTabChange;

/**
 The background view for the tab bar.
 */
@property (nonatomic, strong) UIView *backgroundView;

/**
 The height of the tab bar.
 */
@property (nonatomic, assign, readonly) CGFloat height;

/**
 The internal horizontal label padding value for each tab.
 */
@property (nonatomic, assign) CGFloat tabPadding;

/**
 The content inset for the tabs.
 */
@property (nonatomic, assign) UIEdgeInsets contentInset;

/**
 The height of the selection indicator.
 */
@property (nonatomic, assign) CGFloat selectionIndicatorHeight;

/**
 The inset for the selection indicator from the bottom of the tab bar.
 */
@property (nonatomic, assign) CGFloat selectionIndicatorInset;

/**
 The color of the tab selection indicator.
 */
@property (nonatomic, strong) UIColor *tabIndicatorColor UI_APPEARANCE_SELECTOR;

/**
 The text color of the tabs.
 */
@property (nonatomic, strong) UIColor *tabTextColor UI_APPEARANCE_SELECTOR;

/**
 Initialize a tab bar with a specified height.
 
 @param height
 The height for the tab bar.
 @return Tab bar instance.
 */
- (instancetype)initWithHeight:(CGFloat)height;

/**
 Set the current selected tab index of the tab bar.
 
 @param index
 The index of the current tab.
 @param animated
 Animate the tab index transition.
 */
- (void)setTabIndex:(NSInteger)index animated:(BOOL)animated;

@end
