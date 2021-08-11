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

# 安装带硬件编解码版本的ffmpeg

## 参考URL

https://trac.ffmpeg.org/wiki/CompilationGuide/Ubuntu

https://www.willusher.io/general/2020/11/15/hw-accel-encoding-rpi4

## 安装步骤

1, 按照FFmpeg的官方文档走到“FFmpeg”这一步。

2, 拉下来FFmpeg的代码

```
git clone --depth 1 --branch release/4.3 git@github.com:FFmpeg/FFmpeg.git
cd FFmpeg
```
3, 按照下面的脚本进行编译连接和安装。编译连接的时间大约是30分钟左右，请耐心等待。
```
PATH="$HOME/bin:$PATH" PKG_CONFIG_PATH="$HOME/ffmpeg_build/lib/pkgconfig" ./configure \
  --prefix="$HOME/ffmpeg_build" \
  --pkg-config-flags="--static" \
  --extra-cflags="-I$HOME/ffmpeg_build/include" \
  --extra-ldflags="-L$HOME/ffmpeg_build/lib" \
  --extra-libs="-lpthread -lm" \
  --ld="g++" \
  --bindir="$HOME/bin" \
  --enable-gpl \
  --enable-nonfree \
  --arch=aarch64 \
  --enable-libaom \
  --enable-libass \
  --enable-libfdk-aac \
  --enable-libfreetype \
  --enable-libmp3lame \
  --enable-libopus \
  --enable-libdav1d \
  --enable-libvorbis \
  --enable-libvpx \
  --enable-libx264 \
  --enable-libx265 \
  --enable-nonfree && \
PATH="$HOME/bin:$PATH" make && \
make install && \
hash -r
```
4，安装并且gnome system monitor

参考如下URL

https://vitux.com/how-to-install-and-use-task-manager-system-monitor-in-ubuntu/

5，随便找个网站下载一个示范的1080P的mp4文件

假设名字为sample.mp4,则在控制台执行硬件编解码版本的ffmpeg

```
ffmpeg -i sample.mp4 -c:v h264_v4l2m2m -b:v 8M -c:a copy test1.mp4
```

执行的时候注意观察控制台里面的速度输出，在我这里是1.2x左右，即每秒40帧左右

再执行一下不带硬件编解码的版本，在我这里是0.16x左右，即每秒5帧左右。

```
ffmpeg -i sample.mp4 -b:v 8M -c:a copy test2.mp4
```

两项测试虽然速度有所不同但是CPU的占有率几乎都是100%，即无论是否是硬件编解码，都是很高的CPU占有率，这一点需要引起重视。
