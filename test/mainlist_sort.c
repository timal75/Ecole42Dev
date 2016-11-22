#include "libft.h"

int croissant(int a, int b)
{
		return (a <= b);
}

int		main (void)
{
	t_listi		**lst1;
	int(*f)(int,int);

	f=croissant;
	lst1 = (t_listi **)malloc(sizeof(t_listi *));
	*lst1 = ft_lstnewi(5);
	
	ft_printlisti (*lst1);
	printf("\n");
	ft_lstpushfronti(lst1,8);
	ft_printlisti (*lst1);
	printf("\n");
	ft_lstpushbacki(lst1, 12);
	ft_lstpushbacki(lst1, 2);
	ft_lstpushbacki(lst1, 3);
	ft_lstpushbacki(lst1, -3);

	printf("size est :%d\n",ft_lstsizei(*lst1));
	ft_lstpushfronti(lst1,18);
	ft_lstpushfronti(lst1,8);
	ft_lstpushfronti(lst1,38);
	ft_printlisti (*lst1);
	*lst1 = ft_sort_listi(*lst1, f);
	printf("\n");
	ft_printlisti (*lst1);
	printf("size est :%d\n",ft_lstsizei(*lst1));
	ft_lstcleari(lst1);
	free (lst1);
	//free (lst2);
	//free (lst3);
}
