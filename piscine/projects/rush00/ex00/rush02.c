/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:20:56 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/09/08 16:45:47 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	error(int x, int y)
{
	if (x < 1 || y < 1)
	{
		write(1, "Error: Arguments must value more than 0.\n", 42);
	}
	ft_putchar('\n');
}

void	imprimircarateres(int x, char inicio, char meio, char fim)
{
	int	contadorcolunas;

	contadorcolunas = 1;
	while (contadorcolunas <= x)
	{
		if (contadorcolunas == 1)
		{
			ft_putchar(inicio);
		}
		else if (contadorcolunas == x)
		{
			ft_putchar(fim);
		}
		else
		{
			ft_putchar(meio);
		}
		contadorcolunas++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	contadorlinhas;

	error(x, y);
	if (x >= 1 && y >= 1)
	{
		contadorlinhas = 1;
		while (contadorlinhas <= y)
		{
			if (contadorlinhas == 1)
			{
				imprimircarateres(x, 'A', 'B', 'A');
			}
			else if (contadorlinhas == y)
			{
				imprimircarateres(x, 'C', 'B', 'C');
			}
			else
			{
				imprimircarateres(x, 'B', ' ', 'B');
			}
			contadorlinhas++;
		}
	}
}
