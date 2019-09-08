#include <iostream>
#include <cmath>
#include <complex>

int main(void)
{
	float a, b, c, x1, x2, d;
	
	std::cout<<" Giva a latters from a to c to this equation a*x^2 + b*x + c = 0"<<std::endl;
	std::cout<<" Give a = "<<std::endl;
	std::cin>>a;
	std::cout<<" Give b = "<<std::endl;
	std::cin>>b;
	std::cout<<" Give c = "<<std::endl;
	std::cin>>c;
	
	d = b*b -4*a*c;
	float sd = sqrt(d);
	float cd = sqrt(-d);
	x1 = (-b + sd)/2*a;
	x2 = (-b - sd)/2*a;
	if(a==0 && b==0 && c==0) std::cout<<"There are infinity numbers of solution"<<std::endl;
	
	else if(d == 0)
	{
		std::cout<<"there is only one solution x= "<<-b/(2*a)<<std::endl;
	}
	else if (d > 0)
	{	
	
	std::cout<<" There are 2 real solution x1 = "<<(-b + sd)/(2*a)<<" and the x2 = "<<(-b - sd)/(2*a)<<std::endl;	
	}
	else 
	{
		 std::cout<<"There real solution is"<<-b/(2*a)<<" and imaginary +i"<<cd/(2*a)<<std::endl;
		 std::cout<<"There real solution is"<<-b/(2*a)<<" and imaginary -i"<<cd/(2*a)<<std::endl;	
	}

	
	
	return 0;
}
