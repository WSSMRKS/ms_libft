/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswp_front_where.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:35:51 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/02 10:04:59 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstswp_front_where(t_list **lst, t_lst_pred pred, void *pred_data)
{
	t_list	*target;
	t_list	*prev;

	if (!*lst || pred(*lst, pred_data))
		return (*lst);
	prev = ft_lst_first_where_next(*lst, pred, pred_data);
	if (!prev)
		return (0);
	target = prev->next;
	prev->next = target->next;
	target->next = *lst;
	*lst = target;
	return (*lst);
}
