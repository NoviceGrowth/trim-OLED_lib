# oledlib

#### 介绍
一个开源的oled图形库

#### 软件架构
图形库采用STM32F1单片机在0.96寸的oled上编写的一个oled图形库  
使用Keil5进行开发  
支持软件IIC和软件SPI通信方式
在F103上(72M)上测试通过  

#### 安装教程

1.  若编译出现问题 文件路径下请不要出现中文字符
2.  使用keil5进行开发

#### 硬件支持
1.  在 oled_config.h 中查看或选择驱动方式  
2.  在 oled_driver.h 中查看、配置或更改引脚  
3.  若要更改或新增驱动方式 在oled_driver.c中查看以支持驱动的结构  

#### 使用说明

1.  在每个c文件开头都有相关注释
2.  若对此代码有什么不理解之处 可见[**bilibili 单片机图形库开源分享**](https://www.bilibili.com/video/BV1EC4y1872W "bilibili 单片机图形库开源分享")  
    ![输入图片说明](https://i1.hdslb.com/bfs/archive/eb3319e3afae3c2f835974e244b7971e1338aa4e.jpg@160w_100h_100Q_1c.webp "在这里输入图片标题")

#### 参与贡献

该代码由[MjGame](https://space.bilibili.com/38673747)写出并[发出视频](https://www.bilibili.com/video/BV1MV411o7P5),其[原始代码](https://github.com/hello-myj/stm32_oled)经我整理并由MjGame同意后发出分享给大家,如果你有更好的想法,欢迎在此提交分支,我们一起完善这个图形库  
如果进行PR：代码格式，注释及缩进方式请参考源代码，不要添加无用代码，空行及宏定义  
当然若不会PR，也可以提交ISSUES，我会及时发现并更新 


