#include <bits/stdc++.h>
using namespace std;

// Complete the abbreviation function below.
string abbreviation(string a, string b) {
    if(a.size() < b.size()) return("NO");
    int n = a.size();
    int m = b.size();
    bool dp[n+1][m+1];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<=m; j++){
            if(!dp[i][j]) continue;
            if(!isupper(a[i])) dp[i+1][j] = 1;
            if(j<m and toupper(a[i]) == b[j]) dp[i+1][j+1] = 1;
        }
    }
    if(dp[n][m]) return("YES");
    else return("NO");
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
