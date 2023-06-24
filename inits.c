/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:09:08 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/06/24 15:25:38 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	only_d(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		i++;
	}
	return (0);
}

int	check_arg(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (-1);
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60
		|| ft_atoi(argv[4]) < 60)
		return (-1);
	if (only_d(argv[1]) == -1 || only_d(argv[2]) == -1 || only_d(argv[3]) == -1
		|| only_d(argv[4]) == -1)
		return (-1);
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[2]) > 2147483647
		|| ft_atoi(argv[3]) > 2147483647 || ft_atoi(argv[4]) > 2147483647)
		return (-1);
	if (argc == 6 && (ft_atoi(argv[5]) <= 0 || ft_atoi(argv[5]) > 2147483647
			|| only_d(argv[5]) == -1))
		return (-1);
	return (0);
}

void	mut_init(pthread_mutex_t *forkk, char *str, t_data *times)
{
	int	j;

	j = 0;
	while (j < ft_atoi(str))
	{
		pthread_mutex_init(&forkk[j], NULL);
		j++;
	}
	pthread_mutex_init(&times->wirte, NULL);
	pthread_mutex_init(&times->mail, NULL);
}

void	data_init(t_data *times, char **argv, int argc)
{
	times->time_to_died = ft_atoi(argv[2]);
	times->time_to_eat = ft_atoi(argv[3]);
	times->time_to_sleep = ft_atoi(argv[4]);
	times->inc = 0;
	if (argc == 6)
	{
		times->nbr_eat = ft_atoi(argv[5]) + 1;
	}
	else
	{
		times->nbr_eat = 2147483647;
		times->nn = 1;
	}
	times->start = get_time();
	times->end = 0;
	times->nn = 0;
}

int	inis(int argc,	char **argv, t_philo *info, t_data *times)
{
	pthread_mutex_t		*forkk;
	int					i;
	int					r;

	i = 0;
	if (check_arg(argc, argv) == -1)
		return (-1);
	forkk = malloc(sizeof(pthread_mutex_t) * (ft_atoi(argv[1]) + 1));
	if (!forkk)
		return (-1);
	mut_init(forkk, argv[1], times);
	data_init(times, argv, argc);
	while (i < ft_atoi(argv[1]))
	{
		r = (i + 1) % ft_atoi(argv[1]);
		info[i].id = i;
		info[i].times = times;
		info[i].lfork = &forkk[i];
		info[i].rfork = &forkk[r];
		i++;
	}
	return (1);
}
