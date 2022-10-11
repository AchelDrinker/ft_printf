/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrcharstrhexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:22:54 by humartin          #+#    #+#             */
/*   Updated: 2022/05/31 13:23:08 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*nbrlen(unsigned long number, int *length)
{
	char	*str;

	while (number >= 16)
	{
		number = number / 16;
		*length += 1;
	}
	str = (char *)malloc((*length + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[*length] = '\0';
	return (str);
}

void	ishexa(t_print *arg_count, char c)
{
	unsigned int	number;
	int				length;
	char			*str;

	number = va_arg(arg_count->args, unsigned int);
	length = 1;
	str = nbrlen(number, &length);
	length--;
	while (length >= 0)
	{
		if (number % 16 < 10)
			str[length] = '0' + (number % 16);
		else if (c == 'x')
			str[length] = 'a' - 10 + (number % 16);
		else if (c == 'X')
			str[length] = 'A' - 10 + (number % 16);
		number = number / 16;
		length--;
		arg_count->counter++;
	}
	ft_putstr_fd(str, 1);
	free(str);
}

void	isptr(t_print *arg_count)
{
	int				length;
	char			*str;
	unsigned long	number;

	number = va_arg(arg_count->args, unsigned long);
	length = 1;
	str = nbrlen(number, &length);
	ft_putstr_fd("0x", 1);
	arg_count->counter += 2;
	length--;
	while (length >= 0)
	{
		if (number % 16 < 10)
			str[length] = '0' + (number % 16);
		else
			str[length] = 'a' + (number % 16) - 10;
		number = number / 16;
		length--;
		arg_count->counter++;
	}
	ft_putstr_fd(str, 1);
	free(str);
}

void	ischar(t_print *arg_count)
{
	ft_putchar_fd(va_arg(arg_count->args, int), 1);
	arg_count->counter++;
}

void	isstr(t_print *arg_count)
{
	char	*str;
	int		length;

	str = va_arg(arg_count->args, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		arg_count->counter += 6;
	}
	else
	{
		length = ft_strlen(str);
		ft_putstr_fd(str, 1);
		arg_count->counter += length;
	}
}
