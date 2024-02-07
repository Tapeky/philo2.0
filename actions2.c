/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:30:15 by tsadouk           #+#    #+#             */
/*   Updated: 2024/02/07 15:53:56 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	take_forks(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&philo->left_fork[philo->id]);
	print_philo_action(philo, "has taken a fork");
	pthread_mutex_lock(&philo->right_fork[(philo->id + 1) % data->nb_philos]);
	print_philo_action(philo, "has taken a fork");
}

void	drop_forks(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_unlock(&philo->left_fork[philo->id]);
	pthread_mutex_unlock(&philo->right_fork[(philo->id + 1) % data->nb_philos]);
}
