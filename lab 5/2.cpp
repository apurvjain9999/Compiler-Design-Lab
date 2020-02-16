#include<iostream>
using namespace std;
void E();
void T();
void E_1();
void T_1();
void F();
void E()
{
	T();
}

void E_1()
{
	cout<<"+, Empty\n";
}

void T()
{
	F();
}

void F()
{
	cout<<"id, (\n";
}

void T_1()
{
	cout<<"*, Empty\n";
}

int main()
{
	char ch;
	cout<<"Enter the variable: ";
	cin>>ch;
	if (ch == 'E')
	{
		E();
	}
	else if (ch == 'A')
	{
		E_1();
	}
	
	else if(ch == 'T')
	{
		T();
	}
	
	else if(ch == 'B')
	{
		T_1();
	}
	else if (ch == 'F')
	{
		F();
	}
	else
	{
		cout<<"Wrong non-terminal entered\n";
	}
	return 0;
}

