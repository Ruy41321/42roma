#include <unistd.h>
int main()
{
    int tab[7] = {8,4,5,2,8,5,9};
    
    ft_sort_int_tab(&tab, 7);
    int i = 0;
    char c;
    while(i < 7)
    {
        c = tab[i++] +48;
        write(1, &c, 1);
    }
}