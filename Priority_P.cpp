#include <iostream>
#include <limits.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int p[n], at[n], bt[n], pr[n];
    int rt[n], wt[n], tat[n], ft[n];
    
    cout << "Enter process numbers:\n";
    for (int i = 0; i < n; i++) cin >> p[i];

    cout << "Enter arrival times:\n";
    for (int i = 0; i < n; i++) cin >> at[i];

    cout << "Enter burst times:\n";
    for (int i = 0; i < n; i++) cin >> bt[i];

    cout << "Enter priorities:\n";
    for (int i = 0; i < n; i++) cin >> pr[i];

    for (int i = 0; i < n; i++) rt[i] = bt[i];

    int completed = 0, time = 0;
    int shortest = -1, minPr = INT_MAX;
    bool found = false;
    float avg_wt = 0, avg_tat = 0;

    while (completed != n) {
        minPr = INT_MAX;
        found = false;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && pr[i] < minPr) {
                minPr = pr[i];
                shortest = i;
                found = true;
            }
        }

        if (!found) {
            time++;
            continue;
        }

        rt[shortest]--;

        if (rt[shortest] == 0) {
            completed++;
            ft[shortest] = time + 1;
            wt[shortest] = ft[shortest] - at[shortest] - bt[shortest];
            if (wt[shortest] < 0) wt[shortest] = 0;
            tat[shortest] = bt[shortest] + wt[shortest];
        }

        time++;
    }

    cout << "\nProcess\tAT\tBT\tPR\tFT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
        cout << p[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << pr[i]
             << "\t" << ft[i] << "\t" << wt[i] << "\t" << tat[i] << "\n";
    }

    cout << "\nAverage Waiting Time = " << avg_wt / n;
    cout << "\nAverage Turnaround Time = " << avg_tat / n << endl;

    return 0;
}

// Test suite
// Enter number of processes: 4
// Enter process numbers:
// 1 2 3 4
// Enter arrival times:
// 0 1 2 3
// Enter burst times:
// 7 4 1 4
// Enter priorities:
// 2 1 3 2
