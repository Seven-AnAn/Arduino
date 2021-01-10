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
