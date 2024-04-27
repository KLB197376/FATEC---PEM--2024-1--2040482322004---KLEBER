#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return 0;
    }
    return a / b;
}

int main() {
    int num1, num2, choice, result;
    char exit;

    do {
        printf("Enter two integers: ");
        scanf("%d %d", &num1, &num2);

        printf("Enter choice: 1.Addition 2.Subtraction 3.Multiplication 4.Division\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                result = add(num1, num2);
                printf("Result: %d\n", result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("Result: %d\n", result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("Result: %d\n", result);
                break;
            case 4:
                result = divide(num1, num2);
                printf("Result: %d\n", result);
                break;
            default:
                printf("Error! operator is not correct\n");
                break;
        }

        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &exit);

    } while(exit == 'y' || exit == 'Y');

    return 0;
}

