
#include <bits/stdc++.h>
//algoritmo kadane
using namespace std;

// vector<int> nearestSmallVal(vector<int> &nums){
    
//     int n = nums.size();
//     vector<int> NSValues;
//     NSValues.push_back(0);

//     int minVal = nums[0];
//     int index_ = 0;
//     int ret; 

//     for (size_t i = 1; i < n; i++)
//     {
//         ret = i-1;
//         while (ret >= 0 )
//         {
//             if (nums[ret] < nums[i])
//             {
//                 NSValues.push_back(ret+1);
//                 ret = -1;
//             }else if (minVal < nums[i]){
//                 {
//                     NSValues.push_back(index_+1);
//                     ret = -1;
//                 }
                
//             }else {
//                 NSValues.push_back(0);
//                 ret = -1;
//             }
//             ret--;
//         }
        
//         if (nums[i] < minVal)
//         {
//             minVal = nums[i];
//             index_ = i;
//         }
        
//     }
//     return  NSValues;
    
// }


vector<int> nearestSmallVal(vector<int> &nums){//complejidad n
    
    int n = nums.size();
    vector<int> NSValues;
    NSValues.push_back(0);

    stack<int> minVal;
    minVal.push(0);//pos
    bool isTrue = false;
    for (size_t i = 1; i < n; i++)
    {
        isTrue = false;
        while (!minVal.empty() && isTrue == false)
        {
            if (nums[minVal.top()] < nums[i])
            {
                NSValues.push_back(minVal.top()+1);
                minVal.push(i);
                isTrue = true;
            }else{
                minVal.pop();
            }   
        }if (minVal.empty())
        {    
            NSValues.push_back(0);
            minVal.push(i);
        }
    }
    
    return  NSValues;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,value;
    cin>>n;
    vector<int> arr(n);
    for (size_t i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
 
    for (auto x:nearestSmallVal(arr))
    {
        cout<<x<<" ";
    }
    
    cout<<"\n";

    return 0;
}