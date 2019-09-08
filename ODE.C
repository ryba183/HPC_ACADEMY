#include <iostream>
#include <cmath>




double dy(double y)
{
	return sqrt(y);
}


int main(void)
{
	
	double y0, T, dt, y, t;
	std::cout<<"Imput vale of y0, maximum t value T and time step dt"<<std::endl;
	std::cout<<"Imput vale of y0= "<<std::endl;
	std::cin>>y0;
	std::cout<<"Imput vale of T= "<<std::endl;
	std::cin>>T;
	std::cout<<"Imput vale of dt= "<<std::endl;
	std::cin>>dt;
	
	y = y0;
	t == 0;
	
	while (t<T)
	{
		y = y +dt*dy(y);
		t += dt;
		std::cout<<y<<std::endl;
	}
	
	
	
	return 0;
}
