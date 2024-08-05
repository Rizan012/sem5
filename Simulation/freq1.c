#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sort(float [], int);

int main() {
    int x[100], i, j, m = 101, n = 100, O[10], Ei = 10;
    float r[100], dp[100], dm[100], d0, dt = 0.136, a = 0, b = 0.1;
    float chiO = 0.0, t[10], chiT = 16.9;

    printf("Enter two seed values (x[0] and x[1]): ");
    scanf("%d%d", &x[0], &x[1]);
    r[0] = (float)x[0] / n;
    r[1] = (float)x[1] / n;
    for (i = 2; i < 100; i++) {
        x[i] = (x[i - 1] + x[i - 2]) % m;
        r[i] = (float)x[i] / 100;
    }
    printf("\nGenerated Random Numbers:\n");
    for (i = 0; i < 100; i++) {
        printf("%.2f ", r[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }

    for (i = 0; i < 10; i++) O[i] = 0;
    for (i = 0; i < 100; i++) {
        if (r[i] <= 0.1) O[0]++;
        else if (r[i] > 0.1 && r[i] <= 0.2) O[1]++;
        else if (r[i] > 0.2 && r[i] <= 0.3) O[2]++;
        else if (r[i] > 0.3 && r[i] <= 0.4) O[3]++;
        else if (r[i] > 0.4 && r[i] <= 0.5) O[4]++;
        else if (r[i] > 0.5 && r[i] <= 0.6) O[5]++;
        else if (r[i] > 0.6 && r[i] <= 0.7) O[6]++;
        else if (r[i] > 0.7 && r[i] <= 0.8) O[7]++;
        else if (r[i] > 0.8 && r[i] <= 0.9) O[8]++;
        else O[9]++;
    }

    printf("\nClass Range\tObserved (O[i])\tExpected (E[i])\t(O[i] - E[i])^2 / E[i]\n");
    printf("--------------------------------------------------------------\n");
    for (i = 0; i < 10; i++) {
        t[i] = pow((O[i] - Ei), 2) / Ei;
        chiO += t[i];
        printf("%.1f - %.1f\t\t%d\t\t%d\t\t%.2f\n", a, b, O[i], Ei, t[i]);
        a = b;
        b += 0.1;
    }

    if (chiO <= chiT)
        printf("\nSince %.3f <= %.3f, the generated random numbers are uniformly distributed.\n", chiO, chiT);
    else
        printf("\nSince %.3f > %.3f, the generated random numbers are not uniformly distributed.\n", chiO, chiT);

    sort(r, n);
    for (i = 1; i < n; i++) {
        dp[i] = (float)i / n - r[i];
        if (dp[i] < 0) dp[i] = 0;
        dm[i] = r[i] - (float)(i - 1) / n;
        if (dm[i] < 0) dm[i] = 0;
    }

    sort(dp, n);
    sort(dm, n);

    d0 = (dp[99] > dm[99]) ? dp[99] : dm[99];

    if (d0 <= dt)
        printf("\nSince d0 (%.3f) <= dt (%.3f), the generated random numbers are uniformly distributed.\n", d0, dt);
    else
        printf("\nSince d0 (%.3f) > dt (%.3f), the generated random numbers are not uniformly distributed.\n", d0, dt);

    return 0;
}

void sort(float a[], int n) {
    int i, j;
    float tmp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

