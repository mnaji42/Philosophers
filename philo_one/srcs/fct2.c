/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najimehdi <najimehdi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 23:54:58 by najimehdi         #+#    #+#             */
/*   Updated: 2020/02/16 00:07:35 by najimehdi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*ft_memalloc(size_t size)
{
	void	*temp;

	if (!(temp = malloc(size)))
		return (NULL);
	ft_bzero(temp, size);
	return (temp);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

void	ft_putstr(char const *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin_free(char *tofree, char *s1, char *s2)
{
	char	*str;
	int		len_join;
	int		i;
	int		i2;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	len_join = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	i2 = 0;
	if (!(str = (char*)malloc(sizeof(char) * (len_join + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[i2] != '\0')
		str[i++] = s2[i2++];
	str[i] = '\0';
	free(tofree);
	tofree = NULL;
	return (str);
}
