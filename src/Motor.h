//
// Created by LENOVO on 2026/5/23.
//

#ifndef CAR_MOTOR_H
#define CAR_MOTOR_H
#include <arduino.h>
#include <Motor_Pin.h>


//描述运动状态事件
enum Motor {
    ZHIXING,
    DAOTUI,
    ZUOZHUAN,
    YOUZHUAN,
    TINGZHI
};
class Motor_State {
public:
    void Event_Judgment(Motor EvEnt,uint8_t &SpeedLA1,uint8_t &SpeedLB1,uint8_t &SpeedHA1,uint8_t &SpeedHB1);
private:
    // 控制小车直行
    void Motor_ZHIXING();
    // 控制小车倒退
    void Motor_DAOTUI();
    // 控制小车左转
    void Motor_ZUOZHUAN();
    // 控制小车右转
    void Motor_YOUZHUAN();
    // 控制小车停止
    void Motor_TINGZHI();
public:
    Motor EvEnt;
    uint8_t SpeedLA1;
    uint8_t SpeedHA1;
    uint8_t SpeedLB1;
    uint8_t SpeedHB1;
};
void Motor_Init();
#endif //CAR_MOTOR_H
