/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:42:33 by vvarussa          #+#    #+#             */
/*   Updated: 2021/04/16 10:42:41 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	format_string_c(t_tags *tags)
{
	int	counter;
	int	cn_size;

	cn_size = 1;
	counter = 1;
	if (tags->left_aligned)
	{
		write(1, tags->converted_num, cn_size);
		print_space(tags, &counter, cn_size);
	}
	else
	{
		print_space(tags, &counter, cn_size);
		write(1, tags->converted_num, cn_size);
	}
	return (counter);
}

int	print_pp(t_tags *tags)
{
	int	n;

	tags->converted_num = "%";
	tags->precision = 1;
	n = format_string_c(tags);
	return (n);
}

int	print_c(va_list args, t_tags *tags)
{
	char	c;
	int		n;

	c = va_arg(args, int);
	tags->converted_num = &c;
	tags->precision = 1;
	n = format_string_c(tags);
	return (n);
}
