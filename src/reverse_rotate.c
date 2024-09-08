/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:00:38 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/09/08 17:54:13 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*reverse&rotate: bring the botton to the top*/
static void	rev_rotate(t_stack	**stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

	if (!*stack || !(*stack)->next)
		return ;
	tail = get_stack_bottom(*stack);
	before_tail = get_stack_before_bottom(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

/*do_rra: brings the bottom element of stack a to the top
prints rra*/
void	do_rra(t_stack	**stack_a)
{
	rev_rotate(stack_a);
	ft_putstr("rra\n");
}

/*do_rrb: brings the bottom element of stack b to the top
prints rrb*/
void	do_rrb(t_stack	**stack_b)
{
	rev_rotate(stack_b);
	ft_putstr("rrb\n");
}

/*do_rrr: bring the bottom of both stacks to the top
prints both*/
void	do_rrr(t_stack	**stack_a, t_stack	**stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr("rrr\n");
}
