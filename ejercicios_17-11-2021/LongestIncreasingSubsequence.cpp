
#include <bits/stdc++.h>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int  n = nums.size();
    int max_ = 1;
    
    if(n == 1) return 1;
    
    vector<int> dp_SubSeq(n);
    
    dp_SubSeq[0] = 1;

    for(size_t i = 1; i < n; i++)
    {
        for(size_t j = 0; j <= i; j++)
        {
            if(nums[i] > nums[i - j])
                dp_SubSeq[i] = max(dp_SubSeq[i], dp_SubSeq[i - j]);
        }
        
        dp_SubSeq[i] += 1;
        
        max_ = max(max_, dp_SubSeq[i]);
    }
    
    return max_;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    vector<int> arr(n);

    for(size_t i=0; i<n; i++) cin>>arr[i];
   
    cout<<lengthOfLIS(arr)<<"\n";
    return 0;
}