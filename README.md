Organización del Proyecto push_swap
Para mantener el código organizado y fácil de mantener, es común dividir el proyecto en múltiples archivos. Esta estructura permite una mejor gestión de las dependencias, facilita la compilación modular y hace que el código sea más legible y mantenible.

Estructura de Directorios
La estructura típica del proyecto podría ser:

css
Copiar código
push_swap/
├── includes/
│   └── push_swap.h
├── src/
│   ├── initialization.c
│   ├── 
│   ├── input_check.c
│   ├── sorting_algorithms.c
│   ├── position.c
│   ├── cost.c
│   ├── calculate_move.c
│   ├── operations.c
│   ├── stack_functions.c
│   ├── utils.c
│   ├── error.c
│   └── main.c
└── Makefile
Descripción de los Archivos
includes/push_swap.h:

Contiene todas las declaraciones de funciones y la definición de la estructura t_stack.
Se incluye en todos los archivos .c para que puedan usar las funciones y estructuras declaradas en él.
src/initialization.c:

Implementa fill_stack_values y assign_index.
src/input_check.c:

Implementa is_correct_input, is_digit, is_sign y nbstr_cmp.
src/sorting_algorithms.c:

Implementa is_sorted, tiny_sort y sort.
src/position.c:

Implementa get_lowest_index_position y get_target_position.
src/cost.c:

Implementa get_cost y do_cheapest_move.
src/calculate_move.c:

Implementa do_move.
src/operations.c:

Implementa las operaciones do_pa, do_pb, do_sa, do_sb, do_ss, do_ra, do_rb, do_rr, do_rrr, do_rra y do_rrb.
src/stack_functions.c:

Implementa get_stack_bottom, get_stack_before_bottom, stack_new, stack_add_bottom y get_stack_size.
src/utils.c:

Implementa free_stack, ft_atoi, ft_putstr y nb_abs.
src/error.c:

Implementa exit_error.
src/main.c:

Contiene la función main que orquesta la ejecución del programa.
