/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 01:55:17 by mnaji             #+#    #+#             */
/*   Updated: 2020/02/16 13:38:59 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	print_status(t_philo *ph, char *status, int died)
{
	char	*buff;

	if (!(buff = ft_strdup(ft_itoa(get_time_in_ms() - ph->p->start))))
		exit_error(ph, "print status");
	if (!(buff = ft_strjoin_free(buff, buff, " ")))
		exit_error(ph, "print status");
	if (!(buff = ft_strjoin_free(buff, buff, ft_itoa(ph->n))))
		exit_error(ph, "print status");
	if (!(buff = ft_strjoin_free(buff, buff, status)))
		exit_error(ph, "print status");
	sem_wait(ph->s->write);
	if (ph->p->is_dead == 0)
		ft_putstr(buff);
	free(buff);
	buff = NULL;
	if (died)
		ph->p->is_dead = 0;
	sem_post(ph->s->write);
}

static void	*routine2(void *tmp)
{
	t_philo	*ph;

	ph = tmp;
	while (1)
	{
		sem_wait(ph->s->eat[ph->n]);
		if (get_time_in_ms() - ph->last_eat > \
			(unsigned long int)ph->p->time_die)
		{
			print_status(ph, " died\n", 1);
			exit(0);
		}
		sem_post(ph->s->eat[ph->n]);
		usleep(8000);
	}
	return (NULL);
}

static void	*routine(t_philo *ph)
{
	static int	count = 0;

	if (pthread_create(&ph->thread2, NULL, &routine2, ph) != 0)
		exit_error(ph, "pthread routine2 failed");
	while (1)
	{
		print_status(ph, " is thinking\n", 0);
		sem_wait(ph->s->forks);
		print_status(ph, " has taken a fork\n", 0);
		sem_wait(ph->s->forks);
		print_status(ph, " has taken a fork\n", 0);
		print_status(ph, " is eating\n", 0);
		sem_wait(ph->s->eat[ph->n]);
		ph->last_eat = get_time_in_ms();
		usleep(ph->p->time_eat * 1000);
		sem_post(ph->s->eat[ph->n]);
		sem_post(ph->s->forks);
		sem_post(ph->s->forks);
		if (ph->p->time_must_eat != -1 && count++ > ph->p->time_must_eat)
			break ;
		print_status(ph, " is sleeping\n", 0);
		usleep(ph->p->time_sleep * 1000);
	}
	exit(0);
	return (NULL);
}

int			philo(t_philo *ph)
{
	int		i;
	int		status;

	i = 0;
	while (i < ph->p->nb_philo)
	{
		if (!(ph[i].pid = fork()))
			routine(&ph[i]);
		i++;
		usleep(10);
	}
	i = 0;
	waitpid(-1, &status, 0);
	while (i < ph->p->nb_philo)
		kill(ph[i++].pid, SIGINT);
	exit(WEXITSTATUS(status));
	return (1);
}
