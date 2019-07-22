#include <bits/stdc++.h>

using namespace std;

int max(int a, int b){
    return(a>=b?a:b);
}

// Complete the commonChild function below.
int commonChild(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    int dp[2][n2+1];
    bool bi;
    for(int i = 0; i<=n1; i++){
        for(int j = 0; j<=n2; j++){
            bool bi = i&1;
            if(i == 0 or j == 0) dp[bi][j] = 0;
            else{
                if(s1[i-1] == s2[j-1]){
                    dp[bi][j] = dp[1-bi][j-1] + 1;
                }
                else
                    dp[bi][j] = max(dp[1-bi][j],dp[bi][j-1]);
            }
        }
    }
    return dp[bi][n2];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
