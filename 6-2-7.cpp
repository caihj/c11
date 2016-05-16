#include <vector>
#include <list>

template<typename L,template< typename > class ... B >
struct Container{};


template <typename L,template <typename > class A, template<typename > class ... B>
struct Container<L,A,B ...>{
A<L> a;
Container<L,B...> b;
};


template<typename L>
struct Container<L>{};




template< typename T>
struct Vec{
	std::vector<T> l;
};

template< typename T>
struct List{
	std::list<T> l;
};

int main(){

	Container<int, Vec ,List  > a;


	a.b.a.l.push_back(232);



}


