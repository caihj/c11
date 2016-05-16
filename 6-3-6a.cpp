#include <atomic>
#include <thread>
#include <string>
#include <iostream>
#include <functional>
#include <mutex>


using namespace std;


template<typename T>
struct Node{
	T *d {0};
	Node * next {0};
};

template<typename T>
class List{

private:
	atomic<size_t> _size{0};
	Node<T> * head{nullptr} ;
	Node<T> * tail{nullptr} ;
	mutex m ;
public :

	List(){

		head = new Node<T>;
		tail = new Node<T>;
		head->next = tail;

	}
	List(const List & l){

	}
	List(List && l){

	}

	void push(T & t){

		Node<T>  *  d  = new Node<T>();
		d->d = new T(std::move(t));
		Node<T> * p ;
		Node<T> * nul = 0;

		do{
			p = tail;
		}
		while(!__sync_bool_compare_and_swap(&p->next, nul , d));
		__sync_bool_compare_and_swap(&tail,p,d);

		_size++;
	}

	T * pop(){
		Node<T> * p ;
		do{
			p = head;
			if(p->next == nullptr){
				return nullptr;
			}
		}while(!__sync_bool_compare_and_swap(&head,p,p->next));

		return p->next->d;
	}

	size_t size(){
		return _size;
	}

	void loop(std::function< void (T)> f){

		Node<T> *p = head->next->next;

		while(p!=nullptr){
			f(*p->d);
			p = p->next;
		}
	}


};


void foo(List<int> *l){
	for(int i=0;i<10;i++)
		(*l).push(i);
}



int main(){

	List<int> l;

	thread t1(foo,&l);
	thread t2(foo,&l);

	t1.join();
	t2.join();

	l.loop([](int a){
		std::cout<<a<<std::endl;
	;});


}



