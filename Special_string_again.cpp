#include <bits/stdc++.h>

using namespace std;

bool check(string s, int i , int j, int flag){
    if(!flag){
        char c = s[i];
        int mid = (i + j)/2;
        for(int k = i; k<mid; k++){
            if(s[k] != c or s[j--] != c) return false;
        }
        return true;
    }
    else{
        char c = s[i];
        for(int k = i; k<=j; k++){
            if(s[k] != c) return false;
        }
        return true;
    }
}

int minimum(int a, int b){
    return(a>=b?b:a);
}

// Complete the substrCount function below.
long substrCount(int n, string s) {
    long ans = n;
    int length = n;
    for (int i = 0; i < length; i++) {
        // if the current symbol is in the middle of palindrome, e.g. aba
        int offset = 1;
        while (i - offset >= 0 && i + offset < length 
        && s[i-offset]==s[i - 1]&&s[i + offset]==s[i - 1]) {
            ans++;
            offset++;
        }
        // if this is repeatable characters aa
        int repeats = 0;
        while (i + 1 < length && s[i] == s[i + 1]) {
            repeats++;
            i++;
        }
        ans += repeats * (repeats + 1) / 2;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
