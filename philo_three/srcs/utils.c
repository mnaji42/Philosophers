/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najimehdi <najimehdi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:06:30 by mnaji             #+#    #+#             */
/*   Updated: 2020/02/16 00:17:45 by najimehdi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void				exit_error(t_philo *ph, char *err)
{
	int		i;

	i = 0;
	sem_unlink("fork");
	sem_unlink("write");
	while (i < ph->p->nb_philo)
	{
		sem_unlink(ph->s->eat_name[i]);
		free(ph->s->eat_name[i]);
		ph->s->eat_name[i++] = NULL;
	}
	free(ph->s->eat_name);
	ph->s->eat_name = NULL;
	free(ph->s->eat);
	ph->s->eat = NULL;
	free(ph);
	print_error(err, 0);
	exit(1);
}

unsigned long int	get_time_in_ms(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_usec / 1000 + tv.tv_sec * 1000);
}

int					print_error(char *error, int ret)
{
	ft_putstr("Error : ");
	ft_putstr(error);
	return (ret);
}

void				free_all(t_philo *ph)
{
	int		i;

	i = 0;
	sem_unlink("fork");
	sem_unlink("write");
	while (i < ph->p->nb_philo)
	{
		sem_unlink(ph->s->eat_name[i]);
		free(ph->s->eat_name[i]);
		ph->s->eat_name[i++] = NULL;
	}
	free(ph->s->eat_name);
	ph->s->eat_name = NULL;
	free(ph->s->eat);
	ph->s->eat = NULL;
	free(ph);
}
