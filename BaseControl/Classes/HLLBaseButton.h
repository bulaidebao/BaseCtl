//
//  HLLBaseButton.h
//  HLLDingGouBao
//
//  Created by 段超 on 2018/12/28.
//  Copyright © 2018年 段超. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface HLLBaseButton : UIButton

/**
 初始化 有图片 及 文字

 @param imageName 图片
 @param title 文字
 @param titleColor 文字颜色
 @param font 文字font
 @return HLLBaseButton实例
 */
- (instancetype)initWithImageName:(NSString *)imageName title:(NSString *)title titleColor:(UIColor *)titleColor font:(UIFont *)font;

/**
 初始化 仅有图片

 @param imageName 图片
 @return HLLBaseButton实例
 */
- (instancetype)initWithImageName:(NSString *)imageName;

/**
 初始化 仅有文字

 @param title 文字
 @param titleColor 文字颜色
 @param font 文字font
 @return HLLBaseButton实例
 */
- (instancetype)initWithTitle:(NSString *)title titleColor:(UIColor *)titleColor font:(UIFont *)font;

/// 设置标题字体
- (void)setUpTitleLabelFont:(UIFont *)font;
@end

NS_ASSUME_NONNULL_END
