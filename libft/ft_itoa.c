/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:49:58 by lulee             #+#    #+#             */
/*   Updated: 2019/09/29 00:24:39 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_len(unsigned int nb)
{
	unsigned int	size;

	size = 0;
	while (nb >= 10)
	{
		nb /= 10;
		size++;
	}
	return (size + 1);
}

static char		*ft_itoa_minus(int n)
{
	char			*ptr_new;
	unsigned int	i;

	ptr_new = (char *)malloc(sizeof(char) * (get_len(-n) + 2));
	i = get_len(-n) + 2;
	if (ptr_new == NULL)
		return (NULL);
	ptr_new[i - 1] = '\0';
	i -= 2;
	n = -n;
	while (i > 0)
	{
		ptr_new[i] = n % 10 + 48;
		i--;
		n /= 10;
	}
	ptr_new[i] = '-';
	return (ptr_new);
}

static char		*ft_itoa_plus(int n)
{
	char			*ptr_new;
	unsigned int	i;

	ptr_new = (char *)malloc(sizeof(char) * (get_len(n) + 1));
	i = get_len(n) + 1;
	if (ptr_new == NULL)
		return (NULL);
	i--;
	ptr_new[i-- - 1] = '\0';
	while (i > 0)
	{
		ptr_new[i--] = n % 10 + 48;
		n /= 10;
	}
	ptr_new[i] = n % 10 + 48;
	return (ptr_new);
}

char			*ft_itoa(int n)
{
	char *ptr;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			ptr = ft_itoa(-2147483647);
			ptr[10] = 8 + 48;
		}
		else
			ptr = ft_itoa_minus(n);
	}
	else
		ptr = ft_itoa_plus(n);
	return (ptr);
}
