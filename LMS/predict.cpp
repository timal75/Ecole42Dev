#include <iostream>
#include <string>
#include <fstream>

void	print_help(void)
{
	std::cout << "./estimate <mileage>\n";
	std::cout << "mileage: mileage for which you want to obtain the estimate\n";
}

void	error_msg(void)
{
	std::cout << "Invalid Argument !\n";
}

void	out_of_range(double max, double min)
{
	std::cout << "The number you entered is out of raange !\n";
	std::cout <<" It must be between "<< min << " and " << max << std::endl;
}

bool	getparam(std::string filename, double *param1, double *param2)
{
	std::ifstream 	ifs;
	ifs.open (filename, std::ifstream::in);
	if (!ifs.good())
	{
		std::cout << "File " << filename << " can not be read\n" ;
		return (1 == 2);
	}
	else
	{
		std::string line;
		getline(ifs, line);
		char* pEnd;
	   	*param1 = strtod(line.c_str(), &pEnd);
	   	std::string line2 = line.substr(line.find(";") + 1);
		*param2 = strtod(line2.c_str(), &pEnd);
		ifs.close();
	}
	return (1 == 1);
}

void	evaluate(double a, double b, double mileage, double max, double min)
{
		double res;
		res = a *(mileage- min)/(max - min) + b;
		std::cout << "the corrponding price is : " << res << std::endl;
}

int	main(void)
{
	double	a;
	double 	b;
	double  max;
	double 	min;

	if (!(getparam("RcalculateStep.calc", &a, &b) && (getparam("maxmin.calc", &max, &min))))
	{
		return (-1);
	}
	while ( 1 == 1)
	{
		try
		{
			std::string		line;
			std::cout << " Enter a mileage or Q to quit: ";
			getline(std::cin, line);
			if (line.length() == 1 && line[0] == 'Q')
				return (1);
			else 
			{
				double	mileage;
				std::string::size_type sz;
				mileage = stod(line, &sz);
				if (sz == line.length ())
					if ( mileage <= max && mileage >= min)
						evaluate(a,b,mileage, max, min);
					else
						out_of_range(max, min);
				else
					error_msg();
			}


		}
		catch (std::invalid_argument & e)
		{	
			error_msg ();
		} 

	}
}