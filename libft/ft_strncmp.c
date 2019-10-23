/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:31:07 by lulee             #+#    #+#             */
/*   Updated: 2019/09/29 21:41:25 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned	char	*ptr_s1;
	unsigned	char	*ptr_s2;

	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*ptr_s1 == *ptr_s2 && *ptr_s1 && *ptr_s2 && --n)
	{
		if (*ptr_s1 == '\0')
			return (*ptr_s1 - *ptr_s2);
		ptr_s1++;
		ptr_s2++;
	}
	return (*ptr_s1 - *ptr_s2);
}
