//
//  CiShuShowConfig.h
//  SampleApp
//
//  Created by 辞书_褚平欧 on 2020/6/23.
//  Copyright © 2020 辞书_cpo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface CiShuShowConfig : NSObject

//-----实例化单例-----
+ (CiShuShowConfig *)defaultConfig;


//-----字体-----
//查询词的字体 默认:17
@property (nonatomic , strong) UIFont * titleFont;

//查询词拼音字体 默认:15
@property (nonatomic , strong) UIFont * spellFont;

//结果释义条目 默认:16
@property (nonatomic , strong) UIFont * listFont;

//释义条目引申 默认:14
@property (nonatomic , strong) UIFont * listCiteFont;

//来源介绍字体 默认:12
@property (nonatomic , strong) UIFont * sourceFont;

//-----颜色-----
//查询词的字体颜色 默认:0xFFFFFF
@property (nonatomic , strong) UIColor * titleColor;

//查询词拼音字体颜色 默认:0xFFFFFF
@property (nonatomic , strong) UIColor * spellColor;

//结果释义条目字体颜色 默认:0xFFFFFF
@property (nonatomic , strong) UIColor * listColor;

//释义条目引申字体颜色 默认:0xFFFFFF
@property (nonatomic , strong) UIColor * listCiteColor;

//来源介绍字体颜色 默认:0xFFFFFF
@property (nonatomic , strong) UIColor * sourceColor;

//释义弹出框颜色 默认:0x000000 alpha:0.8
@property (nonatomic , strong) UIColor * showBG;

//-----功能-----
//开启打印
@property (nonatomic , assign) BOOL openLog;

@end

NS_ASSUME_NONNULL_END
