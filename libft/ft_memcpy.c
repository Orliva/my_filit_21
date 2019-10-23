/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:07:59 by lulee             #+#    #+#             */
/*   Updated: 2019/09/28 17:32:49 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*ptr_src;
	unsigned char		*ptr_dst;

	if (!dst && !src)
		return (NULL);
	ptr_dst = (unsigned char *)dst;
	ptr_src = (const unsigned char *)src;
	while (n > 0)
	{
		*ptr_dst = *ptr_src;
		ptr_dst++;
		ptr_src++;
		n--;
	}
	return ((unsigned char *)dst);
}
