#include <iostream>
#include <vector>

using namespace std;

class Parent
{
	public:
		int pole;
		Parent() { pole = 0; }
		Parent(int n) { pole = n; }
		Parent(const Parent& obj) { pole = obj.pole; }
		Parent& operator+ (const Parent& obj)
		{
			Parent temp(this->pole + obj.pole);
			return temp;
		}

};

class Successor : public Parent
{
	public:
		Successor() : Parent() {}
		Successor(int n) : Parent(n) {}
		Successor(const Successor& obj) { pole = obj.pole; }
		Successor& operator+ (const Successor& obj)
		{
			Parent temp(obj.pole);
			Parent temp2;
			temp2 = Parent::operator+(temp);
			Successor temp3(2*temp2.pole);
			return temp3;
		}

};

int main(){
	vector <int> v(1, 2, 3, 4);
	Parent a(5), b(6);
	a = a + b;
	Successor c(5), d(6);
	c = c + d;
	cout << a.pole << " " << c.pole <<endl;
	system("PAUSE");
	return 0;
}