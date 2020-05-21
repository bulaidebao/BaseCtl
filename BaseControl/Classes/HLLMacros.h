//
//  HLLMacros.h
//  HLLDingGouBao
//
//  Created by 段超 on 2018/12/27.
//  Copyright © 2018年 段超. All rights reserved.
//


#ifndef HLLMacros_h
#define HLLMacros_h

// 0. 系统单例对象
#define HLL_NOTIFICATION [NSNotificationCenter defaultCenter]
#define HLL_USERDEFAULT [NSUserDefaults standardUserDefaults]
#define HLL_DEVICE [UIDevice currentDevice]
#define HLL_APPLICATION [UIApplication sharedApplication]
#define HLL_APPLICATION_DELEGATE [UIApplication sharedApplication].delegate
#define HLL_KEYWINDOW [UIApplication sharedApplication].delegate.window
#define HLL_FILEMANAGER [NSFileManager defaultManager]
#define HLL_SCREEN [UIScreen mainScreen]

#define HLL_USERDEFAULTSET(value,key)\
[[NSUserDefaults standardUserDefaults] setObject:value forKey:key];\
[[NSUserDefaults standardUserDefaults] synchronize];
#define HLL_USERDEFAULTGET(key) [[NSUserDefaults standardUserDefaults] objectForKey:key]

// 1. 颜色
#define HLLRGBCOLOR(r, g, b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
#define HLLRGBACOLOR(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(r)/255.0 blue:(r)/255.0 alpha:a]
#define HLLHEXCOLOR(hex) [UIColor colorWithHexString:hex]
#define HLLHEXCOLRA(hex,alpha) [UIColor colorWithHexString:hex alpha:alpha]

// 2.非空判断
// 2.1 字符串非空
#define ISNOTEMPTY_STRING(s) (s && [s isKindOfClass:[NSString class]] && ![s isEqualToString:@""] && ![s isEqual:[NSNull null]])

// 2.2 数组非空
#define ISNOTEMPTY_ARRAY(arr) (arr && [arr isKindOfClass:[NSArray class]] && arr.count > 0 && ![arr isEqual:[NSNull null]])

// 2.3 字典非空
#define ISNOTEMPTY_DICTIONARY(dict) (dict && [dict isKindOfClass:[NSDictionary class]] && dict.count > 0 && ![dict isEqual:[NSNull null]])

// 2.4 集合非空
#define ISNOTEMPTY_SET(set) (set && [set isKindOfClass:[NSSet class]] && set.count > 0 && ![set isEqual:[NSNull null]])

// 2.5 number非空
#define ISNOTEMPTY_NUMBER(number) (number && [number isKindOfClass:[NSNumber class]] && ![number isEqual:[NSNull null]] && ![number isEqualToNumber:[NSDecimalNumber notANumber]])

