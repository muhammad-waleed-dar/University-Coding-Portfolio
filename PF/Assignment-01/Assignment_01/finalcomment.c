#include <stdio.h>
#include <math.h>
#include <time.h>

#define PI 3.141592653589793 

void powerFunction();
void squareRootFunction();
void factorialFunction();
double sineFunction(double);
double cosineFunction(double);
void tangentFunction();
void naturalLog();

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

        start = clock();
        for (int i = 0; i < absExponent; i++) {
            userResult *= base;
        }
        userResult = (exponent < 0) ? (1.0 / userResult) : userResult;
        end = clock();
        userTime = ((double)(end - start)) / CLOCKS_PER_SEC;

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
    printf("🔹 User-defined power function result: %.10lf\n", userResult);
    printf("🔹 Built-in pow() function result: %.10lf\n", builtInResult);
    printf("🔹 Accuracy Difference: %.10e\n", accuracyDiff); // Scientific notation for small differences

    printf("\n⏳ Execution Time:\n");
    printf("------------------------\n");
    printf("🔹 User-defined power function: %.10lf seconds\n", userTime);
    printf("🔹 Built-in pow() function: %.10lf seconds\n", builtInTime);

}

void squareRootFunction() {
    double number, userResult, builtInResult, accuracyDiff, userTime, builtInTime;
    clock_t start, end;

    // Taking valid user input
    printf("\n👉 Enter a non-negative number to calculate its square root: ");
    while (scanf("%lf", &number) != 1 || number < 0) {
        printf("\n❌ Invalid input! Please enter a valid **non-negative** number: ");
        while (getchar() != '\n'); // Clear input buffer
    }

    // User-defined square root function (Simple Newton’s Method)
    start = clock();
    double guess = number; // Initial guess
    double epsilon = 0.000001; // Precision threshold
    while (fabs(guess * guess - number) > epsilon) {
        guess = (guess + number / guess) / 2.0;
    }
    userResult = guess;
    end = clock();
    userTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Built-in sqrt() function
    start = clock();
    builtInResult = sqrt(number);
    end = clock();
    builtInTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Accuracy comparison
    accuracyDiff = fabs(userResult - builtInResult);

    // Display results
    printf("\n📌 Calculation Results:\n");
    printf("------------------------\n");
    printf("🔹 User-defined square root result: %.9lf\n", userResult);
    printf("🔹 Built-in sqrt() function result: %.9lf\n", builtInResult);
    printf("🔹 Accuracy Difference: %.9lf\n", accuracyDiff);

    printf("\n⏳ Execution Time:\n");
    printf("------------------------\n");
    printf("🔹 User-defined square root function: %lf seconds\n", userTime);
    printf("🔹 Built-in sqrt() function: %lf seconds\n", builtInTime);
}

void factorialFunction() {
    double number;
    double fact = 1;
    double userTime;
    clock_t start, end;

    // Input validation
    printf("\n👉 Enter a non-negative integer for factorial: ");
    while (scanf("%lf", &number) != 1 || number < 0) {
        printf("\n❌ Invalid input! Please enter a valid **non-negative** integer: ");
        while (getchar() != '\n'); // Clear input buffer
    }

    // Measure execution time & compute factorial
    start = clock();
    for (double i = 1; i <= number; i++) {
        fact *= i;
    }
    end = clock();
    userTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Display results
    printf("\n📌 Calculation Results:\n");
    printf("------------------------\n");
    printf("🔹 Factorial of %.0lf: %lf\n", number, fact);
    printf("\n⏳ Execution Time:\n");
    printf("------------------------\n");
    printf("🔹 Execution time: %lf seconds\n", userTime);
}

// ✅ Manual Angle Reduction (Without Pointers)
double reduceAngle(double angle) {
    while (angle > 2 * PI) {
        angle -= 2 * PI;  // Subtract 2π until within range
    }
    while (angle < -2 * PI) {
        angle += 2 * PI;  // Add 2π if negative
    }
    return angle;  // Return the reduced angle instead of modifying it
}

// ✅ More Accurate Sine Function (Using Reduced Angle & Dynamic Terms)
double sineFunction(double angle) {
    angle = reduceAngle(angle);  // Reduce large angles

    double result = 0.0, term = angle;
    int i = 1, sign = 1;

    while (fabs(term) > 1e-9) {  // Continue until term is too small
        result += sign * term;
        sign *= -1;
        i += 2;
        term *= (angle * angle) / (i * (i - 1));  // Efficient power & factorial
    }
    return result;
}

