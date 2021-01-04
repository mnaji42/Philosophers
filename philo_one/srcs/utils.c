/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:06:30 by mnaji             #+#    #+#             */
/*   Updated: 2020/02/16 14:14:52 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void				exit_error(t_philo *ph, char *err)
{
	int		i;

	i = 0;
	while (i < ph->p->nb_philo)
		pthread_mutex_destroy(&ph->m->eat[i++]);
	i = 0;
	while (i < ph->p->nb_philo)
		pthread_mutex_destroy(&ph->m->forks[i++]);
	pthread_mutex_destroy(&ph->m->write);
	free(ph->m->forks);
	free(ph->m->eat);
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
	while (i < ph->p->nb_philo)
		pthread_mutex_destroy(&ph->m->eat[i++]);
	i = 0;
	while (i < ph->p->nb_philo)
		pthread_mutex_destroy(&ph->m->forks[i++]);
	pthread_mutex_destroy(&ph->m->write);
	free(ph->m->forks);
	free(ph->m->eat);
	free(ph);
}
