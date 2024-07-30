/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 04:05:45 by kwurster          #+#    #+#             */
/*   Updated: 2024/07/30 21:25:51 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_img.h"
#include <stdlib.h>

t_bool	img_alloc(t_img *img, uint32_t width, uint32_t height, t_bool zero)
{
	size_t	alloc;

	img->px = 0;
	if (!(usizemult(width, height, &img->px_len)
			&& usizemult(img->px_len, sizeof(uint32_t), &alloc)))
		return (FALSE);
	img->px = malloc(alloc);
	if (img->px == 0)
		return (FALSE);
	if (zero)
		ft_bzero(img->px, alloc);
	img->urect = urect(width, height);
	return (TRUE);
}

t_bool	img_malloc(t_img *img, uint32_t width, uint32_t height)
{
	return (img_alloc(img, width, height, FALSE));
}

t_bool	img_calloc(t_img *img, uint32_t width, uint32_t height)
{
	return (img_alloc(img, width, height, TRUE));
}

t_bool	img_clone(t_imgview src, t_img *out)
{
	if (!img_malloc(out, src.width, src.height))
		return (FALSE);
	imgview_copy(src, imgview(out));
	return (TRUE);
}

t_img	img(uint32_t *px, uint32_t width, uint32_t height)
{
	return ((t_img){.px = px, .urect = urect(width, height),
		.px_len = width * height});
}
