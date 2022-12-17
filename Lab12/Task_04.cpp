#include<iostream>
#include<conio.h>
using namespace std;
int size = 5 ; 
class Hash{
	public:
		int id;
		string name;
		string num;
		
		Hash(int i , string n , string nu)
		{
			id = i;
			name = n;
			num = nu;	
		}
};
class HashTable{
	public:
		Hash* *h;
		
		HashTable()
		{
			h = new Hash*[size];
			
			for(int i =0; i<size;i++)
			{
				h[i] = NULL;
			}
		}
		
		int hashfunc(int key)
		{
			return key%size;
		}
		
		void create_record(int id,string name,string num)
		{
			int hashval = hashfunc(id);
			
			while(h[hashval]!=NULL)
			{
				hashval = hashfunc(hashval+1);
			}
			
			h[hashval] = new Hash(id,name,num);
			
			cout<<"Inserted...."<<endl;
			
		}
		
		void search(int key)
		{
			int hashval = hashfunc(key);
			
			while(h[hashval]!=NULL && h[hashval]->id!=key)
			{
				hashval = hashfunc(hashval+1);
			}
			
			cout<<"Record Found\nId			:	"
			<<h[hashval]->id<<"\nName 			:	"
			<<h[hashval]->name<<"\nMob Number		:	"
			<<h[hashval]->num<<endl;
		}
		void display()
		{
			int i = 0;
			int l = 0;
			while(i<5)
			{
				if(h[i]!=NULL)
				{
					cout<<"\nId			:	"
					<<h[i]->id<<"\nName 			:	"
					<<h[i]->name<<"\nMob Number		:	"
					<<h[i]->num<<endl;
					cout<<endl<<endl;
					l = 1;
				}
				i++;
			}
			if(l==0)
			{
				cout<<"No record Found"<<endl;
			}
		}
		
		void update(int key)
		{
			int hashval = hashfunc(key);
			
			while(h[hashval]!=NULL && h[hashval]->id!=key)
			{
				hashval = hashfunc(hashval+1);
			}
			
			cout<<"Record Found\nId			:	"
			<<h[hashval]->id<<"\nName 			:	"
			<<h[hashval]->name<<"\nMob Number		:	"
			<<h[hashval]->num<<endl;
			string no;
			cout<<"Enter the updated number :";
			cin>>no;
			
			h[hashval]->num = no;
			cout<<"Record Updated...."<<endl;
		}
		
		void deletee(int key)
		{
			int hashval = hashfunc(key);
			
			while(h[hashval]!=NULL && h[hashval]->id!=key)
			{
				hashval = hashfunc(hashval+1);
			}
			
			h[hashval] = NULL;
			cout<<"Record Deleted...."<<endl;
		}	
};
int main()
{
	HashTable h1;
	int id;
	string name,num;
	while(1)
	{
		getch();
		system("cls");
		int choise;
		cout<<"1 . Create Record \n2 . Display Record\n3 . Update Record\n4 . Delete Reord\n5 . Search Record\n6 . Exit\n";
		cout<<"Enter your choise :";
		cin>>choise;
		
		switch(choise)
		{
			case 1:{
				cout<<"Enter the id :";
				cin>>id;
				cout<<"Enetr the name :";
				cin>>name;
				cout<<"Enter the phone number :";
				cin>>num;
				h1.create_record(id,name,num);
				break;
			}
			case 2:{
				cout<<"************All Records**************";
				h1.display();
				break;
			}
			case 3:{
				cout<<"Enter the id for update :";
				cin>>id;
				h1.update(id);
				break;
			}
			case 4:{
				cout<<"Enetr the id for deletion :";
				cin>>id;
				h1.deletee(id);
				break;
			}
			case 5:{
				cout<<"Enter the id for searching :";
				cin>>id;
				h1.search(id);
				break;
			}
			case 6:{
				exit(1);
				break;
			}
		}
	} 	
}
