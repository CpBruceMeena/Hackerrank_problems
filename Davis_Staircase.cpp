#include <bits/stdc++.h>
#define mod 10000000007
using namespace std;

// Complete the stepPerms function below.

int solve(int n, int dp[], int t, int var){
    if(var == n) return dp[n];
    else{
        var += 1;
        dp[var] = (dp[var-1]%mod + dp[var-2]%mod + dp[var - 3]%mod)%mod;
    } 

    return(solve(n, dp, t, var)%mod);
}

int stepPerms(int n) {
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    if( n <=3) return(dp[n]);
    int var = 3;
    int t = n+1;
    return(solve(n, dp, t, var));
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int s_itr = 0; s_itr < s; s_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int res = stepPerms(n);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}
