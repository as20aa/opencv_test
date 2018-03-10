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
* 创建一个滑动条		
```c++
int cv::createTrackbar 
(
const String & 
trackbarname, 


const String & 
winname, 


int * 
value, 


int 
count, 


TrackbarCallback 
onChange = 0, 


void * 
userdata = 0 

)
```
此处的滑动条返回的是整数值？
* 高级的形态学操作
```c++
void cv::morphologyEx 
(
InputArray 
src, 


OutputArray 
dst, 


int 
op, 


InputArray 
kernel, 


Point 
anchor = Point(-1,-1), 


int 
iterations = 1, 


int 
borderType = BORDER_CONSTANT, 


const Scalar & 
borderValue = morphologyDefaultBorderValue() 

)
```
此函数是以腐蚀和膨胀作为基本操作的高级的形态学操作，用于简单的形态学分析。[详见](https://docs.opencv.org/master/d4/d86/group__imgproc__filter.html#ga67493776e3ad1a3df63883829375201f)
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
## 图像处理部分
图像处理是OpenCV的重要的一个部分，了解基本的图像处理的操作和原理以及实现，并运用这些方法对未来复杂图像进行处理得到想要的结果
* 平滑图像（又称模糊）		
平滑图像主要是为了去除噪点，从而使整个图像看起来更加柔和，[见此链接](https://docs.opencv.org/master/dc/dd3/tutorial_gausian_median_blur_bilateral_filter.html)
(能够对经过了傅里叶变换的图像信息进行同样的平滑操作呢？)		
高斯模糊有一维和二维，还有中心滤波，为了改进高斯滤波在边缘的局限性，出现了考虑到滤波后与滤波前的像素的差距的
双边滤波器
* 图像腐蚀(Erosion)(Morphological，形态学上的内容)		
是否就是出现人体框架的重要理念？图像腐蚀是通过一个核，中心点称为锚点，在扫描图像的过程中，将选取核覆盖范围内最大的值
替代锚点处的值。因为图像表示中，在黑白图中，纯白色是最大值，黑色是最小值，即锚点处的值越大则图像就越亮，从而把边缘一些黑的角落给
变白，与背景色融合。如果是用一个背景色为白色，物体为黑色的图像进行腐蚀处理，则得到一个看起来更细的形态
* 图像膨胀(Dilation，形态学上的内容)		
与腐蚀相反，这个操作是直接取核的最小值，作用也相反
* opening（不知道中文翻译是啥）		
此操作是先膨胀后腐蚀作用在同一幅图像上的操作，类似于复合函数的概念		
dst=open(src,element)=dilate(erode(src,element))		
能够去掉图像中的一些小的细节部分，并将其融在一起
* closing
dst=close(src,element)=erode(dilate(src,element))		
先腐蚀后膨胀，用于移除一些小的孔洞（即形态上围成的小洞）
* 形态学梯度（Morphological Gradient）		
dst=morphgrad(src,element)=dilate(src,element)−erode(src,element)		
是腐蚀和膨胀两种操作之间的不同得到的，能够得到一个对象的边缘！（简单的边缘检测？）
* Top Hat		
是输入图像和opening操作后的图像的不同
* Black Hat		
是输入图像和closing操作后的图像的不同
* Hit-Miss Theory		
此理论是用来查找那些四个方向上有特定的patten的点，并把它们筛选出来，[详见](https://docs.opencv.org/master/db/d06/tutorial_hitOrMiss.html)
* 图像金字塔(Image Pyramids)		
在现实中我们可能用到图像金字塔的技术来还原或者压缩图像，压缩一个图像是，我们是把原图像放在一个高斯核上进行处理，并把非数字的像素点丢弃，
产生新的一层图像（变成原图的1/4），依次不断重复对每一新层进行处理，知道我们得到一个所需要的点为止，所构成的多福图像就像是金字塔一样。
如果需要扩展则方向使用拉普拉斯变换
* 阈值操作		
适用于分离前景和背景，通过对图像中超过或者低于一定数值的像素进行操作，替换成为特定值
* 对图像梯度计算的重要性		
对图像的梯度计算能够让我们找出在图像中像素点突变的地方，这些像素突变的地方一般都是物体的边缘（假设物体是一个均一
颜色，并且与背景不同），利用梯度可以观察到物体的边缘，故用于物体检测。		
计算梯度有分横向和纵向，两个方向均有不同的核（但是旋转是一致的）来进行处理。我们可以用取模的方式来计算两个方向
的合梯度。当核的大小为3时，我们使用Scharr()而不是Sobel()来计算。在对图像求梯度之前可以先用高斯模糊先消去噪点
然后再对图像求梯度。		
更进一步地！我们可以知道在数学上如果一个函数存在极值点，则它的导数为0，相应地，我们取图像边缘时是取像素变化的最大
处，类推可得，对图像求两次梯度可以也可以得到图像边缘，opencv中用Laplacian（）可以解决这点。
* 对直线和圆的识别
对直线的识别是通过画一条直线，计算与该直线的交点数量来判断是否为直线，圆也类似。操作步骤为：导入图像，对图像
进行高斯核处理，消除噪点，根据边缘分割算法对物体的边缘进行判断，做直线拟合。
* remapping		
实际上就是旋转和堆成操作
* affine remapping		
三维旋转对称操作
* 图像直方图计算（重要！特征识别的重要依据）		
一个图像是由很多种颜色构成的，如果对每个像素点的颜色进行统计，则会得到一张统计表，横轴为颜色，纵轴为出现的次数，
这就是直方图。直方图常常用来表示一个特征的信息。获得的直方图信息是MatND类型或者是直接Mat类型	
常用的对直方图的操作有：
1.对直方图进行拉伸
```c++
void cv::equalizeHist 
(
InputArray 
src, 


OutputArray 
dst 

)
```
而且是直接对图像进行操作了，输入的是图像，返回的也是图像
2.计算图像的直方图信息
```c++
void cv::calcHist 
(
const Mat * 
images, 


int 
nimages, 


const int * 
channels, 


InputArray 
mask, 


OutputArray 
hist, 


int 
dims, 


const int * 
histSize, 


const float ** 
ranges, 


bool 
uniform = true, 


bool 
accumulate = false 

)
```
3.对直方图信息进行比较
```c++
double cv::compareHist 
(
InputArray 
H1, 


InputArray 
H2, 


int 
method 

)
```
使用的是统计学中的标准差的概念来计算的
4.数字化
```c++
static Vec<_Tp, cn> cv::normalize 
(
const Vec< _Tp, cn > & 
v
)
```
* 对于特征的识别		
通过对直方图信息的比较来比较两幅图像的相似性，可以忽略目标的放置角度变换，但是视角有限制
```c++
void cv::calcBackProject 
(
const Mat * 
images, 


int 
nimages, 


const int * 
channels, 


InputArray 
hist, 


OutputArray 
backProject, 


const float ** 
ranges, 


double 
scale = 1, 


bool 
uniform = true 

)
```
这是back project（中文不知道该怎么翻译）是用来匹配原图片与所给图片的，运用的是直方图分析的方法
* template matching（模板匹配）
```c++
void cv::matchTemplate 
(
InputArray 
image, 


InputArray 
templ, 


OutputArray 
result, 


int 
method, 


InputArray 
mask = noArray() 

)
```
此处的模板匹配法有很多种方法，有些是通过蒙板的，有些不是。主要的方法是将小块的特征在待匹配图片上滑动，每次
滑动都计算直方图的相似性，直到整幅图滑动完成，找到相似性最高的一点，就是特征所在位置

