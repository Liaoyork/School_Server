#include "Electronics.h"
#ifndef _TV_H_
#define _TV_H_


class TV : public Electronics{
    public:
        TV(int,int);
        void run();
        void charge();
};










#endif
