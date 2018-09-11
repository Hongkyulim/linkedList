#include <iostream>
#include <cstdlib>

using namespace std;

struct node{
    int data;
    node* next;
};

typedef struct node* nodePtr;

nodePtr head;
nodePtr curr;
nodePtr temp;

class list{
private:
public:
    list();
    void addNode(int data);
    void delNode(int index);
    void display();
    void getNode(int idx);
    bool checkNode(int idx);
};

int main(){
    
    list L;
    L.addNode(0);
    L.addNode(1);
    L.addNode(2);
    L.addNode(3);
    L.addNode(4);
    L.addNode(5);
    L.addNode(6);
    L.addNode(7);
    L.addNode(8);
    L.display();
    
    L.delNode(2);
    L.delNode(4);
    L.delNode(6);
    L.delNode(8);
    L.display();
    
    L.getNode(3);
    L.getNode(5);
    L.getNode(4);
    
    return 0;
}

list::list(){
    head = NULL;
    curr=NULL;
    temp=NULL;
}

void list::addNode(int data){
    nodePtr n = new node;
    n->data = data;
    n->next = NULL;
    
    curr = head;
    
    if(head != NULL){
        while(curr->next != NULL ){
            curr = curr->next;
        }
        
        curr->next = n;
    }
    else{
        head = n;
    }
}

void list::delNode(int index){
    nodePtr delPtr = NULL;
    
    curr = head;
    while(curr->data != index){
        temp = curr;
        curr = curr->next;
    }
    
    if(head != NULL){
        if(curr != head){
            delPtr = curr;
            curr = curr->next;
            temp->next = curr;
        }
        else{
            delPtr = head;
            head = head->next;
        }
    }
    else{
        cout<<"The list is empty."<<endl;
    }
    delete delPtr;
    
}


void list::display(){
    curr=head;
    
    cout<<"Elements in the list : ";
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}



void list::getNode(int idx){
    if(head != NULL){
        if(checkNode(idx)){
            cout<<"Node '"<<idx<<"' is in the list."<<endl;
        }
        else{
            cout<<"Node '"<<idx<<"' is not in the list."<<endl;
        }
    }
    else{
        cout<<"The list is empty."<<endl;
    }
}

bool list::checkNode(int idx){
    
    if(head != NULL){
        curr = head;
        while(curr != NULL){
            if(curr->data == idx){
                return true;
            }
            curr = curr->next;
        }
    }

    return false;
}













