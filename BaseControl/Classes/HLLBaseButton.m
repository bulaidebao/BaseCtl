//
//  HLLBaseButton.m
//  HLLDingGouBao
//
//  Created by 段超 on 2018/12/28.
//  Copyright © 2018年 段超. All rights reserved.
//

#import "HLLBaseButton.h"

@implementation HLLBaseButton

- (instancetype)initWithTitle:(NSString *)title titleColor:(UIColor *)titleColor font:(UIFont *)font {
    return [[HLLBaseButton alloc] initWithImageName:@"" title:title titleColor:titleColor font:font];
}

#pragma mark - 系统方法
- (BOOL)pointInside:(CGPoint)point withEvent:(UIEvent *)event {
    if (!self.userInteractionEnabled || self.alpha < 0.01 || self.hidden) {
        return [super pointInside:point withEvent:event];
    }
    CGRect bounds = self.bounds;
    //若原热区小于44x44，则放大热区，否则保持原大小不变
    CGFloat widthDelta = MAX(44.0 - bounds.size.width, 0);
    CGFloat heightDelta = MAX(44.0 - bounds.size.height, 0);
    bounds = CGRectInset(bounds, -0.5 * widthDelta, -0.5 * heightDelta);
    return CGRectContainsPoint(bounds, point);
}

/// 设置标题字体
- (void)setUpTitleLabelFont:(UIFont *)font;
{
    self.titleLabel.font = font;
}

@end
