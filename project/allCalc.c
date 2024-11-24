#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Define the value of Pi for trigonometric calculations
#define M_PI 3.14159

// Function prototypes for each calculator section
void standard();
void loga();
void matrix();
void trigo();
void pandc();
void inputInt(int *num);
void inputDouble(double *num);
double facto(int n);
void others();

int main(void)
{
    int calc;
    // Main loop to repeatedly show the calculator menu until the user exits

    do
    {
        // Display main menu
        printf("\n======================================\n");
        printf("        Welcome To All Calculator       ");
        printf("\n======================================\n");
        printf("Select Your Desired Calculator:\n");
        printf("1. Standard Calculator\n");
        printf("2. Logarithmic Calculator\n");
        printf("3. Matrix Calculator\n");
        printf("4. Trigonometric Calculator\n");
        printf("5. Permutation & Combination Calculator\n");
        printf("6. Other Calculators\n");
        printf("7. Exit Calculator\n");
        printf("======================================\n");
        printf("Enter the number of the calculator: ");

        inputInt(&calc); // Pass the address of calc
        // Exit option with confirmation
        if (calc == 7)
        {
            char exitConfirm;
            printf("\nAre you sure you want to exit? (y/n): ");
            scanf(" %c", &exitConfirm);
            if (exitConfirm == 'y' || exitConfirm == 'Y')
            {
                printf("\nThank you for using this Calculator!\n");
                break;
            }
            else
            {
                calc = 0; // Reset calc to keep the program running
            }
        }
        // Switch based on the user's selection
        switch (calc)
        {
            case 1:
                standard();
                break;
            case 2:
                loga();
                break;
            case 3:
                matrix();
                break;
            case 4:
                trigo();
                break;
            case 5:
                pandc();
                break;
            case 6:
                others();
                break;
            default:
                printf("\nInvalid selection. Please choose a number from 1 to 6.\n");
        }
    }
    while (1);
}

// Function to safely get an integer input with error checking
void inputInt(int *num)
{
    // int num;
    while (scanf("%d", num) != 1)
    {
        printf("Invalid input. Please enter a valid integer: ");
        while (getchar() != '\n')
            ; // Clear input buffer
    }
}

// Function to safely get a double input with error checking
void inputDouble(double *num)
{
    // double num;
    while (scanf("%lf", num) != 1)
    {
        printf("Invalid input. Please enter a valid number: ");
        while (getchar() != '\n')
            ; // Clear input buffer
    }
}

double facto(int n)
{
    if (n < 0)
    {
        printf("Error: Factorial is not defined for negative numbers.\n");
        return -1; // Error value
    }
    // tgamma returns the factorial result as a double
    return tgamma(n + 1); //returns factorial
}

