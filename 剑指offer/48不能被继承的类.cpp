#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Base{
		friend T;
	private:
		Base();
		~Base();
};

class Derived : virtual public Base<Derived> {
	public:
		Derived();
		~Derived();
	
};

class test:public Derived{
	 public:
	 	test();
		~test(); 
}; 

int main(){
	test tt;
	
	return 0;
}
