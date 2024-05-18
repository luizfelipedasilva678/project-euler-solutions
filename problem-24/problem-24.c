#include <stdio.h>

#define N 10

int numbers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void swap(int *const arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void print_array(int *const arr, int length)
{
    size_t i;

    for (i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    puts("");
}

void reverse(int start, int end)
{
    while (start < end)
    {
        swap(numbers, start++, end--);
    }
}

void permute(int *const arr)
{
    int i, j;

    i = N - 2;
    while (i >= 0 && numbers[i + 1] < numbers[i])
    {
        i--;
    }

    if (i < 0)
        return;

    j = N - 1;
    while (j >= 0 && numbers[j] < numbers[i])
    {
        j--;
    }

    swap(numbers, i, j);
    reverse(i + 1, N - 1);
}

int main(void)
{

    size_t i;

    for (i = 0; i < 1000000; i++)
    {
        print_array(numbers, N);
        permute(numbers);
    }

    return 0;
}