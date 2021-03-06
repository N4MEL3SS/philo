/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:07:15 by celadia           #+#    #+#             */
/*   Updated: 2022/05/17 16:10:36 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h> /* memset */
# include <stdio.h> /* printf,  */
# include <stdlib.h> /* malloc, free */
# include <unistd.h> /* write, usleep, */
# include <sys/time.h> /* gettimeofday */
# include <pthread.h> /* pthread_create, pthread_detach, pthread_join,
 * pthread_mutex_init, pthread_mutex_destroy,
 * pthread_mutex_lock, pthread_mutex_unlock */

# include "message.h"

typedef struct s_data
{
	int		phil_count;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		must_eat;
	int		flag;
	long	start_time;
}				t_data;

typedef struct s_mutexes
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	*data_block;
	pthread_mutex_t	output_block;
}				t_mutexes;

typedef struct s_phil_data
{
	int					phil_id;
	int					must_eat;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					exit_flag;
	long				start_time;
	long				last_meal;
	pthread_t			thread;
	pthread_mutex_t		*output_block;
	pthread_mutex_t		*data_block;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
}				t_phil_data;

typedef struct s_all
{
	int				meals;
	t_data			*data;
	t_mutexes		*mutexes;
	t_phil_data		*phil;
	pthread_t		dead;
	int				errnum;
}				t_all;

/* parser.c */
int		parser(int argc, char **argv, t_data *data);

/* init.c */
int		mutex_init(t_all *info, t_data *data);
int		thread_init(t_all *info);

/* live.c */
void	*start_act(void *phil_thread);

/* death.c */
void	*thread_control(void *all_info);

/* error.c */
int		ft_forever(void);
int		ft_error(int errnum);

/* free.c */
int		ft_free_all(t_all *info, int errnum);

/* utils.c */
void	ft_msg(t_phil_data *phil, char *color, char *msg, long time);
void	ft_wait(t_phil_data *phil, int delay, int flag);
int		ft_strlen(const char *str);
long	ft_get_time(void);

#endif //PHILO_H
