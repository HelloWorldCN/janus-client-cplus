## janus-client

'janus-client' is an open source Janus Gateway client developed with webrtc native C++ for learning and research purposes. Most components are based on 'rtc_base' of WebRTC. In order to facilitate learning and debugging WebRTC code, I choose to use Visual Studio to develop on Windows platform. MacOS, IOS and Linux platforms will be supported after the main features are completed.

## Dependencies

* [Qt5](http://download.qt.io/archive/qt/) Used Qt for UI
* [asio](https://github.com/chriskohlhoff/asio) Referenced by websocketpp
* [websocketpp](https://github.com/zaphoyd/websocketpp) WebSockets support for the Janus API
* [x2struct](https://github.com/xyz347/x2struct/) Used to convert between C++ objects and json
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

	git clone --recursive https://github.com/ouxianghui/janus-client.git
  
  Open RTCSln.sln with Visual Studio(2017)
  
## UI
<img src="https://github.com/ouxianghui/janus_client/blob/main/janus-client-ui.png" height="500" /><br>


## Author
Jackie Ou 750265900@qq.com

Any thought, suggestion, feedback is welcome!
