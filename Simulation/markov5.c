#include <stdio.h>
#include <conio.h>

void main()
{
    int i, j, l, n;
    float p[2][2] = {{0.8, 0.2}, {0.1, 0.9}}, x[1][2], y[1][2];

    printf("Enter today's purchase of Pepsi and Coke: ");
    scanf("%f%f", &x[0][0], &x[0][1]);
    printf("Enter the number of purchases to forecast: ");
    scanf("%d", &n);
    
    printf("\nProbability Transition Matrix:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%5.2f ", p[i][j]);
        }
        printf("\n");
    }
    

    printf("\nPurchase\tPepsi\tCoke\tPreferred\n");
    for (l = 1; l <= n; l++)
    {
        y[0][0] = x[0][0] * p[0][0] + x[0][1] * p[1][0];
        y[0][1] = x[0][0] * p[0][1] + x[0][1] * p[1][1];
        
        // Determine which product has a higher probability
        char* preferred = y[0][0] > y[0][1] ? "Pepsi" : "Coke";
        
        printf("%d\t\t%.2f\t%.2f\t%s\n", l, y[0][0], y[0][1], preferred);
        
        x[0][0] = y[0][0];
        x[0][1] = y[0][1];
    }

    printf("\nAfter %d purchases:\nProbability of purchasing Pepsi: %.2f\n of purchasing Coke: %.2f", n, y[0][0], y[0][1]);
    printf("\n\tPreferred Product: %s", y[0][0] > y[0][1] ? "Pepsi" : "Coke");

    getch();
}
