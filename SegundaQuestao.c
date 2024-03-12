#include <stdio.h>

void
clear_buffer(void)
{
    while (getchar() != '\n');
}

void
check_in_fibonacci(int value)
{
    int current = 0, sum = 0, next = 1;
    printf("Value: %d\nSequence: ", value);
    while (current <= value)
    {
        printf("%d ", current);
        if (current == value)
        {
            printf("\nThe value was found on Fibonacci's sequence!\n");
            return;
        }
        sum = current + next;
        current = next;
        next = sum;
    }
    printf("\nThe value wasn't found on Fibonacci's sequence! Try another one!\n");
}

int
main(void)
{
    int number = -1;
    do
    {
        printf("Type a non-negative number:\n");
        scanf("%d", &number);
        clear_buffer();
        if (number == -1) printf("Try again!\n");
    } while (1);
    check_in_fibonacci(number);
    return 0;
}