// ✅ More Accurate Cosine Function (Using Reduced Angle & Dynamic Terms)
double cosineFunction(double angle) {
    angle = reduceAngle(angle);  // Reduce large angles

    double result = 1.0, term = 1.0;
    int i = 2, sign = -1;

    while (fabs(term) > 1e-9) {  // Continue until term is too small
        term *= (angle * angle) / (i * (i - 1));  // Efficient power & factorial
        result += sign * term;
        sign *= -1;
        i += 2;
    }
    return result;
}

// Tangent Function
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
    double userSin = sineFunction(angle);
    double userCos = cosineFunction(angle);

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

// Computes ln(1 + x) using Taylor Series
double ln_series(double x, int terms) {
    double result = 0.0;
    double term = x;

    for (int i = 1; i <= terms; i++) {
        result += term / i;
        term *= -x;  // Alternating sign
    }

    return result;
}

// Computes natural log, handles input, validation, execution time, and accuracy check
void naturalLog() {
    double x, userResult, builtInResult, accuracyDiff, userTime, builtInTime;
    clock_t start, end;
    int terms = 10;  // Number of terms for Taylor series approximation

    // Take input inside function
    printf("\nEnter a positive number: ");
    scanf("%lf", &x);

    // Validate input
    if (x <= 0) {
        printf("Error: ln(x) is undefined for non-positive values.\n");
        return;
    }

    int count = 0;
    double original_x = x;

    // Measure execution time for user-defined function
    start = clock();

    // Step 1: Adjust x to be in range (0.5, 1.5]
    while (x > 1.5) {
        x /= 2.0;
        count++;
    }
    while (x < 0.5) {
        x *= 2.0;
        count--;
    }

    // Step 2: Compute ln(x) using Taylor series
    userResult = count * 0.69314718056 + ln_series(x - 1, terms);

    end = clock();
    userTime = (double)(end - start) / CLOCKS_PER_SEC;

    // Measure execution time for built-in log()
    start = clock();
    builtInResult = log(original_x);
    end = clock();
    builtInTime = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate accuracy difference
    accuracyDiff = fabs(userResult - builtInResult);

    // Display Results
    printf("\nResults:\n");
    printf("User-defined ln(%lf) = %lf\n", original_x, userResult);
    printf("Built-in log(%lf)    = %lf\n", original_x, builtInResult);

    printf("\nExecution Time:\n");
    printf("User-defined ln execution time: %lf seconds\n", userTime);
    printf("Built-in log execution time: %lf seconds\n", builtInTime);

    printf("\nAccuracy Difference: %lf\n", accuracyDiff);
}


int main() {
    int choice, exponent;
    double base, angle, number, userResult, builtInResult, accuracyDiff, userTime, builtInTime;
    clock_t start, end;

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

        // Valid integer passes but is it a validate integer choice e.g., 1 to 8 (within range)
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
            case 1: 
                printf("\n📌 You selected: Exponentiation (x^y)\n");
                powerFunction();
                break;
            case 2: 
                printf("\n📌 You selected: Square Root (√x)\n");
                squareRootFunction(); 
                break;
            case 3: 
                printf("\n📌 You selected: Natural Logarithm (ln(x))\n");
                naturalLog(); 
                break;
            case 4: 
                printf("\n📌 You selected: Sine Function (sin x)\n");

                // Input validation for angle
                printf("\n👉 Enter an angle in radians: ");
                while (scanf("%lf", &angle) != 1) {
                    printf("\n❌ Invalid input! Please enter a valid number: ");
                    while (getchar() != '\n'); // Clear input buffer
                }

                // Measure execution time for user-defined sine function
                start = clock();
                userResult = sineFunction(angle);
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
                break;
            case 5: 
                printf("\n📌 You selected: Cosine Function (cos x)\n");

                // Input validation
                printf("\n👉 Enter an angle in radians: ");
                while (scanf("%lf", &angle) != 1) {
                printf("\n❌ Invalid input! Please enter a valid number: ");
                while (getchar() != '\n'); // Clear input buffer
                }

                // Measure execution time for user-defined cosine function
                start = clock();
                userResult = cosineFunction(angle);
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
                break;
            case 6: 
                printf("\n📌 You selected: Tangent Function (tan x)\n");
                tangentFunction(); 
                break;
            case 7: 
                printf("\n📌 You selected: Factorial (n!)\n");
                factorialFunction();
                break;
        }
        printf("\n--------------------------------------------------------------------------------\n\n");
    }

    return 0;
}
