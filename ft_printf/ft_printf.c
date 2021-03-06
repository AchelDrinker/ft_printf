/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:03:55 by humartin          #+#    #+#             */
/*   Updated: 2022/03/18 16:03:55 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int		ft_printf(const char *s, ...)
{
	t_buffer	b;
	t_flags		f;
	char		*string;

	string = (char *)s;
	ft_bzero(&b, sizeof(b));
	va_start(b.args, s);
	while (*string)
	{
		if (*string == '%')
		{
			ft_bzero(&f, sizeof(f));
			string = read_format(&b, &f, string);
		}
		else
			add_to_buffer(&b, &f, *string++);
	}
	write(1, b.buffer, b.buff_i);
	va_end(b.args);
	return (b.buff_i + b.written);
}
