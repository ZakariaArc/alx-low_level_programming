#include <stdio.h>
/**
 * custom_sqrt - custom square root function to find integer square root
 * @n: input number
 * Return: integer square root of n
 */
long int custom_sqrt(long int n) {
    long int x = n;
    long int y = (x + 1) / 2;

    while (y < x) {
        x = y;
        y = (x + n / x) / 2;
    }

    return x;
}

/**
 * main - finds and prints the largest prime factors of 612852475143
 * Return: 0 (success)
 */
int main(void) {
    long int n;
    long int max;
    long int i;

    n = 612852475143;
    max = -1;

    while (n % 2 == 0) {
        max = 2;
        n /= 2;
    }

    for (i = 3; i <= custom_sqrt(n); i = i + 2) {
        while (n % i == 0) {
            max = i;
            n = n / i;
        }
    }

    if (n > 2)
        max = n;

    printf("%ld\n", max);

    return 0;
}

