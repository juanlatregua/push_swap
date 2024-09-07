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

static int	arg_is_number(char	*av);
static int	have_duplicates(char	**av);
static int	arg_is_zero(char	*av);
int			is_correct_input(char **av);

/* Input Check_utils 
1. Comprueba que es un dígito
2. Comprueba el signo
3. Compara dos cadenas*/

int			is_digit(char c);
int			is_sign(char c);
int			nbstr_cmp(const char *s1, const char *s2);

/* Sorting Algorithms
1. comprueba si la pila está ordenada
2. ordena pilas pequeñas con un mínimo de movimientos
3. ordenación principal */

static int	find_highest_index(t_stack	*stack);
void		tiny_sort(t_stack **stack);
static void	push_all_save_three(t_stack	**stack_a, t_stack	**stack_b);
static void	shift_stack(t_stack	**stack_a);
void		sort(t_stack **stack_a, t_stack **stack_b);

/*Main*/

int			is_sorted(t_stack *stack);
static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)

/* Position : 
1. Obtiene el nodo con el índice más bajo
2. calcula y asigna las posiciones objetivo para cada nodo en stack b */

static void	get_position(t_stack	**stack);
int			get_lowest_index_position(t_stack **stack);
static int	get_target(t_stack	**a,  int	b_idx, int	target_idx, int	target_pos)
void		get_target_position(t_stack **stack_a, t_stack **stack_b);

/* Cost */

void		get_cost(t_stack **stack_a, t_stack **stack_b);
void		do_cheapest_move(t_stack **stack_a, t_stack **stack_b);

/* Move operations */

void		do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
void		do_rev_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void		do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void		do_rotate_a(t_stack **a, int *cost_a);
void		do_rotate_b(t_stack **b, int *cost_b);

/* Operations */
/* push */

static void	push(t_stack	**src, t_stack	**dest);
void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);

/*swap*/

static void	swap(t_stack	*stack);
void		do_sa(t_stack **stack_a);
void		do_sb(t_stack **stack_b);
void		do_ss(t_stack **stack_a, t_stack **stack_b);

/*Reverse_rotate*/

static void	rev_rotate(t_stack	**stack);
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);

/*rotate*/

static void	rotate(t_stack	*stack)
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
