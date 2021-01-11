# HC-SR501人体红外传感器检测是否有人存在

使用HC-SR501人体红外传感器检测周围是否有人，并在串口输出检测结果；



## 一、简介

HC-SR501人体红外传感器，可在Arduino开发板上编程使用来检测周围是否有人存在。

测量范围：7米以内

角度范围：小于120度锥角



## 二、实验器件

 - arduino  X  1
 - HC-SR501人体红外传感器  X  1
 - USB数据烧写线  X  1
 - 杜邦线  X  3



## 三、实验连线

| HC-SR501 | Arduino |
| -------- | ------- |
| VCC      | 5V      |
| GND      | GND     |
| OUT      | 2       |



## 四、实验步骤

 1.根据连线表格以及实验电路图，将HC-SR501与Arduino开发板进行连接；
 2.将Arduino开发板与电脑通过USB烧写线进行连接
 3.使用Arduino IDE将代码验证并上传
 4.打开串口监视器，查看HC-SR501输出的检测结果	



## 五、实验代码

```
#define HCPin 2    //宏定义一个2号口引脚“MQPin”
void setup()    //setup初始化函数，只运行一次
{
  Serial.begin(9600);    //设置串口数据波特率
  pinMode(HCPin, INPUT);   //将上方定义的MQPin（2号口）的工作模式转化为输入
}
void loop()    //loop函数，循环运行
{
  if (digitalRead(HCPin) == HIGH)    //if判断语句，判断MQPin引脚(2号口)读出(digitalRead)的数据是否为高电平
  {
    Serial.println("Someone here!");    //上方if语句判断满足，在串口持续输出“Someone here!”
  }
  else{    //else,引脚读出数据不是高电平，不满足条件
    Serial.println("Nobody");    //不满足条件，在串口持续输出“Nobody”
  }
  delay(1000);    //延时1秒
}
```

