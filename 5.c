#include <stdio.h>
#include <stdlib.h>

struct complex {
    int real, img;
};

int main() {
    int choice, x, y, z;
    struct complex a, b, c;

    while (1) {
        printf("Press 1 to add two complex numbers.\n");
        printf("Press 2 to subtract two complex numbers.\n");
        printf("Press 3 to multiply two complex numbers.\n");
        printf("Press 4 to divide two complex numbers.\n");
        printf("Press 5 to exit.\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        if (choice == 5) {
            exit(0);
        }

        if (choice >= 1 && choice <= 4) {
            printf("Enter a and b where a + ib is the first complex number.\n");
            printf("\na = ");
            scanf("%d", &a.real);
            printf("b = ");
            scanf("%d", &a.img);

            printf("Enter c and d where c + id is the second complex number.\n");
            printf("\nc = ");
            scanf("%d", &b.real);
            printf("d = ");
            scanf("%d", &b.img);
        }

        if (choice == 1) {
            // Addition of two complex numbers
            c.real = a.real + b.real;
            c.img = a.img + b.img;
            if (c.img >= 0)
                printf("Sum of the complex numbers = %d + %di\n", c.real, c.img);
            else
                printf("Sum of the complex numbers = %d %di\n", c.real, c.img);
        } else if (choice == 2) {
            // Subtraction of two complex numbers
            c.real = a.real - b.real;
            c.img = a.img - b.img;
            if (c.img >= 0)
                printf("Difference of the complex numbers = %d + %di\n", c.real, c.img);
            else
                printf("Difference of the complex numbers = %d %di\n", c.real, c.img);
        } else if (choice == 3) {
            // Multiplication of two complex numbers
            c.real = a.real * b.real - a.img * b.img;
            c.img = a.real * b.img + a.img * b.real;
            if (c.img >= 0)
                printf("Multiplication of the complex numbers = %d + %di\n", c.real, c.img);
            else
                printf("Multiplication of the complex numbers = %d %di\n", c.real, c.img);
        } else if (choice == 4) {
            // Division of two complex numbers
            if (b.real == 0 && b.img == 0) {
                printf("Division by 0 + 0i isn't allowed.\n");
            } else {
                x = a.real * b.real + a.img * b.img;
                y = a.img * b.real - a.real * b.img;
                z = b.real * b.real + b.img * b.img;
                c.real = x / z;
                c.img = y / z;
                if (c.img >= 0)
                    printf("Division of the complex numbers = %d + %di\n", c.real, c.img);
                else
                    printf("Division of the complex numbers = %d %di\n", c.real, c.img);
            }
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
