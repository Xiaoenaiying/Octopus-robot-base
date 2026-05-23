//
// Created by LENOVO on 2026/5/22.
//
#include <arduino.h>
#include "Four-way tracking.h"
// 定义传感器读数变量（使用新名称）
int sensorValue1 = 0; //外线读数
int sensorValue2 = 0; //内线读数
int sensorValue3 = 0; //内线读数
int sensorValue4 = 0; //外线读数



void tracing()
{
  static Motor_State motorRun;
  // 使用新变量名读取传感器数值
  sensorValue1 = analogRead(S1);
  sensorValue2 = analogRead(S2);
  sensorValue3 = analogRead(S3);
  sensorValue4 = analogRead(S4);

  Serial.print("外线S1:");
  Serial.print(sensorValue1);
  Serial.print(" 内线S2:");
  Serial.print(sensorValue2);
  Serial.print(" 内线S3:");
  Serial.print(sensorValue3);
  Serial.print(" 外线S4:");
  Serial.println(sensorValue4);

  // 四路循迹判断逻辑（使用新变量名）
  // 直行（S2 S3在黑线上）
  if(sensorValue1 > 500 && sensorValue2 <= 500 && sensorValue3 <= 500 && sensorValue4 > 500){
    Serial.println("直行");
    motorRun.Motor_ZHIXING();
  }
  // 左转（只有S2在黑线上）
  else if(sensorValue2 <= 500 && sensorValue3 > 500){
    Serial.println("左转");
    motorRun.Motor_ZUOZHUAN();
  }
  // 右转（只有S3在黑线上）
  else if(sensorValue2 > 500 && sensorValue3 <= 500){
    Serial.println("右转");
    motorRun.Motor_YOUZHUAN();
  }
  // 十字路口（全部在黑线上）默认直行
  else if(sensorValue1 <= 500 && sensorValue2 <= 500 && sensorValue3 <= 500 && sensorValue4 <= 500){
    Serial.println("十字路口 - 直行");
    motorRun.Motor_ZHIXING();
  }
  // 直行（S1 S4在黑线上）
  else if(sensorValue2 > 500 && sensorValue1 <= 500 && sensorValue4 <= 500 && sensorValue3 > 500){
    Serial.println("直行");
    motorRun.Motor_ZHIXING();
  }
  // 左转（只有S1在黑线上）
  else if(sensorValue1 <= 500 && sensorValue4 > 500){
    Serial.println("左转");
    motorRun.Motor_ZUOZHUAN();
  }
  // 右转（只有S4在黑线上）
  else if(sensorValue1 > 500 && sensorValue4 <= 500){
    Serial.println("右转");
    motorRun.Motor_YOUZHUAN();
  }
  // 其他情况
  else{
    Serial.println("停止重新寻找路线");
    motorRun.Motor_TINGZHI();
  }
}