/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:17:29 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/06/24 10:51:17 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *pram)
{
	int			i;
	t_philo		*info;

	info = (t_philo *)pram;
	i = 0;
	if ((info->id + 1) % 2 != 0)
	{
		print("is thinking", info);
		sleep_d(info->times->time_to_eat, info);
	}
	while (i < info->times->nbr_eat
		&& get_time() - info->last <= info->times->time_to_died)
	{
		eating_sleeping(info);
		pthread_mutex_lock(&info->times->mail);
		if (info->times->end == 1)
		{
			pthread_mutex_unlock(&info->times->mail);
			break ;
		}
		pthread_mutex_unlock(&info->times->mail);
		if (info->times->inc == 0)
			i++;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t		*thread;
	t_philo			*info;
	t_data			times;
	int				i;

	i = 0;
	thread = (pthread_t *)malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
	info = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (!thread || !info)
		return (0);
	if (inis(argc, argv, info, &times) == -1)
	{
		printf("plese check your args!!\n");
		return (0);
	}
	while (i < ft_atoi(argv[1]))
	{
		info[i].last = get_time();
		if (pthread_create(&thread[i], NULL, routine, (void *)&info[i]) != 0)
			return (0);
		i++;
	}
	end(thread, argv[1], info);
	return (0);
}
