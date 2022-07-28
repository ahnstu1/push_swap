#include "push_swap.h"

void    sort_three(t_ps *stack)
{
    int fst;
    int snd;
    int trd;

    fst = stack -> num;
    snd = stack -> next -> num;
    trd = stack -> next -> next -> num;
    if (fst > snd && snd > trd && fst > trd)
    {
        swap(stack);
        reverse_rotate(stack);
    }
    else if (fst > snd && snd < trd && fst > trd)
        rotate(stack);
    else if (fst < snd && snd > trd && fst < trd)
    {
        swap(stack);
        rotate(stack);
    }
    else if (fst > snd && snd < trd && fst < trd)
        swap(stack);
    else
        reverse_rotate(stack);
}

