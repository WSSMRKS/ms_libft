/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_first.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:48:35 by kwurster          #+#    #+#             */
/*   Updated: 2023/12/27 19:46:08 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstdel_first(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!*lst)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	ft_lstdelone(tmp, del);
}
