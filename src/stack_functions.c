/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:53:19 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/09/07 13:16:18 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* get_stack_bottom: return the last element of the stack*/
t_stack	*get_stack_bottom(t_stack	*stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/* get_stack_before_bottom: return the last before element of the stack*/
t_stack	*get_stack_before_bottom(t_stack	*stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return(stack);
}

/*stack_new : create a new stack elemets whith the value. 
return the new stack whith the new stack element*/
t_stack	*stack_new(int	value)
{
	t_stack	*new;
	
	new = malloc(sizeof	*new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return(new);
}

/*stack_add_bottom: add a element to the bottom of the stack */
void	stack_add_bottom(t_stack	**stack, t_stack	*new)
{
	t_stack	*tail;

	if (!stack || !new)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	tail = get_stack_bottom(*stack);
	tail->next = new;

}

/*get_stack_size: return the number of elements of the stack*/
int	get_stack_size(t_stack	*stack)
{
	int	size;
	
	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}