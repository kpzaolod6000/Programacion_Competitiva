
#include <bits/stdc++.h>
//algoritmo kadane
using namespace std;


vector<long long> sumsPrefix(vector<long long> arr){
    vector<long long> aux;
    aux.push_back(0);

    for (size_t i = 0; i < arr.size(); i++) aux.push_back(aux.back() + arr[i]);

    return aux;

}
// long int maxSubArraySumII(vector<long long int> &nums,int a, int b){//n^3
    
//     int n = nums.size();
//     long long int sumMaxTotal = INT_MIN;
//     long long int sum_ = 0;
//     // cout<<sumMaxTotal<<"\n";
    
//     for (size_t i = 0; i < n; i++)
//     {
//         for (size_t len = a; len <= b; len++)
//         {
//             if (i+len <= n)
//             {
//                 sum_ = 0;
//                 for (size_t id = i; id < len+i; id++)
//                 {
//                     sum_ += nums[id];
//                 }
//                 if(sum_ > sumMaxTotal) sumMaxTotal = sum_;
//                 // cout<<sumMaxTotal<<"\n";
//             }
            
//         }
        

//     }
//     return sumMaxTotal;

// }


// long long int maxSubArraySumII2(vector<long long int> &nums,int a, int b){//complejidad n^2
    
//     int n = nums.size();
//     long long int sumMaxTotal = INT_MIN;
//     long long int sum_ = 0;
//     vector<long long int> sum_prfx = sumsPrefix(nums);
    
//     for(size_t i = 0; i <= n; i++){
//         for(size_t len = a; len <= b; len++){
//             if (i+len <= n)
//             {
//                 sum_ = (sum_prfx[len+i] - sum_prfx[i]);
//                 if(sum_ > sumMaxTotal){
//                     sumMaxTotal = sum_;
//                 }
//             }
//         }
//     }
//     return sumMaxTotal;

// }


long long maxSubArraySumII3(vector<long long> &nums,int a, int b){//complejidad n
     int n = nums.size();
    long long sumMaxTotal = LLONG_MIN;
    long long sum_ = 0;

    deque<long long> dq;

    vector<long long> sum = sumsPrefix(nums);
    
    for (int i = a; i <= n; ++i) {
        if (!dq.empty() && dq.front() < i - b) {
            dq.pop_front();
        }
        while (!dq.empty() && sum[i - a] <= sum[dq.back()]) {
            dq.pop_back();
        }
        dq.emplace_back(i - a);
        sumMaxTotal = max(sumMaxTotal, sum[i] - sum[dq.front()]);
    }
  return sumMaxTotal;
 
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,a,b,value;
    cin>>n>>a>>b;
    vector<long long int> arr;

    for (size_t i = 0; i < n; i++)
    {          
        cin>>value;
        arr.push_back(value);
    }

    // cout<<maxSubArraySumII(arr,a,b)<<"\n";
    cout<<maxSubArraySumII3(arr,a,b)<<"\n";
    
    

    return 0;
}