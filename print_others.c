/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_others.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:43:25 by vvarussa          #+#    #+#             */
/*   Updated: 2021/04/16 10:43:27 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		print_x(va_list args, t_tags *tags)
{
	int		counter;
	char	*s;

	tags->is_negative = 0;
	if (tags->precision == 0)
	{
		tags->precision = 0;
		tags->has_zero = 0;
		s = convert_to_hex(va_arg(args, unsigned int), 1);
		tags->converted_num = s;
	}
	else
	{
		set_precision_0(tags);
		s = convert_to_hex(va_arg(args, unsigned int), 0);
		tags->converted_num = s;
	}
	counter = format_number(tags);
	free(tags->converted_num);
	return (counter);
}

int		print_u(va_list args, t_tags *tags)
{
	int	d;

	tags->is_negative = 0;
	if (tags->precision == 0)
	{
		tags->precision = 0;
		tags->has_zero = 0;
		tags->converted_num = unsigned_itoa(va_arg(args, unsigned int), 1);
	}
	else
	{
		set_precision_0(tags);
		tags->converted_num = unsigned_itoa(va_arg(args, unsigned int), 0);
	}
	d = format_number(tags);
	free(tags->converted_num);
	return (d);
}

char	*up_string(char *s)
{
	char	*c;

	c = s;
	while (*s)
	{
		*s = ft_toupper(*s);
		s++;
	}
	return (c);
}

int		print_xx(va_list args, t_tags *tags)
{
	int		d;
	char	*s;

	tags->is_negative = 0;
	if (tags->precision == 0)
	{
		tags->precision = 0;
		tags->has_zero = 0;
		s = convert_to_hex(va_arg(args, unsigned int), 1);
		tags->converted_num = up_string(s);
	}
	else
	{
		set_precision_0(tags);
		s = convert_to_hex(va_arg(args, unsigned int), 0);
		tags->converted_num = up_string(s);
	}
	d = format_number(tags);
	free(tags->converted_num);
	return (d);
}
