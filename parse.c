/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:30:40 by tsadouk           #+#    #+#             */
/*   Updated: 2024/02/06 12:26:41 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	nb;

	i = 0;
	neg = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * neg);
}

int	errors_handeler(int argc, char **argv)
{
	if (argc != 6 && argc != 5)
	{
		printf("\033[1;31mError: wrong number of arguments\033[0m\n");
		return (1);
	}
	if (ft_atoi(argv[1]) < 2)
	{
		printf("\033[1;31mError: wrong number of philosophers\033[0m\n");
		return (1);
	}
	if (ft_atoi(argv[2]) < 60)
	{
		printf("\033[1;31mError: wrong time to die\033[0m\n");
		return (1);
	}
	if (ft_atoi(argv[3]) < 60)
	{
		printf("\033[1;31mError: wrong time to eat\033[0m\n");
		return (1);
	}
	if (ft_atoi(argv[4]) < 60)
	{
		printf("\033[1;31mError: wrong time to sleep\033[0m\n");
		return (1);
	}
	if (argc == 6 && ft_atoi(argv[5]) < 1)
	{
		printf("\033[1;31mError: wrong number of meals\033[0m\n");
		return (1);
	}
	if (is_input_valid(argv))
		return (1);
	return (0);
}

int	is_input_valid(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
			{
				printf("\033[1;31mError: wrong input\033[0m\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}