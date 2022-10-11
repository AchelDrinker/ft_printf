/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:22:20 by humartin          #+#    #+#             */
/*   Updated: 2022/05/31 13:22:31 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_print	*start(void)
{
	t_print	*arg_count;

	arg_count = (t_print *)malloc(sizeof(t_print));
	if (arg_count == NULL)
		return (NULL);
	arg_count->counter = 0;
	return (arg_count);
}

void	ischecking(const char c, t_print *arg_count)
{
	if (c == 'c')
		ischar(arg_count);
	else if (c == 's')
		isstr(arg_count);
	else if (c == 'p')
		isptr(arg_count);
	else if (c == 'i' || c == 'd')
		isint(arg_count);
	else if (c == 'u')
		isunsignedint(arg_count);
	else if (c == 'x' || c == 'X')
		ishexa(arg_count, c);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		arg_count->counter++;
	}
	else if (c != '\0')
	{
		write(1, &c, 1);
		arg_count->counter++;
	}
}

int	ft_printf(const char *str, ...)
{
	t_print	*arg_count;
	int		finalprint;
	int		i;

	i = 0;
	arg_count = start();
	finalprint = 0;
	va_start(arg_count->args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			ischecking(str[++i], arg_count);
		else
		{
			ft_putchar_fd(str[i], 1);
			arg_count->counter++;
		}
		if (str[i] != '\0')
			i++;
	}
	finalprint = arg_count->counter;
	va_end(arg_count->args);
	free(arg_count);
	return (finalprint);
}
