/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:20:47 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/06/23 21:26:12 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(char	*str, t_philo	*philo)
{
	long	time;

	pthread_mutex_lock(&philo->times->wirte);
	pthread_mutex_lock(&philo->times->mail);
	if (philo->times->end == 0)
	{
		time = get_time() - philo->times->start;
		printf("%ld %d %s\n", time, philo->id + 1, str);
	}
	pthread_mutex_unlock(&philo->times->mail);
	pthread_mutex_unlock(&philo->times->wirte);
}
