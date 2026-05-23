//
// Created by LENOVO on 2026/5/23.
//

#ifndef CAR_MOTOR_H
#define CAR_MOTOR_H
#include <arduino.h>
#include <Motor_Pin.h>

void Motor_Init();

//描述运动状态事件
enum Motor {
    ZHIXING,
    DAOTUI,
    ZUOZHUAN,
    YOUZHUAN,
    TINGZHI
};
struct Motor_State {
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

    void Event_Judgment(Motor EvEnt);
};


#endif //CAR_MOTOR_H
