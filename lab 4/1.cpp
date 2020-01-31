#include<iostream>
#include<string.h>

using namespace std;

void checkComment(string str)
{
	int len=str.length(),k=0,flag=2,i;
	
	for(i=0;i<len;i++)
	{
		if(str.at(i)=='/')
		{
			i++;
			if(str.at(i)=='/')
			{
				k=i;
				flag=0;
				break;
			}
			else if(str.at(i)=='*')
			{
				k=i;
				flag=1;
				break;
			}
		}
	}
	
	if(flag==0)
	{
		for(i=k+1;i<len;i++)
			cout<<str.at(i);
		cout<<endl;
	}
	
	if(flag==1)
	{
		for(i=k+1;i<len;i++)
		{
			if(str.at(i)=='*')
			{
				i++;
				str.at(i)=='/';
				break;
			}
			cout<<str.at(i);
		}
		cout<<endl;
	}
	if(flag==2)
	cout<<"No Comments found !\n";
}

int main()
{
	string str="";
	cout<<"Enter string :";
	getline(cin,str);
	checkComment(str);
	return 0;
}
