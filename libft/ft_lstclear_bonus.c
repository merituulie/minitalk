/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:53:34 by meskelin          #+#    #+#             */
/*   Updated: 2022/11/11 18:41:33 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_clr_rec(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	ft_clr_rec(lst->next, del);
	lst->next = NULL;
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !*lst || !del)
		return ;
	ft_clr_rec(*lst, del);
	*lst = NULL;
}
