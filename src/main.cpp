#include <Arduino.h>
#include <Ultrasound.h>
#include <Motor.h>
#include <PS2Move.h>

void setup()
{
  static UltraSound UltraSound_Pins;
  // 初始化超声波引脚
  pinMode(UltraSound_Pins.trigpin,OUTPUT);
  pinMode(UltraSound_Pins.echopin,INPUT);
  Motor_Init();
  // 设置串口波特率为57600
  Serial.begin(57600);
  PS2_Init();
}

void loop()
{
  PS2_Control();
}