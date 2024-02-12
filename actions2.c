/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:30:15 by tsadouk           #+#    #+#             */
/*   Updated: 2024/02/12 16:22:46 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int set_keep_iterating(t_data *data, bool value)
{
	pthread_mutex_lock(&data->mut_keep_iter);
	data->keep_iterating = value;
	pthread_mutex_unlock(&data->mut_keep_iter);
	return (0);
}

int notify_all_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_lock(&data->philos[i].mut_last_eat_time);
		pthread_mutex_unlock(&data->philos[i].mut_last_eat_time);
		i++;
	}
	return (0);
}


int nb_meals_option(t_data *data)
{
	if (data->nb_meals == -1)
		return (false);
	return (true);
}