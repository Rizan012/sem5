#include <stdio.h>
#include <math.h>

float fun(float x, float y)
{
    return(x*x+y*y);
}

int main()
{
    int X[200],Y[200],i,j,n[50],N,N1,m=100;
    float x[200],y[200],PiE=3.141,PiO=0.0,Pi[50],err;
    printf("Enter number replication:");
    scanf("%d",&N1);
    printf("Enter Number of Points:");
    scanf("%d",&N);
    for(i=0;i<N1;i++)
    {
        printf("Replication: %d\n",i+1);
        printf("Enter seed values X[0] and X[1]:");
        scanf("%d%d",&X[0],&X[1]);
        printf("Enter seed values Y[0] and Y[1]:");
        scanf("%d%d",&Y[0],&Y[1]);
        for(j=2;j<N;j++)
        {
            X[j]=(X[j-1]+X[j-2])%m;
            Y[j]=(Y[j-1]+Y[j-2])%m;
        }
        n[i]=0;
        for(j=0;j<N;j++)
        {
            x[j]=(float) X[j]/m;
            y[j]=(float) Y[j]/m;
            if(fun(x[j],y[j])<=1)
                n[i]=n[i]+1;
        }
        Pi[i]=(float) n[i]/N;
        Pi[i]=Pi[i]*4;
    }
    printf(".::Monte-Carlo Simulation::.\n");
    printf("\nRun\tn\tPi\n");
    for(i=0;i<N1;i++)
    {
        PiO=PiO+Pi[i];
        printf("%d\t%d\t%.3f\n",i+1,n[i],Pi[i]);
    }
    PiO=PiO/N1;
    err=(fabs(PiO-PiE))/PiE;
    err=err*100;
    printf("\nPiO: %.3f\t\tPiE: %.3f\n",PiO,PiE);
    printf("Error Percentage: %.2f \n\n",err);
}