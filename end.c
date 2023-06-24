/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:33:20 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/06/24 11:38:09 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end(pthread_t *thread, char *str, t_philo *info)
{
	int	i;

	i = 0;
	chech_died(info, str);
	while (i < ft_atoi(str))
	{
		pthread_join(thread[i], NULL);
			i++;
	}
	i = 0;
	while (i < ft_atoi(str))
	{
		pthread_mutex_destroy(info[i].lfork);
		i++;
	}
	pthread_mutex_destroy(&info[0].times->wirte);
	pthread_mutex_destroy(&info[0].times->mail);
	free(thread);
	free(info[0].lfork);
	free(info);
}
