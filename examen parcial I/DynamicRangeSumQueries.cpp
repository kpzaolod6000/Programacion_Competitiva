#include <bits/stdc++.h>

using namespace std;

int maxPrefixSums(vector<int> arr,int init,int end){
    
    int max_ = 0, sum_ = 0;

    for (size_t i = init; i <= end; i++){
        sum_ += arr[i];
        if(sum_ > max_) max_ = sum_;         
    }
    if (max_ < 0) return 0;    
    return max_;

}
void dynRangSumQueries(vector<int> &arr,int qline){

    if(qline == 1){
        int k,u;
        cin>>k>>u;
        arr[k - 1] = u;
    }else if(qline == 2){ 
        int a,b;
        cin>>a>>b;
        cout<<maxPrefixSums(arr,a-1,b-1)<<"\n";
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,q,value;
    cin >> n >>q;

    vector<int> arr;
    for (size_t i= 0;i < n; i++){
        cin>>value;
        arr.push_back(value);
    }
    
    // vector<int> output;
    int qline;

    while (q--)
    {
        cin>>qline; 
        dynRangSumQueries(arr,qline);
        //qline.clear();
    }

    return 0;
}