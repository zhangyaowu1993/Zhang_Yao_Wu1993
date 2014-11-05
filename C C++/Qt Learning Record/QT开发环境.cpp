调试...QT属性.....
可执行文件：
E:\Qt\Qt5.3.1\5.3\msvc2013_opengl\bin


包含文件：
E:\Qt\Qt5.3.1\5.3\msvc2013_opengl\include

E:\Qt\Qt5.3.1\5.3\msvc2013_opengl\include\QtGui

E:\Qt\Qt5.3.1\5.3\msvc2013_opengl\include\QtCore

 
引用文件： 
E:\Qt\Qt5.3.1\5.3\msvc2013_opengl\bin

 
库文件： 
E:\Qt\Qt5.3.1\5.3\msvc2013_opengl\lib

 
源文件： 
E:\Qt\Qt5.3.1\5.3\msvc2013_opengl\


QT5程序发布:
首先编译release版本程序 然后使用ProcessExplorer查看所需依赖库DLL
View->Lower Pane View->Show Dll;
然后开启程序 对DLL进行排序 忽略系统DLL 然后根据依赖库加入DLL

DLL保持层级关系 层级如下:

Exe;
//QT模块库
Qt5Core.dll
Qt5Gui.dll
Qt5Widgets.dll

//ICU
icudt52.dll
icuin52.dll
icuuc52.dll

//VC运行库
msvcr120.dll
msvcp120.dll

//插件
platforms->qwindows.dll
accessible->qtaccessiblewidgets.dll
