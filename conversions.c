/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:44:32 by vvarussa          #+#    #+#             */
/*   Updated: 2021/04/16 10:44:35 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

char	*invert_str(char *str, size_t size)
{
	char	*final_str;
	size_t	i;

	i = 0;
	final_str = malloc(sizeof(char) * (size + 1));
	while (i <= size)
	{
		final_str[i] = str[size - i - 1];
		i++;
	}
	final_str[i - 1] = '\0';
	return (final_str);
}

char	*unsigned_itoa(unsigned int number, int return_blank)
{
	char	str[50];
	size_t	counter;
	size_t	modulus;

	counter = 0;
	if (number == 0 && !return_blank)
		return (ft_strdup("0"));
	while (number / 10 > 0 || (number / 10 == 0 && number % 10 > 0))
	{
		modulus = number % 10;
		number /= 10;
		str[counter] = '0' + modulus;
		counter++;
	}
	return (invert_str(str, counter));
}

char	*convert_to_hex(size_t number, int return_blank)
{
	char	str[50];
	size_t	counter;
	size_t	modulus;

	counter = 0;
	if (number == 0 && !return_blank)
		return (ft_strdup("0"));
	while (number / 16 > 0 || (number / 16 == 0 && number % 16 > 0))
	{
		modulus = number % 16;
		number /= 16;
		if (modulus > 9)
			str[counter] = 87 + modulus;
		else
			str[counter] = '0' + modulus;
		counter++;
	}
	return (invert_str(str, counter));
}
