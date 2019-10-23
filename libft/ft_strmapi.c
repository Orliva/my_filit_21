/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:21:13 by lulee             #+#    #+#             */
/*   Updated: 2019/09/28 23:20:02 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned char	i;
	char			*str_new;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	str_new = ft_strnew(ft_strlen(s));
	if (str_new == NULL)
		return (NULL);
	while (s[i])
	{
		str_new[i] = f(i, s[i]);
		i++;
	}
	return (str_new);
}
