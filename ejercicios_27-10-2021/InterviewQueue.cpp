#include <bits/stdc++.h>

using namespace std;

void InterviewQueue(vector<int>& nums) {
    queue<int> leaves;
    vector<int> stay;
    // cout<<nums.size()<<"\n";

    if (nums.size() == 1)
    {
        cout<<nums[0]<<" ";
        return ;
    }else
    {
        int prev = nums[0];
        bool isequal = false;
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (prev != nums[i]) break;
            else isequal = true ;
        }
        if (isequal){
            for (size_t i = 0; i < nums.size(); i++)
            {
                cout<<nums[i]<<" ";
            }
            return ;
        }
        
    }
    
    
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (i == 0)
        {
            if (nums[i] < nums[i+1])
            {
                cout<< nums[i]<<" ";
            }else
            {
                stay.push_back(nums[i]);    
            }
            
        }else if ( i == nums.size() - 1){
            
            if (nums[i] < nums[i-1])
            {
                cout<< nums[i]<<" ";
            }else
            {
                stay.push_back(nums[i]);    
            }
        }else{
            if (nums[i] < nums[i+1] || nums[i] < nums[i-1] )
            {
                cout<<nums[i]<<" ";
            }else{
                stay.push_back(nums[i]);
            }
            
        }
        
    }
    while(!leaves.empty()){
        cout<<leaves.front()<<" ";
        leaves.pop();
    }
    cout<<"\n";
    InterviewQueue(stay);

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> arr(n);
    for (size_t i = 0; i < n; i++) cin>>arr[i];
    InterviewQueue(arr);

    return 0;
}
