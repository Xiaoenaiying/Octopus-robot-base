#include <PS2Move.h>

#include "Motor.h"

// 设置PS2X变量名为ps2x
static PS2X ps2x;
static int error = 0; // 连接状态显示

void PS2_Init() {
  // 初始化PS2控制器
  error = ps2x.config_gamepad(PS2_CLK,PS2_CMD,PS2_CS,PS2_DAT,pressures,rumble);

  if(error == 0) {
    Serial.println("PS2连接成功!");
    ps2x.enablePressures();
  }
}

void PS2_Control()
{
  // 非阻塞帧率控制：每50ms执行一次
  static uint32_t lastFrame = 0;
  uint32_t now = millis();
  if (now - lastFrame < 50) return;
  lastFrame = now;

  ps2x.read_gamepad(false, 0);

  Motor_State PS2Move;
  PS2Move.SpeedLA1=0;
  PS2Move.SpeedLB1=0;
  PS2Move.SpeedHA1=0;
  PS2Move.SpeedHB1=0;
  PS2Move.Event_Judgment(TINGZHI, PS2Move.SpeedLA1, PS2Move.SpeedLB1, PS2Move.SpeedHA1, PS2Move.SpeedHB1);

  PS2_Move PS2_move;

  // // 读取摇杆数据（时分复用）
  // uint8_t stick_X = ps2x.Analog(3);
  // uint8_t stick_Y = ps2x.Analog(4);
  //
  // // 判断是左摇杆还是右摇杆
  // // 当X=255时，是右摇杆；当Y=255时，是左摇杆
  // if(stick_X == 255) {
  //   // 右摇杆
  //   PS2_move.Joystick_Getforce.LX_X = 127;
  //   PS2_move.Joystick_Getforce.LX_Y = 127;
  //   PS2_move.Joystick_Getforce.RX_X = 127;
  //   PS2_move.Joystick_Getforce.RX_Y = stick_Y;
  // }
  // else if(stick_Y == 255) {
  //   // 左摇杆
  //   PS2_move.Joystick_Getforce.LX_X = stick_X;
  //   PS2_move.Joystick_Getforce.LX_Y = 127;
  //   PS2_move.Joystick_Getforce.RX_X = 127;
  //   PS2_move.Joystick_Getforce.RX_Y = 127;
  // }
  // else {
  //   // 两个摇杆都有数据（罕见）
  //   PS2_move.Joystick_Getforce.LX_X = stick_X;
  //   PS2_move.Joystick_Getforce.LX_Y = stick_Y;
  //   PS2_move.Joystick_Getforce.RX_X = 127;
  //   PS2_move.Joystick_Getforce.RX_Y = 127;
  // }
  //
  // // 计算左摇杆力度
  // int LX_norm = PS2_move.Joystick_Getforce.LX_X - 127;
  // int LY_norm = PS2_move.Joystick_Getforce.LX_Y - 127;
  //
  // const int DEADZONE = 10;
  // if(abs(LX_norm) < DEADZONE) LX_norm = 0;
  // if(abs(LY_norm) < DEADZONE) LY_norm = 0;
  //
  // uint16_t L_magnitude_sq = (uint16_t)LX_norm * LX_norm + (uint16_t)LY_norm * LY_norm;
  // uint8_t L_magnitude = min(100, (uint8_t)(sqrt(L_magnitude_sq) / 1.8));
  //
  // // 计算右摇杆力度
  // int RX_norm = PS2_move.Joystick_Getforce.RX_X - 127;
  // int RY_norm = PS2_move.Joystick_Getforce.RX_Y - 127;
  //
  // if(abs(RX_norm) < DEADZONE) RX_norm = 0;
  // if(abs(RY_norm) < DEADZONE) RY_norm = 0;
  //
  // uint16_t R_magnitude_sq = (uint16_t)RX_norm * RX_norm + (uint16_t)RY_norm * RY_norm;
  // uint8_t R_magnitude = min(100, (uint8_t)(sqrt(R_magnitude_sq) / 1.8));
  //
  // // 串口输出
  // Serial.print("L:");
  // Serial.print(PS2_move.Joystick_Getforce.LX_X);
  // Serial.print(",");
  // Serial.print(PS2_move.Joystick_Getforce.LX_Y);
  // Serial.print("|");
  // Serial.print(L_magnitude);
  // Serial.print("% R:");
  // Serial.print(PS2_move.Joystick_Getforce.RX_X);
  // Serial.print(",");
  // Serial.print(PS2_move.Joystick_Getforce.RX_Y);
  // Serial.print("|");
  // Serial.print(R_magnitude);
  // Serial.println("%");
  //
  // delay(50);


  PS2_move.Joystick_Getforce={0};
  PS2_move.Joystick_Getforce.LX_X=ps2x.Analog(PSS_LX);
  Serial.print(PS2_move.Joystick_Getforce.LX_X);
  Serial.print(",");
  PS2_move.Joystick_Getforce.LX_Y=ps2x.Analog(PSS_LY);
  Serial.print(PS2_move.Joystick_Getforce.LX_Y);
  Serial.print(",");
  PS2_move.Joystick_Getforce.RX_X=ps2x.Analog(PSS_RX);
  Serial.print(PS2_move.Joystick_Getforce.RX_X);
  Serial.print(",");
  PS2_move.Joystick_Getforce.RX_Y=ps2x.Analog(PSS_RY);
  Serial.println(PS2_move.Joystick_Getforce.RX_Y);

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
      // Ultrasound_Move();
    }

    if(ps2x.Button(PSB_PINK)) {  // 按钮 - 四路循迹控制
      // tracing();
    }

    if(ps2x.Button(PSB_BLUE)) {  // ×按钮 - PS2控制
      PS2Move.Event_Judgment(TINGZHI,PS2Move.SpeedLA1,PS2Move.SpeedLB1,PS2Move.SpeedHA1,PS2Move.SpeedHB1);
    }
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

