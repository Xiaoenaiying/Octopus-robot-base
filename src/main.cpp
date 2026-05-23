#include <Arduino.h>
#include "Four-way tracking.h"
#include <Ultrasound.h>
#include <Motor.h>

void setup()
{
  static UltraSound UltraSound_Pins;
  // 初始化超声波引脚
  pinMode(UltraSound_Pins.trigpin,OUTPUT);
  pinMode(UltraSound_Pins.echopin,INPUT);
  Motor_Init();
  // 启动串口通信波特率为9600
  Serial.begin(9600);
  Serial.println("循迹小车启动完成");
}

void loop()
{
  static Ultrasound Ultrasound;
  Motor_State Motor_RUN;
  // 将获取到的距离值存储为abc变量
  int cunchuabc = Ultrasound.huoqujuli();
  // 串口发送距离数据，格式为距离：abc cm
  Serial.print("距离：");
  Serial.print(cunchuabc);
  Serial.println("cm");

  if(cunchuabc > 0){
    if(cunchuabc == 20){
      //等于20cm：停止
      Serial.println("距离=20cm,停止");
      Motor_RUN.Motor_TINGZHI();
    }else if(cunchuabc > 20){
      //大于20cm：直行（向前追）
      Serial.println("距离>20cm,直行");
      Motor_RUN.Motor_ZHIXING();
    }else{
      //小于20cm：倒退（保持距离）
      Serial.println("距离<20cmm,倒退");
      Motor_RUN.Motor_DAOTUI();
    }
  }else{
    Serial.println("测量无效，停止");
    Motor_RUN.Motor_TINGZHI();
  }
  delay(100);
  tracing();
  delay(50);
}