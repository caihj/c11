#include <cstdio>
#include <tuple>

using namespace std;


template<typename A,typename B>
struct S{};


template < template<typename ... > class T, typename ...TArgs,
template< typename ... > class U, typename ...UArgs>
struct ss :public  T <TArgs...> , U <UArgs...>  {};

int main(){

	S<int,float> p;
	S1<std::tuple,int,double, std::tuple,int,double > s;


}