// //控制底座左右 - 左摇杆左右
// if(ps2x.Analog(PSS_LX) < 50) {  // 左摇杆向左
//
//   PS2Move.SpeedLA1=100;
//   PS2Move.SpeedLB1=150;
//   PS2Move.SpeedHA1=100;
//   PS2Move.SpeedHB1=150;
//   PS2Move.Event_Judgment(ZUOZHUAN,PS2Move.SpeedLA1,PS2Move.SpeedLB1,PS2Move.SpeedHA1,PS2Move.SpeedHB1);
// }
// else if(ps2x.Analog(PSS_LX) > 200) {  // 左摇杆向右
//   PS2Move.SpeedLA1=150;
//   PS2Move.SpeedLB1=100;
//   PS2Move.SpeedHA1=150;
//   PS2Move.SpeedHB1=100;
//   PS2Move.Event_Judgment(YOUZHUAN,PS2Move.SpeedLA1,PS2Move.SpeedLB1,PS2Move.SpeedHA1,PS2Move.SpeedHB1);
// }
//
// // 控制底座前进和后退 - 右摇杆上下
//   if(ps2x.Analog(PSS_RY) < 50) {  // 右摇杆向上
//     PS2Move.SpeedLA1=150;
//     PS2Move.SpeedLB1=150;
//     PS2Move.SpeedHA1=100;
//     PS2Move.SpeedHB1=100;
//   PS2Move.Event_Judgment(ZHIXING,PS2Move.SpeedLA1,PS2Move.SpeedLB1,PS2Move.SpeedHA1,PS2Move.SpeedHB1);
// }
// else if(ps2x.Analog(PSS_RY) > 200) {  // 右摇杆向下
//   PS2Move.SpeedLA1=100;
//   PS2Move.SpeedLB1=100;
//   PS2Move.SpeedHA1=150;
//   PS2Move.SpeedHB1=150;
//   PS2Move.Event_Judgment(DAOTUI,PS2Move.SpeedLA1,PS2Move.SpeedLB1,PS2Move.SpeedHA1,PS2Move.SpeedHB1);
// }
//
// // 按钮控制 --
// if(ps2x.Button(PSB_TRIANGLE)) {  // △按钮 -超声波控制
//   Ultrasound_Move();
//   delay(100);
// }
//
// if(ps2x.Button(PSB_PINK)) {  // 按钮 - 四路循迹控制
//   tracing();
//   delay(50);
// }
//
// if(ps2x.Button(PSB_BLUE)) {  // ×按钮 - PS2控制
//   PS2Move.Event_Judgment(TINGZHI,PS2Move.SpeedLA1,PS2Move.SpeedLB1,PS2Move.SpeedHA1,PS2Move.SpeedHB1);
//   delay(50);
// }
// delay(50);
