#include <iostream>
#include <stack>
#include <list>

using namespace std;

stack<int> stack_order(stack<int> desor){

  list<int> _list;
  // int value = desor.top();
  // _list.push_back(0);
  _list.push_back(desor.top());
  desor.pop();

  // if(desor.top() <= _list.front()) _list.push_front(desor.top());
  // else _list.push_back(desor.top());
  // desor.pop();

  while(!desor.empty()){
    
    bool is = false;
    list<int>::iterator index;
    for (list<int>::iterator it=_list.begin(); it!=_list.end(); ++it){
      if(desor.top() <= *it){
        is = true;
        _list.insert(it,desor.top());
        break;
      }
    }
    if(!is){
      _list.push_back(desor.top());
    }
    // if (value >= desor.top()){
    //   _list.push_front(desor.top());
    // }else{
    //   _list.push_back(desor.top());
    // }
    // value = desor.top(); 
    desor.pop();
  }
  
  _list.reverse();

  stack<int> result;
  for (list<int>::iterator it=_list.begin(); it != _list.end(); ++it){
    //  cout << *it <<endl;
     result.push(*it);
  }
  return result;

}

int main() {
  stack<int> desor;
  //Ingrese el la cantidad de digitos
  
  int tam;
  cin>>tam;
  //cantidad de digitos : 5
  //CASOS DE PRUEBA: 12 80 3 20 90
  //SALIDA: 3 12 20 80 90
  
  int values;
  for(int i = 0 ; i < tam;i++){
    cin>>values;
    desor.push(values);
  }
  
  // desor.push(90);
  // desor.push(20);
  // desor.push(3);
  // desor.push(80);
  // desor.push(12);

  stack<int> _stack = stack_order(desor);
  
  while(!_stack.empty()){
    cout << _stack.top() <<" ";
    _stack.pop();
  }    
  return 0;
}

