# DHT11温湿度传感器

使用DHT11温湿度传感器检测当前环境的温湿度，并在串口输出当前检测出的温度以及湿度情况。



## 一、简介

DHT11温湿度传感器，可在Arduino开发板上编程使用来检测环境的温度和湿度。

测量范围：温度：0~50℃， 湿度：20~90%RH

测量精度：温度：±2℃， 湿度：±5%RH



## 二、实验器件

- Arduino开发板  X  1
- DHT11温湿度传感器  X  1
- 数据烧写线  X  1
- 杜邦线  X  3

## 三、实验连线

| DHT11 | Arduino |
| :---: | :-----: |
|  VCC  |   5V    |
|  GND  |   GND   |
| DATA  |    8    |



## 四、实验步骤

1. 根据连线表格以及实验电路图，将DHT11与Arduino开发板进行连接；
2. 将Arduino开发板与电脑通过USB烧写线进行连接；
3. 使用Arduino IDE将代码验证并上传；
4. 打开串口监视器，查看DHT11输出的当前环境的温度以及湿度。



## 五、实验代码

```
#include <dht11.h>   //引用dht11库文件，使得下面可以调用相关参数
#define dht11Pin 8   //定义温湿度针脚号为8号引脚
dht11 dht;    //实例化一个对象
void setup()    //初始化函数，只执行一次
{
  Serial.begin(9600);      //设置波特率参数
  pinMode(dht11Pin, OUTPUT);    //通过定义将Arduino开发板上dht11Pin引脚(8号口)的工作模式转化为输出模式
}
void loop()     //loop函数，重复循环执行
{
  int tol = dht.read(dht11Pin);    //将读取到的值赋给tol
  int temp = (float)dht.temperature; //将温度值赋值给temp
  int humi = (float)dht.humidity; //将湿度值赋给humi
  Serial.print("Temperature:");     //在串口打印出Tempeature:
  Serial.print(temp);       //在串口打印温度结果
  Serial.println("℃");    //在串口打印出℃
  Serial.print("Humidity:");     //在串口打印出Humidity:
  Serial.print(humi);     //在串口打印出湿度结果
  Serial.println("%");     //在串口打印出%
  delay(1000);      //延时1秒
}
```

