#include <bits/stdc++.h>
using namespace std; 

struct Person{
    int money;
    int time;
    
    Person(int m, int w){
        money = m;
        time = w;
    }
};

bool Compare(const Person &a, const Person &b){
        return a.money >= b.money;
}

void queuePerson(vector<int> &v, Person c){
    int i = c.time;
    
    while(i >= 0){
        if(v[i] == 0){
            v[i] = c.money;
            return;
        }  
        i--; 
    }
}

int main(){ 

    int N, T, ci, ti;
    int sum = 0;
    int i = 0;
	
    cin>>N>>T;
   
    vector<int> aux_queue(T);
    vector<Person> money;
    
    for(size_t i = 0; i < N; i++){
        cin>>ci>>ti;
        Person c(ci, ti);
        
        money.push_back(c); 
    }    
	
    sort(money.begin(), money.end(), Compare);    
    
    while(i < money.size()){
        queuePerson(aux_queue, money[i]);
        i++;
    }    
    
    for(int i = 0; i < aux_queue.size(); i++){
        sum += aux_queue[i];
    }
    
    cout<<sum<<endl;
    
    return 0;
}