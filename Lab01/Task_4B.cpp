#include <iostream>
using namespace std;
class Animal
{
public:
	void animalSound()
	{
	}
};
class Cats : public Animal
{
public:
	void animalSound()
	{
		cout << endl
			 << "Meoww Meoww";
	}
};
class Dogs : public Animal
{
public:
	void animalSound()
	{
		cout << endl
			 << "Wuf Wuf";
	}
};
class Birds : public Animal
{
public:
	void animalSound()
	{
		cout << endl
			 << "chirp chirp";
	}
};
int main()
{
	Birds crow;
	crow.animalSound();
	Cats kitten;
	kitten.animalSound();
	Dogs doggy;
	doggy.animalSound();
}