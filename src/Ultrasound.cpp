//
// Created by LENOVO on 2026/5/23.
//

#include "Ultrasound.h"
// 超声波测距函数定义
long Ultrasound::huoqujuli() {
    static UltraSound UltraSound_Pins;
    // 发送触发信号
    digitalWrite(UltraSound_Pins.trigpin,LOW);
    delayMicroseconds(2);
    digitalWrite(UltraSound_Pins.trigpin,HIGH);
    delayMicroseconds(10);
    digitalWrite(UltraSound_Pins.trigpin,LOW);

    // 检测回声时间（核心函数）
    long shuzhiabc = pulseIn(UltraSound_Pins.echopin,HIGH);

    // 计算距离
    long cunchuabc = shuzhiabc*0.034/2;
    return cunchuabc;
}

void Ultrasound_Move() {
    static Ultrasound Ultrasound;
    Motor_State Motor_RUN;
    // 将获取到的距离值存储为abc变量
    int cunchuabc = Ultrasound.huoqujuli();
    // 串口发送距离数据，格式为距离：abc cm
    // Serial.print("距离：");
    // Serial.print(cunchuabc);
    // Serial.println("cm");

    if(cunchuabc > 0){
        if(cunchuabc == 20){
            //等于20cm：停止
            // Serial.println("距离=20cm,停止");
            Motor_RUN.Event_Judgment(TINGZHI);
        }else if(cunchuabc > 20){
            //大于20cm：直行（向前追）
            // Serial.println("距离>20cm,直行");
            Motor_RUN.Event_Judgment(ZHIXING);
        }else{
            // //小于20cm：倒退（保持距离）
            // Serial.println("距离<20cmm,倒退");
            Motor_RUN.Event_Judgment(DAOTUI);
        }
    }else{
        // Serial.println("测量无效，停止");
        Motor_RUN.Event_Judgment(TINGZHI);
    }
}

