#include "push_swap.h"

double  compute_disorder(t_stack *s)
{
    int     error;
    int     peer;
    t_node  *curr;
    t_node  *next;

    if (!s || !s-> top)
        return (0.0);
    curr = s-> top;
    error = 0;
    peer = 0;
    while (curr)
    {
        next = curr-> next;
        while (next)
        {
            if (curr-> value > next-> value)
                error++;
            peer++;
            next = next-> next;
        }
        curr = curr-> next;
    }
    if (peer == 0)
        return (0.0);
    return((double)error / peer);
}

void    sort_adaptive(t_stack *a, t_stack *b, t_bench *bench)
{
    double  disorder;

    if (!a || !a-> top || !b)
        return ;
    disorder = compute_disorder(a);
    if (disorder < 0.2)
        sort_simple(a, b, bench);
    else if (disorder < 0.5)
        sort_medium(a, b, bench);
    else
        sort_complex(a, b, bench);
}

int total_operation(t_bench *bench)
{
    if (!bench)
        return (0);
    return (bench-> sa + bench-> sb + bench-> ss +
            bench-> pa + bench-> pb + bench-> ra +
            bench-> rb + bench-> rr + bench-> rra +
            bench-> rrb + bench-> rrr);
}

void    print_bench_operation(t_bench *bench)
{
    ft_putstr_fd("sa: ", 2);
    ft_putnbr_fd(bench->sa, 2);
    ft_putstr_fd(" sb: ", 2);
    ft_putnbr_fd(bench->sb, 2);
    ft_putstr_fd(" ss: ", 2);
    ft_putnbr_fd(bench->ss, 2);
    ft_putstr_fd(" pa: ", 2);
    ft_putnbr_fd(bench->pa, 2);
    ft_putstr_fd(" pb: ", 2);
    ft_putnbr_fd(bench->pb, 2);
    ft_putstr_fd(" ra: ", 2);
    ft_putnbr_fd(bench->ra, 2);
    ft_putstr_fd(" rb: ", 2);
    ft_putnbr_fd(bench->rb, 2);
    ft_putstr_fd(" rr: ", 2);
    ft_putnbr_fd(bench->rr, 2);
    ft_putstr_fd(" rra: ", 2);
    ft_putnbr_fd(bench->rra, 2);
    ft_putstr_fd(" rrb: ", 2);
    ft_putnbr_fd(bench->rrb, 2);
    ft_putstr_fd(" rrr: ", 2);
    ft_putnbr_fd(bench->rrr, 2);
    ft_putstr_fd("\n", 2);
}

void    print_strategy_complexity(char *strategy, double disorder)
{
    if (ft_strcmp(strategy, "simple") == 0)
        ft_putstr_fd(" | O(n)", 2);
    else if (ft_strcmp(strategy, "medium") == 0)
        ft_putstr_fd(" | O(n sqrt n)", 2);
    else if (ft_strcmp(strategy, "complex") == 0)
        ft_putstr_fd(" | O(n log n)", 2);
    else
    {
        if (disorder < 0.2)
            ft_putstr_fd(" | O(n)", 2);
        else if (disorder < 0.5)
            ft_putstr_fd(" | O(n sqrt n)", 2);
        else
            ft_putstr_fd(" | O(n log n)", 2);
    }
}

void    print_bench(t_bench *bench, double disorder, char *strategy)
{
    ft_putstr_fd("disorder: ", 2);
    ft_putdouble_fd(disorder * 100, 2);
    write(2, "%\n", 2);
    ft_putstr_fd("strategy: ", 2);
    ft_putstr_fd(strategy, 2);
    print_strategy_complexity(strategy, disorder);
    write(2, "\n", 1);
    ft_putstr_fd("total_ops: ", 2);
    ft_putnbr_fd(total_operation(bench), 2);
    write(2, "\n",1);
    print_bench_operation(bench);
}
