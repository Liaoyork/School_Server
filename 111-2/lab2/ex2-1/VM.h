#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct item{
    int id;
    string name;
    int price;
};

class VM{
    private:
        vector<item> item_vec;
        string password;
        void add_item();
        void remove_item();
        void find_change(item,int,int,int,int);
        void purchase_item();
        void print_itemList();
        void print_optionList();
        string set_password();
    public:
        VM();
        ~VM();
        void start();
};
