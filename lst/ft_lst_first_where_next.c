/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_first_where_next.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:43:03 by kwurster          #+#    #+#             */
/*   Updated: 2023/12/27 19:45:52 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lst_first_where_next(t_list *lst, t_lst_pred pred, void *pred_data)
{
	while (lst->next)
	{
		if (pred(lst->next, pred_data))
			return (lst);
		lst = lst->next;
	}
	return (0);
}
