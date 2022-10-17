#include <string>
#include <vector>
#include <iostream>

using namespace std;

class in
{
public:
	virtual void a();

};


class inn:in
{
public:
	void a()
	{
		cout << "a" << endl;
	}
};



