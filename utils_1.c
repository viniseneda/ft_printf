/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:44:05 by vvarussa          #+#    #+#             */
/*   Updated: 2021/04/16 10:44:07 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		verify(char c, const char *list)
{
	int	i;

	i = 0;
	while (*list != '\0')
	{
		if (c == list[i])
			return (1);
		list++;
	}
	return (0);
}

void	read_number(va_list args, const char **cursor, int *revised_number,
t_tags *tags)
{
	int	number;

	number = 0;
	if (ft_isdigit(**cursor))
	{
		while (ft_isdigit(**cursor))
		{
			number = gen_number(number, **cursor - '0');
			*cursor = *cursor + 1;
		}
		*revised_number = number / 10;
	}
	else if (**cursor == '*')
	{
		number = va_arg(args, int);
		if (number < 0 && tags->neg_arg_min_size)
		{
			tags->left_aligned = 1;
			number *= -1;
		}
		*revised_number = number;
		*cursor = *cursor + 1;
	}
	skip(cursor);
}

int		gen_number(int a, int b)
{
	a = a + b;
	return (a * 10);
}

int		skip(const char **cursor)
{
	while (!ft_isdigit(**cursor) && !verify(**cursor, SKIP))
	{
		*cursor = *cursor + 1;
		if (**cursor == '\0')
			return (0);
	}
	return (1);
}
