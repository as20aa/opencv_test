# opencv的第一个测试程序搭建过程记录
## 搭建前的准备
* 设置好环境变量，将opencv的安装目录加入到环境变量中,如下
D:\Software\OpenCV\build\x64\vc15\bin
## 开始搭建
* 首先建立一个新的控制台应用程序项目
* 点击视图->其他视图->属性管理器
* 找到debug64，右键单击新建配置文件
* 输入配置文件为opencv_64
* 双击打开opencv_64
* 在C/C++常规菜单中，新建一个附加包含目录，如下
D:\Software\OpenCV\build\include
* 选择链接器中的常规项，添加附加库目录，如下
D:\Software\OpenCV\build\x64\vc15\lib
* 将选择链接器中的输入项，添加附加依赖项，如下
opencv_world340d.lib
* 保存之后回到代码编辑界面，因为vs新版之后都是默认将包含文件放在stdafx.h中，所以与示例文件有点不同
[示例代码](https://github.com/opencv/opencv/blob/master/samples/cpp/tutorial_code/introduction/windows_visual_studio_opencv/introduction_windows_vs.cpp#L1)
* 将上面的include和using全部添加进stdafx.h，剩下的代码全都复制粘贴进项目的主代码文件中
## 快速入门系列
首先了解下cv中的一些常用的class
* 读取一张图片
```c++
Mat cv::imread 
(
const String & 
filename, 


int 
flags = IMREAD_COLOR 

)

```
说明：Mat在cv中是一个矩阵，因为图片以矩阵的方式存储（如果是按位存储的话）
,即cv::imread()默认返回是一个矩阵，代表了图片，flag默认为彩色模式，如果需要更改图片的读取模式可以修改flag		
[cv::imread](https://docs.opencv.org/3.4.1/d4/da8/group__imgcodecs.html)
* 显示一个窗口（为了显示图片做准备）
```c++
void cv::namedWindow 
(
const String & 
winname, 


int 
flags = WINDOW_AUTOSIZE 

)


Python:

None
=
cv.namedWindow(
winname[, flags]
)
```

* 显示一张图片
```c++
void cv::imshow 
(
const String & 
winname, 


InputArray 
mat 

)
```
显示一张图片，但是这张图片可能只能显示部分大小，而不是按照完全的大小显示
如果要显示一张完全的图片并且可以调整显示的窗口大小，则在call nameWindow时使用cv::WINDOW_AUTOSIZE标签		
[有关窗口操作的参考](https://docs.opencv.org/3.4.1/d7/dfc/group__highgui.html#ga5afdf8410934fd099df85c75b2e0888b)
* 打开电脑自带摄像头(需要了解下什么是videoCapture)
```c++
cv::VideoCapture::VideoCapture 
(
int 
index
)

Python:

<VideoCapture object>
=
cv.VideoCapture(

)

<VideoCapture object>
=
cv.VideoCapture(
filename
)

<VideoCapture object>
=
cv.VideoCapture(
filename, apiPreference
)

<VideoCapture object>
=
cv.VideoCapture(
index
)
```
此处的videoCapture()可以打开默认的摄像头，但是同样也需要建立一个窗口用来显示，获得的视频流用Mat表示，但是打开一个视频
端口需要声明一个VideoCapture的类来表示，即要用到VideoCapture和Mat两种数据类型
[打开摄像头示例](https://docs.opencv.org/3.4.1/d8/dfe/classcv_1_1VideoCapture.html#details)
* 打开外接的摄像头
```c++
cv::VideoCapture::VideoCapture 
(
const String & 
filename, 


int 
apiPreference 

)
```
这里的启动函数与上面的打开笔记本电脑自带的摄像头类似，只是因为传入的参数发生了改变，是重载函数，这里的filename决定了
视频的来源是什么，如果是视频文件，则是播放视频；如果是一系列的图片，则是类似于播放gif一样；如果是url则代表的是
网络摄像头；如果是视频流，则显示的是该视频流的内容
* 动作分析(不知道干啥和如何用的，暂时mark)
[motion analysis](https://docs.opencv.org/3.4.1/d7/de9/group__video.html)
## 较为系统且完整的学习请看官方tutorial
## 一些基础
* Mat是用来存储图像的类，由于opencv以前使用c写的，内存管理不太方便，后来出现了C++之后，就换用C++开发，mat对于图像的存储是
存储一个头和一个指向存储矩阵的指针，当对mat类进行复制时，得到的只是该头和指针的复制，真正的存储矩阵是不会被复制的，只是指向
该存储矩阵的指针变多了而已，同样，如果对其中一个mat进行操作，就会相应改变其他的mat，如果需要将矩阵也拷贝，则可以使用
```c++
mat.clone()
mat.copyto()
```
两个函数进行复制
