#include <stdio.h>



int main() {
    int choice;

    // Display a welcome message
    printf("\n--------------------------------------------------------------------------------\n\n");
    printf("                    WELCOME TO THE SCIENTIFIC CALCULATOR            \n");
    printf("\n--------------------------------------------------------------------------------\n\n");
    printf("This calculator provides advanced mathematical operations.\n");
    printf("Simply enter the number corresponding to your desired function.\n\n");

        while(1){           // Display Menu
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
        printf("\n👉 Please enter your choice (1-8): ");
        scanf("%d", &choice);

        // Get user input
        // while(choice < 1 || choice > 8) {
        //     printf("\n❌ Invalid choice!!! Please enter a number between 1 and 8 now:  ");
        //     scanf("%d", &choice);
        // }
        // Check if the input is within the valid range

        if (choice >= 1 && choice <= 8) {
            if (choice == 8) {
            printf("\n✅ Exiting the scientific calculator. Thank you for using it! Have a great day!\n");
            printf("\n--------------------------------------------------------------------------------\n\n");
            break; // Exit the loop
            }

        // Process user choice
        // printf("\n--------------------------------------------------------------------------------\n");
        switch (choice) {
            case 1: 
                printf("\n📌 You selected: Exponentiation (x^y)\n");
                // powerFunction(); 
                break;
            case 2: 
                printf("\n📌 You selected: Square Root (√x)\n");
                // squareRoot(); 
                break;
            case 3: 
                printf("\n📌 You selected: Natural Logarithm (ln(x))\n");
                // naturalLog(); 
                break;
            case 4: 
                printf("\n📌 You selected: Sine Function (sin x)\n");
                // sineFunction(); 
                break;
            case 5: 
                printf("\n📌 You selected: Cosine Function (cos x)\n");
                // cosineFunction(); 
                break;
            case 6: 
                printf("\n📌 You selected: Tangent Function (tan x)\n");
                // tangentFunction(); 
                break;
            case 7: 
                printf("\n📌 You selected: Factorial (n!)\n");
                // factorialFunction(); 
                break;
        }
    }
        else
            printf("\n❌ Invalid choice! Please enter a number between 1 and 8.\n");

        printf("\n--------------------------------------------------------------------------------\n\n");
    }
    return 0;
}
