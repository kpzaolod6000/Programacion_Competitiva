#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> nums(n);
    for (size_t i = 0; i < n; i++) cin>>nums[i];

    // *************
    vector<vector<int>> result_leaves;
    int g = 0;
    queue<int> leaves;
    vector<int> stay;
    vector<int> aux;

    bool isequal = false;
    while (nums.size() != 1 && isequal == false)
    {
        stay.clear();
        aux.clear();
        
        int prev = nums[0];
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (prev != nums[i]){
                isequal = false;
                break;
            }else{
                isequal = true;
            }
            prev = nums[i];
        }
        
        if (isequal){
            result_leaves.push_back(nums);
            break;
        }
        
        for (size_t i = 0; i < nums.size(); i++)
        {
            
            if (i == 0)
            {
                if (nums[i] < nums[i+1])
                {
                    leaves.push(nums[i]);
                    // cout<< nums[i]<<" ";
                }else
                {
                    stay.push_back(nums[i]);    
                }
                
            }else if ( i == nums.size() - 1){
                
                if (nums[i] < nums[i-1])
                {
                    leaves.push(nums[i]);
                    // cout<< nums[i]<<" ";
                }else
                {
                    stay.push_back(nums[i]);    
                }
            }else{
                if (nums[i] < nums[i+1] || nums[i] < nums[i-1] )
                {
                    leaves.push(nums[i]);
                    // cout<<nums[i]<<" ";
                }else{
                    stay.push_back(nums[i]);
                }
                
            }
            
        }
        
        while(!leaves.empty()){
            aux.push_back(leaves.front());
            leaves.pop();
        }
        result_leaves.push_back(aux);
        nums = stay;
        g++;
    }
    // *************
    // InterviewQueue(arr);


    cout<<g<<"\n";
    if (nums.size() == 1)
    {
        result_leaves.push_back(nums);
    }
    

    for(auto arr : result_leaves){
        for(auto x : arr) {
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
