#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
using namespace std;


#define FUNC  do{printf(__FUNCTION__);printf("  called\n");}while(0);

class String{

public:
	String(){
		printf("String()\n");
		ch = new char[10];
		_size = 0;
		cap = 10;
		ch[0]='\0';
	}


	String(const char *str){
		printf("String(const char *str)\n");

		size_t len = strlen(str);
		ch = new char[len+10];
		_size=len;
		cap=len+10;
		memcpy(ch,str,len+1);

	}

	String(const String & str){
		FUNC;
		ch = new char[str.cap];
		_size = str._size;
		cap = str.cap;
		memcpy(ch,str.ch,_size+1);
	}

	String(const string &b){
		printf("String(const string &b)\n");
		ch = new char[b.size()+10];
		printf("ch is %p\n",ch);
		_size=b.size();
		cap=b.size()+10;
		memcpy(ch,b.data(),b.size()+1);
	}

	const char * c_str() const{
			return ch;
	}


	operator string (){
		printf("operator string ()\n");
		string a(ch,_size);
		return a;
	}

	~String(){
		FUNC;
		printf("free %p\n",ch);
		delete [] ch;
		ch= 0;
	}




private:
	char *ch;
	size_t _size;
	size_t cap;
};

ostream & operator << (ostream & out,String & s){
	out << s.c_str();
	return out;
}



int main(){

	//String s;


	string b="ghh";
	String c ;

	//c = b;
	c=b;
//
//	cout << a <<endl;
//	cout << b <<endl;
//
//	cout << c << endl;

	return 0;
}



