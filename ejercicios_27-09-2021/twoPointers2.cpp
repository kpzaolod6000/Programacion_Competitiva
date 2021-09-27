#include <bits/stdc++.h>

using namespace std;

void twoPointer(int* arr,int n,int target){
    
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

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n = 5;
    // cin>>n;
    int target = 19;
    // cin>>target;

    
    int array[n] = {1,2,4,5,12};
    
    // for (size_t i = 0; i < n; i++)
    // {
    //     cin>>array[i];        
    // }

    twoPointer(array,n,target);

    return 0;
}