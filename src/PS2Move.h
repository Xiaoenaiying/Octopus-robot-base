//
// Created by LENOVO on 2026/5/28.
//

#ifndef CAR_PS2MOVE_H
#define CAR_PS2MOVE_H

#include <Motor_Pin.h>
// 加入PS2手柄库
#include<PS2X_lib.h>

#include <Ultrasound.h>

#include <Four-way tracking.h>

#include <Task.h>

// 定义PS2引脚
#define PS2_DAT 12
#define PS2_CMD 10
#define PS2_CS  9
#define PS2_CLK 8

// 模式配置
#define pressures false
#define rumble false

// 控制灵敏度
const uint8_t ANGLE_STEP = 2;

void PS2_Init();
void PS2_Control();

typedef enum {
    EVT_NONE,//没有事件
    EVT_PRESS,//按键按下
    EVT_RELEASE,//按键抬起
    EVT_TIMEOUT,//按键超时，消抖定时
} key_event_t;

enum button_type{
    Triangle_button,//三角按键（执行超声波和四路循迹）
    X_type_button,//X按键（执行停止和清空按键）
    O_type_button//O按键单击（执行底盘PS2控制）,双击执行机械臂控制
};

class PS2_Move {
public:
    void PS2_tick();
private:
    uint32_t Key_Flag;
    bool button_Getstate(button_type);//按键类型取
    bool button_check(button_type, key_event_t);//按键状态检查
    const uint8_t KEY_HOLD=0x01;
    const uint8_t KEY_DOWN=0x02;
    const uint8_t KEY_UP=0x04;
    const uint8_t KEY_SINGLE=0x08;
    const uint8_t KEY_DOUBLE=0x10;
    const uint8_t KEY_REPEAT=0x20;
};


#endif //CAR_PS2MOVE_H
