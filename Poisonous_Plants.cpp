#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the poisonousPlants function below.
int poisonousPlants(vector<int> p) {
    int ans = 0;
    if(p.size() == 1) return(0);
    bool flag = 0;
    stack<int> s;
    while(true){
        for(int i = p.size()-1; i>0; i--){
            if(p[i] > p[i-1]){
                p[i] = 0;
                flag = 1;
            }
            else s.push(p[i]);
        }
        s.push(p[0]);
        if(flag) ans += 1;
        if(flag == 0) return ans;
        flag = 0;
        p.clear();
        while(!s.empty()){
            p.push_back(s.top());
            s.pop();
        }
    }
}

void print(vector<int> prev){
    int i = 0;
    while(i != prev.size()){
        cout<<prev[i]<<" ";
        i++;
    }
    cout<<endl;
}

int poisonousPlants1(vector<int> p) {
    int ans = 0;
    if(p.size() == 1) return(0);
    bool flag = 0;
    vector<vector<int>> temp;
    temp.push_back(p);
    int i = 0;
    while(true){
        vector<int> prev;
        for(int j = temp[i].size()-1; j>0; j--){
            if(temp[i][j] <= temp[i][j-1]){
                prev.push_back(temp[i][j]);
            }
            else flag = 1;
        }
        if(flag) ans+=1;
        if(flag == 0) return ans;
        flag = 0;
        prev.push_back(temp[i][0]);
        reverse(prev.begin(), prev.end());
        i+=1;
        temp.push_back(prev);
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string p_temp_temp;
    getline(cin, p_temp_temp);

    vector<string> p_temp = split_string(p_temp_temp);

    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        int p_item = stoi(p_temp[i]);

        p[i] = p_item;
    }

    int result = poisonousPlants(p);

    fout << result << "\n";

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
