/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najimehdi <najimehdi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 23:53:10 by najimehdi         #+#    #+#             */
/*   Updated: 2020/02/16 00:04:49 by najimehdi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int			ft_atoi(const char *nptr)
{
	int		i;
	int		negativ;
	int		res;

	i = 0;
	negativ = 1;
	res = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
			|| nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '-')
		negativ = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * negativ);
}

void		ft_bzero(void *s, size_t n)
{
	int				i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char*)s;
	while ((size_t)i < n)
	{
		str[i] = '\0';
		i++;
	}
}

static int	ft_size(int n)
{
	int		size;

	size = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	else
	{
		if (n < 0)
		{
			size++;
			n = -n;
		}
		while (n != 0)
		{
			n = n / 10;
			size++;
		}
		return (size);
	}
}

static int	ft_particular(char *str, int n)
{
	if (n == 0)
		str[0] = '0';
	else if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		return (147483648);
	}
	else if (n < 0)
	{
		str[0] = '-';
		return (-n);
	}
	return (n);
}

char		*ft_itoa(int n)
{
	int		size;
	char	*str;

	size = ft_size(n);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	n = ft_particular(str, n);
	while (n > 0)
	{
		size--;
		str[size] = (char)(n % 10 + 48);
		n = n / 10;
	}
	return (str);
}
