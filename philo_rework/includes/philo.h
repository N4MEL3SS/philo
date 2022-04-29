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
}				t_data;

typedef struct s_mutexes
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	output;
}				t_mutexes;

typedef struct s_phil_data
{
	int					phil_id;
	int					must_eat;
	long				start_time;
	long				last_meal;
	t_data				*data;
	t_mutexes			*mutex;
	pthread_t			thread;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
}				t_phil_data;

typedef struct s_all
{
	t_data			*data;
	t_mutexes		*mutexes;
	t_phil_data		*phil;
	pthread_t		death;
	int				errnum;
}				t_all;

int		parser(int argc, char **argv, t_data *data);
int		mutex_init(t_all *info, t_data *data);
int		thread_init(t_all *info);

int		ft_sleep(long time_to_wait, t_phil_data *phil);
void	eating(t_phil_data *phil);
void	sleeping(t_phil_data *phil);
void	thinking(t_phil_data *phil);

int		ft_forever(void);
int		ft_error(int errnum);

int		ft_free_all(t_all *info, int errnum);

/* utils.c */
int		ft_strlen(const char *str);
long	ft_get_time(void);

#endif //PHILO_H