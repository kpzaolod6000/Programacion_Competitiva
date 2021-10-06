#include <bits/stdc++.h>
//algoritmo kadane
using namespace std;

long int MaxSubarraySum(vector<int> &arr){

    long int maxSubArr_sum = 0;
    long int current_maxSubArr_sum = 0;
    int n = arr.size();
 
    // traverse the given array
    long int max_ = arr[0];
    for (int i = 0; i < n; i++)
    {
        // max_ = max(max_, arr[i]);
        if(arr[i] > max_) max_ = arr[i];
        
        current_maxSubArr_sum = current_maxSubArr_sum + arr[i];

        if(0 > current_maxSubArr_sum) current_maxSubArr_sum = 0;  
        // current_maxSubArr_sum = max(current_maxSubArr_sum, 0);
 
        if(current_maxSubArr_sum > maxSubArr_sum) maxSubArr_sum = current_maxSubArr_sum;
        // maxSubArr_sum = max(maxSubArr_sum,current_maxSubArr_sum);
    }
    if (maxSubArr_sum == 0) return max_;
    
    return maxSubArr_sum;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,value;
    cin >> n;
    vector<int> arr;
    for (size_t i= 0;i < n; i++){
        cin>>value;
        arr.push_back(value);
    }
    
    cout<<MaxSubarraySum(arr)<<"\n";

    return 0;
}