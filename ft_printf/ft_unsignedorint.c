/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedorint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:23:56 by humartin          #+#    #+#             */
/*   Updated: 2022/05/31 13:23:59 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbrlen(unsigned int number)
{
	int	length;

	length = 1;
	while (number > 9)
	{
		number = number / 10;
		length++;
	}
	return (length);
}

static char	*uitoa(unsigned int number)
{
	char	*str;
	int		length;

	length = nbrlen(number);
	str = (char *)malloc(length + 1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[length] = '\0';
	while (length > 0)
	{
		str[--length] = number % 10 + '0';
		number = number / 10;
	}
	return (str);
}

void	isint(t_print *arg_count)
{
	char	*str;
	int		result;

	result = va_arg(arg_count->args, int);
	str = ft_itoa(result);
	ft_putstr_fd(str, 1);
	arg_count->counter += ft_strlen(str);
	free(str);
}

void	isunsignedint(t_print *arg_count)
{
	char			*str;
	unsigned int	result;

	result = va_arg(arg_count->args, unsigned int);
	str = uitoa(result);
	ft_putstr_fd(str, 1);
	arg_count->counter += ft_strlen(str);
	free(str);
}
