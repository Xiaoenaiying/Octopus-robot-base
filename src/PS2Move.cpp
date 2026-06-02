#include <PS2Move.h>

#include "Motor.h"

// 设置PS2X变量名为ps2x
static PS2X ps2x;
static int error = 0; // 连接状态显示

void PS2_Init() {
  // 初始化PS2控制器
  error = ps2x.config_gamepad(PS2_CLK,PS2_CMD,PS2_CS,PS2_DAT,pressures,rumble);

  if(error == 0){
    Serial.println("PS2控制器连接成功,小车准备就绪！");
  }
  delay(1000);
}

void PS2_Control()
{
  // 读取PS2手柄数据
  ps2x.read_gamepad(false, 0);

  Motor_State PS2Move;

  PS2Move.SpeedLA1=0;
  PS2Move.SpeedLB1=0;
  PS2Move.SpeedHA1=0;
  PS2Move.SpeedHB1=0;
//控制底座左右 - 左摇杆左右
if(ps2x.Analog(PSS_LX) < 50) {  // 左摇杆向左
  PS2Move.SpeedLA1=100;
  PS2Move.SpeedLB1=150;
  PS2Move.SpeedHA1=100;
  PS2Move.SpeedHB1=150;
  PS2Move.Event_Judgment(ZUOZHUAN,PS2Move.SpeedLA1,PS2Move.SpeedLB1,PS2Move.SpeedHA1,PS2Move.SpeedHB1);
}
else if(ps2x.Analog(PSS_LX) > 200) {  // 左摇杆向右
  PS2Move.SpeedLA1=150;
  PS2Move.SpeedLB1=100;
  PS2Move.SpeedHA1=150;
  PS2Move.SpeedHB1=100;
  PS2Move.Event_Judgment(YOUZHUAN,PS2Move.SpeedLA1,PS2Move.SpeedLB1,PS2Move.SpeedHA1,PS2Move.SpeedHB1);
}

// 控制底座前进和后退 - 右摇杆上下
  if(ps2x.Analog(PSS_RY) < 50) {  // 右摇杆向上
    PS2Move.SpeedLA1=150;
    PS2Move.SpeedLB1=150;
    PS2Move.SpeedHA1=100;
    PS2Move.SpeedHB1=100;
  PS2Move.Event_Judgment(ZHIXING,PS2Move.SpeedLA1,PS2Move.SpeedLB1,PS2Move.SpeedHA1,PS2Move.SpeedHB1);
}
else if(ps2x.Analog(PSS_RY) > 200) {  // 右摇杆向下
  PS2Move.SpeedLA1=100;
  PS2Move.SpeedLB1=100;
  PS2Move.SpeedHA1=150;
  PS2Move.SpeedHB1=150;
  PS2Move.Event_Judgment(DAOTUI,PS2Move.SpeedLA1,PS2Move.SpeedLB1,PS2Move.SpeedHA1,PS2Move.SpeedHB1);
}

// 按钮控制 --
if(ps2x.Button(PSB_TRIANGLE)) {  // △按钮 -超声波控制
  Ultrasound_Move();
  delay(100);
}

if(ps2x.Button(PSB_PINK)) {  // 按钮 - 四路循迹控制
  tracing();
  delay(50);
}

if(ps2x.Button(PSB_BLUE)) {  // ×按钮 - PS2控制
  PS2Move.Event_Judgment(TINGZHI,PS2Move.SpeedLA1,PS2Move.SpeedLB1,PS2Move.SpeedHA1,PS2Move.SpeedHB1);
  delay(50);
}
delay(50);

}

bool PS2_Move::button_Getstate(button_type button) {
  //三角形按键
  if (Triangle_button==button) {
    return Triangle_button;
  }
  //X型按键
  else if (X_type_button==button) {
    return X_type_button;
  }
  //Y型按键
  else if (O_type_button==button) {
    return O_type_button;
  }
  return false;
}

bool PS2_Move::button_check(button_type, key_event_t key_eve) {
   key_eve=EVT_NONE;
}

void PS2_Move::PS2_tick() {

}


