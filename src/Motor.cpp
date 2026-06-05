//
// Created by LENOVO on 2026/5/23.
//

#include "Motor.h"


/*
 *电机初始化
 */
void Motor_Init() {
    // 初始化前端电机
    pinMode(QA1,OUTPUT);
    pinMode(QA2,OUTPUT);
    pinMode(QB1,OUTPUT);
    pinMode(QB2,OUTPUT);
    // 初始化后端电机
    pinMode(HA1,OUTPUT);
    pinMode(HA2,OUTPUT);
    pinMode(HB1,OUTPUT);
    pinMode(HB2,OUTPUT);
}

    // 控制小车直行
    void Motor_State::Motor_ZHIXING(){
        // 前端电机
        analogWrite(QA1,SpeedLA1);
        digitalWrite(QA2,LOW);
        analogWrite(QB1,SpeedLB1);
        digitalWrite(QB2,LOW);
        // 后端电机
        analogWrite(HA1,SpeedHA1);
        digitalWrite(HA2,LOW);
        analogWrite(HB1,SpeedHB1);
        digitalWrite(HB2,LOW);
    }
    // 控制小车倒退
    void Motor_State::Motor_DAOTUI(){
        // 前端电机
        analogWrite(QA1,SpeedLA1);
        digitalWrite(QA2,HIGH);
        analogWrite(QB1,SpeedLB1);
        digitalWrite(QB2,HIGH);
        // 后端电机
        analogWrite(HA1,SpeedHA1);
        digitalWrite(HA2,HIGH);
        analogWrite(HB1,SpeedHB1);
        digitalWrite(HB2,HIGH);
    }
    // 控制小车左转
    void Motor_State::Motor_ZUOZHUAN(){
        // 前端电机
        analogWrite(QA1,SpeedLA1);
        digitalWrite(QA2,HIGH);
        analogWrite(QB1,SpeedLB1);
        digitalWrite(QB2,LOW);
        // 后端电机
        analogWrite(HA1,SpeedHA1);
        digitalWrite(HA2,HIGH);
        analogWrite(HB1,SpeedHB1);
        digitalWrite(HB2,LOW);
    }
    // 控制小车右转
    void Motor_State::Motor_YOUZHUAN(){
        // 前端电机
        analogWrite(QA1,SpeedLA1);
        digitalWrite(QA2,LOW);
        analogWrite(QB1,SpeedLB1);
        digitalWrite(QB2,HIGH);
        // 后端电机
        analogWrite(HA1,SpeedHA1);
        digitalWrite(HA2,LOW);
        analogWrite(HB1,SpeedHB1);
        digitalWrite(HB2,HIGH);
    }
    // 控制小车停止
    void Motor_State::Motor_TINGZHI(){
        // 前端电机
        digitalWrite(QA1,LOW);
        digitalWrite(QA2,LOW);
        digitalWrite(QB1,LOW);
        digitalWrite(QB2,LOW);
        // 后端电机
        digitalWrite(HA1,LOW);
        digitalWrite(HA2,LOW);
        digitalWrite(HB1,LOW);
        digitalWrite(HB2,LOW);
    }

void Motor_State::Event_Judgment(Motor EvEnt,uint8_t &SpeedLA1,uint8_t &SpeedLB1,uint8_t &SpeedHA1,uint8_t &SpeedHB1){
     {
         this->SpeedLA1 = SpeedLA1;
         this->SpeedLB1 = SpeedLB1;
         this->SpeedHA1 = SpeedHA1;
         this->SpeedHB1 = SpeedHB1;
         this->EvEnt=EvEnt;
        // 保持原有代码不变
        switch(EvEnt){
            case ZHIXING:
                Motor_ZHIXING();
                break;

            case DAOTUI:
                Motor_DAOTUI();
                break;

            case ZUOZHUAN:
                Motor_ZUOZHUAN();
                break;

            case YOUZHUAN:
                Motor_YOUZHUAN();
                break;

            default:
                Motor_TINGZHI();
                break;
        }
    }

}

