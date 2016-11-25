#include "libft.h"

int croissant(int a, int b)
{
		return (a <= b);
}

int		main (void)
{
	t_lists		**lst1;
	int(*f)(char *,char *);
	char		*s;

	f=ft_strcmp;
	lst1 = (t_lists **)malloc(sizeof(t_lists *));
	*lst1 = ft_lstnews("toto est grand\0");
	

	 ft_printlists (*lst1);
	 printf("\n");
	 ft_lstpushfronts(lst1,"toto n'est plus grand\0");
	 ft_printlists (*lst1);
	 printf("\n");
	 ft_lstpushbacks(lst1, "12\0");
	 ft_lstpushbacks(lst1, "ici c'est 42\0");
	 ft_lstpushbacks(lst1, "mieux faire les choses\0");
	 ft_lstpushbacks(lst1, "aaaaaaa\0");
	
	 ft_printlists (*lst1);
	 printf("\n");
	 s=ft_lstvaluens(*lst1,12);
	 printf("12eme element %s\n",s);
	 printf("size est :%d\n",ft_lstsizes(*lst1));
	 ft_lstpushfronts(lst1,"zzzzzz\0");
	 ft_lstpushfronts(lst1,"ZZZZZ\0");
	 ft_lstpushfronts(lst1,"yuyuioi\0");
	 ft_printlists (*lst1);
	 *lst1 = ft_sort_lists(*lst1, f);
	 printf("\n");
	 ft_printlists (*lst1);
	 printf("position zzzz :%d\n",ft_lstvaluefounds(*lst1, "ZZZZZ\0"));
	 printf("size est :%d\n",ft_lstsizes(*lst1));
	 ft_lstclears(lst1);
	free (lst1);
	//free (lst2);
	//free (lst3);
}
