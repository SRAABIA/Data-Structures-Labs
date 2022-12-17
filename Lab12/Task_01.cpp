#include<iostream>
using namespace std;
const int table_size = 10;
class Hash{
    public:
    int data;
    Hash*next;
    Hash(){
        data = 0;
        next=NULL;
    }
    Hash(int d){
        data = d;
        next=NULL;
    }
};

class HashTable{
    public:
    Hash **table;
    int table_s;
    HashTable(){
        table_s = table_size;
        table = new Hash*[table_size];
        for(int i = 0 ; i<table_size; i++){
            table[i] = NULL;
        }
    }
    HashTable(int s){
        table_s = s;
        table = new Hash*[table_s];
        for(int i = 0 ; i<table_s; i++){
            table[i] = NULL;
        }
    }
    int HashingFunction(int key){
        return key % table_s;
    }
    void insert(int key){
        Hash* obj = new Hash(key);
        int hash1 = HashingFunction(key);
        if(table[hash1] == NULL){
            table[hash1] = obj;

        }
        //collision technique
        else if(table[hash1] != NULL){
            Hash*entry = table[hash1];
            while(entry->next!=NULL){
                entry = entry->next;
            }
            entry->next = obj;                                                          
        }
    }
    void print(int k){
        Hash*temp = table[k];
        while(temp!=NULL){
            cout<<" "<<temp->data<<" -> ";
            temp = temp->next;
        }
    }
    void Display_HashTable(){
        cout<<endl<<"\t------------------------------------------------------";
        for(int i=0;i<table_s;i++){
            cout<<endl<<"\t\t"<<i<<" -->";
            print(i);
        }
        cout<<endl<<"\t------------------------------------------------------";
    }
    void search(int val){
        int k = HashingFunction(val);
        Hash*temp = table[k];
        // I AM RAABIA AND I AM SAVAGE
        while(temp!=NULL){
            if(temp->data == val){
                cout<<endl<<"\tValue Found in the Hashtable.";
                return;
            }
            temp = temp->next;
        }
        cout<<endl<<"\tValue not found in the Hashtable.";
    }
    bool del(Hash*node,int k){
        Hash*temp = table[k];
        while(temp!=NULL){
            if(temp->next==node){
                Hash*abc = temp->next->next;
                delete(temp->next);
                temp->next = abc;
                return true;
            }
            temp = temp->next;
        }
    }
    void Delete(int val){
        int k = HashingFunction(val);
        Hash*temp = table[k];
        if(temp->data == val){
            Hash* node = temp->next;
            delete(temp);
            table[k] = node;
        }
        else{
        while(temp!=NULL){
            if(temp->data == val){
                if(del(temp,k)){
                    cout<<endl<<"\tSuccessfully Deleted [ "<<val<<" ].";
                }
                return;
            }
            temp = temp->next;
        }
        }
    }
};


int main(){
    HashTable hash(10);
    int k; int j;
    do{
    cout<<endl<<endl
    <<"\tSelect:"<<endl
    <<"\t0. Exit()"<<endl
    <<"\t1. Insert()"<<endl
    <<"\t2. Search()"<<endl
    <<"\t3. Delete()"<<endl
    <<"\t4. Display_HashTable()"<<endl
    <<"\t:: ";
    cin>>k;
    switch(k){
        case 1:
            cout<<endl<<"\tEnter value to insert: ";
            cin>>j;
            hash.insert(j);
        break;
        case 2:
            cout<<endl<<"\tEnter value to search: ";
            cin>>j;
            hash.search(j);
        break;
        case 3:
            cout<<endl<<"\tEnter value to delete: ";
            cin>>j;
            hash.Delete(j);
        break;
        case 4:
            hash.Display_HashTable();
        break;
    }
    }while(k!=0);
}