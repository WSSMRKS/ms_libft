/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:29:40 by kwurster          #+#    #+#             */
/*   Updated: 2023/12/27 17:20:28 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static t_list	*init(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;
	void	*tmp;

	tmp = f(lst->content);
	out = ft_lstnew(tmp);
	if (!out)
	{
		del(tmp);
		return (0);
	}
	return (out);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;
	t_list	*out_tail;
	void	*tmp;

	if (!lst)
		return (0);
	out = init(lst, f, del);
	if (!out)
		return (0);
	lst = lst->next;
	out_tail = out;
	while (lst)
	{
		tmp = f(lst->content);
		out_tail->next = ft_lstnew(tmp);
		if (!out_tail->next)
		{
			del(tmp);
			ft_lstclear(&out, del);
			return (0);
		}
		out_tail = out_tail->next;
		lst = lst->next;
	}
	return (out);
}
