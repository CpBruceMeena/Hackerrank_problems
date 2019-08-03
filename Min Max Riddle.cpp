#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long long getMin(vector<long> arr, int i , int j){
    long long ans = INT_MAX;
    for(int k = i; k<=j; k++){
        if(arr[k] < ans) ans = arr[k];
    }
    return ans;
}

// Complete the riddle function below.
//The below solution is a naive solution i.e., bruce force approach.
vector<long> riddle1(vector<long> arr) {
    vector<long> result;
    int n = arr.size();
    for(int len = 0; len<n; len++){
        long long int temp = INT_MIN;
        for(int i = 0; i<n-len; i++){
            long long int l = getMin(arr, i, i+len);
            temp = max(l, temp);
        }
        result.push_back(temp);
    }
    return result;
}

long long getMax(vector<long> current){
    long long ans = 0;
    for(int i = 0; i<current.size(); i++){
        if(current[i] > ans) ans = current[i];
    }
    return ans;
}

vector<long> riddle(vector<long> current) {
    vector<long> result;
    int n = current.size();
    long long ans = getMax(current);
    result.push_back(ans);
    for(int len = 1; len<n; len++){
        long long temp, val = INT_MIN;
        for(int i = 0; i<n-len; i++){
            temp = min(current[i], current[i+1]);
            val =  max(temp, val);
            current[i] = temp;
        }
        result.push_back(val);
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<long> res = riddle(arr);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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
