#include <stdio.h>
int main() {
    float num1, num2;
    char symbol;
    scanf("%f%c%f", &num1, &symbol, &num2);
    switch (symbol) {
        case '+':
            printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 != 0) {
                printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
            } else {
                printf("Invalid Input.\n");
            }
            break;
        default:
            printf("Invalid Input.\n");
            break;
    }
    return 0;
}
