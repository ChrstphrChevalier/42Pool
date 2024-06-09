/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:17:37 by waziz             #+#    #+#             */
/*   Updated: 2023/09/19 03:14:45 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char a)
{
	write (1, &a, 1);
}

void	ft_puthex(unsigned char b)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar(hex[b / 16]);
	ft_putchar(hex[b % 16]);
}

int	ft_str_is_printable(unsigned char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_str_is_printable(str[i]))
		{
			ft_putchar(str[i]);
		}
		else
		{
			ft_putchar('\\');
			ft_puthex(str[i]);
		}
		i++;
	}
}