#include <bits/stdc++.h>

using namespace std;

void twoPointer(int* arr,int n,int target){//complejidad n³
    
    int in,en = n-1,auxT;
    int sum;
    // int endP = *(arr+(n-1));
    // cout << endP << "\n";

    for (size_t i = 0; i < n; i++)
    {
        auxT = target - *(arr+i);
        en = n-1;
        in = i+1;

        while(in != en){
            
            sum = *(arr+in) + *(arr+en);
            if (sum < auxT ) { auxT = auxT - sum; in++; }
            else if (sum > auxT ) { auxT = auxT - sum; en--; }
            else auxT -=sum ;
            // cout<<auxT<<endl;
            if (auxT == 0) {
                // cout<<"[ "<<i<<","<<in<<","<<en<<"]\n"; 
                break;
            } else auxT = target - *(arr+i);

        }
        if( auxT == 0 ) {
            cout<<"[ "<<i<<","<<in<<","<<en<<"]\n";
            break;
        }
    }    
}

vector<int> twoPointer2(vector<int> arr,int target){

    vector<int> idx;
    int n = arr.size();
    map<int,int> aux;

    int in,en,target_fake,sum_;

    for(size_t i = 0; i < n ; i++){
        aux[arr[i]] = i;
    }


    sort(arr.begin(),arr.begin()+n);

    bool isTrue = true;
    for(size_t j = 0; j < n; j++){
        target_fake = target - arr[j];
        in = j+1;
        en = n-1;
        
        while(in < en){
            sum_ = arr[in]+arr[en]; 
            if (sum_ < target_fake ) in++;
            else if (sum_ > target_fake ) en--;
            else break;
        }
    
        if (in == en) isTrue = false; 
        else{
            map<int,int>::iterator j_idx = aux.find(arr[j]);
            map<int,int>::iterator in_idx = aux.find(arr[in]);
            map<int,int>::iterator en_idx = aux.find(arr[en]);

            idx.push_back( j_idx->second );
            idx.push_back( in_idx->second );
            idx.push_back( en_idx->second );
            isTrue = true;
            return idx;
        }

    }
    if(!isTrue) cout << "IMPOSSIBLE\n";
    
    
    return idx;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n = 5;
    // cin>>n;
    int target = 19;
    // cin>>target;

    
    int array[n] = {1,2,4,5,12};
    
    twoPointer(array,n,target);
    
    vector<int> arr;
    for (size_t i = 0; i < n; i++)
    {
        arr.push_back(array[i]);
    }
    
    vector<int> idx = twoPointer2(arr,target);

    cout<<"[ ";
    for(auto x : idx) cout << x <<" ";
    cout<<"]\n";

    return 0;
}
