#include <bits/stdc++.h>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> sorted;

    for (size_t i = 0; i < nums.size(); i++) sorted.push(nums[i]);
    
    for (size_t i = 1; i < k; i++)
    {
        sorted.pop();
    }
    return sorted.top();
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for (size_t i = 0; i < n; i++) cin>>arr[i];
    cout<<findKthLargest(arr,k)<<"\n";

    return 0;
}
