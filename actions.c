/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:34:13 by tsadouk           #+#    #+#             */
/*   Updated: 2024/02/07 15:24:04 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_for(uint64_t time)
{
	uint64_t	start;

	start = get_time();
	while (get_time() < start + time)
		usleep(100);
}

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
	ft_usleep(get_sleep_time(data));
	return (0);
}

void	change_philo_state(t_philo *philosopher, t_state new_state)
{
	pthread_mutex_lock(&philosopher->mut_state);
	philosopher->state = new_state;
	pthread_mutex_unlock(&philosopher->mut_state);
}