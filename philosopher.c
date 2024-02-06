/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:30:28 by tsadouk           #+#    #+#             */
/*   Updated: 2024/02/06 10:16:19 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_args(char **argv)
{
    printf("\033[0;33mnumbers of philosophers 😊: %d\033[0m\n", ft_atoi(argv[1])); // Marron pour "numbers of philosophers"
    printf("\033[1;31mtime to die ☠️⏰: %d\033[0m\n", ft_atoi(argv[2])); // Ajout de ☠️ à côté de "die" en rouge
    printf("\033[1;32mtime to eat 🍴 > %d\033[0m\n", ft_atoi(argv[3])); // Affichage de 🍴 suivi de ">" en vert
    printf("\033[1;34mtime to sleep 😴: %d\033[0m\n", ft_atoi(argv[4])); // Bleu clair pour "sleep"
	if (argv[5] != NULL)
    	printf("\033[0;33mnumber of times each philosopher must eat 🍕: %d\033[0m\n", ft_atoi(argv[5]));// Marron pour "number of times each philosopher must eat"
	else
		printf("\033[0;33mnumber of times each philosopher must eat 🍕: ∞\033[0m\n");
}

int	main(int argc, char **argv)
{
	if (errors_handeler(argc, argv))
		return (1);

	print_args(argv);


	return (0);
}