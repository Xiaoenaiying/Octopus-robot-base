//
// Created by LENOVO on 2026/5/23.
//

#ifndef CAR_ULTRASOUND_H
#define CAR_ULTRASOUND_H
#include <arduino.h>
#include <Four-way tracking.h>
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




// 控制小车直行
void Ultrasound_ZHIXING();

// 控制小车倒退
void Ultrasound_DAOTUI();

void Ultrasound_ZUOZHUAN();

void Ultrasound_YOUZHUAN();

void Ultrasound_TINGZHI();




#endif //CAR_ULTRASOUND_H
