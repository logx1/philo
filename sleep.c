/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:30:58 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/06/23 21:22:03 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_d(int time, t_philo *philo)
{
	long	timee;

	timee = get_time();
	while (timee + time > get_time())
	{
		usleep(50);
		pthread_mutex_lock(&philo->times->mail);
		if (philo->times->end == 1)
		{
			pthread_mutex_unlock(&philo->times->mail);
			break ;
		}
		pthread_mutex_unlock(&philo->times->mail);
	}	
}
