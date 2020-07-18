项目名称：SPlayer多媒体播放软件                                             
项目编号：                                                        第  版
文档编号：项目编号_PD_流水号                            第  册/共  册






概要设计

版本：Ver 0.1














总页数 16  正文  13  附录  1   生效日期    2016.6.30
 
修订记录

日期  版本  说明  作者
2016-6-30   V0.1    初次创建完成
            
            



 
目录
1.  引言  1
1.1 术语  1
2.  系统结构    2
3.  模块功能概述  3
3.1 欢迎界面    3
3.2 播放器界面   3
3.3 播放器模块   3
3.4 播放列表模块  4
4.  模块架构    4
4.1 模块内部构成  4
4.2 变更机能    7
5.  模块接口设计  8
5.1 欢迎界面模块  8
5.2播放界面模块   8
5.3播放器模块    9
5.4播放列表模块   10
5.5网络热门视频模块 12
6.  关键数据结构  12
7.  附件  13
7.1 模块技术点整理 13
7.2 参考文档    13
 
1.  引言
此文档概要讲述了SPlayer多媒体播放软件的主要功能模块以及内部功能实现，涉及了本软件架构级设计的基本算法、关键数据结构、主要设计思想等。

预期读者为本软件设计团队team3的所有成员。


1.1 术语
表 1 1：技术术语
番号  用語  説明
1   UI  用户界面
2   Player  播放器
        
        
 
2.  系统结构
 

图2-1 系统结构图


本系统主要包括UI、网络浏览器和文件操作三大部分，UI主要包括播放界面、播放列表、历史记录、设置框，通过播放界面上按钮操作可以弹出设置框，播放界面上显示播放列表与历史记录以及热门推荐，热门推荐使用网络浏览器打开；播放视频与音频文件可以通过标准文件选择或直接拖拽到播放器播放区域实现，播放器播放视频音频文件通过读写文件，同时更新播放列表与历史记录。








3.  模块功能概述
3.1 欢迎界面
功能点 功能点详细说明
欢迎界面图片  软件打开时，显示进度条与欢迎动画
进入软件主界面 欢迎动画结束或点击进入软件播放界面





表3-1 欢迎界面功能表

3.2 播放器界面（软件主界面）
视频播放界面  用来播放视频的区域
操作栏 包括播放/暂停，停止，循环播放，全屏/退出全屏，快进，快退,声音调节条和静音按钮,视频进度调节条,截屏，录制
声音和时间显示 显示声音百分比和时间进度
列表  包括播放列表和历史记录
菜单栏 包含设置，关于和文件








表3-2 播放器界面功能表

