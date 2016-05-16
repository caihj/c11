#include <iostream>
#include <typeinfo>

using namespace std;

class White{

public:
    int a;
};


White operator "" _w(unsigned long long a){
    White w;
    w.a=a;
    return w;
}

class Black{};

int main(){

    White a = 89_w;

    Black b;
    cout<< typeid(a).name()<<endl;
    cout<< typeid(b).name()<<endl;
    cout<< typeid(b).hash_code()<<endl;

    White c;
    bool a_b_sametype=(typeid(a).hash_code()==typeid(b).hash_code());
    bool a_c_sametype=(typeid(a).hash_code()==typeid(c).hash_code());

    cout<<"same type?"<<endl;
    cout<<" A and B?"<<(int)a_b_sametype<<endl;
    cout<<" A and c?"<<a_c_sametype<<endl;

    int i=0;
    ++i = 5;
    std::cout<<i<<endl;
}
