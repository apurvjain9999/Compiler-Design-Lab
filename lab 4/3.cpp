#include<iostream>

using namespace std;

bool check(string s)
{
	int i;
	int f = -1;
	for(i=0; i<s.size(); i++)
	{
		if (s.at(i) != 'a')
		{
			f = i;
			break;
		}
	}
	if (f == -1)
		return true;
	
	for(i=f; i<s.size(); i++)
	{
		if(s.at(i) != 'b')
			return false;
	}
	return true;
}

int main()
{
	string s = "";
	cout<<"Enter string: ";
	getline(cin, s);
	bool d;
	d = check(s);
	if (d)
		cout<<"String is valid!";
	else
		cout<<"String is not valid!";
}
