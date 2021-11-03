#include <bits/stdc++.h>

using namespace std;

void integerList(string text, vector<int> arr){//stack and queue

    stack<int> elem_inv1;
    deque<int> elem_inv2;

    if (text.size()>arr.size()) {
        cout<<"error"<<endl;
        return ;
    }
    for (size_t i = 0; i < arr.size(); i++) elem_inv2.push_back(arr[i]);
    
    string isStoreIn= "deque";


    for (size_t i = 0; i < text.size(); i++)
    {
        
        if (text[i] == 'R')
        {   
            if (isStoreIn == "stack"){
                while (!elem_inv1.empty())
                {
                    elem_inv2.push_front(elem_inv1.top());
                    elem_inv1.pop();
                }
                
                isStoreIn = "deque";

            }else if(isStoreIn == "deque")
            {   
                while (!elem_inv2.empty())
                {
                    elem_inv1.push(elem_inv2.front());
                    elem_inv2.pop_front();
                }
                isStoreIn = "stack";
            }
            
            
        }else if (text[i] == 'D')
        {
        
            if (isStoreIn == "stack"){
                elem_inv1.pop();
                
            }else if(isStoreIn == "deque")
            {
                elem_inv2.pop_front();
            } 
        }  
       
    }
    // string result = "[";
    if (!elem_inv1.empty())
    {
        while (!elem_inv1.empty())
        {    
            // result += to_string(elem_inv1.top()) + ",";
            cout<<elem_inv1.top()<<" ";
            elem_inv1.pop();
        }
    }else if(!elem_inv2.empty())
    {
        while (!elem_inv2.empty())
        {
            // result += to_string(elem_inv2.front()) + ",";
            cout<<elem_inv2.front()<<" ";
            elem_inv2.pop_front();
        }
    }
    cout<<endl;
    // result = result.substr (0,result.size ()-1);
    // result += "]";
    // cout<<result<<"\n";
    // return 1;

}

// int integerList(string text, vector<int> arr){//deque n^2

//     deque<int> proc_rd;
//     for (size_t i = 0; i < arr.size(); i++) proc_rd.push_back(arr[i]);

//     for (size_t i = 0; i < text.size(); i++)
//     {
//         if (text.size()>arr.size()) return 0;

//         if (text[i] == 'R')
//         {   
//             deque<int> aux;
//             int tam =  proc_rd.size();
//             for (size_t j = 0; j < tam ; j++)
//             {
                
//                 int val = proc_rd.back();
//                 aux.push_back(val);
//                 proc_rd.pop_back();

//             }   
//             proc_rd = aux;     
//         }else if (text[i] == 'D')
//         {
            
//             proc_rd.pop_front();
//         }  
       
        
//     }
//     while (!proc_rd.empty())
//     {
//         cout << proc_rd.front()<<" ";
//         proc_rd.pop_front();
//     }
//     cout<<"\n";
//     return 1;
// }



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q,val,n;
    cin>>q;
    
    while (q--)
    {
        
        string text;
        cin>>text;
        cin>>n;
        vector<int> arr(n);
        for (size_t i = 0; i < n; i++) cin>>arr[i];

        integerList(text, arr);
      
    }
    return 0;
}
