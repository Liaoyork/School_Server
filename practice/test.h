#include <iostream>
#include <string>

using namespace std;

class airticket{
    private:
        double price;
        string name;
    public:
        airticket(string, double);
        ~airticket();
        void resetName();
        void resetPrice();
        void takeprice();
};
