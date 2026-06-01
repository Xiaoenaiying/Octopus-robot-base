//
// Created by LENOVO on 2026/5/23.
//

#ifndef CAR_ULTRASOUND_H
#define CAR_ULTRASOUND_H
#include <arduino.h>
#include <Motor.h>

struct UltraSound{
    // 超声波引脚
    const int trigpin = A4;
    const int echopin = A5;
};

class Ultrasound
{
public:
    long huoqujuli();



private:
    // 设置超声波测距阀值
    int jiancejuli = 20;

};

void Ultrasound_Move();

#endif //CAR_ULTRASOUND_H
