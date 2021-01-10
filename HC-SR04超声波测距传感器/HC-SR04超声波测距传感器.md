# HC-SR04超声波测距传感器

使用arduino开发板以及HC-SR04超声波测距传感器检测距离，并在串口输出检测出的距离数据；



## 一、简介

HC-SR04超声波测距传感器，可在Arduino开发板上编程使用来检测障碍物距离。

测量范围：2-400cm

测量精度：±3mm



## 二、实验器件

 - arduino  X  1
 - HC-SR04超声波测距传感器  X  1
 - USB数据烧写线  X  1
 - 杜邦线  X  4



## 三、实验连线

| HC-SR04 | Arduino |
| :-----: | :-----: |
|   VCC   |   5V    |
|   GND   |   GND   |
|  Trig   |    2    |
|  Echo   |    3    |


## 四、实验步骤

1.根据连线表格以及实验电路图，将HC-SR04与Arduino开发板进行连接；
2.将Arduino开发板与电脑通过USB烧写线进行连接
3.使用Arduino IDE将代码验证并上传
4.打开串口监视器，查看HC-SR04输出的当前检测出的距离	



## 五、实验代码

```
int TrigPin = 2;    //将Trig的引脚定义为2号口
int EchoPin = 3;    //将Echo的引脚定义为3号口
float dist;    //定义一个变量，在下面存储HC-SR04返回的值
void setup()    //setup初始化函数，只运行一次
{
  Serial.begin(9600);    //设置运行波特率
  pinMode(TrigPin, OUTPUT);    //通过定义将Arduino开发板上TrigPin引脚(2号口)的工作模式转化为输出模式
  pinMode(EchoPin, INPUT);    //通过定义将Arduino开发板上EchoPin引脚(2号口)的工作模式转化为输入模式
}
void loop()    //loop函数，重复循环执行
{
  digitalWrite(TrigPin, LOW);    //发送低电平、发一个短时间脉冲去TrigPin
  delayMicroseconds(5);
  digitalWrite(TrigPin, HIGH);    //发送高电平、发一个短时间脉冲去TrigPin
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);    //发送低电平脉冲去TrigPin
  dist = pulseIn(EchoPin, HIGH) / 58.00; //将pulseIn换算成cm，并赋值给dist变量，转化方式见下：
  /**
     声波在常温常压的空气中传播的速度344米/秒，进行单位转化，34400厘米/秒
     继续做单位转化，为0.0344厘米/微秒，反过来，即29.069微秒/厘米，即声波传播一厘米需要29.069微秒
     而检测距离，是先发送声波，后接收，声波走的是二倍的距离，
     也就是说，超声波测距检测出1厘米，需要58.13微秒，即58.13
     pulseIn的时间是微秒，所以换算成cm，需要除以58
  */
  Serial.print(dist);    //在串口打印输出dist变量
  Serial.println("cm");    //在串口打印输出cm单位
  delay(1000);    //延时1秒
}
```