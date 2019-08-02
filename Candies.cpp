#include <bits/stdc++.h>
using namespace std;

long long max(int a, int b){
    return(a>=b?a:b);
}

// Complete the candies function below.
long candies(int n, vector<int> arr) 
    long long int temp[n];
    long long int first[n], back[n];

    for(int i = 0; i<n ;i++){
        first[i] = 1;
        back[i] = 1;   
    }

    for(int i = 0; i<n-1; i++){
        if(arr[i] < arr[i+1]){
            first[i+1] = first[i] + 1;
        }
    }

    for(int i = n-1; i>0; i--){
        if(arr[i] < arr[i-1]){
            back[i-1] = back[i] + 1;
        }
    }

    for(int i = 0; i<n; i++){
        temp[i] = max(first[i], back[i]);
    }

    if(arr[n-1] > arr[n-2]) temp[n-1] = temp[n-2] + 1;
    long long ans = 0;
    for(int i = 0; i<n; i++){
        ans += temp[i];
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
