#include <bits/stdc++.h>

using namespace std;

int minimum(int a, int b){
    return(a>=b?b:a);
}

// Complete the isValid function below.
string isValid(string s) {
    if(s.size() == 1) return("YES");
     int character[26];
     memset(character, 0, sizeof(character));
     for(int i = 0; i<s.size(); i++){
         character[s[i] - 'a']++;
     }
     set<int> count;
     for(int i = 0; i<26; i++){
         if(character[i] != 0) count.insert(character[i]);
     }
     if(count.size() == 1) return("YES");
     if(count.size() > 2) return("NO");
     int a, b;
     set<int> ::iterator itr = count.begin();
     a = *itr;
     itr++;
     b = *itr;
     if(a > 1 and b>1 and abs(a - b) > 1) return("NO");

     int counta = 0, countb = 0;
     for(int i = 0; i<26; i++){
         if(character[i] == a) counta++;
         else if(character[i] == b) countb++;
     }
     if(counta > 1 and abs(b - a) > 2) return ("NO");
     if(counta == 1 or countb == 1) return ("YES");
     else return("NO");
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
