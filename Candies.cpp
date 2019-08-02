#include <bits/stdc++.h>

using namespace std;

// Complete the candies function below.
long candies(int n, vector<int> arr) {
    long long int temp[n];
    for(int i = 0; i<n ;i++) temp[i] = 1;
    for(int i = 0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            int j = i;
            while(arr[j] > arr[j+1] and j+1 < n){
                j++;
            }
            int k = j;
            while(j != i){
                temp[j-1] = temp[j] + 1;
                j--;
            }
            i = k;
        }
        else if(arr[i] < arr[i+1]){
            while(arr[i] < arr[i+1] and i+1 < n){
                temp[i+1]  = temp[i] + 1;
                i++;
            }
        }
        else if(arr[i] == arr[i+1]){
            continue;
        }
    }

    if(arr[n-1] > arr[n-2]) temp[n-1] = temp[n-2] + 1;
//    else temp[n-1] = temp[n-2] - 1;

    for(int i = 0; i<n ;i++){
        if(arr[i] == arr[i+1]){       
            int j = i;
            while(arr[j] == arr[j+1] and j + 1 < n){
                j++;
            }
            for(int k = i+1; k<j; k++){
                if(temp[k-1] == 1) temp[k] = 2;
            }
            i = j;
        }
    }

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
