#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>

void	print_help(void)
{
	std::cout << "./train file\n";
	std::cout << "file : file containing the data\n";
}

void	ft_fill(std::vector<double> *x, std::vector<double>  *y, std::string line)
{
	double	   num;
	char*      pEnd;

	num = strtod(line.c_str(), &pEnd);
	x->push_back(num);
	std::string line2 = line.substr(line.find(",") + 1);
	num = strtod(line2.c_str(), &pEnd);
	y->push_back(num);
}

void	ft_calculate(std::vector<double> *x, std::vector<double> *y, int size)
{
	double			    a;
	double			    b;
	double			    top;
	double			    bottom;
	double			    moy_x;
	double			    moy_y;
	std::string		  fileoutput ("Rcalculate.calc");
	int				      i;

	if ( size == 1)
	{
		a = 0;
		b = y->at(0);
	}
	else
	{
		moy_x = 0;
		moy_y = 0;
		i = 0;
		while (i < size )
		{
			moy_x = moy_x + x->at(i);
			moy_y = moy_y + y->at(i);
			i++;
		}
		moy_x = moy_x / size;
		moy_y = moy_y / size;
		i = 0;
		top = 0;
		bottom = 0;
		while ( i < size)
		{
			top = top + ((x->at(i) - moy_x) * (y->at(i) - moy_y));
			bottom = bottom + ((x->at(i) - moy_x) * (x->at(i) - moy_x));
			i++;
		}
		a = top/bottom;
		b = moy_y - a * moy_x;
	}

	std::ofstream output;
	output.open(fileoutput);
	if (!output.good())
		std::cout << "File can not created\n";
	else
	{
		output << a <<";"<< b << std::endl;
		output.close ();
	}
}

int		read_file(std::string fic, std::vector<double> *x, std::vector<double>  *y, int *size)
{
	std::ifstream 	ifs;
	int				      ret;
	std::string		  line;

	ret = 0;
	ifs.open (fic, std::ifstream::in);
	if (!ifs.good())
	{
		std::cout << "File can not be read\n" ;
		ret = 0;
	}
	else
	{
		*size = 0;
		while (getline(ifs, line))
	   	{
			  (*size)++;
			  ft_fill(x, y, line);
		}
		ifs.close();
		ret = 1;
	}
	return (ret);

}

double	estimate(double a, double b, double value)
{
	return (a*value + b);
}

void	get_max_min(std::vector<double> *x, int size, double *max, double *min)
{
	*max = x->at(0);
	*min = x->at(0);

	size = size -1;
	while (size >= 0)
	{
		if (*max < x->at(size))
			*max = x->at(size);
		if (*min > x->at(size))
			*min = x->at(size);
		size--;
	}
}

void	ft_scale(std::vector<double> *x, int size, float max, float min)
{
	size = size -1;
	while (size >= 0)
	{
		x->at(size) = (x->at(size) - min)/(max - min);
		size--;
	}
}

double	ft_error(std::vector<double> *x, std::vector<double> *y,int size,double a, double b)
{
	double	total;
	int		i;

	total =0;
	i = 0;
	while(i < size)
	{
		total += (y->at(i) - estimate(a, b, x->at(i))) * (y->at(i) - estimate(a, b, x->at(i)));
		i++;
	}
	return (total/size);
}

void	ft_calculate_step(std::vector<double> *x, std::vector<double> *y, int size)
{
	double			  a;
	double			  b;
	double			  step;
	int				    i;
	int				    iteration;
	double			  sum_a;
	double			  sum_b;
	double			  max;
	double 			  min;
	double			  error;
	double			  error1;

	std::string	ferror ("error.calc");
	std::ofstream output_error;
	output_error.open(ferror);
	if (!output_error.good())
	{
		std::cout << "File " << ferror << " can not created\n";
		return;
	}
	get_max_min(x, size, &max, &min);
	ft_scale (x, size, max, min);
	a = 0.0;
	b = 0.0;
	step = 0.03;
	error = 0;
	error1 = 0;

	iteration = 0;
	while ((std::abs(error - error1) > 0.00001) || (iteration == 0))
	{
		error1 = error;
		sum_a = 0;
		sum_b = 0;
		i = 0;
		while (i < size)
		{
			sum_b += estimate(a, b, x->at(i)) - y->at(i);
			sum_a += (estimate(a, b, x->at(i)) - y->at(i)) * x->at(i);
			i++;
		}
		b -= (step/size) * sum_b;
		a -= (step / size) * sum_a;
		error = ft_error(x,y,size,a,b);
		output_error << iteration << ";" << error << std::endl;
		iteration++;
	}
	output_error.close ();
	std::string	filename ("RcalculateStep.calc");
	std::ofstream output_calc;
	output_calc.open(filename);
	if (!output_calc.good())
	{
		std::cout << "File " << filename << " can not created\n";
		return;
	}
	else
	{
		output_calc << a << ";" << b << std::endl;
		output_calc.close();
	}

	std::string	fmax ("maxmin.calc");
	std::ofstream output_max;
	output_max.open(fmax);
	if (!output_max.good())
	{
		std::cout << "File " << fmax << " can not created\n";
		return;
	}
	else
	{
		output_max << max << ";" << min << std::endl;
		output_max.close();
	}
	std::string	fnormalize ("RcalculateStep.normalize");
	std::ofstream output_nor;
	output_nor.open(fnormalize);
	if (!output_nor.good())
	{
		std::cout << "File " << fnormalize << " can not created\n";
		return;
	}
	else
	{
		i = 0;
		while ( i < size)
		{
			output_nor << x->at(i) << ";" << y ->at(i) << std::endl;
			i++;
		}
		output_calc.close();
	}
}

int 	main (int argc, char **argv)
{
	std::vector<double>  	x;
	std::vector<double>  	y;
	int						size;
	std::string				output;

	if ((argc != 2) || (!(read_file(std::string(argv[1]), &x, &y, &size))))
	{
		print_help();
		return (-1);
	}

	ft_calculate( &x, &y, size);
	ft_calculate_step( &x, &y, size);
	output = "Rscript test.R  ";
	output = output + argv[1];
	//system("R CMD BATCH test.R");
	//system("Rscript  test.R");
	system(output.c_str());

	return (1);
}
