/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:42:05 by vvarussa          #+#    #+#             */
/*   Updated: 2021/04/16 10:42:16 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# define TYPES "cspdiuxX%"
# define SKIP "cspdiuxX%.*"

typedef struct	s_tags
{
	int		neg_arg_min_size;
	int		has_zero;
	int		has_run;
	int		left_aligned;
	int		min_size;
	int		precision;
	int		is_negative;
	char	type;
	char	*converted_num;
}				t_tags;

void			parse_tags(va_list args, const char **cursor, t_tags *tags);
int				ft_printf(const char *string, ...);
void			print_tags(t_tags tags);
char			*unsigned_itoa(unsigned int number, int return_blank);
char			*convert_to_hex(size_t number, int return_blank);
void			put(int c, int size, int *counter);
void			print_space(t_tags *tags, int *mcounter, int cn_size);
int				format_number(t_tags *tags);

int				print_d(va_list args, t_tags *tags);
int				print_c(va_list args, t_tags *tags);
int				print_s(va_list args, t_tags *tags);
int				print_x(va_list args, t_tags *tags);
int				print_xx(va_list args, t_tags *tags);
int				print_p(va_list args, t_tags *tags);
int				print_u(va_list args, t_tags *tags);
int				print_pp(t_tags *tags);

/*
** utils_1
*/
int				verify(char c, const char *list);
void			read_number(va_list args, const char **cursor, int
*revised_number, t_tags *tags);
int				gen_number (int a, int b);
int				skip(const char **cursor);

/*
** utils_2
*/
void			put(int c, int size, int *counter);
void			read_char(const char **cursor);
void			set_tags_for_precision_0_d(t_tags *tags, char *c);
void			set_precision_0(t_tags *tags);
void			put_0x(int *counter);

#endif
