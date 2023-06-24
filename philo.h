/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:43:04 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/06/24 10:51:10 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int					time_to_think;
	int					time_to_eat;
	int					nbr_eat;
	int					time_to_sleep;
	int					time_to_died;
	long				start;
	pthread_mutex_t		wirte;
	pthread_mutex_t		mail;
	int					end;
	int					nn;
	int					inc;
}t_data;

typedef struct s_philo
{
	int					id;
	long				time;
	t_data				*times;
	long				last;
	pthread_mutex_t		*lfork;
	pthread_mutex_t		*rfork;

}t_philo;

int		inis(int argc, char **argv, t_philo *data, t_data *times);
long	get_time(void);
void	sleep_d(int time, t_philo	*philo);
void	print(char	*str, t_philo	*philo);
void	chech_died(t_philo *info, char *philo_total);
long	ft_atoi(char *str);
int		only_d(char *str);
void	eating_sleeping(t_philo *info);
void	end(pthread_t *thread, char *str, t_philo *info);

#endif
