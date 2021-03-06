#include<iostream>
using namespace std;

int counter = 0;

char lookahead(char ch)
{
	return ch;
}

bool validIdentifier(char ch)
{
	if ((ch >= 48 && ch <= 57))
		return true;
	else
		return false;
}

bool E(string s);
bool E_1(string s);
bool F(string s);
bool T(string s);
bool T_1(string s);

bool E(string s)
{
	char ch = s[counter];
	if (lookahead(ch) == '(' || validIdentifier(ch))
	{
		bool a;
		a = T(s);
		if (!a)
			return false;
		a = E_1(s);
		if (!a)
			return false;
	}
	else
	{
		return false;
	}
	return true;
}

bool F(string s)
{
	char ch = s[counter];
	if (validIdentifier(ch))
	{
		counter++;
	}
	else if (lookahead(ch) == '(')
	{
		counter++;
		bool a;
		a = E(s);
		if (!a)
			return false;
		if (lookahead(ch) == ')')
			return true;
		else
			return false;
	}
	else
	{
		return false;
	}
	return true;
}

bool T(string s)
{
	char ch = s[counter];
	if (lookahead(ch) == '(' || validIdentifier(ch))
	{
		bool a;
		a = F(s);
		if (!a)
			return false;
		a = T_1(s); 
		if (!a)
			return false;
	}
	else
	{
		return false;
	}
	return true;
}

bool E_1(string s)
{
	char ch = s[counter];
	if (lookahead(ch) == '+')
	{
		counter++;
		bool a;
		a = T(s);
		if (!a)
			return false;	
		a = E_1(s);
		if (!a)
			return false;
	}
	
	else if (counter == s.length())	
		return true;
	else
		return false;
	
	return true;
}

bool T_1(string s)
{
	char ch = s[counter];
	if (lookahead(ch) == '*')
	{
		counter++;
		bool a;
		a = F(s);
		if (!a)
			return false;
		a = T_1(s);
		if (!a)
			return false;
	}
	
	else if (counter == s.length())
		return true;
	
	else
		return false;
	return true;
}



int main()
{
	string s;
	cout<<"Enter expression: ";
	cin>>s;
	bool a;
	a = E(s);
	if (!a)
		cout<<"\nString is not accepted\n";
	else
		cout<<"\nString accepted\n";
		
	return 0;
}
