/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:40:10 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/06/23 20:08:21 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating_sleeping(t_philo *info)
{
	pthread_mutex_lock(info->lfork);
	print("has taken a fork", info);
	pthread_mutex_lock(info->rfork);
	print("has taken a fork", info);
	pthread_mutex_lock(&info->times->mail);
	info->last = get_time();
	pthread_mutex_unlock(&info->times->mail);
	print("is eating", info);
	pthread_mutex_lock(&info->times->mail);
	info->times->nn++;
	pthread_mutex_unlock(&info->times->mail);
	sleep_d(info->times->time_to_eat, info);
	pthread_mutex_unlock(info->lfork);
	pthread_mutex_unlock(info->rfork);
	print("is sleeping", info);
	sleep_d(info->times->time_to_sleep, info);
	print("is thinking", info);
}
