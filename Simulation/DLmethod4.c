#include <stdio.h>

int main()
{
    float I[50], T[50], C[50], G[50], Y[50];
    int year = 2024, i, n;
    
    printf("Enter National Income for %d: ", year);
    scanf("%f", &Y[0]);
    printf("Enter Government Expenditure for year %d: ", year);
    scanf("%f", &G[0]);
    printf("Enter Number of Years to simulate: ");
    scanf("%d", &n);
    
    printf("\n\t\tNational Economy Simulation Using Distributed Lag Model\n");
    printf("\n   Income [%d]: %.2f\t\tExpenditure [%d]: %.2f\n", year, Y[0], year, G[0]);
    printf("\n   SN\tYear\tInvestment\tTax\tExpenditure\tConsumption\tIncome\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");
    
    for(i = 1; i <= n; i++)
    {
        I[i] = 2 + 0.1 * Y[i - 1];
        T[i] = 0.2 * Y[i - 1];
        G[i] = 0.15 * G[i - 1] + G[i - 1];
        C[i] = 45.45 + 2.27 * (I[i] + G[i]);
        Y[i] = C[i] + I[i] + G[i];
        
        printf("   %d\t%d\t%12.2f\t%12.2f\t%12.2f\t%12.2f\t%12.2f\n", i, year + i, I[i], T[i], G[i], C[i], Y[i]);
    }
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");
    
    return 0;
}
