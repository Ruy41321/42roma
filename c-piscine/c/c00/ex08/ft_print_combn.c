#include <unistd.h>

void    print_comb(int n, int *nums);
int has_repetition(int n, int *nums);

void ft_print_combn(int n)
{
    int digits[n];
    int i = 0;
    int val = 0;
    while(i < n)
    {
        digits[i] = val;
        //int j = i+1;
        while (//)
        {
             //
        }
        val++;
    }
}

void    print_comb(int n, int *nums)
{
    if (!has_repetition(n, nums))
    {
        int i = 0;
        while (i < n)
        {
            write(1, &(char)i+48, 1);
        }
    }
}

int has_repetition(int n, int *nums)
{
    int i = 0;
    while (i < n-1)
    {
        j = i+1;
        while (j < n)
        {
            if (nums[i] == nums[j])
                return 1;
        }
    }
    return 0;
}