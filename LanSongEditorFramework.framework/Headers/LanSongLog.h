//
//  LanSongLog.h
//  LanSongEditorFramework
//
//  Created by sno on 2018/9/20.
//  Copyright © 2018 sno. All rights reserved.
//

#import <Foundation/Foundation.h>

//显示或注释掉.
#define LANSONGSDK_DEBUG 1

#define LSOLog_w(fmt, ...) NSLog((@"LanSongSDK.Warning: " fmt), ##__VA_ARGS__);
#define LSOLog_e(fmt, ...) NSLog((@"LanSongSDK.Error: " fmt), ##__VA_ARGS__);

#define LSOERROR_RELEASE  LSOLog_e(@"Execution object maybe already dealloced(对象或许已经被释放.)")
// 设置Dlog可以打印出类名,方法名,行数.
#ifdef LANSONGSDK_DEBUG
    #define LSDELETE(fmt, ...) NSLog((@"" fmt), ##__VA_ARGS__);
    #define LANSOSDKLine NSLog(@"LanSongSDK: function:%s [Line %d]", __PRETTY_FUNCTION__, __LINE__);

    #define LSOLog(fmt, ...) NSLog((@"LanSongSDK: " fmt), ##__VA_ARGS__);
    #define LSOLog_i(fmt, ...) NSLog((@"LanSongSDK.info: " fmt), ##__VA_ARGS__);
    #define LSOLog_d(fmt, ...) NSLog((@"LanSongSDK.Debug: " fmt), ##__VA_ARGS__);

#else
    #define LSDELETE ;
    #define LANSOSDKLine ;

    #define LSOLog(fmt, ...);
    #define LSOLog_i(fmt, ...);
    #define LSOLog_d(fmt, ...);

#endif


#define LSORUN_IN_BACKGLOBAL(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define LSORUN_IN_MAIN(block) dispatch_async(dispatch_get_main_queue(),block)

//计算时间.
#define CHECK_TIME_START_LSDELETE CFAbsoluteTime start = CFAbsoluteTimeGetCurrent();
#define CHECK_TIME_END_LSDELETE LSOLog(@"当前消耗的时间是: %0.3f(秒)", (CFAbsoluteTimeGetCurrent() - start));
// do something

#define WS(weakSelf)  __weak __typeof(&*self)weakSelf = self;


#define LSO_DELPRECATED  __attribute__((deprecated))

//返回当前bundle中的文件完整路径 NSString类型;
//举例:  UIImage *image=[UIImage imageWithContentsOfFile:LSOBundlePath(@"IMG_0285.JPG")];
#define LSOBundlePath(fileName) [[[NSBundle mainBundle] bundlePath] stringByAppendingPathComponent:fileName]

//-------LANSO++  END

