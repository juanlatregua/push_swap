/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:33:59 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/09/08 17:34:04 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value; // valor del nodo
	int				index; // índice del valor en la pila ordenada
	int				pos; // posición actual del nodo en la pila
	int				target_pos; // Posición objetivo en la pila ordenada
	int				cost_a; // costo de mover el nodo a la pila 'a'
	int				cost_b; // costo de mover el nodo a la pila 'b'
	struct s_stack	*next;
}	t_stack;

/* Initialization 
llena la pila con valores dados como argumentos y en la segunda función asigna
un índice a cada valor*/

t_stack		*fill_stack_values(int ac, char **av);
void		assign_index(t_stack *stack_a, int ac);

/* Input Check
1. Comprueba si el argumento es un número.
2. Comprueba si hay argumentos duplicados
3. Comprueba si el argunto es 0.
4. verfica si la entrada es correcta
*/

int			is_correct_input(char **av);
int			is_digit(char c);
int			is_sign(char c);
int			nbstr_cmp(const char *s1, const char *s2);

/* Sorting Algorithms
1. comprueba si la pila está ordenada
2. ordena pilas pequeñas con un mínimo de movimientos
3. ordenación principal */

int			is_sorted(t_stack *stack);
void		tiny_sort(t_stack **stack);
void		sort(t_stack **stack_a, t_stack **stack_b);

/* Position : 
1. Obtiene el nodo con el índice más bajo
2. calcula y asigna las posiciones objetivo para cada nodo en stack b */

int			get_lowest_index_position(t_stack **stack);
void		get_target_position(t_stack **stack_a, t_stack **stack_b);

/* Cost */

void		get_cost(t_stack **stack_a, t_stack **stack_b);
void		do_cheapest_move(t_stack **stack_a, t_stack **stack_b);

/* Move operations */

void		do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

/* Operations */

void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
void		do_sa(t_stack **stack_a);
void		do_sb(t_stack **stack_b);
void		do_ss(t_stack **stack_a, t_stack **stack_b);
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);
void		do_ra(t_stack **stack_a);
void		do_rb(t_stack **stack_b);
void		do_rr(t_stack **stack_a, t_stack **stack_b);

/* Stack Functions
1. obtiene el nodo infer */

t_stack		*get_stack_bottom(t_stack *stack);
t_stack		*get_stack_before_bottom(t_stack *stack);
t_stack		*stack_new(int value);
void		stack_add_bottom(t_stack	**stack, t_stack	*new);
int			get_stack_size(t_stack	*stack);

/* Utils */

void		free_stack(t_stack **stack);
long int	ft_atoi(const char *str);
void		ft_putstr(char *str);
int			nb_abs(int nb);

/* Error */

void		exit_error(t_stack **stack_a, t_stack **stack_b);

#endif
