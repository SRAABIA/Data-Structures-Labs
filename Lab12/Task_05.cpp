#include<iostream>
#include<conio.h>
using namespace std;
const int size = 5;
class HashNode{
	public:
		string name;
		string pass;
		HashNode *next;
	
	HashNode(string n ,string p)
	{
		name = n;
		pass = p;
		next = NULL;
	}
};
class HashTable{
	public:
		HashNode* *h;
		
		HashTable()
		{
			h = new HashNode*[size];
			for(int i = 0; i<size;i++)
			{
				h[i] = NULL;
			}
		}
		
		int hashfunc(string pass)
		{
			int num = pass[0];

			return num%size;
		}
		
    void insertion1(string name,string pass)
    {
    	int hashval = hashfunc(pass);
    	HashNode *prev = NULL;
    	HashNode *root = h[hashval];
        while (root != NULL)
        {
            prev = root;
            root = root->next;
        }
        if(root==NULL)
        {
            root = new HashNode(name,pass);
        	if(prev==NULL)
        	{
            	h[hashval] = root;
			}
			else
			{
				prev->next = root;
				
			}
		}
		else
		{
			root = new HashNode(name,pass);
		}
		
	}
	
    int Search(string pass)
    {
        bool flag = false;
        int hashval = hashfunc(pass);
        HashNode* entry = h[hashval];
        while (entry != NULL)
    	{
       		if (entry->pass == pass)
        	{
          		cout<<"Name		:		"<<entry->name<<"\nPassword	:		"<<entry->pass<<endl;
          		flag = true;
        	}
        	entry = entry->next;
        }
        	if (!flag)
        		cout<<endl<<"Data Not Found"<<endl;
    }
    void update(string pass)
    {
        bool flag = false;
        int hashval = hashfunc(pass);
        HashNode* entry = h[hashval];
        while (entry != NULL)
    	{
       		if (entry->pass == pass)
        	{
        		cout<<"Data Founded "<<endl;
          		cout<<"Name		:		"<<entry->name<<"\nPassword	:		"<<entry->pass<<endl;
          		
          		cout<<"Enter the updated name : ";
				cin>>entry->name;
				cout<<"Enter the updated password : ";
				cin>>entry->pass;
				
				cout<<endl<<endl<<"Data Updated..."<<endl;
          		flag = true;
        	}
        	entry = entry->next;
        }
        	if (!flag)
        		cout<<endl<<"Data Not Found"<<endl;
    }
    
    void deletion(string pass)
    {
        int hashval = hashfunc(pass);
        HashNode* entry = h[hashval];
        HashNode* prev = NULL;
        if (entry == NULL )
        {
      	cout<<"No Element found"<<endl;
        return;
        }
        while (entry->next != NULL)
   	    {
           prev = entry;
           entry = entry->next;
        }
        if (prev != NULL)
        {
         prev->next = entry->next;
        }
        delete entry;
        cout<<"Element Deleted"<<endl;
    }
    
    
	
		
};
int main()
{
	HashTable h;
	
	while(1)
	{
		system("cls");
		int choise;
		cout<<"1 . Insertion\n2 . Search\n3 . Update\n4 . Delete\n5 . Exit"<<endl;
		cout<<"Enter your choise :";
		cin>>choise;  		
		switch(choise)
		{
			case 1:{
				string name ,pass;
				cout<<"Enter the name :";
				cin>>name;
				cout<<"Enter the password :";
				cin>>pass;
				h.insertion1(name,pass);
				break;
			}
			case 2:{
				string pass;	
				cout<<"Enter the password :";
				cin>>pass;
				h.Search(pass);
				getch();
				break;
			}
			case 3:{
				string pass;	
				cout<<"Enter the password :";
				cin>>pass;
				h.update(pass);
				break;
			}
			case 4:{
				string pass;	
				cout<<"Enter the password :";
				cin>>pass;
				h.deletion(pass);
				break;
			}
			case 5:{
				exit(1);
				break;
			}
		}
	}
}