#include <bits/stdc++.h>

using namespace std;

void sortedOrder(vector<int> arr,int n){//Complejidad n con k²
    
    int in = 0, en = n-1,temp;
    int a,b;
    int aux[n];
    for (size_t i = 0; i < n; i++)
    {
        aux[i] = abs(arr[i] * arr[i]); 
    }
    

    while (arr[in] < 0)// k veces
    {
        en = n-1;
        while(arr[en] > 0){// k(n-k) veces
            if(aux[in] > aux[en]){
                temp = aux[in];
                aux[in] = aux[en];
                aux[en] = temp;
            }
            en--;
        }
        // break;
        in++;
    }

    for (size_t i = 0; i < n; i++)
    {
        cout << aux[i] <<" ";
    }
}

bool ordSquare(int i,int j){ return(i*i < j*j); }

void sortOrderSquare(vector<int> &arr){

    sort(arr.begin(), arr.end(), ordSquare); 
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=5;
    
    vector<int> array = {-4,-3,1,2,3};
    sortedOrder(array,n);
    vector<int> arr (array.begin(), array.begin()+n);
    sortOrderSquare(arr);
    cout<<"\n";

    for(auto x : arr) cout << x*x <<" ";
    cout<<"\n";
    
    return 0;
}
