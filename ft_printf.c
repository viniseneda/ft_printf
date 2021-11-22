/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:44:45 by vvarussa          #+#    #+#             */
/*   Updated: 2021/04/16 10:44:59 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_type(va_list *args, t_tags *tags, int *counter,
const char **string)
{
	tags->type = 'm';
	parse_tags(*args, string, tags);
	if (tags->type == 'd' || tags->type == 'i')
		*counter = *counter + print_d(*args, tags);
	if (tags->type == 's')
		*counter = *counter + print_s(*args, tags);
	if (tags->type == 'c')
		*counter = *counter + print_c(*args, tags);
	if (tags->type == 'x')
		*counter = *counter + print_x(*args, tags);
	if (tags->type == 'X')
		*counter = *counter + print_xx(*args, tags);
	if (tags->type == 'p')
		*counter = *counter + print_p(*args, tags);
	if (tags->type == 'u')
		*counter = *counter + print_u(*args, tags);
	if (tags->type == '%')
		*counter = *counter + print_pp(tags);
	tags->has_run = 1;
	if (**string != '\0')
		*string = *string + 1;
}

int		ft_printf(const char *string, ...)
{
	va_list	args;
	t_tags	tags;
	int		counter;

	counter = 0;
	va_start(args, string);
	while (*string != '\0')
	{
		tags.has_run = 0;
		if (*string == '%')
		{
			print_type(&args, &tags, &counter, &string);
		}
		if (*string != '%' && *string != '\0')
		{
			write(1, string, 1);
			tags.has_run = 1;
			counter++;
			string++;
		}
		if (!tags.has_run)
			string++;
	}
	return (counter);
}
