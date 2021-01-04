/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:17:38 by mnaji             #+#    #+#             */
/*   Updated: 2020/02/16 14:14:38 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct		s_param
{
	unsigned long	start;
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_must_eat;
	int				is_dead;
}					t_param;

typedef struct		s_mutex
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	*eat;
	pthread_mutex_t	write;
}					t_mutex;

typedef struct		s_philo
{
	int					n;
	unsigned long int	last_eat;
	pthread_t			thread;
	int					finish;
	pthread_t			thread2;
	t_mutex				*m;
	t_param				*p;
}					t_philo;

void				*ft_memalloc(size_t size);
void				ft_putstr(char const *s);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strjoin_free(char *tofree, char *s1, char *s2);
char				*ft_itoa(int n);
void				ft_bzero(void *s, size_t n);
int					ft_atoi(const char *nptr);

int					print_error(char *error, int ret);
unsigned long int	get_time_in_ms(void);
void				exit_error(t_philo *ph, char *err);
void				free_all(t_philo *ph);

int					philo(t_philo *ph);

#endif
