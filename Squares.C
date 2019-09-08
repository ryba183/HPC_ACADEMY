#include <iostream>
#include <cmath>
#include <fstream>


int main(void)
{
	int a;
	
	std::ofstream data;
	
	do
	{
	std::cout<<"Enter an integer, so I can proceed a list of all squars up to this integer"<<std::endl;
	std::cin>>a;
	} 
	while (a<0);
	
	data.open("data.txt");
	for (int i =0; i <=a; i++) data <<i<<"\t "<<i*i<<std::endl;
	data.close();
	
	return 0;
}
