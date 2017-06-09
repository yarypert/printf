#include "ft_printf.h"

void	check_lst(t_lst *lst)
{
	while (lst)
	{
		// if (!lst->flag)
		// {
			ft_putstr(L_ROUGE);
			ft_putstr(lst->str);
			ft_putendl(FIN);
		// }
		if (lst->next != NULL)
			lst = lst->next;
		else
			break ;
	}
	// while (lst)
	// {
	// 	ft_putstr(L_VERT);
	// 	ft_putstr(lst->str);
	// 	ft_putendl(FIN);
	// 	if (lst->prev != NULL)
	// 		lst = lst->prev;
	// 	else
	// 		break ;
	// }
}
