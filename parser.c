/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:43:35 by vvarussa          #+#    #+#             */
/*   Updated: 2021/04/16 10:43:39 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	set_minus_or_zero(const char **c, t_tags *tags)
{
	if (**c == '0' || **c == '-')
	{
		if (**c == '0')
			tags->has_zero = 1;
		if (**c == '-')
			tags->left_aligned = 1;
		*c = *c + 1;
		set_minus_or_zero(c, tags);
	}
}

void	set_min_size(va_list args, const char **cursor, t_tags *tags)
{
	tags->neg_arg_min_size = 1;
	read_number(args, cursor, &tags->min_size, tags);
	if (**cursor == '*' || ft_isdigit(**cursor))
		set_min_size(args, cursor, tags);
}

int		is_another_minus(const char **cursor)
{
	while (**cursor == '0')
	{
		*cursor = *cursor + 1;
		if (**cursor == '\0')
			return (0);
	}
	if (**cursor == '-')
		return (1);
	else
		return (0);
}

void	set_precision(va_list args, const char **cursor, t_tags *tags)
{
	tags->neg_arg_min_size = 0;
	if (**cursor == '.')
	{
		*cursor = *cursor + 1;
		if (**cursor == '\0')
			return ;
		tags->precision = 0;
		if (is_another_minus(cursor))
		{
			set_minus_or_zero(cursor, tags);
			set_min_size(args, cursor, tags);
		}
		else
		{
			read_number(args, cursor, &tags->precision, tags);
			set_min_size(args, cursor, tags);
		}
	}
	if (**cursor == '.')
		set_precision(args, cursor, tags);
}

void	parse_tags(va_list args, const char **cursor, t_tags *tags)
{
	*cursor = *cursor + 1;
	if (**cursor == '\0')
		return ;
	tags->precision = -1;
	tags->min_size = 0;
	tags->is_negative = 0;
	tags->has_zero = 0;
	tags->left_aligned = 0;
	set_minus_or_zero(cursor, tags);
	set_min_size(args, cursor, tags);
	set_precision(args, cursor, tags);
	if (verify(**cursor, TYPES))
	{
		tags->type = **cursor;
	}
}
