/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:38:19 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/21 18:56:06 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list	*lst_start; // pointer to the start of the list
    int		swap; // variable to store the value to be swapped

    if (!lst) // if the list is empty, return 0
        return (0);
    lst_start = lst; // set the start of the list to the beginning
    while (lst_start->next) // while the next element is not null
    {
        // if the comparison function returns 0
        if ((*cmp)(lst_start->data, lst_start->next->data) == 0)
        {
            swap = lst_start->data; // store the value of the current element
            lst_start->data = lst_start->next->data; // set the current element to the next element
            lst_start->next->data = swap; // set the next element to the stored value
            lst_start = lst; // set the start of the list to the beginning
        }
        else
            lst_start = lst_start->next; // move to the next element
    }
    lst = lst_start; // set the list to the start of the list
    return (lst); // return the sorted list
}