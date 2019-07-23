#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int max(int a, int b){
    return(a <= b?b:a);
}
int min(int a, int b){
    return(a<=b?a:b);
}

// Complete the whatFlavors function below.
void whatFlavors(vector<int> cost, int money) {
        int n = cost.size();
        int a = 0, b = 0;
        unordered_set<int> s;
        for(int i = 0; i<n ;i++){
            int temp = money - cost[i];
            if(s.find(temp) != s.end()){
                    a = cost[i], b = temp;                    
                    break;
            }
            else s.insert(cost[i]);
        }
        int c = max(a, b);
        int d = min(a, b);
        a = -1, b = -1;
        for(int i = 0; i<n; i++){
            if(cost[i] == d and a== -1) a = i+1;
            else if(cost[i] == c and b== -1) b = i+1;
        }
        cout<<min(a, b)<<' '<<max(a, b)<<endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int money;
        cin >> money;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector<string> cost_temp = split_string(cost_temp_temp);

        vector<int> cost(n);

        for (int i = 0; i < n; i++) {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        whatFlavors(cost, money);
    }

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
