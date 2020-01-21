#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long work_remain(int days, int done, int no_sleep, int remaining, int D[100002]){
    long long dp[days+1][2] = {0};
    dp[0][0] = remaining; // 0 represent sleep
    dp[0][1] = remaining; // 1 represent no sleep
    for(int i=1;i<=days;i++){
        dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + D[i];
        dp[i][1] = INT_MAX;

        for(int X=1;X<=i;X++){
            dp[i][1]  = min(dp[i][1], dp[i-X][0] - done*X + no_sleep*(1+X)*X/2);
        }


    }
    return min(dp[days][0], dp[days][1]);
}
int main()
{
    int days, done, no_sleep, remaining;
    cin >> days >> done >> no_sleep >> remaining;
    int D[days];
    D[0] = 0;
    for(int i=1;i <= days;i++){
        cin >> D[i];
    }

    long long answer = work_remain(days, done, no_sleep, remaining, D);
    cout << answer << endl;
    return 0;
}
