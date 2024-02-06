/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:34:13 by tsadouk           #+#    #+#             */
/*   Updated: 2024/02/06 12:34:47 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	think(t_philo *philosopher)
{
	t_data *data = philosopher->data;
	
	if (get_philo_state(philosopher) == DEAD)
		return (1);
	change_philo_state(philosopher, THINK);
	print_philo_action(philosopher, "is thinking");
	sleep_for(data->sleep_time);
	return (0);
}

int	ft_sleep(t_philo *philosopher)
{
	t_data *data = philosopher->data;
	
	if (get_philo_state(philosopher) == DEAD)
		return (1);
	change_philo_state(philosopher, SLEEPING);
	print_philo_action(philosopher, "is sleeping");
	sleep_for(data->sleep_time);
	return (0);
}