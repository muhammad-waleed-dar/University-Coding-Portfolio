#include<stdio.h>
double POW(double a, double b);
double FAC(double a);
double SIN( double a);
double COSIN( double a);
double TAN( double a);
double SEC( double a);
double COSEC( double a);
double COT( double a);
double SR(double a);
double LOG(double a);
double natural_log(double n, int terms);
double ln_series(double x, int terms);
int main(){
    printf("Enter 1 for power\nEnter 2 for factorial\nEnter 3 for sin\nEnter 4 for cosin\nEnter 5 for tan\nEnter 6 for sec\nEnter 7 for cosec\nEnter 8 for cot\nEnter 9 for square root\nEnter 10 for natural log.");
    int n;
    scanf("%d", &n);
    if (n == 1)
    {

        double a;
        double b;
        printf("Enter the number and its exponent: ");
        scanf("%lf %lf", &a, &b);
        printf("%lf", POW(a, b));
    }
    else if(n == 2){
        double a;
        printf("Enter the number to find factorial: ");
        scanf("%lf", &a);
        printf("%lf", FAC(a));
    }
    else if(n == 3){
        double a;
        printf("Enter the number: ");
        scanf("%lf", &a);
        printf("%lf", SIN(a));
    }
    else if(n == 4){
        double a;
        printf("Enter the number: ");
        scanf("%lf", &a);
        printf("%lf", COSIN(a));
    }
    else if(n == 5){
        double a;
        printf("Enter the number: ");
        scanf("%lf", &a);
        printf("%lf", TAN(a));
    }
    else if(n == 6){
        double a;
        printf("Enter the number: ");
        scanf("%lf", &a);
        printf("%lf", SEC(a));
    }
    else if(n == 7){
        double a;
        printf("Enter the number: ");
        scanf("%lf", &a);
        printf("%lf", COSEC(a));
    }
    else if(n == 8){
        double a;
        printf("Enter the number: ");
        scanf("%lf", &a);
        printf("%lf", COT(a));
    }
    else if(n == 9){
        double a;
        printf("Enter the number: ");
        scanf("%lf", &a);
        if(a > 0){
        printf("%lf", SR(a));
        }
        else if (a < 0){
            a = a * -1;
            printf("%lfi", SR(a));
        }
    }
    else if(n == 10){
        double a;
    printf("Enter a positive number: ");
    scanf("%lf", &a);
    
    double result = natural_log(a, 20);  // Using 20 terms for accuracy
    if (result != -1)
        printf("ln(%.6f) = %.6f\n", a, result);
    
    }
    else {
        printf("Enter value from the given range");
    }
    
    
return 0;
}
double POW(double a, double b){
    double n = 1;
    for (int i = 1; i <= b; i++)
    {
        n *= a;
    }
    return n;    
}
double FAC(double a){
    double n = 1;
 for (int i = 1; i <= a; i++)
 {
    n = n * i;
 }
    return n;
}
double SIN(double a) {
    // Convert degrees to radians (if input is in degrees)
    a = a * 3.141592653589793 / 180.0;

    // Compute the Taylor series expansion up to the 4th term
    double b = a - (POW(a, 3) / FAC(3)) + (POW(a, 5) / FAC(5)) - (POW(a, 7) / FAC(7));

    return b;
}

double COSIN(double a){
    a = a * 3.141592653589793 / 180.0;
    double b = 1 - (POW(a, 2)/FAC(2)) + (POW(a, 4)/FAC(4)) - (POW(a, 6)/FAC(6));
    return b;
}
double TAN(double a){

    double b = SIN(a)/COSIN(a);
    return b;
}
double SEC(double a){
    double b = 1 / COSIN(a);
    return b;
}
double COSEC(double a){
    double b = 1 / SIN(a);
    return b;
}
double COT(double a){
    double b = 1 / TAN(a);
    return b;
}
double SR(double a){
    if (a < 0){
        return -1;
    }
    if (a == 0 || a == 1)
    {
        return a;
    }
    double new_num = a;
    while ((new_num * new_num - a > 0.00001) || (a - new_num * new_num > 0.00001))
    {
        new_num = (new_num + a/ new_num) / 2;
    }
     return new_num; 
}
double ln_series(double x, int terms) {
    double result = 0.0;
    double term = x;
    for (int i = 1; i <= terms; i++) {
        result += term / i;
        term *= -x;  // Alternating sign
    }
    return result;
}
double natural_log(double n, int terms) {
    if (n <= 0) {
        printf("Error: Log is undefined for non-positive values.\n");
        return -1;
    }
    int count = 0;
    while (n > 2) { // Reduce n to range (0,2]
        n /= 2.0;
        count++;
    }
    
    return count * 0.69314718056 + ln_series(n - 1, terms); // ln(2) ≈ 0.693
}