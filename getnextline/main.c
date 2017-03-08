#include  "libft.h"
#include "get_next_line.h"

int		main (int argc, char **argv)
{
	int		ret;
	char	*line = NULL;
	//int		out;
	//int		p[2];
	int		fd;
   int      fd2;
   int      fd3;

// 	if (argc != 2)
// 		return (EXIT_FAILURE);
// 	if ((fd = open(argv[1], O_RDONLY)) == -1)
// 		return (EXIT_FAILURE);
// 	sleep(15);
// 	while ((ret = get_next_line(fd, &line)) > 0)
// 	{		
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	free(line);
// 	line = NULL;
// 	close(fd);
// 	//sleep(30);
// 	return (EXIT_SUCCESS);
// }

if ((fd = open(argv[1], O_RDONLY)) == -1)
       return (EXIT_FAILURE);
if ((fd2 = open(argv[2], O_RDONLY)) == -1)
       return (EXIT_FAILURE);
if ((fd3 = open(argv[3], O_RDONLY)) == -1)
       return (EXIT_FAILURE);

ret = get_next_line(fd, &line);
printf("%s %d\n", line, ret);
ret = get_next_line(fd2, &line);
printf("%s\n", line);
ret = get_next_line(fd2, &line);
ret = get_next_line(fd3, &line);
printf("%s\n", line);

while ((ret = get_next_line(fd, &line)) > 0)
   {     
      printf("%s\n", line);
      free(line);
   }
   free(line);
   line = NULL;
   close(fd);

while ((ret = get_next_line(fd3, &line)) > 0)
   {     
      printf("%s\n", line);
      free(line);
   }
   free(line);
   line = NULL;
   close(fd2);

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
