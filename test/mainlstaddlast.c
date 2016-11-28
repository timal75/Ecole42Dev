#include "libft.h"

int main (void)
{
	t_list	**lst;
	t_list	**lst1;
	t_list	*next;
	t_listi	*lsti;
	t_listi	*lsti2;
	t_listi	*lsti1;
	int		y;

	lst = (t_list **)malloc(sizeof(t_list *));
	lst1 = (t_list **)malloc(sizeof(t_list *));
	*lst = NULL;
	*lst1 = NULL;

	lsti = ft_create_elemi(5);
	ft_lstadd(lst,ft_lstnew(lsti,sizeof(lsti)));
	ft_lstaddlast(lst1,ft_lstnew(lsti,sizeof(lsti)));
	lsti1 = ft_create_elemi(8);
	ft_lstadd(lst,ft_lstnew(lsti1,sizeof(lsti)));
	ft_lstaddlast(lst1,ft_lstnew(lsti1,sizeof(lsti)));
	
	lsti1 = ft_create_elemi(25);
	ft_lstadd(lst,ft_lstnew(lsti1,sizeof(lsti)));
	ft_lstaddlast(lst1,ft_lstnew(lsti1,sizeof(lsti)));

	lsti1 = ft_create_elemi(525);
	ft_lstadd(lst,ft_lstnew(lsti1,sizeof(lsti)));
	ft_lstaddlast(lst1,ft_lstnew(lsti1,sizeof(lsti)));

	while (*lst)
	{
		//y = (int)((*lst)->content).data;
		y = ((t_listi *)(*lst)->content)->data;
		ft_putnbreol(y);
		*lst = (*lst)->next;
	}
	ft_putstr("----------\n");
	while (*lst1)
	{
		//y = (int)((*lst)->content).data;
		y = ((t_listi *)(*lst1)->content)->data;
		ft_putnbreol(y);
		*lst1 = (*lst1)->next;
	}
}