// 3. Log格式化
#ifndef __OPTIMIZE__
#define NSLog(format, ...)\
{\
NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];\
[dateFormatter setDateStyle:NSDateFormatterMediumStyle];\
[dateFormatter setTimeStyle:NSDateFormatterShortStyle];\
[dateFormatter setDateFormat:@"HH:mm:ss:SSSSSS"]; \
NSString *str = [dateFormatter stringFromDate:[NSDate date]];\
printf("%s class: <%p %s:(%d) > method: %s \n%s\n",[str UTF8String] ,stderr, [[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, __PRETTY_FUNCTION__, [[NSString stringWithFormat:(format), ##__VA_ARGS__] UTF8String] );\
}
#else
#define NSLog(...) {}
#endif

// 4.机型
#define HLL_IPHONEX \
({BOOL isPhoneX = NO;\
    if (@available(iOS 11.0, *)) {\
        isPhoneX = [[UIApplication sharedApplication] delegate].window.safeAreaInsets.bottom > 0.0;\
    }\
    (isPhoneX);\
})

// 5. view size
#define HLL_SCREENWIDTH [UIScreen mainScreen].bounds.size.width
#define HLL_SCREENHEIGHT [UIScreen mainScreen].bounds.size.height
#define HLL_TOPSAFEAREA ((HLL_IPHONEX) ? 24 : 0.0)
#define HLL_BOTTOMSAFEAREA (HLL_IPHONEX ? 34 : 0.0)
#define HLL_STATUSBARHEIGHT 20
#define HLL_NAVIGATIONBARHEIGHT 44
#define HLL_MAXNAVIGATIONY HLL_NAVIGATIONBARHEIGHT + HLL_TOPSAFEAREA + HLL_STATUSBARHEIGHT
#define HLL_TABBARHEIGHT 49
#define HLL_SCREENSCALE3 HLL_SCREEN.scale == 3.0
#define HLL_SCREENSCALE2 HLL_SCREEN.scale == 2.0
#define HLL_COMMONMARGIN ((HLL_SCREENWIDTH > 320) ? 13 : 10)
#define HLL_SEPWIDTH   ((HLL_SCREENWIDTH > 320) ? 0.35 : 0.3)
#define HLL_COMMON_CELLHEIGHT 45
#define HLL_ANIMATIONDURATION 0.25
// 公用圆角
#define HLL_COMMON_CORNERRADIUS  14.0f

// 公用图片圆角
#define HLL_COMMON_IMAGE_CORNERRADIUS  10.0f

// 公用阴影圆角
#define HLL_COMMON_SHADOW_CORNERRADIUS  3.0f

// 公用cell间距
#define HLL_COMMON_CELLMARGIN  10.0f

// 公用控件中间距
#define HLL_COMMON_CONTROLMARGIN  10.0f

// 底部操作栏高度
#define HLL_COMMON_OPERBOTTOMHEIGHT  50.0f

// 6. 字体
#define HLL_FONT_NORMAL(s1,s2) [UIFont systemFontOfSize:HLL_SCREENSCALE3 ? s1 : s2]
#define HLL_FONT_BOLD(s1,s2) [UIFont boldSystemFontOfSize:HLL_SCREENSCALE3 ? s1 : s2]
#define HLL_FONT_CUSTOM(fontName,s1,s2) [UIFont fontWithName:fontName size:HLL_SCREENSCALE3 ? s1 : s2]

#define HLL_FONT_SMALLEST HLL_FONT_NORMAL(10,9)
#define HLL_FONT_SMALLER HLL_FONT_NORMAL(12,10)
#define HLL_FONT_SMALL HLL_FONT_NORMAL(13,12)
#define HLL_FONT_MIDDLE HLL_FONT_NORMAL(15,14)
#define HLL_FONT_BIG HLL_FONT_NORMAL(16,15)
#define HLL_FONT_BIGEST HLL_FONT_NORMAL(20,19)

#define HLL_FONT_BOLDSMALLEST HLL_FONT_BOLD(10,9)
#define HLL_FONT_BOLDSMALLER  HLL_FONT_BOLD(12,11)
#define HLL_FONT_BOLDSMALL HLL_FONT_BOLD(13,12)
#define HLL_FONT_BOLDMIDDLE HLL_FONT_BOLD(15,14)
#define HLL_FONT_BOLDBIG HLL_FONT_BOLD(16,15)
#define HLL_FONT_BOLDBIGEST HLL_FONT_BOLD(20,19)

// 7. 赋值类
#define HLL_IMAGE(imageName) [UIImage imageNamed:imageName]
#define HLL_WEAK(obj,weakObj) __weak typeof(obj)weakObj = obj;
#define HLL_WEAKSELF HLL_WEAK(self,weakself)
#define HLL_PAGESIZE @"20"

///  小数点保留
#define HLL_DECIMALBYTENUM  2

// 8. 沙盒地址
//获取temp
#define HLL_SANDBOXPATH_TEMP NSTemporaryDirectory()
//获取沙盒 Document
#define HLL_SANDBOXPATH_DOCUMENT [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
//获取沙盒 Cache
#define HLL_SANDBOXPATH_CACHE [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]

// 9 设备系统版本
#define HLLIOS11 ([[UIDevice currentDevice].systemVersion floatValue] >= 11.0)

// 11 消息内容公共key
#define kNotiHLLComMessageKey    @"kNotiHLLComMessageKey"

#pragma mark - 讯飞语音部分 ---------------------------

#define APPID_VALUE           @"58520a21"
#define URL_VALUE             @""                 // url
#define TIMEOUT_VALUE         @"8000"            // timeout      连接超时的时间，以ms为单位
#define BEST_URL_VALUE        @"1"                // best_search_url 最优搜索路径
#define HLLXFCUSTOMDOMAIN     @"com.hualala.DingGouBao"

#pragma mark - Bugly 部分 ----------------------------
// 11. bugly配置
#ifdef DEBUG

#define HLLBUGLYAPPID @"ff07834d92"

#else

#define HLLBUGLYAPPID @"ff07834d92"

#endif

// 12. block安全执行
#define HLLSAFEBLOCK(BlockName, ...) ({ !BlockName ? nil : BlockName(__VA_ARGS__); })

#pragma mark - Countly统计 --------------------------------
#define COUNTLYAPPKEY @"0e40b4a84153f7005ab5de56224705af272cbc89"

#define COUNTLY_HOST @"http://countly.hualala.com"

// 13.微信注册
#define kWeChatAppId @"wxf495651aa3600e24"

// 14.qq注册
#define kQQAppId @"1110389180"


#endif