3.3 播放器模块
路径（Path）    保存视频路径
暂停播放(pause) 点击按钮，暂停播放视频
开始播放（start） 点击按钮，开始播放视频
停止播放（stop）  点击按钮，停止播放视频
快进(goForward)   点击按钮，播放快进T秒（T为设置时间)
快退(goBack)  点击按钮，播放后退T秒（T为设置时间）
快速定位(locate)    拖动滑条，快速定位播放视频的位置
全屏(setFullScreen)   点击按钮，视频全屏播放
退出全屏(escFullScreen)     点击按钮，视频退出全屏播放
亮度（brightness）  拖动滑条，设置亮度
饱和度(saturability)   拖动滑条，设置饱和度
色调(hue) 拖动滑条，设置色调
对比度(contrast）   拖动滑条，设置对比度
表3-3 播放器功能表

3.4 播放列表模块
功能点 功能点详细说明
Last    播放上一条记录
Next    播放下一条记录
隐藏列表    播放区域覆盖列表
显示列表    播放区域缩小，显示列表
清空列表    删除所有播放记录
增加记录    加入一条等待播放的文件的记录
删除记录    删除一条记录
播放  播放一条记录对应的文件
找到文件所在目录    找到列表中记录对应的文件所在目录
表3-4 播放列表功能表
4.  模块架构

4.1 模块内部构成
欢迎模块（WizardPage Module）：软件的开始界面，通过此界面进入主界面。
 
图4-1 欢迎界面模块图


序号  模块名称    接口函数    函数说明
1   WizardPage  wizardpage  进入主界面
表4-1 欢迎界面接口函数表

播放器界面（软件主界面）模块（Player Module）：此界面通过操作栏对打开的视频进行操作，通过视频播放界面播放视频，通过菜单栏或者拖动行为实现打开视频等操作，通过列表访问本地记录的历史记录和播放列表，此外还会显示当前声音的比例和播放进度：
 
图4-2 播放器界面模块图

序号  模块名称    接口函数    函数说明
1   Player  on_buttonXXX_clicked    对xxx按钮作出响应
2   Player  on_sliderXXX_valueChanged   对xxx滑动条作出响应
表4-2 播放器界面接口函数表
播放器模块（Media Module）：此模块包含控制视频播放进度，视频路径，设置视频亮度、对比度、饱和度、色调的功能。

 
图4-3 播放器模块图
序号  模块名称    接口函数    函数说明
1   Meida   void setPath(QString path)  初始化视频路径类型
2   Media   void pause()    暂停播放视频
3   Media   void start()    开始播放视频
4   Media   void stop() 停止播放视频
5   Media   void goFoward(qint64 value) 快进播放value时间
6   Media   void goBack(qint64 value)   后退播放value时间
7   Media   void locate(qint64 value)   快速定位至value位置播放
8   Media   void setFullScreen()    全屏播放
9   Media   void escFullScreen()    退出全屏
10  Media   void setContrast(qint8 value)   设置对比度为value
11  Media   void setSaturation(qint8 value) 设置饱和度为value
12  Media   void setBrightness(qint8 value) 设置亮度为value
13  Media   void setHue(qint8 value)    设置色调为value
表4-3 播放器接口函数表
播放列表模块（List Moudle）:主要负责为上层的界面模块提供控制的功能， 使本软件能对记录及记录对应的文件进行相关操作。
 
图4-4 播放列表模块图
序号  模块名称    接口函数    函数说明
1   List    last    Last:上一条记录
2   List    next    Next：下一条记录
3   List    hideList    隐藏列表/显示列表
4   List    clearList   清空列表
5   List    addFile 增加记录
6   List    delete  删除记录
7   List    play    播放
8   List    openDir 找到文件所在目录
图4-1 播放列表接口函数表
4.2 变更机能
暂无
  
5.  模块接口设计
5.1 欢迎界面模块
函数名
wizardpage
文件名  wizardpage.cpp
功能概要    跳转到播放界面
记述形式    void wizardpage(void)
参数
类型  变量名 I/O 说明
-   -   -   -
返回值 类型  void    说明
    值   -   -
详细说明
 响应鼠标点击进入播放界面或等待动画结束进入播放界面
使用注意事项
无

5.2播放界面模块
函数名
on_buttonXXX_clicked
文件名 player.cpp
功能概要    对XXX按钮进行响应
记述形式    void on_buttonXXX_clicked (void)
参数
类型  变量名 I/O 说明
void    -   -   -
返回值 类型  void    说明
    值   1   -
详细说明
对XXX按钮进行响应
使用注意事项
无

函数名
on_sliderXXX_valueChanged
文件名 player.cpp
功能概要    获取滑动条改变值，并进行操作
记述形式    void on_sliderXXX_valueChanged (int value)
参数
类型  变量名 I/O 说明
int value   -   滑动条的值
返回值 类型  -   说明
    值   -   -
详细说明
对XXX滑动条进行响应
使用注意事项
无

5.3播放器模块
函数名
setPath
文件名 media.cpp
功能概要    初始化视频路径和类型
记述形式    int setPath(string path)
参数
类型  变量名 I/O 说明
string  path    -   视频路径
返回值 类型      说明
    值   0   视频可以播放
        1   视频不可以播放
详细说明
输入要播放视频的路径
使用注意事项
无





函数名
pause
文件名 media.cpp
功能概要    暂停播放视频
记述形式    void pause()
参数
类型  变量名 I/O 说明
N/A N/A N/A N/A
返回值 类型      说明
    值   N/A N/A
详细说明
暂停播放视频
使用注意事项
无

函数名
goForward(int step)
文件名 media.cpp
功能概要    视频快进播放
记述形式    void goForward(int step)
参数
类型  变量名 I/O 说明
int step    -   快进时间
返回值 类型      说明
    值   -   -
详细说明
视频快进播放
使用注意事项
无

5.4播放列表模块
函数名
last
文件名  list.cpp
功能概要    播放上一条记录
记述形式    void last(void)
参数
类型  变量名 I/O 说明
-   -   -   -
返回值 类型  void    说明
    值   -   -
详细说明
 点击上一项时播放上一条记录
使用注意事项
无

函数名
hidelist
文件名  list.cpp
功能概要    实现列表的显示或隐藏
记述形式    void hidelist(void)
参数
类型  变量名 I/O 说明
-   -   -   -
返回值 类型  void    说明
    值   -   -
详细说明
响应播放界面中的显示/隐藏选项，实现播放列表的显示/隐藏
使用注意事项
无


函数名
addFile
文件名 list.cpp
功能概要    向列表中增加一条文件
记述形式    void addFile(string path)
参数
类型  变量名 I/O 说明
string  path    -   用于存放选入的文件的文件路径
返回值 类型  void    说明
    值   -   -
详细说明
添加指定位置的文件到列表，并在播放界面中的播放列表显示
使用注意事项
无

函数名
play
文件名  list.cpp
功能概要    播放指定播放记录对应的文件
记述形式    string play ()
参数
类型  变量名 I/O 说明
-   -   -   -
返回值 类型      说明
    值   string  返回当前播放的视频路径
详细说明
根据编号读出文件进行播放，若有，将正在播放的文件关闭并写入历史记录
使用注意事项
无
5.5网络热门视频模块
函数名
goWeb
文件名 media.cpp
功能概要    打开内置浏览器
记述形式    bool goWeb(void)
参数
类型  变量名 I/O 说明
N/A N/A N/A N/A
返回值 类型  bool    说明:打开内置浏览器是否成功
    值   0   打开浏览器成功
        1   打开浏览器失败
详细说明
无
使用注意事项
无

6.  关键数据结构
数据结构
 

7.  附件
无
7.1 模块技术点整理
无
7.2 参考文档
编号  文档名称    版本  作者
            
            
            
            





