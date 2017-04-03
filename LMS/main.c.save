#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>

#include "libft.h"

void	print_help(void)
{
	write(1,"./llmsq file\n",13);
	write(1,"file : file containing the data\n",32);
}

void	ft_fill(float **x, float **y, int size, char *line)
{
	float	num;
	float	num2;
	float  *tmp;
	float  *tmp2;
	int		i;
	
	num = atof(line);
	while (*line != ',')
		line++;
	line++;
	num2 = atof(line);
	tmp = *x;
	tmp2 = *y;
	if (!(*x = (float *)malloc(sizeof(float) *(size))))
		return ;
	if (!(*y = (float *)malloc(sizeof(float) *(size))))
		return ;
	i = 0;
	while (i < (size-1))
	{
		(*x)[i] = tmp[i];
		(*y)[i] = tmp2[i];
		i++;
	}
	(*x)[size-1] = num;
	(*y)[size-1] = num2;
	if (tmp)
		free(tmp);
	if (tmp2)
		free(tmp2);

}

int		read_file(char *file, float **x, float **y, int *size)
{
	int		fc;
	int		ret;
	char	*line;
	int		tr;

	ret = 0;
	fc = open(file, O_RDONLY);
	if (fc == -1)
	{
		write(1, "File can not be read\n", 21);
		ret = 0;
	}
	else
	{
		*size = 0;
		while ((ret = get_next_line(fc, &line)) > 0)
	   	{
			  (*size)++;
			  ft_fill(x, y, *size, line);
		      free(line);
		}
		free(line);
		line = NULL;
		close(fc);
		ret = 1;
	}
	return (ret);

}

void	ft_calculate(float **x, float **y, int size)
{
	float		a;
	float		b;
	float		top;
	float		bottom;
	float		moy_x;
	float		moy_y;
	char		filename[25];
	int			i;
	char 		*buffer;
	int 		fc;

	buffer = ft_strnew(64);
	ft_strcpy(filename,"Rcalculate.calc");
	if ( size == 1)
	{
		a = 0;
		b = (*y)[0];
	}
	else
	{
		moy_x = 0;
		moy_y = 0;
		i = 0;
		while (i < size )
		{
			moy_x = moy_x + (*x)[i];
			moy_y = moy_y + (*y)[i];
			i++;
		}
		moy_x = moy_x / size;
		moy_y = moy_y / size;
		i = 0;
		top = 0;
		bottom = 0;
		while ( i < size)
		{
			top = top + (((*x)[i] - moy_x) * ((*y)[i] - moy_y));
			bottom = bottom + (((*x)[i] - moy_x) * ((*x)[i] - moy_x));
			i++;
		}
		a = top/bottom;
		b = moy_y - a * moy_x;
	}
	fc = open(filename, O_CREAT | O_WRONLY, 0666 );
	if (fc < 0)
		write(1, "File can not created\n", 21);
	else
	{
		snprintf(buffer, sizeof(buffer), "%f", a);
		write(fc,buffer,ft_strlen(buffer));
		write(fc,";",1);
		ft_bzero(buffer, 64);
		snprintf(buffer, sizeof(buffer), "%f", b);
		write(fc,buffer,ft_strlen(buffer));
		write(fc,"\n",1);
		close(fc);
		free(buffer);
	}

}

float	estimate(float a, float b, float value)
{
	return (a*value + b);
}

void	get_max_min(float **x, int size, float *max, float *min)
{
	*max = (*x)[0];
	*min = (*x)[0];

	size = size -1;
	while (size >= 0)
	{
		if (*max < (*x)[size])
			*max = (*x)[size];
		if (*min > (*x)[size])
			*min = (*x)[size];
		size--;
	}
}

void	ft_scale(float **x, int size, float max, float min)
{
	size = size -1;
	while (size >= 0)
	{
		(*x)[size] = ((*x)[size] - min)/(max - min);
		size--;
	}
}

float	ft_error(float **x, float **y,int size,float a, float b)
{
	float	total;
	int		i;

	total =0;
	i = 0;
	while(i < size)
	{
		total += ((*y)[i] - estimate(a, b, (*x)[i])) * ((*y)[i] - estimate(a, b, (*x)[i]));
		i++;
	}
	return (total/size);
}

