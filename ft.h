/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alunard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:33:05 by alunard           #+#    #+#             */
/*   Updated: 2022/07/16 13:33:31 by alunard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* this is just as a general repo for all the short functions*/
#ifndef FT_H
# define FT_H
#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str);
int	ft_solve(int **tab, int index);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int	ft_print_tab(int **tab);
int	init_borders(int **tab, char *str);
int	**init_tab(char *str);

#endif
