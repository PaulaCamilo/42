/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:01:35 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/19 11:09:07 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_rrange(int start, int end)
{
	int *range;
	int i = 0;
	int len = end - start;
	int step = 1;

	if (len < 0)
		len *= -1;
	len++;
	range = (int *)malloc(sizeof(int) * len);
	if (range)
	{
		if (start < end)
			step *= -1;
		while (i < len)
		{
			range[i] = end;
			end = end + step;
			i++;
		}
	}
	return (range);
}

#include <stdio.h>

int main(int argc, char **argv)
{
	int *arr;
	int arrlen;
	int min = 0;
	int max = 0;
	int i = 0;
	
	if (argc == 3)
	{
		min = atoi(argv[1]);
		max = atoi(argv[2]);
		arr = ft_rrange(min, max);
		if (!arr)
			return (1);
		printf("min = %d\nmax = %d\n", min, max);

		arrlen = 0;
		if (min <= max)
		{
			while (min <= max)
			{
				++arrlen;
				++min;
			}
		}
		else
		{
			while (min >= max)
			{
				++arrlen;
				--min;
			}
		}
		i = 0;
		while (i < arrlen)
		{
			printf("%d ", arr[i]);
			++i;
		}
		printf("\n");
	}
	else
		printf("Usage: %s min max\n", argv[0]);
	return (0);
}