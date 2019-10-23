/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:42:14 by lulee             #+#    #+#             */
/*   Updated: 2019/10/15 17:56:32 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	cut_str(char **str_stack, char **line)
{
	size_t	len;
	char	*tmp;

	len = 0;
	while ((*str_stack)[len] != '\n' && (*str_stack)[len] != '\0')
		len++;
	if ((*str_stack)[len] == '\n')
	{
		*line = ft_strsub(*str_stack, 0, len);
		tmp = ft_strdup(&((*str_stack)[len + 1]));
		free(*str_stack);
		*str_stack = tmp;
		if (*str_stack[0] == '\0')
			ft_strdel(str_stack);
	}
	else
	{
		*line = ft_strdup(*str_stack);
		ft_strdel(str_stack);
	}
	return (1);
}

static	int	case_val(const int fd, char **line, int ref, char **stack_f)
{
	if (ref < 0)
		return (-1);
	else
	{
		if (ref == 0 && stack_f[fd] == NULL)
			return (0);
		else
			return (cut_str(&stack_f[fd], line));
	}
}

int			get_next_line(const int fd, char **line)
{
	static	char	*stack_f[FD_SIZE];
	int				ref;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ref = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ref] = '\0';
		if (stack_f[fd] == NULL)
			stack_f[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(stack_f[fd], buf);
			free(stack_f[fd]);
			stack_f[fd] = tmp;
		}
		if (ft_strchr(stack_f[fd], '\n'))
			break ;
	}
	return (case_val(fd, line, ref, stack_f));
}
