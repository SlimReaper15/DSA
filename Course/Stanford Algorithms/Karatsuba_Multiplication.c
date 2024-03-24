#include <math.h>
#include <stdio.h>

int karatsuba(int x, int  y) {
    if (x < 10 || y < 10)
        return x * y;

    int max = (x > y) ? x : y;
    int dig = (int)log10(max) + 1; // Number of digits in the bigger number
    int exp = pow(10, dig / 2);

    int a = x / exp;
    int b = x % exp;
    int c = y / exp;
    int d = y % exp;

    int ac = karatsuba(a, c);
    int bd = karatsuba(b, d);
    int adbc = karatsuba(a + b, c + d) - ac - bd;

    int res = ac * exp * exp + adbc * exp + bd;

    return res;
}

int main() {
    printf("Enter the two numbers to be multiplied:\n");
    int x, y;
    scanf("%d %d", &x, &y);

    printf("The product of %d and %d is %d\n", x, y, karatsuba(x, y));
}