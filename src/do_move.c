/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:25:06 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/08/21 16:53:45 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*do_rev_rotate_both*/
static void	do_rev_rotate_both(t_stack	**a, t_stack	**b, int	*cost_a, int	*cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(a, b);
	}
}

/*do_rotate_both*/
static void	do_rotate_both(t_stack	**a, t_stack	**b, int	*cost_a, int	*cost_b)
{
	while (*cost_a > 0 && cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(a, b);
	}
}

/*do_rotate_a*/
static void	do_rotate_a(t_stack	**a, int	*cost_a)
{
	while (*cost_a)
	{
		if (*cost_a > 0)
		{
			do_ra(a);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
		{
			do_rra(a);
			(*cost_a)++
		}
	}
}

/*do_rotate_b*/
static void	do_rotate_b(t_stack	**b, int	*cost_b)
{
	while (*cost_b)
	{
		if (*cost_b > 0)
		{
			do_rb(b);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			do_rrb(b);
			(*cost_b)++;
		}
	}
}

/*do_move*/
void	do_move(t_stack	**a, t_stack	**b, int	*cost_a, int	*cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(a, b, &cost_a, &cost_b);
	do_rotate_a(a, &cost_a);
	do_rotate_b(b, &cost_b);
}
