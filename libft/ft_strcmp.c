/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:29:26 by lulee             #+#    #+#             */
/*   Updated: 2019/09/29 19:45:44 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *ptr_s1;
	unsigned char *ptr_s2;

	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	while (*ptr_s1 == *ptr_s2)
	{
		if (*ptr_s1 == '\0')
			return (0);
		ptr_s1++;
		ptr_s2++;
	}
	return (*ptr_s1 - *ptr_s2);
}
