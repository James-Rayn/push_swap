#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
    int size;
    t_node *top;
} t_stack;

void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);
long    ft_atol(const char *str);
int     is_valid_int(char *str);
int     is_in_range(char *str);
int     has_duplicate(t_stack *s, int value);
t_stack *init_stack(void);
void    push(t_stack *stack, int value);
int     pop(t_stack *stack);
void    free_stack(t_stack *s);
int     find_max(t_stack *s);
int     find_pos(t_stack *s, int value);
void    push_max(t_stack *a, t_stack *b);
void    sort_simple(t_stack *a, t_stack *b);

#endif