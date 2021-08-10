# 1，麦克风信息

sunfounder

http://wiki.sunfounder.cc/index.php?title=To_use_USB_mini_microphone_on_Raspbian


# 2，麦克风的安装和确认
将麦克风插入树莓派的USB2端口，打开树莓派的控制台输入
```lsusb```
可以得到下述结果
```
Bus 003 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
Bus 002 Device 002: ID 1a6e:089a Global Unichip Corp.
Bus 002 Device 001: ID 1d6b:0003 Linux Foundation 3.0 root hub
Bus 001 Device 004: ID 8086:0808 Intel Corp. USB PnP Sound Device
Bus 001 Device 005: ID 1a81:1004 Holtek Semiconductor, Inc. Wireless Dongle 2.4 GHZ HT82D40REW
Bus 001 Device 002: ID 2109:3431 VIA Labs, Inc. Hub
Bus 001 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
```

确认可用的麦克风设备
```arecord -l```
可以得到类似下面的结果
```
**** List of CAPTURE Hardware Devices ****
card 3: Device [USB PnP Sound Device], device 0: USB Audio [USB Audio]
  Subdevices: 1/1
  Subdevice #0: subdevice #0
```
其中，我们的麦克风设备的id是3.

确定详细信息
```
cat /proc/asound/cards
```
可以得到类似下面的输出
```
 0 [Headphones     ]: bcm2835_headpho - bcm2835 Headphones
                      bcm2835 Headphones
 1 [vc4hdmi0       ]: vc4-hdmi - vc4-hdmi-0
                      vc4-hdmi-0
 2 [vc4hdmi1       ]: vc4-hdmi - vc4-hdmi-1
                      vc4-hdmi-1
 3 [Device         ]: USB-Audio - USB PnP Sound Device
                      C-Media Electronics Inc. USB PnP Sound Device at usb-0000:01:00.0-1.4, full spe
```
可以再次确认我们正在使用第3号设备。使用如下命令确认录制声音test.wav是否有问题
```
arecord -D sysdefault:CARD=3 test.wav
```

上述命令行里面去掉设备编号看看是否有问题
```
arecord test.wav
```
如果有问题，应该是如下的输出：
```
arecord: main:852: audio open error: No such file or directory
```
这个时候，需要使用命令
```
sudo nano /etc/asound.conf
```
打开了nano之后，粘贴如下信息，作为缺省的麦克风设备

```
pcm.!default {
        type hw
        card 3
}

ctl.!default {
        type hw
        card 3
}
```

Or, 使用命令
```nano ~/.asoundrc```
打开了nano之后，粘贴如下信息，作为缺省的麦克风设备

```
defaults.pcm.card 3;
defaults.ctl.card 3;
```

再次运行
```
arecord test.wav
```
这个时候应该是好用的。以上，麦克风安装完毕。
