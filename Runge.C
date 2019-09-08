#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <getopt.h>



//Dane poczatkowe
double ystart = 1;
double T = 10;
double dt = 0.001;
std::string outPath = "-";



void PrintHelp()
{
	std::cout<<
		"Parameter setting:\n"
		"	-T, --maxTime:			Set maxiumum time\n"
		"	-y, --initialState:		Set initial condition\n"
		"	-d, --timeStep:			Set time step delta t\n"
		"	-o, --outfile:			File to write solution\n"
		"	-h, --help:				Show help\n";
		exit(1);
}

void Arguments(int argc, char** argv)
{
	const char* const short_opts = "T:y:d:0:h";
	const option long_opts[] = {
		{"maxTime", required_argument, nullptr, 'T'},
		{"initialState", no_argument, nullptr, 'y'},
		{"timeStep", required_argument, nullptr, 'd'},
		{"outfile", required_argument, nullptr, 'o'},
		{"help", no_argument, nullptr, 'h'},
		{nullptr, no_argument, nullptr, 0}
	};

	while (true)
	{
		const auto opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);
		
		if (-1 == opt)
			break;
			
		switch (opt)
		{ 
		case 'T':
			T = std::stoi(optarg);
			break;
			
		case 'y':
			ystart = std::stof(optarg);
			break;
			
		case 'd':
			dt = std::stof(optarg);
			break;
			
		case 'o':
			outPath = std::string(optarg);
			break;
			
		case 'h': 
		case '?':
		default:
			PrintHelp();
			break;
		}
	}
}

		
double f(double y)
{
	return sqrt(y);
}



double runge(double y0, double dt, double T, std::ostream& out = std::cout)
{
	
	double y = y0;
	double t = 0;
	double k1, k2;
	
	// Warunki poczatkowe
	
	out << t << "\t" << y0 << std::endl;
	while (t<T)
	{
		//Pozwala na obnizenie wartosci osiaganej, tak aby jej nie przekroczyc.
		if ( t + dt > T)
		{
			dt = T - t;
		}
		k1 = f(y);
		k2 = f(y+(k1*dt));
		y = y + 0.5*dt*(k1+k2);
		t += dt;
		
		out << std::setprecision(10) << t << "\t" << y <<std::endl;
	}
	return y;
}

int main(int argc, char* argv[])
{
	Arguments(argc, argv);
	std::cerr << "Max time set to: "<< T << std::endl;
	std::cerr << "Initial state set to: "<< ystart << std::endl;
	std::cerr << "Time step set to: "<< dt << std::endl;
	std::cerr << "Write file set to: "<< outPath << std::endl;
	
	std::ofstream outFile;
	
	if(outPath != "-"){
		outFile.open(outPath, std::ios::out);
	}
	std::ostream& out = (outPath != "-" ? outFile : std::cout);
	
	runge(ystart, dt, T, out);
	
	return 0;
}
