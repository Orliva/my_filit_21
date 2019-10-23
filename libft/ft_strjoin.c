/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:15:32 by lulee             #+#    #+#             */
/*   Updated: 2019/09/28 23:38:48 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	size;
	size_t	i;

	size = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	ptr = ft_strnew(size);
	if (ptr == NULL)
		return (NULL);
	ft_strcpy(ptr, s1);
	ft_strcat(ptr, s2);
	return (ptr);
}
