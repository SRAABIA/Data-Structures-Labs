#include<iostream>
using namespace std;
const int size = 8;
static int count1  = 0;
static int count2 = 0;
class Hash{
	public:
		int data;
		int key;
		Hash(int d , int k)
		{
			data = d;
			key = k;
		}
		
};
class LinearHashing{
	public:
		Hash* *h;
		
		LinearHashing()
		{
			h = new Hash*[size];
			for(int i = 0;i < size;i++)
			{
				h[i] = NULL;
			}
		}
		
		int hashfunc(int key)
		{
			return key%size;
		}
		void isnertion(int data,int key)
		{
			int i = 0;
			int hashval = hashfunc(key);
			
			while(h[hashval]!=NULL)
			{
				hashval = hashfunc(hashval+1);
				i++;
				count1++;
			}
			h[hashval] = new Hash(data,key);
			cout<<"Probing count in the isnertion of "<<key<<" is "<<i<<endl<<endl;
		}
};
class QuardHashing{
	public:
		Hash* *h;
		
		QuardHashing()
		{
			h = new Hash*[size];
			for(int i = 0;i < size;i++)
			{
				h[i] = NULL;
			}
		}
		
		int hashfunc(int key)
		{
			return key%size;
		}
		void isnertion(int data,int key)
		{
			int i = 0;
			int hashval = hashfunc(key);
			while(h[hashval]!=NULL)
			{
				
				hashval = hashfunc(hashval+(i*i));
				count2++;
				i++;
			}
			h[hashval] = new Hash(data,key);
			cout<<"Colision in the isnertion of "<<key<<" is "<<i<<endl<<endl;
		}
};
int main()
{
	cout<<"*-*-*-*-*-*-*-*Linear Probing*-*-*-*-*-*-*-*-*"<<endl<<endl;
	LinearHashing l;
	QuardHashing q;
	l.isnertion(3,3);
	l.isnertion(2,2);
	l.isnertion(9,9);
	l.isnertion(6,6);
	l.isnertion(11,11);
	l.isnertion(13,13);
	l.isnertion(7,7);
	l.isnertion(12,12);
	cout<<"Total Number of collision :"<<count1;
	
	cout<<endl<<endl<<"*-*-*-*-*-*-*-*Quardatic Probing*-*-*-*-*-*-*-*-*"<<endl<<endl;
	q.isnertion(3,3);
	q.isnertion(2,2);
	q.isnertion(9,9);
	q.isnertion(6,6);
	q.isnertion(11,11);
	q.isnertion(13,13);
	q.isnertion(7,7);
	q.isnertion(12,12);	
	cout<<"Total number of collision :"<<count2<<endl;
	
	
}
