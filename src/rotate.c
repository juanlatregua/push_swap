/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:57:34 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/09/07 13:26:47 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*rotate: the top element of the stack is sent to the bottom
manejando el erro de pilas con 0 o 1 elemento*/
static void	rotate(t_stack	**stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	if (!stack || !(*stack) || !((*stack)->next))
	return ;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_stack_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
	
}

/*do_ra: sends the top element of stack a to the bottom. 
printsd ra.*/
void	do_ra(t_stack	**stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

/*do_rb: sends the top element of stack b to the bottom.
prints rb. */
void	do_rb(t_stack	**stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
	
}

/*do_rr: sends the top element of both stacks a-b to the bottom.
prints rb.*/
void	do_rr(t_stack	**stack_a, t_stack	**stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}

/**/