//SJF
#include <stdio.h>

#define MAX 30

int main(void) {
    int i, j, n, t;
    int p[MAX], bt[MAX], wt[MAX], tat[MAX];
    float awt = 0.0, atat = 0.0;

    printf("Enter the number of Process: ");
    scanf("%d", &n);

    printf("Enter the process numbers: ");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("Enter the Burst time of the process: ");
    for (i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    // Sort processes by burst time (SJF non-preemptive)
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                t = bt[j]; bt[j] = bt[j + 1]; bt[j + 1] = t;
                t = p[j];  p[j]  = p[j + 1];  p[j + 1]  = t;
            }
        }
    }

    printf("process \t Burst time \t waiting time \t turn around time\n");
    for (i = 0; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];


        tat[i] = wt[i] + bt[i];

        awt += wt[i];
        atat += tat[i];

        printf("%d\t %d\t\t %d\t\t %d\n", p[i], bt[i], wt[i], tat[i]);
    }

    awt /= n;
    atat /= n;

    printf("Average waiting time = %f\n", awt);
    printf("Average turn around time = %f\n", atat);

    return 0;
}
