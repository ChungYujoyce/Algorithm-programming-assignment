#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long work_remain(int days, int done, int no_sleep, int remaining, int D[100002]){
    long long dp[days+1][days+1] = {0};
    dp[0][0] = remaining;
    for(int i=1;i<=days;i++){
        for(int j=0;j<=days;j++){
            if(j>i) dp[i][j] = INT_MAX;
            else if(j>0) dp[i][j] = dp[i-1][j-1] - done + j*no_sleep;
            else {
                int tmp = INT_MAX;
                for(int k=0;k<i;k++){
                    if(dp[i-1][k] < tmp)
                        tmp = dp[i-1][k];
                }
                dp[i][j] = tmp + D[i];
            }

        }

    }
    long long answer = INT_MAX;
    for(int i=0;i<=days;i++){
        if(dp[days][i] < answer)
            answer = dp[days][i];
    }
    return answer;
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
