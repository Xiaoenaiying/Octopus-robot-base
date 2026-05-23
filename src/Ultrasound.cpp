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

