#include <iostream>
#include<conio.h>
using namespace std;

const int size = 100;

class HashTableEntry
{
	public:
		int val;
		int key;
		HashTableEntry(int key,int val)
		{
			this->key = key;
			this->val = val;
		}
};

class HashMapTable 
{
	public:
		HashTableEntry **t;
		HashMapTable()
		{
			t = new HashTableEntry *[size];
			for(int i=0;i<size;i++)
			{
				t[i] = NULL;
			}
		}
		int Hashfunc(int key)
		{
			return (key%size);
		}
		void insert(int key,int val)
		{
			int h = Hashfunc(key);
			while(t[h]!=NULL && t[h]->key != key)
			{
				h = Hashfunc(h+1);
			}
			if(t[h]!=NULL)
			{
				delete t[h];
			}
			t[h] = new HashTableEntry(key,val);
		}
		int SearchKey(int key)
		{
			int h = Hashfunc(key);	
			while(t[h]!=NULL && t[h]->key != key)
			{
				h = Hashfunc(h+1);
			}
			if(t[h]==NULL)
			{
				return -1;
			}
			else
			{
				cout<<"Element finded: "<<t[h]->val<<endl;
			}
		}
		int SizeOfBook()
		{
			int count=0,j=0;
			while(j<100)
			{
				if(t[j])
				{
				count++;
				}
				j++;
			}
			return count;
		}
		bool IsEmpty()
		{
			if(SizeOfBook())
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		void Remove(int key)
		{
			int h = Hashfunc(key);
			while(t[h]!=NULL)
			{
				if(t[h]->key==key)
				{
					break;
				}
				h = Hashfunc(h+1);
			}
			if(t[h]!=NULL)
			{
				delete t[h];
				cout<<"Element deleted: ";
				return;
			}
			else
			{
				cout<<"No elemented found\n";
			}
		}
};

int main() {
   HashMapTable hash;
   int k, v;
   int c;
   while (1) 
   {
   		cout<<"Enter any key for continue...."<<endl;
   		getch();
   		system("cls");
      cout<<"1.Insert element into the table"<<endl;
      cout<<"2.Search element from the key"<<endl;
      cout<<"3.Delete element at a key"<<endl;
      cout<<"4.Exit"<<endl;
      cout<<"Enter your choice: ";
      cin>>c;
      switch(c) 
	  {
         case 1:
            cout<<"Enter element to be inserted: ";
            cin>>v;
            cout<<"Enter key at which element to be inserted: ";
            cin>>k;
            hash.insert(k, v);
        break;
         case 2:
            cout<<"Enter key of the element to be searched: ";
            cin>>k;
            if (hash.SearchKey(k) == -1) {
               cout<<"No element found at key "<<k<<endl;
               continue;
            } else {
               cout<<"Element at key "<<k<<" : ";
               cout<<hash.SearchKey(k)<<endl;
            }
         break;
         case 3:
            cout<<"Enter key of the element to be deleted: ";
            cin>>k;
            hash.Remove(k);
         break;
         case 4:
         	cout<<"Size of Contact Book: "<<hash.SizeOfBook()<<endl;
			cout<<"Contact Book Empty: "<<hash.IsEmpty();
            exit(1);
         default:
            cout<<"Enter correct option";
      }
   }
}
