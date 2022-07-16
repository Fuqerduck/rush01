/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alunard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:31:21 by alunard           #+#    #+#             */
/*   Updated: 2022/07/16 16:21:15 by alunard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* this it to print the table*/
#include "ft.h"

void	ft_print_tab(int **tab)
{
	int	index;

	index = 0;
	while (index < 16)
	{
		ft_putchar(tab[index / 4 + 1][index % 4 + 1] + '0');
		if ((index + 1) % 4 == 0)
			ft_putchar('\n');
		else
			ft_putchar(' ');
		index++;
	}
]
