/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:02:10 by lulee             #+#    #+#             */
/*   Updated: 2019/09/26 19:03:20 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			ft_putnbr(-n);
		}
		else
		{
			if (n >= 10)
			{
				ft_putnbr(n / 10);
				ft_putchar(n % 10 + 48);
			}
			else
				ft_putchar(n + 48);
		}
	}
}
