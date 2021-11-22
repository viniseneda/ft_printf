/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:44:13 by vvarussa          #+#    #+#             */
/*   Updated: 2021/04/16 10:44:14 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put(int c, int size, int *counter)
{
	char	ch;

	if (size < 0)
		return ;
	while (size)
	{
		ch = (char)c;
		write(1, &ch, 1);
		size--;
		*counter = *counter + 1;
	}
}

void	put_0x(int *counter)
{
	write(1, "0x", 2);
	*counter = *counter + 2;
}

void	read_char(const char **cursor)
{
	if (**cursor != '\0')
		*cursor = *cursor + 1;
}

void	set_tags_for_precision_0_d(t_tags *tags, char *c)
{
	*c = '\0';
	tags->precision = 0;
	tags->converted_num = c;
	tags->has_zero = 0;
}

void	set_precision_0(t_tags *tags)
{
	if (tags->precision < 0)
		tags->precision = 0;
	else
		tags->has_zero = 0;
}
