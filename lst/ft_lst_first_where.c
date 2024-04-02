/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_first_where.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:35:08 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/02 10:04:52 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lst_first_where(t_list *lst, t_lst_pred pred, void *pred_data)
{
	while (lst)
	{
		if (pred(lst, pred_data))
			return (lst);
		lst = lst->next;
	}
	return (0);
}
