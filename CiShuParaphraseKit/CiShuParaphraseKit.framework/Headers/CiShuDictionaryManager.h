//
//  CiShuDictionaryManager.h
//  SampleApp
//
//  Created by 辞书_褚平欧 on 2020/6/23.
//  Copyright © 2020 辞书_cpo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, CiShuMenuTipDirection) {
    CiShuMenuTipDirectionUp = 0, //从左下角开始绘制释义窗口
    CiShuMenuTipDirectionDown = 1 //从左上角开始绘制释义窗口
};

@class CiShuResultObject;

typedef NS_ENUM(NSUInteger, CiShuAuthCodeType) {
    CiShuAuthCodeTypeSucess         = 1,//初始化成功，可以正常使用查词功能
    CiShuAuthCodeTypeInit           = 0,//初始化中
    CiShuAuthCodeTypeTimeError      = -1,//初始化失败,用户使用的自定义时间与标准UTC时间偏差过大
    CiShuAuthCodeTypeAuthError      = -2,//appKey appSecret 不正确，请检查SDK
    CiShuAuthCodeTypeNetError       = -3,//网络异常
};

@interface CiShuDictionaryManager : NSObject

/// 通过id和key获取APP 授权
/// @param appKey 管理后台提供的App Key String
/// @param appSecret 管理后台提供的App Secret String
+ (void)authWithAppKey:(NSString *)appKey
             appSecret:(NSString *)appSecret;


/// 获取当前SDK的初始化状态，建议每次查词前调用，如果SDK激活失败可以做对应处理。
+ (CiShuAuthCodeType)cheackInitStatus;

/// 查询词条释义，并展示在window上
/// @param word 查询的词条
/// @param direction 释义窗口绘制方向 0:从左下角开始绘制释义窗口 1:从左上角开始绘制释义窗口
/// @param origin 释义窗口绘制起点
/// @param width 绘制窗口的宽
/// @param height 绘制窗口最大的高，内容高度超过则上下滚动，不足，自适应高度
+ (void)showExplainViewWithWord:(NSString *)word
                  viewDirection:(CiShuMenuTipDirection)direction
                         origin:(CGPoint)origin
                      viewWidth:(CGFloat)width
                  viewMaxHeight:(CGFloat)height;


/// 查询词条释义,返回结果
/// @param word 查询的词条
/// @param result 返回结果的回调
+ (void)getExplainWithWord:(NSString *)word
               resultBlock:(void(^)(CiShuResultObject * response))result;

@end

typedef NS_ENUM(NSInteger, CiShuResultCodeType) {
    CiShuResultCodeTypeOK           = 0,
    CiShuResultCodeTypeNetError     = -1,//网络错误
    CiShuResultCodeTypeNullResp     = -2,//无相关释义
    CiShuResultCodeTypeUnauthorized = -3,//token过期未授权
};

@interface CiShuResultObject : NSObject

//返回错误错误码，正常为 0
@property (nonatomic , assign) CiShuResultCodeType errorCode;

//错误描述
@property (nonatomic , strong) NSString * errorDescription;

//服务器返回的XML数据
@property (nonatomic , strong) NSString * docXml;

//数据来源
@property (nonatomic , strong) NSString * docSource;

@end

NS_ASSUME_NONNULL_END
