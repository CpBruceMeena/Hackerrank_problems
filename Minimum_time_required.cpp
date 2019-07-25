#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

long long getTotal(vector<long int> machines, long long int middle){
    long long ans = 0;
    for(int i = 0; i<machines.size(); i++){
        ans += middle/machines[i];
    }
    return ans;
}

// Complete the minTime function below.
long minTime(vector<long> machines, long goal) {
    sort(machines.begin(), machines.end());
    float n = machines.size();
    double u = (double)(n/machines[n-1]);
    double l = (float)(n*1.0)/(machines[0]*(1.0));
    long long int lower_bound = goal/l;
    long long int upper_bound = goal/u + 1;
    while(lower_bound < upper_bound){
        long long int middle = (lower_bound + upper_bound)/2;
        long long int days = getTotal(machines, middle);
        if(days < goal){
            lower_bound = middle+1;
        }
        else upper_bound = middle;
    }
    return lower_bound;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nGoal_temp;
    getline(cin, nGoal_temp);

    vector<string> nGoal = split_string(nGoal_temp);

    int n = stoi(nGoal[0]);

    long goal = stol(nGoal[1]);

    string machines_temp_temp;
    getline(cin, machines_temp_temp);

    vector<string> machines_temp = split_string(machines_temp_temp);

    vector<long> machines(n);

    for (int i = 0; i < n; i++) {
        long machines_item = stol(machines_temp[i]);

        machines[i] = machines_item;
    }

    long ans = minTime(machines, goal);

    fout << ans << "\n";

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
