#include <stdio.h>

int main()
{
    float a, b, result;
    char op;

    printf("Enter first number: ");
    scanf("%f", &a);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Enter second number: ");
    scanf("%f", &b);

    switch(op)
    {
        case '+':
            result = a + b;
            printf("Result = %.2f", result);
            break;

        case '-':
            result = a - b;
            printf("Result = %.2f", result);
            break;

        case '*':
            result = a * b;
            printf("Result = %.2f", result);
            break;

        case '/':
            if(b != 0)
            {
                result = a / b;
                printf("Result = %.2f", result);
            }
            else
            {
                printf("Cannot divide by zero");
            }
            break;

        default:
            printf("Invalid operator");
    }

    return 0;
}