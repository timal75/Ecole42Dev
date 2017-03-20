
void    print_help(void)
{
	write(1,"./predict <number>\n",19);
	write(1,"number : number you wish to predict result\n",43);
}

int 	main (int argc, char **argv)
{
	int		fstep;
	int		fc;
	char	file[50];
	char	filestep[50];

	if (argc != 2)
		print_help ();
	else
	{
		ft_strcpy(file,"Rcalculate.calc");
		ft_strcpy(filestep,"max.calc");
		fc= open(file, O_RDONLY);
	}
}
