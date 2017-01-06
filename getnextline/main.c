#include  "libft.h"
#include "get_next_line.h"

int		main (int argc, char **argv)
{
	int		ret;
	char	*line = NULL;
	//int		out;
	//int		p[2];
	int		fd;

	if (argc != 2)
		return (EXIT_FAILURE);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (EXIT_FAILURE);
	sleep(15);
	while ((ret = get_next_line(fd, &line)) > 0)
	{		
		printf("%s\n", line);
		free(line);
	}
	free(line);
	line = NULL;
	close(fd);
	//sleep(30);
	return (EXIT_SUCCESS);
}

// while ((ret = get_next_line(fd,line) == 1))
// {
// 	ft_putstr(*line);
// 	ft_putstr("|");
// }
//out = dup(1);
//pipe(p);

//fd = 1;
//dup2(p[1], fd);
//write(fd, "abc\n\n", 5);
//close(p[1]);
//dup2(out, fd);
/*
   ret = get_next_line(fd,&line);
   ft_putstr("code retour : ");
   ft_putnbreol(ret);
   ft_putnbreol(strcmp(line, "abc"));
   ft_putstr(line);
   ft_putstr("|\n");
   ret = get_next_line(fd,&line);
   ft_putstr("code retour : ");
   ft_putnbreol(ret);
   ft_putstr(line);
   ft_putstr("|\n");

   ret = get_next_line(fd,&line);
   ft_putstr("code retour : ");
   ft_putnbreol(ret);
   ft_putstr(line);
   ft_putstr("|\n");

   ret = get_next_line(fd,&line);
   ft_putstr("code retour : ");
   ft_putnbreol(ret);
   ft_putstr(line);
   ft_putstr("|\n");
   free(line);
   close(fd);
   }
   */
/*
return (1);
}*/
