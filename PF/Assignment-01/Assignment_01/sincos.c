#include <stdio.h>
#include <math.h>
#include <time.h>

#define PI 3.141592653589793

// ✅ Manual Angle Reduction (Without fmod())
void reduceAngle(double* angle) {
    while (*angle > 2 * PI) {
        *angle -= 2 * PI;  // Subtract 2π until within range
    }
    while (*angle < -2 * PI) {
        *angle += 2 * PI;  // Add 2π if negative
    }
}

// ✅ More accurate sine function using angle reduction & dynamic terms
double sineFunction(double angle) {
    reduceAngle(&angle);  // Reduce large angles

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

// ✅ More accurate cosine function using angle reduction & dynamic terms
double cosineFunction(double angle) {
    reduceAngle(&angle);  // Reduce large angles

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

int main() {
    double angle, userSin, builtInSin, userCos, builtInCos, accuracySin, accuracyCos;
    clock_t start, end;
    double userTime, builtInTime;

    // ✅ User input with validation
    printf("\n👉 Enter an angle in radians: ");
    while (scanf("%lf", &angle) != 1) {
        printf("\n❌ Invalid input! Please enter a valid number: ");
        while (getchar() != '\n'); // Clear input buffer
    }

    // ✅ Measure execution time for user-defined sine function
    start = clock();
    userSin = sineFunction(angle);
    end = clock();
    userTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    // ✅ Measure execution time for built-in sine function
    start = clock();
    builtInSin = sin(angle);
    end = clock();
    builtInTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    // ✅ Measure execution time for user-defined cosine function
    start = clock();
    userCos = cosineFunction(angle);
    end = clock();
    userTime += ((double)(end - start)) / CLOCKS_PER_SEC;

    // ✅ Measure execution time for built-in cosine function
    start = clock();
    builtInCos = cos(angle);
    end = clock();
    builtInTime += ((double)(end - start)) / CLOCKS_PER_SEC;

    // ✅ Compute accuracy difference
    accuracySin = fabs(userSin - builtInSin);
    accuracyCos = fabs(userCos - builtInCos);

    // ✅ Display results
    printf("\n📌 Calculation Results:\n");
    printf("------------------------\n");
    printf("🔹 User-defined sin(%.6lf): %.9lf\n", angle, userSin);
    printf("🔹 Built-in sin(%.6lf): %.9lf\n", angle, builtInSin);
    printf("🔹 Accuracy Difference: %.9lf\n", accuracySin);

    printf("\n🔹 User-defined cos(%.6lf): %.9lf\n", angle, userCos);
    printf("🔹 Built-in cos(%.6lf): %.9lf\n", angle, builtInCos);
    printf("🔹 Accuracy Difference: %.9lf\n", accuracyCos);

    printf("\n⏳ Execution Time:\n");
    printf("------------------------\n");
    printf("🔹 User-defined sine function: %lf seconds\n", userTime);
    printf("🔹 Built-in sin() function: %lf seconds\n", builtInTime);
    
    return 0;


}