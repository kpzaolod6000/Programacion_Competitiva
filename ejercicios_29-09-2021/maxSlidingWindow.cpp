#include <bits/stdc++.h>

using namespace std;

vector<int> maxSlidingWindow(vector<int> vector_, int n, int k){//complejidad n^2
    
    int max_;
    vector<int> maxList;
    for (size_t i = 0; i < n-k+1; i++)
    {
        max_ = vector_[i];
        for (size_t j = i+1; j < i+k; j++)
        {
            max_ = max(max_,vector_[j]);
        }
        maxList.push_back(max_);
        
    }
    return maxList;

}



vector<int> maxSlidingWindow2(vector<int> &nums, int n, int k){//complejidad n²

    vector<int> max_list;
    deque<int> k_elem;
    //int max_ = 0;
    
    for (size_t i = 0; i < k ; i++) k_elem.push_back(nums[i]);
    deque<int>::iterator it = max_element(k_elem.begin(), k_elem.end());
    max_list.push_back(*it);

    for(size_t j = k; j < n ; j++){
        k_elem.pop_front();
        k_elem.push_back(nums[j]);
        it = max_element(k_elem.begin(), k_elem.end());
        max_list.push_back(*it);
    }

    return max_list;

}

vector<int> maxSlidingWindows3(vector<int> &nums,int k){//complejidad n
    deque<int> slides;
    vector<int> maxValues;
    
    int left = 0;
    for(int right = 0; right < nums.size(); right++){
        if(!slides.empty() && slides.front() < left)
            slides.pop_front();
        
        while(!slides.empty() && nums.at(slides.back()) < nums.at(right))
            slides.pop_back();
        
        slides.push_back(right);
        if(right - left + 1 == k){
            maxValues.push_back(nums.at(slides.front()));
            
            left++;
        }
            
    }
    
    return maxValues;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 3;
    int n = 8;
    int arr[] = {1,3,-1,-3,5,3,6,7};
   

    //int k = 1;
    //int n = 1;
    // int arr[] = {1};
    
    vector<int> vector_ (arr, arr+n);
   

    for(auto x: maxSlidingWindow(vector_,n,k)) cout<<x<<" ";
    cout<<"\n";
    
    for(auto x: maxSlidingWindow2(vector_,n,k)) cout<<x<<" ";
    cout<<"\n";
    
   
    return 0;
}
