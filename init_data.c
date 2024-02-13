/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:58:00 by tsadouk           #+#    #+#             */
/*   Updated: 2024/02/13 15:24:19 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, int argc, char **argv)
{
	data->nb_philos = ft_atoi(argv[1]);
	data->nb_meals = -1;
	data->nb_full_p = 0;
	data->keep_iterating = true;
	data->eat_time = ft_atoi(argv[3]);
	data->die_time = ft_atoi(argv[2]);
	data->sleep_time = ft_atoi(argv[4]);
	data->start_time = 0;
	if (argc == 6)
		data->nb_meals = ft_atoi(argv[5]);
	if (errors_handeler(argc, argv) != 0)
		return (1);
	if (data->nb_philos < 2 || data->nb_philos > 200 || data->nb_meals < 0
		|| data->eat_time < 60 || data->die_time < 60 || data->sleep_time < 60)
		return (1);
	init_mutex(data);
	return (0);
}

void	init_mutex(t_data *data)
{
	pthread_mutex_init(&data->mut_eat_t, NULL);
	pthread_mutex_init(&data->mut_die_t, NULL);
	pthread_mutex_init(&data->mut_sleep_t, NULL);
	pthread_mutex_init(&data->mut_print, NULL);
	pthread_mutex_init(&data->mut_nb_philos, NULL);
	pthread_mutex_init(&data->mut_keep_iter, NULL);
	pthread_mutex_init(&data->mut_start_time, NULL);
}

int	init_forks(t_data *data)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = data->philos;
	while (i < data->nb_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	philos[0].left_fork = &data->forks[0];
	philos[0].right_fork = &data->forks[data->nb_philos - 1];
	i = 1;
	while (i < data->nb_philos)
	{
		philos[i].left_fork = &data->forks[i];
		philos[i].right_fork = &data->forks[i - 1];
		i++;
	}
	return (0);
}

int	init_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = data->philos;
	while (i < data->nb_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].data = data;
		data->philos[i].state = IDLE;
		pthread_mutex_init(&data->philos[i].mut_state, NULL);
		pthread_mutex_init(&data->philos[i].mut_meals_eaten, NULL);
		pthread_mutex_init(&data->philos[i].mut_last_eat_time, NULL);
		update_last_meal_time(&philos[i]);
		i++;
	}
	return (0);
}

int	malloc_data(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	if (!data->philos)
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!data->forks)
		return (free(data->philos), 1);
	data->philo_ths = malloc(sizeof(pthread_t) * data->nb_philos);
	if (!data->philo_ths)
		return (free(data->philos), free(data->forks), 1);
	return (0);
}
