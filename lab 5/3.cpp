#include<iostream>
using namespace std;

int counter = 0;

char lookahead(char ch)
{
	return ch;
}

bool validIdentifier(string s)
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

bool E(string s);
bool E_1(string s);
bool F(string s);
bool T(string s);
bool T_1(string s);

bool E(string s)
{
	char ch = s[counter];
	if (lookahead(ch) == '(')
	{
		bool a;
		a = T(s);
		if (!a)
			return false;
		a = E_1(s);
		if (!a)
			return false;
	}
	else if (ch != '+' || ch != '*' || ch != '(' || ch != ')')
	{
		string d = "";
		int i;
		i = counter;
		while(ch != '+' || ch != '*' || ch != '(' || ch != ')')
		{
			d.push_back(ch);
			i++;
			ch = s[i];
		}
		if (validIdentifier(d))
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
	if (ch != '+' || ch != '*' || ch != '(' || ch != ')')
	{
		string d = "";
		while(ch != '+' || ch != '*' || ch != '(' || ch != ')')
		{
			d.push_back(ch);
			counter++;
			ch = s[counter];
		}
		if (validIdentifier(d))
		{
			counter++;
		}
		else
			return false;
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
	if (lookahead(ch) == '(')
	{
		bool a;
		a = F(s);
		if (!a)
			return false;
		a = T_1(s); 
		if (!a)
			return false;
	}
	else if (ch != '+' || ch != '*' || ch != '(' || ch != ')')
	{
		string d = "";
		int i;
		i = counter;
		while(ch != '+' || ch != '*' || ch != '(' || ch != ')')
		{
			d.push_back(ch);
			i++;
			ch = s[i];
		}
		if (validIdentifier(d))
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
