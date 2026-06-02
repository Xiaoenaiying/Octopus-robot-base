//
// Created by LENOVO on 2026/5/22.
//
#include <arduino.h>
#include "Four-way tracking.h"
// 定义传感器读数变量（使用新名称）
volatile uint16_t sensorValue1 = 0; //外线读数
volatile uint16_t sensorValue2 = 0; //内线读数
volatile uint16_t sensorValue3 = 0; //内线读数
volatile uint16_t sensorValue4 = 0; //外线读数


void tracing()
{
  static Motor_State motorRun;
  // 使用新变量名读取传感器数值
  sensorValue1 = analogRead(S1);
  sensorValue2 = analogRead(S2);
  sensorValue3 = analogRead(S3);
  sensorValue4 = analogRead(S4);

  // Serial.print("外线S1:");
  Serial.print(sensorValue1);
  Serial.print(",");
  // Serial.print(" 内线S2:");
  Serial.print(sensorValue2);
  Serial.print(",");
  // Serial.print(" 内线S3:");
  Serial.print(sensorValue3);
  Serial.print(",");
  // Serial.print(" 外线S4:");
  Serial.println(sensorValue4);

  motorRun.SpeedLA1=0;
  motorRun.SpeedLB1=0;
  motorRun.SpeedHA1=0;
  motorRun.SpeedHB1=0;

  // 四路循迹判断逻辑（使用新变量名）
  // 直行（S2 S3在黑线上）
  if(sensorValue1 > 500 && sensorValue2 <= 500 && sensorValue3 <= 500 && sensorValue4 > 500){
    motorRun.SpeedLA1=170;
    motorRun.SpeedLB1=170;
    motorRun.SpeedHA1=170;
    motorRun.SpeedHB1=170;
    // Serial.println("直行");
    motorRun.Event_Judgment(ZHIXING,motorRun.SpeedLA1, motorRun.SpeedLB1, motorRun.SpeedHA1, motorRun.SpeedHB1);
  }
  // 左转（只有S2在黑线上）
  else if(sensorValue2 <= 500 && sensorValue3 > 500){
    motorRun.SpeedLA1=100;
    motorRun.SpeedLB1=150;
    motorRun.SpeedHA1=100;
    motorRun.SpeedHB1=150;
    // Serial.println("左转");
    motorRun.Event_Judgment(ZUOZHUAN,motorRun.SpeedLA1, motorRun.SpeedLB1, motorRun.SpeedHA1, motorRun.SpeedHB1);
  }
  // 右转（只有S3在黑线上）
  else if(sensorValue2 > 500 && sensorValue3 <= 500){
    motorRun.SpeedLA1=150;
    motorRun.SpeedLB1=100;
    motorRun.SpeedHA1=150;
    motorRun.SpeedHB1=100;
    // Serial.println("右转");
    motorRun.Event_Judgment(YOUZHUAN,motorRun.SpeedLA1, motorRun.SpeedLB1, motorRun.SpeedHA1, motorRun.SpeedHB1);
  }
  // 十字路口（全部在黑线上）默认直行
  else if(sensorValue1 <= 500 && sensorValue2 <= 500 && sensorValue3 <= 500 && sensorValue4 <= 500){
    motorRun.SpeedLA1=200;
    motorRun.SpeedLB1=200;
    motorRun.SpeedHA1=200;
    motorRun.SpeedHB1=200;
    // Serial.println("十字路口 - 直行");
    motorRun.Event_Judgment(ZHIXING,motorRun.SpeedLA1, motorRun.SpeedLB1, motorRun.SpeedHA1, motorRun.SpeedHB1);
  }
  // 直行（S1 S4在黑线上）
   else if(sensorValue2 > 500 && sensorValue1 <= 500 && sensorValue4 <= 500 && sensorValue3 > 500){
     motorRun.SpeedLA1=170;
     motorRun.SpeedLB1=170;
     motorRun.SpeedHA1=170;
     motorRun.SpeedHB1=170;
  //   Serial.println("直行");
    motorRun.Event_Judgment(ZHIXING,motorRun.SpeedLA1, motorRun.SpeedLB1, motorRun.SpeedHA1, motorRun.SpeedHB1);
  }
  // 左转（只有S1在黑线上）
  else if(sensorValue1 <= 500 && sensorValue4 > 500){
    motorRun.SpeedLA1=100;
    motorRun.SpeedLB1=150;
    motorRun.SpeedHA1=100;
    motorRun.SpeedHB1=150;
    // Serial.println("左转");
    motorRun.Event_Judgment(ZUOZHUAN,motorRun.SpeedLA1, motorRun.SpeedLB1, motorRun.SpeedHA1, motorRun.SpeedHB1);
  }
  // 右转（只有S4在黑线上）
  else if(sensorValue1 > 500 && sensorValue4 <= 500){
    motorRun.SpeedLA1=150;
    motorRun.SpeedLB1=100;
    motorRun.SpeedHA1=150;
    motorRun.SpeedHB1=100;
    // Serial.println("右转");
    motorRun.Event_Judgment(YOUZHUAN,motorRun.SpeedLA1, motorRun.SpeedLB1, motorRun.SpeedHA1, motorRun.SpeedHB1);
  }
  // 其他情况
  else{
    // Serial.println("停止重新寻找路线");
    motorRun.Event_Judgment(TINGZHI,motorRun.SpeedLA1, motorRun.SpeedLB1, motorRun.SpeedHA1, motorRun.SpeedHB1);
  }
}