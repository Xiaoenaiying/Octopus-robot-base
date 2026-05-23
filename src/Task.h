//
// Created by LENOVO on 2026/5/22.
//

#ifndef CAR_TASK_H
#define CAR_TASK_H
#include <arduino.h>
#include <stdint.h>
class Tasktimer {
public:
        Tasktimer():lasttime(0),currenttime(0){}
        Tasktimer(uint32_t interval):lasttime(0),currenttime(interval){}
        void setCurrenttime(uint32_t setCurrentimevalue) {
            currenttime=setCurrentimevalue;
        }
        bool ReadTask(void) {
            uint32_t nowtime=millis();
            if (nowtime - lasttime >= currenttime) {
                lasttime=nowtime;
                return true;
            }
            else {
                return false;
            }
        }

private:
     uint32_t lasttime;//上一次执行时间
     uint32_t currenttime;//间隔时间
};

#endif //CAR_TASK_H