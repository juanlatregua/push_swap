/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:22:01 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/09/07 09:39:32 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* free_stack: frees each element in a given stack 
	and set the stack pointer to NULL*/
void	free_stack(t_stack	**stack)
{
	t_stack	*tmp;
	
	if (!stack || !(*stack))
		return;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
/* ft_atoi: converts alphanumeric string of chars int a long int*/
long int	ft_atoi(const char	*str)
{
	long int	nb;
	int	isneg;
	int	i;

	nb = 0;
	isneg = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg = -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * isneg);
}
/* ft_putstr: prints a given strint of chars to the standard output*/
void	ft_putstr(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	
}
/* nb_abs: return the absolute value of a given numb.
	the ab nb is used to mesure the distance from 0 of the numb. 
	- or +, ex: for -6 is 6*/
int	nb_abs(int	nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}