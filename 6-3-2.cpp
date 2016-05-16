#include <atomic>
#include <thread>
#include <iostream>

using namespace std;

atomic_llong total{0};



void func(){
	long long i;
	for(i=0;i<100000000LL;i++){
		total +=i;
	}
}

int main(){


	thread t1(func);
	thread t2(func);

	t1.join();
	t2.join();

	cout<< total << endl;
	return 0;
}
