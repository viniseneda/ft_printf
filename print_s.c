/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:42:55 by vvarussa          #+#    #+#             */
/*   Updated: 2021/04/16 10:42:59 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	write_amount(t_tags *tags, int *counter, int amount)
{
	write(1, tags->converted_num, amount);
	*counter = *counter + amount;
}

void	print_string(t_tags *tags, int *counter, int cn_size)
{
	int	i;

	i = tags->precision;
	if (i < 0)
		write_amount(tags, counter, cn_size);
	else
	{
		if (i > cn_size)
			write_amount(tags, counter, cn_size);
		else
			write_amount(tags, counter, i);
	}
}

void	print_space(t_tags *tags, int *mcounter, int cn_size)
{
	int		i;
	char	c;

	c = ' ';
	if (tags->has_zero && !tags->left_aligned)
		c = '0';
	if (tags->precision < 0)
	{
		put(c, tags->min_size - cn_size, mcounter);
		return ;
	}
	else if (tags->precision < cn_size)
		i = tags->precision;
	else
		i = cn_size;
	if (tags->min_size > i)
		put(c, tags->min_size - i, mcounter);
}

int		format_string(t_tags *tags)
{
	int	counter;
	int	cn_size;

	cn_size = ft_strlen(tags->converted_num);
	counter = 0;
	if (tags->left_aligned)
	{
		print_string(tags, &counter, cn_size);
		print_space(tags, &counter, cn_size);
	}
	else
	{
		print_space(tags, &counter, cn_size);
		print_string(tags, &counter, cn_size);
	}
	return (counter);
}

int		print_s(va_list args, t_tags *tags)
{
	int	n;

	tags->converted_num = va_arg(args, char *);
	if (tags->converted_num == NULL)
	{
		tags->converted_num = ft_strdup("(null)");
		n = format_string(tags);
		free(tags->converted_num);
	}
	else
		n = format_string(tags);
	return (n);
}
