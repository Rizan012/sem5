#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void generateRandomNumbers(int Xo, int X1, int m, int randomNumbers[], int count) {
    int X[count];
    X[0] = Xo;
    X[1] = X1;

    for (int i = 2; i < count; i++) {
        X[i] = (X[i - 1] + X[i - 2]) % m;
        if (X[i] < 1000) {
            X[i] += 1000;
        }
        randomNumbers[i - 2] = X[i];
    }
}

void calculateObservedFrequencies(int randomNumbers[], int observedFreq[], int count) {
    for (int i = 0; i < count; i++) {
        int num = randomNumbers[i];
        int digits[4];
        for (int j = 0; j < 4; j++) {
            digits[j] = num % 10;
            num /= 10;
        }
        int uniqueDigits = 0;
        int freq[10] = {0};

        for (int j = 0; j < 4; j++) {
            if (freq[digits[j]] == 0) {
                uniqueDigits++;
            }
            freq[digits[j]]++;
        }

        if (uniqueDigits == 1) {
            observedFreq[0]++;
        } else if (uniqueDigits == 4) {
            observedFreq[1]++;
        } else if (uniqueDigits == 2) {
            for (int j = 0; j < 10; j++) {
                if (freq[j] == 3) {
                    observedFreq[2]++;
                    break;
                } else if (freq[j] == 2) {
                    observedFreq[3]++;
                    break;
                }
            }
        } else if (uniqueDigits == 3) {
            observedFreq[4]++;
        }
    }
}

void pokerTest(int observedFreq[], int totalCount) {
    double expectedFreq[] = {0.001 * totalCount, 0.504 * totalCount, 0.036 * totalCount, 0.432 * totalCount, 0.027 * totalCount};
    double chiSquare = 0;

    printf("Class Interval\tExpected Frequency\tObserved Frequency\tO_i - E_i\t(O_i - E_i)^2\tX_0^2\n");

    for (int i = 0; i < 5; i++) {
        double O_minus_E = observedFreq[i] - expectedFreq[i];
        double O_minus_E_squared = pow(O_minus_E, 2);
        double X_0_squared = O_minus_E_squared / expectedFreq[i];
        chiSquare += X_0_squared;
        printf("%d\t\t%.3lf\t\t\t%d\t\t\t%.3lf\t\t%.3lf\t\t%.3lf\n", i + 1, expectedFreq[i], observedFreq[i], O_minus_E, O_minus_E_squared, X_0_squared);
    }

    printf("\nChi-Square value: %.3lf\n", chiSquare);
    printf("Critical value: 9.49\n");

    if (chiSquare > 9.49) {
        printf("Chi-Square value exceeds critical value. Random numbers are not independent.\n");
    } else {
        printf("Chi-Square value does not exceed critical value. Random numbers are independent.\n");
    }
}

int main() {
    int Xo = 111, X1 = 212, m = 9000;
    int count = 1002;
    int randomNumbers[count - 2];
    generateRandomNumbers(Xo, X1, m, randomNumbers, count);

    printf("Generated random numbers:\n");
    for (int i = 0; i < count - 2; i++) {
        printf("%d ", randomNumbers[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n\n");

    int observedFreq[5] = {0};
    calculateObservedFrequencies(randomNumbers, observedFreq, count - 2);

    printf("Observed Frequencies:\n");
    printf("All same: %d\n", observedFreq[0]);
    printf("All different: %d\n", observedFreq[1]);
    printf("Three of a kind: %d\n", observedFreq[2]);
    printf("One pair: %d\n", observedFreq[3]);
    printf("Two pairs: %d\n\n", observedFreq[4]);

    printf("Performing Poker Test...\n");
    pokerTest(observedFreq, count - 2);

    return 0;
}
