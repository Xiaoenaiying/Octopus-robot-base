//
// Created by LENOVO on 2026/5/23.
//

#ifndef CAR_MOTOR_PIN_H
#define CAR_MOTOR_PIN_H
#include <arduino.h>
// 定义前端电机驱动引脚
const uint8_t QA1 = 3;
const uint8_t QA2 = 2;
const uint8_t QB1 = 5;
const uint8_t QB2 = 4;
// 定义后端电机驱动引脚
const uint8_t HA1 = 6;
const uint8_t HA2 = 7;
const uint8_t HB1 = 11;
const uint8_t HB2 = 13;

// 定义传感器引脚
const uint8_t S1 = A0; //外线
const uint8_t S2 = A1; //内线
const uint8_t S3 = A2; //内线
const uint8_t S4 = A3; //外线
#endif //CAR_MOTOR_PIN_H
