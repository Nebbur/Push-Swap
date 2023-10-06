#include "push.h"

void ft_until_pivot(t_list **stack_a, t_list **stack_b, t_data *st)
{
    while (ft_smallest_number(*stack_a)->position < st->pivot)
    {
        if (st->pivot > (*stack_a)->position)
            pb(stack_b, stack_a);
        else if (ft_check_rb_rr(stack_a, stack_b) != 0)
            ra(stack_a, 1);

        if (ft_lstsize(*stack_b) > 5 && ((*stack_b)->position < st->pivot / 2))
        {
            if ((*stack_a)->position > st->pivot)
                rr(stack_a, stack_b);
            else
                rb(stack_b, 1);
        }
    }
}

static void ft_sort_a_(t_list **stack_a, t_list **stack_b, t_data *st)
{
    long content_to_change;
    int cont = 1;
    bool checker[2] = {false, false};

    if ((*stack_a)->position == ft_bigger_number(*stack_a)->position && ft_check_rb_rr(stack_a, stack_b) != 0)
        ra(stack_a, 1);

    while (!checker[0] && cont <= ft_lstsize(*stack_a) / 2)
    {
        if (ft_lstsorted_num(*stack_a, ++cont) != 0)
        {
            checker[0] = true;
            checker[1] = true;
        }
    }

    if (!checker[0])
    {
        cont = ft_lstsize(*stack_a);
        while (!checker[0])
        {
            if (ft_lstsorted_num(*stack_a, --cont) != 0)
                checker[0] = true;
        }
    }

    if (checker[1])
        content_to_change = ft_find_position(*stack_a, cont, st);
    else
        content_to_change = ft_find_position(*stack_a, cont, st);

    for (; (*stack_a)->next->position != st->aux_position; )
    {
        if ((*stack_a)->position == st->aux_position)
        {
            rra(stack_a, 1);
            break;
        }

        int dist = ft_lstdistance(stack_a, st->aux_position);

        if (dist <= ft_lstsize(*stack_a) / 2 && !((*stack_a)->position == st->aux_position))
        {
            if (ft_check_rb_rr(stack_a, stack_b) != 0)
                ra(stack_a, 1);
        }
        else if (ft_check_rrb_rrr(stack_a, stack_b) != 0)
        {
            rra(stack_a, 1);
        }

        if ((*stack_a)->position == st->aux_position && checker[1])
        {
            if (ft_check_sb_ss(stack_a, stack_b) != 0)
                sa(stack_a, 1);
        }
    }

    if (checker[1])
        cont = ft_lstsize(*stack_a) - cont;

    while (ft_lstsorted_num(*stack_a, cont) != 0)
    {
        if (ft_check_sb_ss(stack_a, stack_b) != 0)
            sa(stack_a, 1);

        if (ft_lstlast(*stack_a, 1, false)->position < (*stack_a)->position)
        {
            if (ft_check_rrb_rrr(stack_a, stack_b) != 0)
                rra(stack_a, 1);

            if (ft_check_sb_ss(stack_a, stack_b) != 0)
                sa(stack_a, 1);
        }

        ft_position_with_cont(stack_a, cont, st);
    }

    while (ft_lstsorted_num(*stack_a, 3) != 0)
        ft_sort_a_(stack_a, stack_b, st);
}

static void ft_sorted_a_aux_second(t_list **stack_a, t_list **stack_b, t_data *st)
{
    long bridge = ft_find_bridge_last_content(*stack_a, 1, st);
    
    // Verifique se o elemento desejado é o próximo
    while (bridge > 0 && (*stack_a)->next->position != bridge)
    {
        if (ft_check_rb_rr(stack_a, stack_b) != 0)
            ra(stack_a, 1);
        else
            rra(stack_a, 1); // Se não puder fazer ra, faça rra
    }

    st->count_max = 0;

    while (bridge > 0 && (*stack_a)->position != bridge - 1 && st->count_max != 1)
    {
        ra(stack_a, 1);

        if ((*stack_a)->position != bridge - 1)
        {
            sa(stack_a, 1);
        }

        ft_sorted_wrong(*stack_a, st);
    }

    ft_sorted_wrong(*stack_a, st);

    if (st->count_max == 1)
    {
        while (ft_lstsorted(*stack_a) != 0)
        {
            if (ft_lstdistance(stack_a, ft_smallest_number(*stack_a)->position) < ft_lstsize(*stack_a) / 2)
            {
                ra(stack_a, 1);
            }
            else
            {
                rra(stack_a, 1);
            }
        }
    }
}

static void ft_sort_third_a(t_list **stack_a, t_list **stack_b, t_data *st)
{
    int rotate_count = 0;

    while (ft_lstsorted_num(*stack_a, (ft_lstsize(*stack_a) / 3) * 2) != 0)
    {
        if (ft_check_rrb_rrr(stack_a, stack_b) != 0)
            rra(stack_a, 1);
        else
            ra(stack_a, 1); // Se não puder fazer rra, faça ra

        rotate_count++;

        if (rotate_count >= ft_lstsize(*stack_a))
            break; // Evite o loop infinito
    }
}

void ft_plusdecinq(t_list **stack_a, t_list **stack_b, t_data *st)
{
    for (int cont = 0; ft_lstsize(*stack_a) > 12; cont++)
    {
        ft_until_pivot(stack_a, stack_b, st);
        ft_sort_a_(stack_a, stack_b, st);
    }

    while (ft_lstsorted(*stack_a) != 0)
    {
        ft_sorted_a_aux_second(stack_a, stack_b, st);
    }

    while (ft_lstsorted(*stack_a) != 0)
    {
        if (ft_smallest_number(*stack_a)->position <= ft_lstsize(*stack_a) / 2)
        {
            if (ft_check_rb_rr(stack_a, stack_b) != 0)
            {
                ra(stack_a, 1);
            }
        }
        else
        {
            if (ft_check_rrb_rrr(stack_a, stack_b) != 0)
            {
                rra(stack_a, 1);
            }
        }
    }

    while (ft_lstsize(*stack_b) != 0)
    {
        if (ft_bigger_number(*stack_b)->position == (*stack_b)->position)
            pa(stack_a, stack_b);
        else
        {
            if (ft_bigger_number(*stack_b)->position <= (ft_lstsize(*stack_b) / 2) && ft_lstsize(*stack_b) % 2 == 0 ||
                ft_bigger_number(*stack_b)->position <= (ft_lstsize(*stack_b) / 2) - 0.5 && ft_lstsize(*stack_b) % 2 != 0)
                rrb(stack_b, 1);
            else
                rb(stack_b, 1);
        }
    }

    if (ft_lstsize(*stack_b) == 0 && ft_lstsorted_num(*stack_a, (ft_lstsize(*stack_a) / 3) * 2) == 0 && ft_lstsorted(*stack_a) != 0)
        ft_sort_third_a(stack_a, stack_b, st);
}
