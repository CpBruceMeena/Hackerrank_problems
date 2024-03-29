#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    stack<char> temp;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '(' or s[i] == '{' or s[i] == '['){
            temp.push(s[i]);
        }
        else if(s[i] == ')'){
            if(!temp.empty() and temp.top() == '(') temp.pop();
            else return ("NO");
        }
        else if(s[i] == '}'){
            if(!temp.empty() and temp.top() == '{') temp.pop();
            else return ("NO");
        }
        else if(s[i] == ']'){
            if(!temp.empty() and temp.top() == '[') temp.pop();
            else return ("NO");
        }
    }
    if(!temp.empty()) return("NO");
    return("YES");
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