void	ft_calculate_step(float **x, float **y, int size)
{
	float	a;
	float	b;
	float	step;
	int		i;
	int		fcmax;
	int		fcerr;
	int		fcstep;
	int		iteration;
	char	ferror[25];
	char	fmax[25];
	char	filename[25];
	char 	*buffer;
	float	sum_a;
	float	sum_b;
	float	max;
	float 	min;
	float	error;
	float	error1;

	ft_strcpy(ferror,"error.calc");
	ft_strcpy(fmax,"maxmin.calc");
	ft_strcpy(filename,"RcalculateStep.calc");
	buffer = ft_strnew(64);
	fcerr = open(ferror, O_CREAT | O_WRONLY, 0666 );
	if (fcerr < 0)
		write(1, "File can not created\n", 21);
	get_max_min(x, size, &max, &min);
	ft_scale (x, size, max, min);
	a = 0.0;
	b = 0.0;
	step = 0.3;
	error = 0;
	error1 = 0;

	iteration = 0;
	while ((fabs(error - error1) > 0.001) || (iteration == 0))
	{
		error1 = error;
		sum_a = 0;
		sum_b = 0;
		i = 0;
		while (i < size)
		{
			sum_b += estimate(a, b, (*x)[i]) - (*y)[i] ;
			sum_a += (estimate(a, b, (*x)[i]) - (*y)[i]) * (*x)[i];
	//printf("sum a : %f\n", sum_a);
	//printf("sum bb : %f\n", sum_b);
			i++;
		}
		b -= (step/size) * sum_b;
		a -= (step / size) * sum_a;
		error = ft_error(x,y,size,a,b);
		ft_bzero(buffer, 64);
		snprintf(buffer, sizeof(buffer), "%d", iteration);
		write(fcerr,buffer,ft_strlen(buffer));
		write(fcerr,";",1);
		ft_bzero(buffer, 64);
		snprintf(buffer, sizeof(buffer), "%f", error);
		write(fcerr,buffer,ft_strlen(buffer));
		write(fcerr,"\n",1);
		//printf("iter %d error %f\n", iteration, error);
	//printf("sum a : %f\n", sum_a);
	//printf("sum bb : %f\n", sum_b);
	//printf("a : %f\n", a);
	//printf("b : %f\n", b);
		iteration++;
	}
	fcstep = open(filename, O_CREAT | O_WRONLY, 0666 );
	if (fcstep < 0)
		write(1, "File can not created\n", 21);
	else
	{
		ft_bzero(buffer, 64);
		snprintf(buffer, sizeof(buffer), "%f", a);
		write(fcstep,buffer,ft_strlen(buffer));
		write(fcstep,";",1);
		ft_bzero(buffer, 64);
		snprintf(buffer, sizeof(buffer), "%f", b);
		write(fcstep,buffer,ft_strlen(buffer));
		write(fcstep,"\n",1);
		close(fcstep);
	//	free(buffer);
	}
	fcmax = open(fmax, O_CREAT | O_WRONLY, 0666 );
	if (fcmax < 0)
		write(1, "File can not created\n", 21);
	else
	{
		ft_bzero(buffer, 64);
		snprintf(buffer, sizeof(buffer), "%f", max);
		write(fcmax,buffer,ft_strlen(buffer));
		write(fcmax,";",1);
		ft_bzero(buffer, 64);
		snprintf(buffer, sizeof(buffer), "%f", min);
		write(fcmax,buffer,ft_strlen(buffer));
		write(fcmax,"\n",1);
		close(fcmax);
		free(buffer);
	}
	close(fcerr);
}
int 	main (int argc, char **argv)
{
	float		**x;
	float		**y;
	int			size;
	char		*output;

	if (!(x = (float **)malloc(sizeof(float *))))
		return (-1);
	*x = NULL;
	if (!(y = (float **)malloc(sizeof(float *))))
		return (-1);
	*y = NULL;
	if ((argc != 2) || (!(read_file(argv[1], x, y, &size))))
	{
		print_help();
		return (-1);
	}
	output = ft_strnew(ft_strlen(argv[1]) + 20);
	ft_calculate( x, y, size);
	ft_calculate_step( x, y, size);
	ft_strcpy(output,"Rscript test.R  ");
	ft_strcat(output, argv[1]);
	//system("R CMD BATCH test.R");
	//system("Rscript  test.R");
	system(output);
	free(*x);
	free(x);
	free(*y);
	free(y);
	free(output);
	return (1);
}
