# opencv�ĵ�һ�����Գ������̼�¼
## �ǰ��׼��
* ���úû�����������opencv�İ�װĿ¼���뵽����������,����
D:\Software\OpenCV\build\x64\vc15\bin
## ��ʼ�
* ���Ƚ���һ���µĿ���̨Ӧ�ó�����Ŀ
* �����ͼ->������ͼ->���Թ�����
* �ҵ�debug64���Ҽ������½������ļ�
* ���������ļ�Ϊopencv_64
* ˫����opencv_64
* ��C/C++����˵��У��½�һ�����Ӱ���Ŀ¼������
D:\Software\OpenCV\build\include
* ѡ���������еĳ������Ӹ��ӿ�Ŀ¼������
D:\Software\OpenCV\build\x64\vc15\lib
* ��ѡ���������е��������Ӹ������������
opencv_world340d.lib
* ����֮��ص�����༭���棬��Ϊvs�°�֮����Ĭ�Ͻ������ļ�����stdafx.h�У�������ʾ���ļ��е㲻ͬ
[ʾ������](https://github.com/opencv/opencv/blob/master/samples/cpp/tutorial_code/introduction/windows_visual_studio_opencv/introduction_windows_vs.cpp#L1)
* �������include��usingȫ����ӽ�stdafx.h��ʣ�µĴ���ȫ������ճ������Ŀ���������ļ���
## ��������ϵ��
�����˽���cv�е�һЩ���õ�class
* ��ȡһ��ͼƬ
```c++
Mat cv::imread 
(
const String & 
filename, 


int 
flags = IMREAD_COLOR 

)

```
˵����Mat��cv����һ��������ΪͼƬ�Ծ���ķ�ʽ�洢������ǰ�λ�洢�Ļ���
,��cv::imread()Ĭ�Ϸ�����һ�����󣬴�����ͼƬ��flagĬ��Ϊ��ɫģʽ�������Ҫ����ͼƬ�Ķ�ȡģʽ�����޸�flag		
[cv::imread](https://docs.opencv.org/3.4.1/d4/da8/group__imgcodecs.html)
* ��ʾһ�����ڣ�Ϊ����ʾͼƬ��׼����
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

* ��ʾһ��ͼƬ
```c++
void cv::imshow 
(
const String & 
winname, 


InputArray 
mat 

)
```
��ʾһ��ͼƬ����������ͼƬ����ֻ����ʾ���ִ�С�������ǰ�����ȫ�Ĵ�С��ʾ
���Ҫ��ʾһ����ȫ��ͼƬ���ҿ��Ե�����ʾ�Ĵ��ڴ�С������call nameWindowʱʹ��cv::WINDOW_AUTOSIZE��ǩ		
[�йش��ڲ����Ĳο�](https://docs.opencv.org/3.4.1/d7/dfc/group__highgui.html#ga5afdf8410934fd099df85c75b2e0888b)
* �򿪵����Դ�����ͷ(��Ҫ�˽���ʲô��videoCapture)
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
�˴���videoCapture()���Դ�Ĭ�ϵ�����ͷ������ͬ��Ҳ��Ҫ����һ������������ʾ����õ���Ƶ����Mat��ʾ�����Ǵ�һ����Ƶ
�˿���Ҫ����һ��VideoCapture��������ʾ����Ҫ�õ�VideoCapture��Mat������������
[������ͷʾ��](https://docs.opencv.org/3.4.1/d8/dfe/classcv_1_1VideoCapture.html#details)
* ����ӵ�����ͷ
```c++
cv::VideoCapture::VideoCapture 
(
const String & 
filename, 


int 
apiPreference 

)
```
�������������������Ĵ򿪱ʼǱ������Դ�������ͷ���ƣ�ֻ����Ϊ����Ĳ��������˸ı䣬�����غ����������filename������
��Ƶ����Դ��ʲô���������Ƶ�ļ������ǲ�����Ƶ�������һϵ�е�ͼƬ�����������ڲ���gifһ���������url��������
��������ͷ���������Ƶ��������ʾ���Ǹ���Ƶ��������
* ��������(��֪����ɶ������õģ���ʱmark)
[motion analysis](https://docs.opencv.org/3.4.1/d7/de9/group__video.html)
## ��Ϊϵͳ��������ѧϰ�뿴�ٷ�tutorial
## һЩ����
* Mat�������洢ͼ����࣬����opencv��ǰʹ��cд�ģ��ڴ����̫���㣬����������C++֮�󣬾ͻ���C++������mat����ͼ��Ĵ洢��
�洢һ��ͷ��һ��ָ��洢�����ָ�룬����mat����и���ʱ���õ���ֻ�Ǹ�ͷ��ָ��ĸ��ƣ������Ĵ洢�����ǲ��ᱻ���Ƶģ�ֻ��ָ��
�ô洢�����ָ�����˶��ѣ�ͬ�������������һ��mat���в������ͻ���Ӧ�ı�������mat�������Ҫ������Ҳ�����������ʹ��
```c++
mat.clone()
mat.copyto()
```
�����������и���
