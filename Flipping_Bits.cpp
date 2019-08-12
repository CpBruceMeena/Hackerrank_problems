#include <bits/stdc++.h>

using namespace std;

// Complete the flippingBits function below.
long flippingBits(long n) {
    int count[32];
    for(int i = 0; i<32; i++){
        if(n>>i & 1){
            count[i] = 0;
        }
        else count[i] = 1;
    }
    long long ans = 0;
    for(int i = 0; i<32; i++){
        ans += pow(2, i)*count[i];
    }
    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long result = flippingBits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
