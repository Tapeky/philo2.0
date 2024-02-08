/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:58:00 by tsadouk           #+#    #+#             */
/*   Updated: 2024/02/08 14:28:42 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_philo_full(t_philo *philo)
{
	int	nb_meals;

	pthread_mutex_lock(&philo->mut_meals_eaten);
	nb_meals = philo->meals_eaten;
	pthread_mutex_unlock(&philo->mut_meals_eaten);
	if (nb_meals >= philo->data->nb_meals)
		return (1);
	return (0);
}

int	is_philo_dead(t_philo *philo)
{
	uint64_t	die_time;
	uint64_t	last_eat_time;

	die_time = get_die_time(philo->data);
	last_eat_time = get_last_eat_time(philo);
	if (get_time() - last_eat_time > die_time
			&& get_philo_state(philo) != EATING)
	{
		change_philo_state(philo, DEAD);
		print_philo_action(philo, "died");
		return (1);
	}
	return (0);
}

int monitor_all_alive(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->nb_philos)
	{
		if (get_philo_state(&philos[i]) == DEAD)
			return (1);
		i++;
	}
	return (0);
}