// Standard calculator function (basic operations)
void standard()
{
    double num1, num2;
    char op;

    printf("\n--- Standard Calculator ---\n");
    // Loop to perform multiple operations until the user chooses to exit
    do
    {
        printf("\nChoose an operation (+, -, *, /, s for square root, q for square, c for "
               "cube, b for cube root, e to exit): ");
        scanf(" %c", &op);

        if (op == 'e')
        {
            printf("\nExiting Standard Calculator.\n");
            break;
        }

        else if (op != '+' && op != '-' && op != 's' && op != 'q' && op != 'c' && op != 'b' && op != '/')
        {
            printf("Invalid choice. Please enter 'n', 'l', 'c', or 'e'.\n");
            continue;
        }

        printf("\nEnter the first number: ");
        inputDouble(&num1);

        // Perform operation based on user's choice
        switch (op)
        {
            case 's':
                printf("\nSquare root of %.2lf = %.2lf\n", num1, sqrt(num1));
                break;
            case 'q':
                printf("\nSquare of %.2lf = %.2lf\n", num1, num1 * num1);
                break;
            case 'c':
                printf("\nCube of %.2lf = %.2lf\n", num1, num1 * num1 * num1);
                break;
            case 'b':
                printf("\nCube root of %.2lf = %.2lf\n", num1, cbrt(num1));
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                printf("\nEnter the second number: ");
                inputDouble(&num2); // Pass the address of num2
                if (op == '/' && num2 == 0)
                {
                    printf("\nError: Division by zero is not allowed.\n");
                }
                else
                {
                    double result = (op == '+')   ? (num1 + num2)
                                    : (op == '-') ? (num1 - num2)
                                    : (op == '*') ? (num1 * num2)
                                                  : (num1 / num2);
                    printf("\nResult: %.2lf %c %.2lf = %.2lf\n", num1, op, num2, result);
                }
                break;
            default:
                printf("\nError: Invalid operation.\n");
                break;
        }
    }
    while (1);

    return;
}
// Logarithmic calculator function
void loga()
{
    printf("\n--- Logarithmic Calculator ---\n");
    double num, base;
    char op;

    do
    {
        // Display options and prompt the user for a selection
        printf("\nChoose the type of logarithm operation:\n");
        printf("   n - Natural log (ln)\n");
        printf("   l - Logarithm base 10 (log10)\n");
        printf("   c - Custom base log\n");
        printf("   e - Exit the Logarithmic Calculator\n");
        printf("Enter your choice: ");
        scanf(" %c", &op);

        // Check for valid input
        if (op == 'e')
        {
            printf("\nThank you for using the Logarithmic Calculator!\n");
            break;
        }
        else if (op != 'n' && op != 'l' && op != 'c')
        {
            printf("Invalid choice. Please enter 'n', 'l', 'c', or 'e'.\n");
            continue;
        }

        // Prompt for the number to log, and validate it
        printf("Enter the number you want to find the log of (must be positive): ");
        inputDouble(&num); // Use pointer to get input

        if (num <= 0)
        {
            printf("Error: Logarithm is undefined for non-positive numbers.\n");
            continue; // Restart loop for a valid number
        }

        // Perform the chosen logarithmic operation
        switch (op)
        {
            case 'n':
                printf("Natural log (ln) of %.2lf = %.2lf\n", num, log(num));
                break;

            case 'l':
                printf("Logarithm base 10 (log10) of %.2lf = %.2lf\n", num, log10(num));
                break;

            case 'c':
                printf("Enter the base for the custom log (must be positive and not equal to 1): ");
                inputDouble(&base); // Use pointer for base input

                if (base <= 0 || base == 1)
                {
                    printf("Error: Base must be greater than 0 and not equal to 1.\n");
                    continue; // Restart for a valid base
                }
                printf("Logarithm of %.2lf with base %.2lf = %.2lf\n", num, base,
                       log(num) / log(base));
                break;

            default:
                printf("Invalid operation.\n");
                break;
        }
    }
    while (1);
}
// Matrix calculator function
void matrix()
{
    printf("\n--- Matrix Calculator ---\n");
    int a[100][100], b[100][100], c[100][100], d[100][100], i, j, n, m, p, q;
    char op, yn;

    do
    {
        // Input dimensions for matrix 1 with error checking
        do
        {
            printf("\nEnter number of rows and columns for Matrix 1 (format: rows columns): ");
            if (scanf("%d%d", &n, &m) != 2)
            {
                printf("Invalid input. Please enter two integers.\n");
                while (getchar() != '\n')
                    ; // Clear input buffer
            }
            else if (n <= 0 || m <= 0)
            {
                printf("Error: Dimensions must be positive integers.\n");
            }
        }
        while (n <= 0 || m <= 0);

        // Input dimensions for matrix 2 with error checking
        do
        {
            printf("Enter number of rows and columns for Matrix 2 (format: rows columns): ");
            if (scanf("%d%d", &p, &q) != 2)
            {
                printf("Invalid input. Please enter two integers.\n");
                while (getchar() != '\n')
                    ; // Clear input buffer
            }
            else if (p <= 0 || q <= 0)
            {
                printf("Error: Dimensions must be positive integers.\n");
            }
        }
        while (p <= 0 || q <= 0);

        // Input matrix elements with error checking
        printf("Enter elements of Matrix 1:\n");
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                while (1)
                {
                    printf("Element [%d][%d]: ", i + 1, j + 1);
                    if (scanf("%d", &a[i][j]) == 1)
                        break;
                    printf("Invalid input. Please enter an integer.\n");
                    while (getchar() != '\n')
                        ; // Clear input buffer
                }
            }
        }

        printf("Enter elements of Matrix 2:\n");
        for (i = 0; i < p; i++)
        {
            for (j = 0; j < q; j++)
            {
                while (1)
                {
                    printf("Element [%d][%d]: ", i + 1, j + 1);
                    if (scanf("%d", &b[i][j]) == 1)
                        break;
                    printf("Invalid input. Please enter an integer.\n");
                    while (getchar() != '\n')
                        ; // Clear input buffer
                }
            }
        }

        // Operation selection
        do
        {
            printf("\nSelect your operation:\n");
            printf("a - Addition\n");
            printf("s - Subtraction\n");
            printf("m - Multiplication\n");
            printf("i - Inverse (Matrix 1 only)\n");
            printf("Enter your choice: ");
            while (getchar() != '\n')
                ; // Clear input buffer
            scanf("%c", &op);
        }
        while (op != 'a' && op != 'm' && op != 's' && op != 'i');

        // Perform addition
        if (op == 'a')
        {
            if (n != p || m != q)
            {
                printf("Error: Matrices must be of the same dimensions for addition.\n");
            }
            else
            {
                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < m; j++)
                    {
                        c[i][j] = a[i][j] + b[i][j]; // Add corresponding elements
                    }
                }
                printf("Result of Matrix Addition:\n");
                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < m; j++)
                    {
                        printf("%4d ", c[i][j]); // Print the result
                    }
                    printf("\n");
                }
            }
        }

        // Perform subtraction
        if (op == 's')
        {
            if (n != p || m != q)
            {
                printf("Error: Matrices must be of the same dimensions for subtraction.\n");
            }
            else
            {
                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < m; j++)
                    {
                        c[i][j] = a[i][j] - b[i][j]; // Subtract corresponding elements
                    }
                }
                printf("Result of Matrix Subtraction:\n");
                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < m; j++)
                    {
                        printf("%4d ", c[i][j]); // Print the result
                    }
                    printf("\n");
                }
            }
        }

        // Perform multiplication
        if (op == 'm')
        {
            if (m != p)
            {
                printf("Error: Matrices cannot be multiplied (columns of first must equal rows of "
                       "second).\n");
            }
            else
            {
                // Initialize the result matrix to zero
                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < q; j++)
                    {
                        d[i][j] = 0; // Clear result matrix
                    }
                }

                // Perform multiplication
                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < q; j++)
                    {
                        for (int k = 0; k < m; k++)
                        {
                            d[i][j] += a[i][k] * b[k][j]; // Calculate the product
                        }
                    }
                }
                printf("Result of Matrix Multiplication:\n");
                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < q; j++)
                    {
                        printf("%4d ", d[i][j]); // Print the result
                    }
                    printf("\n");
                }
            }
        }

        // Perform inverse (only for 2x2 matrices)
        if (op == 'i')
        {
            if (n != 2 || m != 2)
            {
                printf("Error: Inverse can only be calculated for 2x2 matrices.\n");
            }
            else
            {
                int determinant = a[0][0] * a[1][1] - a[0][1] * a[1][0];
                if (determinant == 0)
                {
                    printf("Error: Matrix is singular and cannot be inverted.\n");
                }
                else
                {
                    float inverse[2][2];
                    inverse[0][0] = (float) a[1][1] / determinant;
                    inverse[0][1] = (float) -a[0][1] / determinant;
                    inverse[1][0] = (float) -a[1][0] / determinant;
                    inverse[1][1] = (float) a[0][0] / determinant;

                    printf("Inverse of Matrix 1:\n");
                    printf("%10.2f %10.2f\n", inverse[0][0], inverse[0][1]);
                    printf("%10.2f %10.2f\n", inverse[1][0], inverse[1][1]);
                }
            }
        }

        // Prompt user for continuation
        printf("\nDo you want to perform another operation? (y/n): ");
        while (getchar() != '\n')
            ; // Clear input buffer
        scanf("%c", &yn);
    }
    while (yn == 'y' || yn == 'Y');

    printf("Thank you for using the Matrix Calculator!\n");
}
// P&C calculator function
void pandc()
{
    printf("\n--- P&C Calculator ---\n");
    int n, r;
    unsigned long long permutation, combination;
    char op;
    double result;
    do
    {
        do
        {
            // Display options and prompt the user for a selection
            printf("\nChoose the type of operation:\n");
            printf("   f - factorial\n");
            printf("   p - nPr\n");
            printf("   c - nCr\n");
            printf("   e - Exit the Calculator\n");
            printf("Enter your choice: ");
            scanf(" %c", &op);
        }
        while (op != 'p' && op != 'c' && op != 'f' && op != 'e');
        if (op == 'e')
        {
            printf("exiting the calculator\n");
            break;
        }
        if (op == 'f')
        {
            printf("\nEnter n: ");
            inputInt(&n);
        }
        else
        {
            printf("\nEnter n: ");
            inputInt(&n); // Use pointer for n input
            printf("\nEnter r: ");
            inputInt(&r); // Use pointer for r input
            if (n < 0 || r < 0 || r > n)
            {
                printf("Invalid input: Ensure that n >= 0, r >= 0, and n >= r.\n");
                continue;
            }
        }
        switch (op)
        {
            case 'f':
                result = facto(n);
                if (result != -1)
                {
                    printf("Factorial of %d (using tgamma) is %.0f\n", n, result);
                }
                break;
            case 'p':
                permutation = facto(n) / facto(n - r);
                printf("%dP%d is %llu\n", n, r, permutation);
                break;
            case 'c':
                combination = facto(n) / (facto(r) * facto(n - r));
                printf("%dC%d is %llu\n", n, r, combination);
                break;
        }
    }
    while (op != 'e');
    return;
}
// Trigonometric calculator function
void trigo()
{
    printf("\n--- Trigonometric Calculator ---\n");
    double angle;
    char op;

    do
    {
        // Prompt the user for the trigonometric operation
        printf("\nChoose a trigonometric operation:\n");
        printf("   s - Sine (sin)\n");
        printf("   c - Cosine (cos)\n");
        printf("   t - Tangent (tan)\n");
        printf("   o - Hyperbolic Cosine (cosh)\n");
        printf("   i - Hyperbolic Sine (sinh)\n");
        printf("   a - Hyperbolic Tangent (tanh)\n");
        printf("   e - Exit the Trigonometric Calculator\n");
        printf("Enter your choice: ");
        scanf(" %c", &op);

        // Validate the input
        if (op == 'e')
        {
            printf("\nThank you for using the Trigonometric Calculator!\n");
            break;
        }
        else if (op != 's' && op != 'c' && op != 't' && op != 'o' && op != 'i' && op != 'a')
        {
            printf("Invalid choice. Please enter 's', 'c', 't', 'o', 'i', 'a', or 'e'.\n");
            continue;
        }

        // Get angle input and convert it to radians
        printf("Enter the angle in degrees: ");
        inputDouble(&angle); // Use pointer for angle input
        double radians = angle * M_PI / 180;

        // Perform the selected trigonometric calculation
        switch (op)
        {
            case 's':
                printf("sin(%.2lf degrees) = %.2lf\n", angle, sin(radians));
                break;

            case 'c':
                printf("cos(%.2lf degrees) = %.2lf\n", angle, cos(radians));
                break;

            case 't':
                printf("tan(%.2lf degrees) = %.2lf\n", angle, tan(radians));
                break;

            case 'o':
                printf("cosh(%.2lf degrees) = %.2lf\n", angle, cosh(radians));
                break;

            case 'i':
                printf("sinh(%.2lf degrees) = %.2lf\n", angle, sinh(radians));
                break;

            case 'a':
                printf("tanh(%.2lf degrees) = %.2lf\n", angle, tanh(radians));
                break;

            default:
                printf("Unexpected error.\n");
                break;
        }
    }
    while (1);
}
// Other calculator functions
void others()
{
    printf("\n--- Other Calculators ---\n");
    char op;
    int n;
    int *num, sum, choice;
    double c, f, b, h, side, length, breadth, radius, height;

    do
    {
        printf("\nChoose your desired operation\n");
        printf("   a   - Average\n");
        printf("   c   - Centigrade to Fahrenheit\n");
        printf("   t   - Triangle\n");
        printf("   s   - Square\n");
        printf("   r   - Rectangle\n");
        printf("   C(UpperCase)   - Circle\n");
        printf("   e   - Exit the Calculator\n");
        printf("Enter your choice: ");

        scanf(" %c", &op); // Space before %c helps skip leftover newlines

        if (op == 'e')
        {
            printf("\nThank you for using this calculator!\n");
            break;
        }
        else if (op != 'a' && op != 'c' && op != 't' && op != 's' && op != 'r' && op != 'C')
        {
            printf("Invalid choice. Please enter 'a', 'c', 't', 's', 'r', 'C', or 'e'.\n");
            continue;
        }

        switch (op)
        {
            case 'a':
                printf("How many numbers to average? ");
                inputInt(&n);
                if (n <= 0)
                {
                    printf("Invalid number of entries.\n");
                    continue;
                }

                num = (int *) malloc(n * sizeof(int));
                if (num == NULL)
                {
                    printf("Memory allocation error\n");
                    break;
                }

                sum = 0; // Reset sum each time for a fresh calculation

                for (int i = 0; i < n; i++)
                {
                    printf("Enter number %d: ", i + 1);
                    inputInt(&num[i]);
                    sum += num[i];
                }

                printf("The average is: %.2f\n", (double) sum / n);
                free(num); // Free memory after use
                break;

            case 'c':
                printf(
                    "Temperature Conversion:\n1.Celsius to Fahrenheit\n2.Fahrenheit to Celsius\n");
                printf("choice: ");
                inputInt(&choice);
                if (choice == 1)
                {
                    printf("Enter Temperature in Celsius: ");
                    inputDouble(&c);
                    printf("Fahrenheit Temperature: %.2lf\n", (1.8 * c) + 32.0);
                }
                else if (choice == 2)
                {
                    printf("Enter Temperature in Fahrenheit: ");
                    inputDouble(&f);
                    printf("Celsius Temperature: %.2lf\n", (f - 32) * 5 / 9);
                }
                else
                {
                    printf("Invalid choice\n");
                }
                break;
            // triangle
            case 't':
                printf("1. Area\n2. Perimeter\n");
                inputInt(&choice);
                if (choice == 1)
                {
                    printf("Enter Base and Height of the triangle: ");
                    inputDouble(&b);
                    inputDouble(&h);
                    printf("Area of the Triangle is %.2lf\n", 0.5 * b * h);
                }
                else if (choice == 2)
                {
                    printf("Enter the sides of the triangle: ");
                    inputDouble(&b);
                    inputDouble(&h);
                    inputDouble(&side);
                    printf("Perimeter of the Triangle is %.2lf\n", b + h + side);
                }
                else
                {
                    printf("Invalid choice\n");
                }
                break;
            // square
            case 's':
                printf("1. Area\n2. Perimeter\n3. Volume of cube\n");
                inputInt(&choice);
                printf("Enter Side of the square: ");
                inputDouble(&side);
                if (choice == 1)
                {
                    printf("Area of the Square is %.2lf\n", side * side);
                }
                else if (choice == 2)
                {
                    printf("Perimeter of the Square is %.2lf\n", 4 * side);
                }
                else if (choice == 3)
                {
                    printf("Volume of a cube is %.2lf\n", side * side * side);
                }
                else
                {
                    printf("Invalid choice\n");
                }
                break;
            // rectangle
            case 'r':
                printf("1. Area\n2. Perimeter\n3. Volume of a cuboid\n");
                inputInt(&choice);
                printf("Enter length and breadth of the rectangle: ");
                inputDouble(&length);
                inputDouble(&breadth);
                if (choice == 1)
                {
                    printf("Area of the Rectangle is %.2lf\n", length * breadth);
                }
                else if (choice == 2)
                {
                    printf("Perimeter of the Rectangle is %.2lf\n", 2 * (length + breadth));
                }
                else if (choice == 3)
                {
                    printf("Enter height of the cuboid: ");
                    inputDouble(&height);
                    printf("Volume of a cuboid is %.2lf\n", length * breadth * height);
                }
                else
                {
                    printf("Invalid choice\n");
                }
                break;
            // circle
            case 'C':
                printf("1. Area\n2. Perimeter\n3. volume of the Sphere\n");
                inputInt(&choice);
                printf("Enter the radius of the Circle: ");
                inputDouble(&radius);
                if (choice == 1)
                {
                    printf("Area of the Circle is %.2lf\n", M_PI * (radius * radius));
                }
                else if (choice == 2)
                {
                    printf("Perimeter of the Circle is %.2lf\n", 2 * M_PI * radius);
                }
                else if (choice == 3)
                {
                    printf("Volume of the sphere is %.2lf\n",
                           4 / 3 * M_PI * (radius * radius * radius));
                }
                else
                {
                    printf("Invalid choice\n");
                }
                break;
            default:
                printf("Option not implemented yet.\n");
                break;
        }
    }
    while (1);
}
