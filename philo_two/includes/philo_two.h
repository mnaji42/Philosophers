/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najimehdi <najimehdi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:17:38 by mnaji             #+#    #+#             */
/*   Updated: 2020/02/16 00:22:12 by najimehdi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>

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

typedef struct		s_sem
{
	sem_t	*forks;
	sem_t	**eat;
	sem_t	*write;
	char	**eat_name;
}					t_sem;

typedef struct		s_philo
{
	int					n;
	unsigned long int	last_eat;
	pthread_t			thread;
	int					finish;
	pthread_t			thread2;
	t_sem				*s;
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
int					init_semaphore(t_sem *s, t_param p);

#endif
