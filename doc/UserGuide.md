
# 拓灵声纹使用文档

## 使用说明

1. 在拓灵开放平台[官网](http://yun.twirlingvr.com/index.php/home/sdkdownload/index.html)下载对应版本的 SDK 工具包，并完成注册和购买(试用)操作，获取自己的`token`和密码，在接口调用时需要用到
2. 在`project`文件夹里，简单阅读和修改`TwirlingVPRSamples.c`:将`输入音频`修改为自己测试的**16k采样，16 bit量化，单通道，pcm 文件**的具体路径
3. 代码实时处理 PCM，可通过`math_distance`返回值来区分不同音频声纹差异；0-1，1为最大
4. 通过project目录下的`64bit_make.sh`创建您的可执行程序，生成路径为`TwirlingVPR/bin/TwirlingVPRSamples`
5. `TwirlingVPR/bin/TwirlingVPRSamples`可直接运行，目前测试用例是自对比，故输出为1

## 头文件接口说明

1. `char *TwirlingVPRGetVersion()`
 - 返回值：当前版本
 - 功能： 确定版本是否正确
2. `void *TwirlingVPRInit(int *features_len, const char* app_id, const char* passwd)`
 - `features_len` 特征数
 - `appid[IN]` 拓灵账号注册后的`token`
 - `pwd[IN]` 拓灵账号注册的的密码
 - 返回值: 初始化后下一步处理需要的指针
 - 功能: 初始化操作

3. `int TwirlingVPRProcess(void *obj, char *file_name, float* d_vector)`
 - `obj[IN]` TwirlingVPRInit 函数返回的指针
 - `file_name` 输入pcm音频
 - 返回值: 0成功，d_vector输出特征值
 - 功能: 判断声纹特征

4. `void TwirlingVPRRelease(void *obj)`
 - `obj[IN]` TwirlingVPRInit 函数返回的指针
 - 功能: 销毁声纹对象指针，释放资源
