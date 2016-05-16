#include <type_traits>
#include <iostream>
#include <typeinfo>

using namespace std;

typedef int (*FF)();

typedef FF (*FFR)();

FFR foo(){return nullptr;}

FFR foo2(){return nullptr;}

int(*(*(*pf())())()) (){
    return nullptr;
}
int pf2() {
    return 0;
}

auto pf1() -> auto (*)() -> int(*)(){
    return nullptr;
}

int main(){

	cout<<typeid(FF).name()<<endl;
	cout<<typeid(FFR).name()<<endl;
	cout<<typeid(pf).name()<<endl;
    cout<<is_same<decltype(pf), decltype(pf1) > ::value << endl;
    cout<<is_same<decltype(pf), decltype(foo) >::value << endl;

}




