#include<iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> find_bucle(int N,int arr[]){

  vector< pair <int,int> > conteo;
  conteo.push_back( make_pair(arr[0],1) );
  for (int i=1; i<N; i++)
  {
    bool isList = false; 
    int index;
    for(int j = 0 ; j < conteo.size() ; j++){
      if( conteo[j].first == arr[i]){
        isList = true;
        index = j;
        break;
      } 
    }
    if(isList) conteo[index].second += 1;
    else conteo.push_back( make_pair(arr[i],1));
    
  }

  vector<int> result;
  for( int i = 0; i < conteo.size(); i++)
    if(conteo[i].second  > 2) result.push_back(conteo[i].first); 
  return result;
  
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
    vector<int> result = find_bucle(N,arr);
    for(int i=0; i<result.size();i++){
        cout << result[i] <<endl;
    }   
    
}