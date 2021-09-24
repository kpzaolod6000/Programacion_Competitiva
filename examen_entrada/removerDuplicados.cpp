#include <iostream>

using namespace std;

class Node
{
    public:
        Node *next;
        int data;

        Node();
        Node(int);
        ~Node();
        void delete_all();
        void print();
};
Node ::Node()
{
    next = NULL;
}
 
Node :: Node(int data){
    this->data = data;
    next = NULL;
}

void Node::delete_all()
{
    if (next)
        next->delete_all();
    delete this;
}
 
void Node::print()
{
    cout << data << "-> ";
}
 
Node::~Node() {}

class list
{
    private:
        Node* _head;
        int tam;
    public:
        list();
        //list(int);
        void insert(int);
        void delete_duplicate();
        void print();

        ~list();
};

list :: list(){
    tam = 0;
    //this-> tam = tam;
} 

void list::insert(int data){
    Node* new_node = new Node(data);
    Node* aux = _head;

    if(!_head){
        _head = new_node;
    }else{
        while (aux->next != NULL) aux = aux->next;
        aux->next = new_node;
    }
    
    tam++;
}

void list::print(){
    cout<<"Total de elementos: "<<tam<<endl;
    Node* aux = _head;
    do
    {
        aux->print();
        aux = aux->next;
    } while (aux != NULL);
    cout<<endl;

}
void list::delete_duplicate(){
    Node* aux_p = _head;
    int temp_data;
    while(aux_p != NULL){
        temp_data = aux_p->data;
        Node* aux_s = aux_p;
        Node* aux_actual = aux_s->next;
        while(aux_actual != NULL){
            
            if(temp_data == aux_actual->data){
                if(aux_actual->next != NULL){
                    aux_s->next = aux_actual->next;
                }
                delete aux_actual;
                aux_actual = 0;
            }
            if(aux_actual == NULL){
                aux_s->next = aux_actual;
            
            }else{
                aux_s = aux_s->next;
                aux_actual = aux_s->next;
            }
        } 
        aux_p = aux_p->next;
    }
}

list::~list() {
    _head->delete_all();
    _head = 0;
}


using namespace std;

int main()
{
    //CASOS DE PRUEBA :   14-> 10-> 5-> 1-> 20-> 10-> 
    //SALIDA: 14-> 10-> 5-> 1-> 20-> 

    //CASOS DE PRUEBA :20-> 5-> 20-> 5-> 5-> 5-> 
    //SALIDA: 20-> 5->
    list* _list = new list();
    _list->insert(14);
    _list->insert(10);
    _list->insert(5);
    _list->insert(1);
    _list->insert(20);
    _list->insert(10);
    _list->print();
    _list->delete_duplicate();
    _list->print();
    return 0;
}