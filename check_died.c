/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_died.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:16:09 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/06/23 22:38:39 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_time(long long period, t_philo *info, int x)
{
	if (period > info[x].times->time_to_died && info->times->end == 0)
	{
		print("died", &info[x]);
		pthread_mutex_lock(&info[x].times->mail);
			info[x].times->end = 1;
		pthread_mutex_unlock(&info[x].times->mail);
		pthread_mutex_unlock(info[x].lfork);
	}
}

void	chech_died(t_philo *info, char *philo_total)
{
	int			x;
	long long	period;
	int			nbr_eat;

	x = 0;
	while (info->times->end == 0)
	{
		if (x == ft_atoi(philo_total))
			x = 0;
		pthread_mutex_lock(&info[x].times->mail);
		nbr_eat = info[x].times->nn
			- (info->times->nbr_eat * ft_atoi(philo_total));
		pthread_mutex_unlock(&info[x].times->mail);
		if (nbr_eat == 0)
		{
			pthread_mutex_lock(&info[x].times->mail);
			info[x].times->end = 1;
			pthread_mutex_unlock(&info[x].times->mail);
		}
		pthread_mutex_lock(&info[x].times->mail);
		period = get_time() - info[x].last;
		pthread_mutex_unlock(&info[x].times->mail);
		check_time(period, info, x);
		x++;
	}
}
