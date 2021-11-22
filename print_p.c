/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:44:23 by vvarussa          #+#    #+#             */
/*   Updated: 2021/04/16 10:44:25 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	format_left_algn_p(t_tags *tags, int *counter, int cn_size)
{
	if (tags->is_negative)
		put_0x(counter);
	if (cn_size < tags->precision)
		put('0', tags->precision - cn_size, counter);
	write(1, tags->converted_num, cn_size);
	if (tags->min_size > *counter + cn_size)
		put(' ', tags->min_size - *counter - cn_size, counter);
	*counter = *counter + cn_size;
}

void	format_right_algn_precision_p(t_tags *tags, int *counter, int cn_size)
{
	int	size_of_zero;
	int	i;

	size_of_zero = 0;
	if (tags->precision > cn_size)
		size_of_zero = tags->precision - cn_size;
	i = size_of_zero + cn_size + tags->is_negative;
	if (tags->min_size > i)
		put(' ', tags->min_size - i, counter);
	if (tags->is_negative)
		put_0x(counter);
	if (size_of_zero > 0)
		put('0', tags->precision - cn_size, counter);
	write(1, tags->converted_num, cn_size);
	*counter = *counter + cn_size;
}

void	format_right_algn_others_p(t_tags *tags, int *counter, int cn_size)
{
	if (tags->min_size > (cn_size + tags->is_negative))
	{
		if (tags->has_zero)
		{
			if (tags->is_negative)
			{
				put_0x(counter);
				put('0', tags->min_size - cn_size - tags->is_negative, counter);
				tags->is_negative = 0;
			}
			else
				put('0', tags->min_size - cn_size, counter);
		}
		else
			put(' ', tags->min_size - cn_size - tags->is_negative, counter);
	}
	if (tags->is_negative)
		put_0x(counter);
	write(1, tags->converted_num, cn_size);
	*counter = *counter + cn_size;
}

int		format_number_p(t_tags *tags)
{
	int	counter;
	int	cn_size;

	cn_size = ft_strlen(tags->converted_num);
	counter = 0;
	if (tags->left_aligned)
		format_left_algn_p(tags, &counter, cn_size);
	else
	{
		if (tags->precision > 0)
			format_right_algn_precision_p(tags, &counter, cn_size);
		else
			format_right_algn_others_p(tags, &counter, cn_size);
	}
	return (counter);
}

int		print_p(va_list args, t_tags *tags)
{
	int	d;

	tags->is_negative = 2;
	if (tags->precision == 0)
		tags->converted_num = convert_to_hex(va_arg(args, size_t), 1);
	else
		tags->converted_num = convert_to_hex(va_arg(args, size_t), 0);
	d = format_number_p(tags);
	free(tags->converted_num);
	return (d);
}
