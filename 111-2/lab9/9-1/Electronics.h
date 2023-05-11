#ifndef ELECTRONICS_H_
#define ELECTRONICS_H_
using namespace std;
class Electronics{
   private:
    int length;
    int width;
    bool usage;
    bool charging;
   public:
    Electronics(int length, int width);
    bool get_usage();
    virtual void set_usage(bool flag);
    bool get_charging();
    virtual void set_charging(bool flag);
    virtual void charge();
    virtual void poweron();
    virtual void poweroff();
    int getLen();
    int getWid();
    virtual void run();
};
#endif //ELECTRONICS_H_
