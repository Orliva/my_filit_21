/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:18:27 by lulee             #+#    #+#             */
/*   Updated: 2019/09/28 23:19:18 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*str_new;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	str_new = ft_strnew(ft_strlen(s));
	if (str_new == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str_new[i] = f(s[i]);
		i++;
		if (s[i] == '\0')
			str_new[i] = '\0';
	}
	return (str_new);
}
