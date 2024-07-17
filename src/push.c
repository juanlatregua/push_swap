/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:59:35 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/07/17 16:59:52 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*push: move the top element from src to dest*/
static void	push(t_stack	**src, t_stack	*dest)
{
	t_stack	*tmp;

	if(!*src)
		return (NULL);
	tmp = (*src)->next;
	((*src)->next) = *dest;
	*dest = *src;
	*src = tmp;
	
}

/*do_pa : pushes the top element of stack b to the top of stack a.
prints "pa"*/
void	do_pa(t_stack	**stack_a, t_stack	**stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pa\n");
}

/*do_pb: pushes the top elment of stac a to the topo of stack b.
prints "pb"*/
void	do_pb(t_stack	**stack_a, t_stack	**stack_b)
{
	push(stack_b, stack_a);
	ft_putstr("pb\n");
}