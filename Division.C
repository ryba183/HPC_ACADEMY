#include <iostream>
#include <cmath>



int main(void)
{
	unsigned int a, b;
	
	std::cout<<" Give first negative integer a= "<<std::endl;
	std::cin>>a;
	std::cout<<" Give 2nd negative integer b= "<<std::endl;
	std::cin>>b;
	std::cout<<" Check if division of negative itegers is same as (a/b)*b + a%b ==a."<<std::endl;
	std::cout<<"Standard division is equal to "<<a/b<<std::endl;
	std::cout<<"Division from equation i equal to "<<(a/b)*b + a%b<< std::endl;
	
	
	
	
	
	
	return 0;
}
