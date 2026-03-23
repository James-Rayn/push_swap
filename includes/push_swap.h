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

typedef struct s_bench
{
    int sa;
    int sb;
    int ss;
    int pa;
    int pb;
    int ra;
    int rb;
    int rr;
    int rra;
    int rrb;
    int rrr;
}   t_bench;

void    sa(t_stack *a, t_bench *bench);
void    sb(t_stack *b, t_bench *bench);
void    ss(t_stack *a, t_stack *b, t_bench *bench);
void    pa(t_stack *a, t_stack *b, t_bench *bench);
void    pb(t_stack *a, t_stack *b, t_bench *bench);
void    ra(t_stack *a, t_bench *bench);
void    rb(t_stack *b, t_bench *bench);
void    rr(t_stack *a, t_stack *b, t_bench *bench);
void    rra(t_stack *a, t_bench *bench);
void    rrb(t_stack *b, t_bench *bench);
void    rrr(t_stack *a, t_stack *b, t_bench *bench);
long    ft_atol(const char *str);
int     ft_sqrt(int n);
int     ft_strcmp(char *s1, char *s2);
void    ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
void    ft_putdouble_fd(double n, int fd);
int     is_valid_int(char *str);
int     is_in_range(char *str);
int     has_duplicate(t_stack *s, int value);
t_stack *init_stack(void);
void    push(t_stack *stack, int value);
int     pop(t_stack *stack);
void    free_stack(t_stack *s);
int     find_max(t_stack *s);
int     find_pos(t_stack *s, int value);
void    push_max(t_stack *a, t_stack *b, t_bench *bench);
void    sort_simple(t_stack *a, t_stack *b, t_bench *bench);
void    sort_medium(t_stack *a, t_stack *b, t_bench *bench);
void    sort_complex(t_stack *a, t_stack *b, t_bench *bench);
void    sort_adaptive(t_stack *a, t_stack *b, t_bench *bench);
void    normalize(t_stack *s);
void    init_bench(t_bench *bench);
double  compute_disorder(t_stack *s);
void    print_bench(t_bench *bench, double disorder, char *strategy);

#endif