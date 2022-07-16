/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebigel <bebigel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:06:22 by alunard           #+#    #+#             */
/*   Updated: 2022/07/16 14:40:31 by bebigel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_args(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		return (0);
	if (ft_(argv[1]) != 4 * 3 - 1)
		return (0);
	i = 0;
	while (argv[1][i])
	{
		if (i % 2 == 0 && (argv[1][i] < '1' || argv[1][i] > '4'))
			return (0);
		else if (i % 2 == 1 && argv[1][i] != '\0')
			return (0);
		i++;
	}
	return (1);
}	

int	main(int argc, char **argv)
{
	int	**tab;
	int	j;

	if (!check_args(argc, argv))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	tab = init_tab(argv[1]);
	if (!tab)
		return (-1);
	if (ft_solve(tab, 0))
		ft_print_tab(tab);
	else
		write(2, "Error\n", 6);
	free(tab);
	return (0);
}
