/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:15:48 by lulee             #+#    #+#             */
/*   Updated: 2019/09/28 18:04:05 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr_mass;
	unsigned char	*ptr_src;
	unsigned char	*ptr_dst;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	i = 0;
	ptr_mass = (unsigned char *)malloc(sizeof(char) * n);
	if (ptr_mass == NULL)
		return (NULL);
	while (i < n)
	{
		ptr_mass[i] = ptr_src[i];
		i++;
	}
	while (i > 0)
	{
		ptr_dst[n - i] = ptr_mass[n - i];
		i--;
	}
	free(ptr_mass);
	return ((unsigned char *)dst);
}
