/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:28:46 by tsadouk           #+#    #+#             */
/*   Updated: 2024/02/08 15:13:42 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	drop_left_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
}

void	drop_right_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
}

int	take_left_fork(t_philo *philo)
{
	if (is_philo_dead(philo) || get_philo_state(philo) == DEAD)
		return (1);
	pthread_mutex_lock(philo->left_fork);
	
	return (0);
}

int	take_right_fork(t_philo *philo)
{
	if (is_philo_dead(philo) || get_philo_state(philo) == DEAD)
		return (1);
	pthread_mutex_lock(philo->right_fork);
	print_philo_action(philo, "is taking fork");
	return (0);
}


int	take_forks(t_philo *philo)
{
	/*if (get_nb_philos(philo->data) == 1)
		return (handle_1_philo(philo));*/
	if (take_right_fork(philo) != 0)
		return (1);
	if (take_left_fork(philo) != 0)
	{
		drop_right_fork(philo);
		return (1);
	}
	return (0);
}


/*
int	handle_1_philo(t_philo *philo)
{

}
*/