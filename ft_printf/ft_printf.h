/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:22:37 by humartin          #+#    #+#             */
/*   Updated: 2022/05/31 13:22:39 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_print
{
	va_list	args;
	int		counter;
}	t_print;

void	ischar(t_print *arg_count);
void	isstr(t_print *arg_count);
void	isptr(t_print *arg_count);
void	ishexa(t_print *arg_count, char c);
void	isint(t_print *arg_count);
void	isunsignedint(t_print *arg_count);
int		ft_printf(const char *str, ...);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
#endif
