#include <stdio.h>
#include <math.h>
#include <time.h>

double powerFunction(double base, int exponent);

double powerFunction(double base, int exponent) {
    double result = 1.0;
    int absExponent = (exponent < 0) ? -exponent : exponent; // Convert to positive for iteration

    // Compute power using simple loops
    for (int i = 0; i < absExponent; i++) {
        result *= base;
    }
    
    // Handle negative exponent
    return (exponent < 0) ? (1.0 / result) : result;
}

int main() {
    int choice;

    // Display a welcome message
    printf("\n--------------------------------------------------------------------------------\n\n");
    printf("                    WELCOME TO THE SCIENTIFIC CALCULATOR            \n");
    printf("\n--------------------------------------------------------------------------------\n\n");
    printf("This calculator provides advanced mathematical operations.\n");
    printf("Simply enter the number corresponding to your desired function.\n\n");

    while (1) {           
        // Display Menu
        printf("            --------------------------------------------------              \n");
        printf("                               MAIN MENU                       \n");
        printf("            --------------------------------------------------               \n");
        printf("1. Exponentiation (x^y)  - Compute the power of a number\n");
        printf("2. Square Root (√x)      - Calculate the square root\n");
        printf("3. Natural Logarithm     - Compute ln(x)\n");
        printf("4. Sine Function         - Compute sin(x) (in radians)\n");
        printf("5. Cosine Function       - Compute cos(x) (in radians)\n");
        printf("6. Tangent Function      - Compute tan(x) (in radians)\n");
        printf("7. Factorial (n!)        - Compute the factorial of a number\n");
        printf("8. Exit                  - Close the calculator\n");
        printf("\n--------------------------------------------------------------------------------\n");
        
        // Prompt for user input
        printf("\n👉 Please enter your choice (1-8): ");
        
        // Check if input is a valid integer (character, letter, symbols etc are not valid here)
        if (scanf("%d", &choice) != 1) {
            printf("\nError: Invalid input! Please enter a valid number between 1 and 8.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        // Check if choice is within range
        if (choice < 1 || choice > 8) {
            printf("\n❌ Error: Invalid choice!!! Please enter a number between 1 and 8.\n");
            continue;
        }

        // Exit condition
        if (choice == 8) {
            printf("\n✅ Exiting the scientific calculator. Thank you for using it! Have a great day!\n");
            printf("\n--------------------------------------------------------------------------------\n\n");
            break; // Exit the loop and end the program
        }

        // Process user choice
        printf("\n--------------------------------------------------------------------------------\n");
        switch (choice) {
            case 1: {
                printf("\n📌 You selected: Exponentiation (x^y)\n");

                double base, userResult, builtInResult, userTime, builtInTime, accuracyDiff;
                int exponent;
                clock_t start, end;

                // Input validation for base
                printf("\n👉 Enter base (a valid number): ");
                while (scanf("%lf", &base) != 1) {
                    printf("\n❌ Invalid input! Enter a valid number for base: ");
                    while (getchar() != '\n'); // Clear buffer
                }

                // Input validation for exponent
                printf("\n👉 Enter exponent (an integer): ");
                while (scanf("%d", &exponent) != 1) {
                    printf("\n❌ Invalid input! Enter a valid integer for exponent: ");
                    while (getchar() != '\n'); // Clear buffer
                }

                // Measure execution time for user-defined power function
                start = clock();
                userResult = powerFunction(base, exponent);
                end = clock();
                userTime = ((double)(end - start)) / CLOCKS_PER_SEC;

                // Measure execution time for built-in pow() function
                start = clock();
                builtInResult = pow(base, exponent);
                end = clock();
                builtInTime = ((double)(end - start)) / CLOCKS_PER_SEC;

                // Compute accuracy difference
                accuracyDiff = fabs(userResult - builtInResult);

                // Display results
                printf("\n📌 Calculation Results:\n");
                printf("------------------------\n");
                printf("🔹 User-defined power function result: %.10lf\n", userResult);
                printf("🔹 Built-in pow() function result: %.10lf\n", builtInResult);
                printf("🔹 Accuracy Difference: %.10e\n", accuracyDiff); // Scientific notation for small differences

                printf("\n⏳ Execution Time:\n");
                printf("------------------------\n");
                printf("🔹 User-defined power function: %.10lf seconds\n", userTime);
                printf("🔹 Built-in pow() function: %.10lf seconds\n", builtInTime);
                break;
            }
        }
        printf("\n--------------------------------------------------------------------------------\n\n");
    }
    void powerFunction() {
        double base, userResult = 1, builtInResult, userTime, builtInTime, accuracyDiff;
        int exponent, absExponent;
        clock_t start, end;
    
            // Input validation
        printf("\n👉 Enter base (a valid number): ");
        while (scanf("%lf", &base) != 1) {
        printf("\nInvalid input! Enter a valid number for base: ");
        while (getchar() != '\n');
        }
    
        printf("\n👉 Enter exponent (an integer): ");
        while (scanf("%d", &exponent) != 1) {
            printf("\nInvalid input! Enter a valid integer for exponent: ");
            while (getchar() != '\n');
        }
    
        absExponent = (exponent < 0) ? -exponent : exponent; // Handling negative exponent
    
        // Handling exponent = 0 case separately (anything raised to power 0 is 1)
        // if (exponent == 0) {
        //     userResult = 1;
        // } else {
            // Measure execution time for user-defined power function
            start = clock();
            for (int i = 0; i < absExponent; i++) {
                userResult *= base;
            }
            userResult = (exponent < 0) ? (1.0 / userResult) : userResult;
            end = clock();
            userTime = ((double)(end - start)) / CLOCKS_PER_SEC;
        // }
    
        // Measure execution time for built-in pow function
        start = clock();
        builtInResult = pow(base, exponent);
        end = clock();
        builtInTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    
        // Compute accuracy difference
        accuracyDiff = fabs(userResult - builtInResult);
    
        // Display results
        printf("\n📌 Calculation Results:\n");
        printf("------------------------\n");
        printf("🔹 User-defined power function result: %lf\n", userResult);
        printf("🔹 Built-in pow() function result: %lf\n", builtInResult);
        printf("🔹 Accuracy Difference: %lf\n", accuracyDiff);
    
        printf("\n⏳ Execution Time:\n");
        printf("------------------------\n");
        printf("🔹 User-defined power function: %lf seconds\n", userTime);
        printf("🔹 Built-in pow() function: %lf seconds\n", builtInTime);
    
    }

    void factorialFunction() {
        int number;
        unsigned long long fact = 1;
        double userTime;
        clock_t start, end;
    
        // Input validation
        printf("\n👉 Enter a non-negative integer for factorial: ");
        while (scanf("%d", &number) != 1 || number < 0) {
            printf("\n❌ Invalid input! Please enter a valid **non-negative** integer: ");
            while (getchar() != '\n'); // Clear input buffer
        }
    
        // Measure execution time & compute factorial
        start = clock();
        for (int i = 1; i <= number; i++) {
            fact *= i;
        }
        end = clock();
        userTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    
        // Display results
        printf("\n📌 Calculation Results:\n");
        printf("------------------------\n");
        printf("🔹 Factorial of %d: %llu\n", number, fact);
        printf("\n⏳ Execution Time:\n");
        printf("------------------------\n");
        printf("🔹 Execution time: %lf seconds\n", userTime);
    }

    void sineFunction() {
        double angle, userResult = 0.0, builtInResult, accuracyDiff, userTime, builtInTime;
        clock_t start, end;
        int terms = 10;  // Number of terms in Maclaurin series
    
        // Input validation
        printf("\n👉 Enter an angle in radians: ");
        while (scanf("%lf", &angle) != 1) {
            printf("\n❌ Invalid input! Please enter a valid number: ");
            while (getchar() != '\n'); // Clear input buffer
        }
    
        // Measure execution time for user-defined sine function
        start = clock();
        for (int i = 0; i < terms; i++) {
            int exponent = 2 * i + 1;
            double term = powerFunction(angle, exponent) / factorialFunction(exponent);
            userResult += (i % 2 == 0) ? term : -term;  // Alternating signs
        }
        end = clock();
        userTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    
        // Measure execution time for built-in sine function
        start = clock();
        builtInResult = sin(angle);
        end = clock();
        builtInTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    
        // Compute accuracy difference
        accuracyDiff = fabs(userResult - builtInResult);
    
        // Display results
        printf("\n📌 Calculation Results:\n");
        printf("------------------------\n");
        printf("🔹 User-defined sin(%.6lf): %.9lf\n", angle, userResult);
        printf("🔹 Built-in sin(%.6lf): %.9lf\n", angle, builtInResult);
        printf("🔹 Accuracy Difference: %.9lf\n", accuracyDiff);
    
        printf("\n⏳ Execution Time:\n");
        printf("------------------------\n");
        printf("🔹 User-defined sine function: %lf seconds\n", userTime);
        printf("🔹 Built-in sin() function: %lf seconds\n", builtInTime);
    }


void cosineFunction() {
    double angle, userResult = 0.0, builtInResult, accuracyDiff, userTime, builtInTime;
    clock_t start, end;
    int terms = 10;  // Number of terms in Maclaurin series

    // Input validation
    printf("\n👉 Enter an angle in radians: ");
    while (scanf("%lf", &angle) != 1) {
        printf("\n❌ Invalid input! Please enter a valid number: ");
        while (getchar() != '\n'); // Clear input buffer
    }

    // Measure execution time for user-defined cosine function
    start = clock();
    for (int i = 0; i < terms; i++) {
        int exponent = 2 * i;
        double term = powerFunction(angle, exponent) / factorialFunction(exponent);
        userResult += (i % 2 == 0) ? term : -term;  // Alternating signs
    }
    end = clock();
    userTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Measure execution time for built-in cosine function
    start = clock();
    builtInResult = cos(angle);
    end = clock();
    builtInTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Compute accuracy difference
    accuracyDiff = fabs(userResult - builtInResult);

    // Display results
    printf("\n📌 Calculation Results:\n");
    printf("------------------------\n");
    printf("🔹 User-defined cos(%.6lf): %.9lf\n", angle, userResult);
    printf("🔹 Built-in cos(%.6lf): %.9lf\n", angle, builtInResult);
    printf("🔹 Accuracy Difference: %.9lf\n", accuracyDiff);

    printf("\n⏳ Execution Time:\n");
    printf("------------------------\n");
    printf("🔹 User-defined cosine function: %lf seconds\n", userTime);
    printf("🔹 Built-in cos() function: %lf seconds\n", builtInTime);
}

void tangentFunction() {
    double angle, userTan, builtInTan, accuracyDiff, userTime, builtInTime;
    clock_t start, end;

    // Input validation
    printf("\n👉 Enter an angle in radians: ");
    while (scanf("%lf", &angle) != 1) {
        printf("\n❌ Invalid input! Please enter a valid number: ");
        while (getchar() != '\n'); // Clear input buffer
    }

    // Compute user-defined sin and cos
    double userSin = sine(angle);
    double userCos = cosine(angle);

    // Check if cos(x) is too close to zero (tan is undefined at odd multiples of π/2)
    if (fabs(userCos) < 1e-10) {
        printf("\n Tangent is undefined at this angle (cos(%.6lf) ≈ 0)\n", angle);
        return;
    }

    // Measure execution time for user-defined tangent function
    start = clock();
    userTan = userSin / userCos;
    end = clock();
    userTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Measure execution time for built-in tangent function
    start = clock();
    builtInTan = tan(angle);
    end = clock();
    builtInTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Compute accuracy difference
    accuracyDiff = fabs(userTan - builtInTan);

    // Display results
    printf("\n📌 Calculation Results:\n");
    printf("------------------------\n");
    printf("🔹 User-defined tan(%.6lf): %.9lf\n", angle, userTan);
    printf("🔹 Built-in tan(%.6lf): %.9lf\n", angle, builtInTan);
    printf("🔹 Accuracy Difference: %.9lf\n", accuracyDiff);

    printf("\n⏳ Execution Time:\n");
    printf("------------------------\n");
    printf("🔹 User-defined tangent function: %lf seconds\n", userTime);
    printf("🔹 Built-in tan() function: %lf seconds\n", builtInTime);
}
double sineFunction(double angle) {
    double userResult = 0.0;
    int terms = 10;  // Number of terms in Maclaurin series

    for (int i = 0; i < terms; i++) {
        int exponent = 2 * i + 1;
        double term = powerFunction(angle, exponent) / factorialFunction(exponent);
        userResult += (i % 2 == 0) ? term : -term;  // Alternating signs
    }
    return userResult;
}


// Cosine Function
double cosine(double angle) {
    double userResult = 0.0;
    int terms = 10;  // Number of terms in Maclaurin series

    for (int i = 0; i < terms; i++) {
        int exponent = 2 * i;
        double term = powerFunction(angle, exponent) / factorialFunction(exponent);
        userResult += (i % 2 == 0) ? term : -term;  // Alternating signs
    }
    return userResult;
}
    return 0;
}
