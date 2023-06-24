/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:46:50 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/06/11 15:05:47 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	current_timee;

	gettimeofday(&current_timee, NULL);
	return (current_timee.tv_sec * 1000 + current_timee.tv_usec / 1000);
}
