# opencv的第一个测试程序搭建过程记录
## 搭建前的准备
* 设置好环境变量，将opencv的安装目录加入到环境变量中
## 开始搭建
* 首先建立一个新的控制台应用程序项目
* 点击视图->其他视图->属性管理器
* 找到debug64，右键单击新建配置文件
* 输入配置文件为opencv_64
* 双击打开opencv_64
* 在C/C++目录菜单中，新建一个包含目录
* 将opencv安装目录下的build/include添加进去
* 回到C/C++目录菜单，新建一个包含库
* 将安装目录下的build/x64/lib/vc15添加进去
* 保存之后回到代码编辑界面，因为vs新版之后都是默认将包含文件放在stdafx.h中，所以与示例文件有点不同
[示例代码](https://github.com/opencv/opencv/blob/master/samples/cpp/tutorial_code/introduction/windows_visual_studio_opencv/introduction_windows_vs.cpp#L1)
* 将上面的include和using全部添加进stdafx.h，剩下的代码全都复制粘贴进项目的主代码文件中
