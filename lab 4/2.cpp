#include<iostream>

using namespace std;

bool checkValidIdentifier(string s)
{
	if ((s[0] == '_') || (s[0] >= 65 && s[0] <= 90) || (s[0] >= 97 && s[0] <= 122))
		{;}
	else
		return false;
	int i = 1;
	for(i=1; i<s.size(); i++)
	{
		if (s[i] == '_' || (s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57))
			continue;
		else
			return false;
	}
	
	return true;
}
int main()
{
	string s;
	cout<<"Enter identifier: ";
	getline(cin, s);
	bool d;
	d = checkValidIdentifier(s);
	if (d == true)
		cout<<"Valid Identifier !\n";
	else
		cout<<"Invalid Identifier !\n";
	return 0;
}
