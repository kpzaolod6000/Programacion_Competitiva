#include<iostream>

using namespace std;

int maximo_product(int N,int arr[]){
    int mayor = 0;
    int firts_index = 0;
    for (int i = 0; i<N ;i++){
        if (arr[i] > mayor){
            mayor = arr[i];
            firts_index = i;
        }
    }
    int mayor_sec = 0;
    for (int i = 0; i<N ;i++){
        if (i != firts_index){
            if (arr[i] > mayor_sec){
                mayor_sec = arr[i];
            }
        }
    }
    return mayor * mayor_sec;
}

int main()
{
    int N;
    cin>>N;

    int arr[N];
    int value;
    for(int i=0; i<N;i++){
        cin>>value;
        arr[i] = value;
    } 
    
    cout << maximo_product(N,arr) << endl;

}