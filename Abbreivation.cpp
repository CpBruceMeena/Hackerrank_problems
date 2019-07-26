#include <bits/stdc++.h>

using namespace std;

// Complete the abbreviation function below.
string abbreviation(string a, string b) {
    if(a.size() < b.size()) return("NO");
    int i = 0, j = 0;
    while(i != a.size() and j != b.size()){
        if(a[i] != b[j]){
            if(isupper(a[i])){
    //            cout<<a[i]<<" "<<b[j]<<endl;
                return("NO"); 
            } 
            else if(toupper(a[i]) == b[j]){
                while(toupper(a[i]) == a[i+1] and i+1 < a.size()) i++;
                i++, j++;
            }
            else if(i+1 == a.size()) return("NO");
            else i++;
        }
        else if(a[i] == b[j]){
            i++, j++;
        }
    }
    if(j != b.size()) return("NO");
    while(i != a.size()){
        if(isupper(a[i])) return("NO");
        i++;
    }
    return("YES");
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
