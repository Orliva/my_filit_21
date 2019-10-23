/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:33:17 by lulee             #+#    #+#             */
/*   Updated: 2019/09/28 20:41:43 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*empty_needle(const char *haystack)
{
	ft_strchr(haystack, ' ');
	return ((char *)haystack);
}

static	int		*eval_substr(char *ptr_hs, char *ptr_nl, int *check)
{
	while (*ptr_hs && *ptr_nl)
	{
		ptr_nl++;
		ptr_hs++;
		if (*ptr_hs != *ptr_nl && *ptr_nl)
		{
			*check = 48;
			return (check);
		}
	}
	*check = 49;
	return (check);
}

char			*ft_strstr(const char *haystack, const char *needle)
{
	int		check;
	char	*ptr_hs;
	char	*ptr_nl;

	if (*needle == '\0')
		return (empty_needle(haystack));
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			check = 49;
			ptr_hs = (char *)haystack;
			ptr_nl = (char *)needle;
			check = *eval_substr(ptr_hs, ptr_nl, &check);
			if (check == 49)
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
