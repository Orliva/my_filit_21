/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:44:24 by lulee             #+#    #+#             */
/*   Updated: 2019/09/28 23:27:51 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr_new;
	char	*ptr_s;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	ptr_s = (char *)&s[start];
	ptr_new = ft_strnew(len);
	if (ptr_new == NULL)
		return (NULL);
	while (ptr_s[i] && i < len)
	{
		ptr_new[i] = ptr_s[i];
		i++;
	}
	ptr_new[i] = '\0';
	return (ptr_new);
}
