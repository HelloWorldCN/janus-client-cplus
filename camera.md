# 系统信息
## Raspberry Pi 4B

## Ubuntu Desktop 21.04

https://ubuntu.com/download/raspberry-pi

## Camera

https://www.raspberrypi.org/products/camera-module-v2/

# 步骤

## 硬件连接

参考如下的图片。（Ubuntu 21的设定跟Raspibian的设定不一样，所以设定可以略去不看）

https://thepihut.com/blogs/raspberry-pi-tutorials/16021420-how-to-install-use-the-raspberry-pi-camera

## 软件设定

参考如下连接

https://askubuntu.com/questions/1211805/raspberry-picamera-on-ubuntu-not-found

设定完成之后，可以访问如下网页确认可以使用摄像头。

https://janus.conf.meetecho.com/videoroomtest.html

打开控制台输入
```
sudo chmod 777 /dev/vchiq
sudo raspistill -o image.jpg
```
大约几秒钟时间之后，即可在根目录下看到你拍摄的照片。
