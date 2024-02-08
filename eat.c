/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:28:46 by tsadouk           #+#    #+#             */
/*   Updated: 2024/02/08 15:13:42 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



int	eat(t_philo *philo)
{
	uint64_t	eat_time;

	eat_time = get_eat_time(philo->data);
	pthread_mutex_lock(&philo->mut_last_eat_time);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->mut_last_eat_time);
	print_philo_action(philo, "is eating");
	wait_until(philo->last_eat_time + eat_time);
	return (0);
}

int	nb_meals_option(t_data *data)
{
	int	nb_meals;
	t_philo	*philos;

	philos = data->philos;
	
	nb_meals = get_nb_meals_philo_had(philos);
	if (nb_meals >= philos->data->nb_meals)
	{
		pthread_mutex_lock(&philos->mut_state);
		philos->state = DEAD;
		pthread_mutex_unlock(&philos->mut_state);
		print_philo_action(philos, "is DEAD");
		return (1);
	}
	return (0);
}

void	update_last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_last_eat_time);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->mut_last_eat_time);
}



