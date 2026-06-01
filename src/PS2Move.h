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
#define PS2_DAT 11
#define PS2_CMD 10
#define PS2_CS  9
#define PS2_CLK 8

// 模式配置
#define pressures false
#define rumble false

// 控制灵敏度
const int ANGLE_STEP = 2;

void PS2_Init();
void PS2_Control();

typedef enum{
    Key_idle,//按键空闲

    Triangle_button_pressed,//三角按键按下（执行超声波和四路循迹）
    Triangle_button_pressed_Delay,//三角按键按下延时
    Triangle_button_Lift,//三角按键抬起
    Triangle_button_Lift_Delay,//三角按键抬起延时

    X_type_button_pressed,//X按键按下（执行停止和清空按键）
    X_type_button_pressed_Delay,//X按键按下延时
    X_type_button_Lift,//X按键抬起
    X_type_button_Lift_Delay,//X按键抬起延时

    O_key_click,//O按键单击（执行底盘PS2控制）
    O_key_click_Delay,//O按键单击延时
    O_key_click_Lift,//O按键单击抬起
    O_key_click_Lift_Delay,//O按键单击抬起延时

    Double_click_the_O_key,//双击O按键（发送数据给STM32，进行机械臂控制）
    Double_click_the_O_key_Delay,//O按键单击延时
    Double_click_the_O_key_Lift,//O按键单击抬起
    Double_click_the_O_key_Lift_Delay,//O按键单击抬起延时
}PS2_State;

typedef enum {
    EVT_NONE,//没有事件
    EVT_PRESS,//按键按下
    EVT_RELEASE,//按键抬起
    EVT_TIMEOUT,//按键超时，消抖定时
} key_event_t;

class PS2_Move {
public:
    

private:
    uint32_t Key_Flag;
};


#endif //CAR_PS2MOVE_H
