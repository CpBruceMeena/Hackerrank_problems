#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long long int max(long long int a, long long int b){
    return(a<=b?b:a);
}


// Complete the maximumSum function below.
long maximumSum(vector<long> a, long m) {
    long long int n = a.size();
    long long int prefix[n], current = 0, result = 0;
    set<long long int> s;
    for(int i = 0; i<n; i++){
        current = (current%m + a[i]%m)%m;
        prefix[i] = current;
    }
    for(int i = 0; i < n; i ++) {
        s.insert(prefix[i]);
        result = max(result, (prefix[i] - 
                 *(s.upper_bound(prefix[i])) + m) % m);

        result = max(result, prefix[i]); // Don't forget sum from beginning. 
    }       
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        long m = stol(nm[1]);

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split_string(a_temp_temp);

        vector<long> a(n);

        for (int i = 0; i < n; i++) {
            long a_item = stol(a_temp[i]);

            a[i] = a_item;
        }

        long result = maximumSum(a, m);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
