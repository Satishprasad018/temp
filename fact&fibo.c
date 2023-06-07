#include <stdio.h>
#include<time.h>
void Clock()
{
    double time1, time_diff;
    int n;
    time1 = (double) clock();
    time1 = time1 / CLOCKS_PER_SEC;
    for (n=0; n<100000000; n++);
    time_diff = (((double) clock()) / CLOCKS_PER_SEC) - time1;
    printf("The elapsed time is %lf seconds\n", time_diff);
}
// Function to calculate the factorial of a number without tail recursion
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
    Clock();
}


// Function to calculate the factorial of a number with tail recursion
int factorial_tail(int n, int result) {
    if (n == 0 || n == 1) {
        return result;
    } else {
        return factorial_tail(n - 1, n * result);
    }
    Clock();
}


// Function to calculate the nth number in the Fibonacci sequence without tail recursion
int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
    Clock();
}


// Function to calculate the nth number in the Fibonacci sequence with tail recursion
int fibonacci_tail(int n, int a, int b) {
    if (n == 0) {
        return a;
    } else if (n == 1) {
        return b;
    } else {
        return fibonacci_tail(n - 1, b, a + b);
    }
    Clock();
}
int main() {
    int choice, num;


    do {
        printf("\n1. Factorial without tail recursion");
        printf("\n2. Factorial with tail recursion");
        printf("\n3. Fibonacci without tail recursion");
        printf("\n4. Fibonacci with tail recursion");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
                printf("\nEnter a number: ");
                scanf("%d", &num);
                printf("Factorial of %d = %d\n", num, factorial(num));
                Clock();
                break;


            case 2:
                printf("\nEnter a number: ");
                scanf("%d", &num);
                printf("Factorial of %d = %d\n", num, factorial_tail(num, 1));
                Clock();
                break;


            case 3:
                printf("\nEnter a number: ");
                scanf("%d", &num);
                printf("Fibonacci sequence up to %d:\n", num);
                for (int i = 0; i <= num; i++) {
                    printf("%d ", fibonacci(i));
                }
                printf("\n");
                Clock();
                break;


            case 4:
                printf("\nEnter a number: ");
                scanf("%d", &num);
                printf("Fibonacci sequence up to %d:\n", num);
                for (int i = 0; i <= num; i++) {
                    printf("%d ", fibonacci_tail(i, 0, 1));
                }
                printf("\n");
                Clock();
                break;


            case 5:
                printf("Exiting program...\n");
                break;


            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 5);


    return 0;
}
