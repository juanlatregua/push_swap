/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:58:33 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/09/07 10:21:14 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* swap: the 2 element of a stack. Do nothing if there is only
one or no elements*/
static void	swap(t_stack	*stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack ->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

/*do_sa: swaps the top 2 elements of stack a.
Prints "sa"*/
void	do_sa(t_stack	**stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

/*do_sb: swap the top 2 elements of stack b. 
Prints "sb"*/
void	do_sb(t_stack	**stackb)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

/*do_ss: swap the top 2 elements of stack a and the top 2 elements
of stack b. */
void	do_ss(t_stack	**stack_a, t_stack	**stack_b)
{
	swap(*stack_a);
	swap(*stack_a);
	ft_putstr("ss\n");
}