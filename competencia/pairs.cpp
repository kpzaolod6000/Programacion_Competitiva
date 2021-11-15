#include <bits/stdc++.h>

using namespace std;



int pairs(int k, vector<int> arr) {
    sort (arr.begin(), arr.end());  

    int init = 0, end_ = 1;
    int cnt = 0;
    int diff;

    while (end_ < arr.size()) {
        diff = arr[end_] - arr[init];
        if (diff < k)end_++;
        else if (diff > k) init++;
        else if (diff == k){
            cnt++;
            end_++;
        }
        
    }
    return cnt;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n,k;
    cin>>n>>k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {

        cin>>arr[i];
    }
    
    int result = pairs(k, arr);

    cout << result << "\n";

    return 0;
}