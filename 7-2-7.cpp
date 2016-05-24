class ConvType{
public:
	ConvType(int i){};
	explicit  ConvType(char c)= delete;
};


void Func(ConvType ct){}

int main(){
	Func(3);
	Func('a');

	ConvType ci(3);
	ConvType cc('a');
}