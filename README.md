## janus-client

'janus-client' is an open source Janus Gateway client developed with webrtc native C++ for learning and research purposes. Most components are based on 'rtc_base' of WebRTC. In order to facilitate learning and debugging WebRTC code, I choose the Visual Studio to develop on Windows platform. MacOS, IOS and Linux platforms will be supported after the main features are completed.

## Dependencies
* 安装Visual Studio community 2017

安装的时候需要选定C++/CLI，以及其他的C++必要组件。

* Qt5的安装
https://www.qt.io/offline-installers

选择“5.12.x Offline Installers”，然后下载安装Windows Host。

选择“Other downloads”，安装“Visual Studio Add-in 2.5.2 for Qt5 MSVC 2017 (17 MB) ”。

安装的时候，需要选择“msvc2017_64”。注意，这个在缺省的状态下是不会被安装的。

* [asio](https://github.com/chriskohlhoff/asio) Referenced by websocketpp
* [websocketpp](https://github.com/zaphoyd/websocketpp) WebSockets support for the Janus API
* [x2struct](https://github.com/xyz347/x2struct/) Used for conversion between C++ objects and json
* [glew](http://glew.sourceforge.net/) Used to render video frames
* [spdlog](https://github.com/gabime/spdlog) Used to build a log system
* WebRTC

* *Note:* 
* asio/websocketpp/x2struct/spdlog have joined this repository as submodules. 
* glew and WebRTC library(M85, release, webrtc.7z) have been included directly in this repository. 

## Features
* video room (available, and multistream branch is also avaliable)
* text room
* video call
* voice mail

## Arch
<img src="https://github.com/ouxianghui/janus_client/blob/main/janus-client-arch.svg" height="500" /><br>

## Compile
Get the code:

	git clone --recursive https://github.com/HelloWorldCN/janus-client-cplus.git
  注意，这里必须要使用recursive标志，并且你拉下来代码之后，需要去3rd目录下，把相关的zip给解压缩。
  
  Open RTCSln.sln with Visual Studio(2017)，打开了之后，需要
  
  1，先编译一下RTCSDK
  
  2，将UI工程设定为主工程。右键打开属性，UI Property Pages里面的Linker里面的Input，需要加上如下内容,如果已经设定了,此步骤可以忽略.
  ```
  Qt5Gui.lib
  Qt5Core.lib
  Qt5Widgets.lib
  ```
  UI Property Pages里面的Debugging，假设你的glew的路径是`C:\Users\tyori\Documents\janus-client\3rd\glew\bin\Release\x64`
  则需要修改路径为以下内容
  ```
  PATH=$(QTDIR)\bin%3bC:\Users\tyori\Documents\janus-client\3rd\glew\bin\Release\x64%3b$(PATH)
  ```
  3，编译的时候会出现一些找不头文件的错误，假设你的Qt的include目录是
  ```
  C:\Qt\Qt5.12.11\5.12.11\msvc2017_64\include
  ```
  则去该目录寻找找不到的头文件，找到了之后，追加源代码里面include的路径，比如是这样
  ```C
  //#include <QApplication>
  #include <QtWidgets/QApplication>
  ```
  如果没有错误,此步骤可以忽略.
  4，去Visual Studio的Qt VS Tools菜单里面选择Qt Options里面的QT->Vesions选项，在Path里面追加你安装的Qt的include所在的父目录路径，在我这里是
  ```
  C:\Qt\Qt5.12.11\5.12.11\msvc2017_64\include
  ```
  5，去Visual Studio的Qt VS Tools菜单里面选择Qt Project Settings,设定Version为你在第四步设定的Qt。
## UI
<img src="https://github.com/ouxianghui/janus_client/blob/main/janus-client-ui.png" height="500" /><br>




