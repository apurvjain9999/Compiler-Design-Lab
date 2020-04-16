#include<iostream>
#include<ctype.h>
#include<string>
#include<string.h>
#include<cstring>
#include<stdlib.h>
#include<limits>
using namespace std; 

void followfirst(char , int , int); //Function to calculate the Follow of a symbol, from the First of another symbol
void First(char , int , int); //Function to calculate the First of a symbol
void Follow(char c); //Function to determine Follow of a symbol

int ct,n=0;
char calc_first[10][100]; //For calculatig first
char calc_follow[10][100]; //For calculating follow
int m=0;
char production[10][10]; //For storing the production rules
char first[10]; //For storing the first
char f[10]; //For storing the follow
int k;
char ck;
int e;

int main()
{
	int jm=0;
	int km=0;
	int i,choice;
	char c,ch;
	cout<<"How many productions ? : ";
	cin>>ct;
	cout<<"\nEnter "<<ct<<" productions: \n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for(i=0;i<ct;i++)
	{	
		string str = "";
		getline(cin, str, '\n');
		strcpy(production[i], str.c_str());
	}
	/*for(i=0; i<ct; i++)
	{
		cout<<"\n"<<production[i]<<"\n";
	}*/
	int kay;
	char firstDone[ct]; //For determining symbols, whose first has been already calculated
	int ptr = -1;
	for(k=0;k<ct;k++){
		for(kay=0;kay<100;kay++){
			calc_first[k][kay] = '!';
		}
	}
	cout<<"\n\nFirst of all of all non-terminals are as follows:\n";
	int pt1 = 0, pt2,fg;
	for(k=0;k<ct;k++)
	{
		c=production[k][0];
		pt2 = 0;
		fg = 0;
		for(kay = 0; kay <= ptr; kay++)
			if(c == firstDone[kay]) //If first already calculated
				fg = 1;
		if (fg == 1)
			continue;
		First(c,0,0); //Calculate the first of symbol c
		ptr++;
		firstDone[ptr] = c;
		//Print the first of symbol c
		cout<<"\n"<<c<<"= { ";
		calc_first[pt1][pt2++] = c;
		for(i=0+jm;i<n;i++){
			int lk = 0,chk = 0;
  			for(lk=0;lk<pt2;lk++){
  				if (first[i] == calc_first[pt1][lk]){
  					chk = 1;
  					break;
				}
			}
			if(chk == 0){
  		 		cout<<first[i]<<",";
  				calc_first[pt1][pt2++] = first[i];
			}
		}
		cout<<"}\n";
		jm=n;
		pt1++;
	}

	char followDone[ct]; //To determine symbols, whose follow has been calculated
	ptr = -1;
	for(k=0;k<ct;k++){
		for(kay=0;kay<100;kay++){
			calc_follow[k][kay] = '!';
		}
	}

	cout<<"\n\nFollow of all of all non-terminals are as follows:\n";
	pt1 = 0;
	int ln = 0;
	for(e=0;e<ct;e++)
  	{
		ck=production[e][0];
		pt2 = 0;
		fg = 0;
		for(kay = 0; kay <= ptr; kay++)
			if(ck == followDone[kay]) //If follow already calculated
				fg = 1;
		if (fg == 1)
			continue;
  		ln += 1;
		Follow(ck); //Calculate follow of symbol ck
  		ptr+=1;
		followDone[ptr] = ck;
		//Print follow of symbol ck
  		cout<<"\n"<<ck<<"{ ";
  		calc_follow[pt1][pt2++] = ck;
  		for(i=0+km;i<m;i++){
  			int lk = 0,chk = 0;
  			for(lk=0;lk<pt2;lk++){
  				if (f[i] == calc_follow[pt1][lk]){
  					chk = 1;
  					break;
				}
			}
			if(chk == 0){
  		 		cout<<f[i]<<",";
  				calc_follow[pt1][pt2++] = f[i];
  			}
  		}
  		cout<<"}\n\n";
		km=m;
		pt1++; 
	}

	char ter[10]; //For storing all terminal symbols
	for(k=0;k<10;k++){
		ter[k] = '!';
	}

	//Determining all terminal symbols
	int ap,vp,sid = 0;
	for(k=0;k<ct;k++){
		for(kay=0;kay<ct;kay++){
			if(!isupper(production[k][kay]) && production[k][kay]!= '#' && production[k][kay] != '=' && production[k][kay] != '\0'){
				vp = 0;
				for(ap = 0;ap < sid; ap++){
					if(production[k][kay] == ter[ap]){
						vp = 1;
						break;
					}
				}
				if(vp == 0){
					ter[sid] = production[k][kay];
					sid++;
				}
			}
		}
	}
	ter[sid] = '$';
	sid++;
	cout<<"\n\n\n\n The LL(1) Parsing Table for the given grammer is :";
	cout<<"\n\n\n\t\t---------------------------------------------------------------------------------------------------------------------\n";
	cout<<"\t\t\t\t|\t";
	for(ap = 0;ap < sid; ap++){
		cout<<ter[ap]<<"\t\t";
	}
	cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------------------\n";
	char first_prod[ct][sid];
	for(ap=0;ap<ct;ap++){
		int dt = 0;
		k = 2;
		int cnt = 0;
		char tem[100];
		while(production[ap][k] != '\0'){
			if(!isupper(production[ap][k])){
				tem[cnt++] = production[ap][k];
				tem[cnt++] = '_';
				tem[cnt++] = '\0';
				k++;
				break;
			}
			else{
				int zap=0;
				int tuna = 0;
				for(zap=0;zap<ct;zap++){
					if(calc_first[zap][0] == production[ap][k]){
						for(tuna=1;tuna<100;tuna++){
							if(calc_first[zap][tuna] != '!'){
								tem[cnt++] = calc_first[zap][tuna];
							}
							else
								break;
						}
					break;
					}
				}
				tem[cnt++] = '_';
			}
			k++;
		}
		int zap = 0,tuna;		
		for(tuna = 0;tuna<cnt;tuna++){
			if(tem[tuna] == '#'){
				zap = 1;
			}
			else if(tem[tuna] == '_'){
				if(zap == 1){
					zap = 0;
				}
				else
					break;
			}
			else{
				first_prod[ap][dt++] = tem[tuna];
			}
		}
	}
	char table[ln][sid+1]; //Storing respective symbols to store the productions
	ptr = -1;
	for(ap = 0; ap < ln ; ap++){
		for(kay = 0; kay < (sid + 1) ; kay++){
			table[ap][kay] = '!';
		}
	}
	for(ap = 0; ap < ct ; ap++){
		ck = production[ap][0];
		fg = 0;
		for(kay = 0; kay <= ptr; kay++)
			if(ck == table[kay][0])
				fg = 1;
		if (fg == 1)
			continue;
		else{
			ptr = ptr + 1;
			table[ptr][0] = ck;
		}
	}
	for(ap = 0; ap < ct ; ap++){
		int tuna = 0;
		while(first_prod[ap][tuna] != '\0'){
			int to,ni=0;
			for(to=0;to<sid;to++){
				if(first_prod[ap][tuna] == ter[to]){
					ni = 1;
				}
			}
			if(ni == 1){
				char xz = production[ap][0];
				int cz=0;
				while(table[cz][0] != xz){
					cz = cz + 1;
				}
				int vz=0;
				while(ter[vz] != first_prod[ap][tuna]){
					vz = vz + 1;
				}
				table[cz][vz+1] = (char)(ap + 65);
			}
			tuna++;
		}
	}
	for(k=0;k<sid;k++){
		for(kay=0;kay<100;kay++){
			if(calc_first[k][kay] == '!'){
				break;
			}
			else if(calc_first[k][kay] == '#'){
				int fz = 1;
				while(calc_follow[k][fz] != '!'){
					char xz = production[k][0];
					int cz=0;
					while(table[cz][0] != xz){
						cz = cz + 1;
					}
					int vz=0;
					while(ter[vz] != calc_follow[k][fz]){
						vz = vz + 1;
					}
					table[k][vz+1] = '#';
					fz++;	
				}
				break;
			}
		}
	}	
	/*for(ap=0; ap<ln; ap++)
	{
		cout<<table[ap][0]<<" : ";
		for(kay=1; kay<(sid+1); kay++)
		{
			cout<<table[ap][kay]<<" ";
		}
		cout<<"\n";
	}*/

	//Printing the LL(1) table entries
	for(ap = 0; ap < ln ; ap++){
		cout<<"\t\t\t"<<table[ap][0]<<"\t|\t";
		for(kay = 1; kay < (sid + 1) ; kay++){
			if(table[ap][kay] == '!')
				cout<<"\t\t";
			else if(table[ap][kay] == '#')
				cout<<table[ap][0]<<"=#\t\t";
			else{
				int mm = (int)(table[ap][kay]);
				mm -= 65;
				cout<<production[mm]<<"\t\t";
			}
		}
		cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------------------\n";
	}
	int j;
	//Stack Operations
	cout<<"\n\nPlease enter the INPUT STRING = ";
	char input[100];
	cin>>input>>ch;
	cout<<"\n\t\t\t\t\t===========================================================================\n";
	cout<<"\t\t\t\t\t\tStack\t\t\tInput\t\t\tAction";
	cout<<"\n\t\t\t\t\t===========================================================================\n";
	int i_ptr = 0,s_ptr = 1;
	char stack[100];
	stack[0] = '$';
	stack[1] = table[0][0];
	while(s_ptr != -1){
		cout<<"\t\t\t\t\t\t";
		int vp = 0;
		for(vp=0;vp<=s_ptr;vp++){
			cout<<stack[vp];
		}
		cout<<"\t\t\t";
		vp = i_ptr;
		while(input[vp] != '\0'){
			cout<<input[vp];
			vp++;
		}
		cout<<"\t\t\t";
		char hr = input[i_ptr];
		char hm = stack[s_ptr];
		s_ptr--;
		if(!isupper(hm)){
			if(hr == hm){
				i_ptr++;
				cout<<"POP\n";
			}
			else{
				cout<<"\nString is not Accepted by LL(1) Parser !!\n";
				exit(0);
			}
		}
		else{
			for(i=0;i<sid;i++){
				if(ter[i] == hr)
					break;
			}
			char produ[100];
			for(j=0;j<ln;j++){
				if(hm == table[j][0]){
					if (table[j][i+1] == '#'){
						cout<<table[j][0]<<"=#\n";
						produ[0] = '#';
						produ[1] = '\0';
					}
					else if(table[j][i+1] != '!'){
						int mum;
						int ph = i+1;
						int fp = 0;
						int hp = 0;
						while(table[j][ph] != '\0')
						{
							char mk = table[j][ph];
							if (mk == input[i_ptr])
							{
								fp = 1;
								mum = (int)(table[j][ph]);
								mum -= 65;
								break;
							}
							else if (mk == '#')
							{
								hp = (int)(table[j][i+1]);
								hp -= 65;	
							}
							ph++;
						}
						if (fp == 0 && hp > 0)
							mum = hp;
						else if (fp == 0 && hp == 0)
						{
							mum = (int)(table[j][i+1]);
							mum -= 65;
						}
						strcpy(produ,production[mum]);
						printf("%s\n",produ);
					}
					else{
						cout<<"\nString is not Accepted by LL(1) Parser !!\n";
						exit(0);
					}
				}
			}
			int le = strlen(produ);
			le = le - 1;
			if(le == 0){
				continue;
			}
			for(j=le;j>=2;j--){
				s_ptr++;
				stack[s_ptr] = produ[j];
			}
		}
	}
	cout<<"\n\t\t\t------------------------------------------------------------------------------------------------------------------------\n";
	if (input[i_ptr] == '\0'){
		cout<<"\t\t\t\t\t\t\t\t STRING ACCEPTED !!\n";
	}
	else
		cout<<"\n\t\t\t\t\t\t\t\tSTRING REJECTED !!\n";
	cout<<"\t\t\t------------------------------------------------------------------------------------------------------------------------\n";
}

//To determine follow
void Follow(char c)
{
	int i ,j;
	if(production[0][0]==c){
 		f[m++]='$'; //The starting production always has '$' as its follow
 	}
 	for(i=0;i<10;i++)
 	{
  		for(j=2;j<10;j++)
  		{
   			if(production[i][j]==c)
   			{
				//Determine the first of the symbol, foolowing the symbol c    
    			if(production[i][j+1]!='\0'){ 
					followfirst(production[i][j+1],i,(j+2));
 				}
				//If the symbol c in any production is the last symbol, then follow will be the first
				//of the symbol whose production, it is   
    			if(production[i][j+1]=='\0'&& c!=production[i][0]){
     				Follow(production[i][0]);
				}
   			}   
  		}
 	}
}

//To determine First
void First(char c ,int q1 , int q2)
{
	int j;
	//If the first symbol in a production is not a terminal, then it is the first
	if(!(isupper(c))){ 
		first[n++]=c;
	}
	for(j=0;j<ct;j++)
	{
		if(production[j][0]==c)
		{
			//If first symbol in production is # (empty)
			if(production[j][2]=='#'){
				//If only empty, then first is empty
				if(production[q1][q2] == '\0')
					first[n++]='#';
				//Else if calculate first of next symbol following '#'
				else if(production[q1][q2] != '\0' && (q1 != 0 || q2 != 0))
				{
					First(production[q1][q2], q1, (q2+1));
				}
				//Else '#'
				else
					first[n++]='#';
			}
			//If the first symbol in a production is not a terminal, then it is the first
			else if(!isupper(production[j][2])){
				first[n++]=production[j][2];
			}
			//If the first symbol in a production is a terminal, then determine its first
			else {
				First(production[j][2], j, 3);
			}
		}
	}	
}

//To determine first of the symbol for calculating follow
void followfirst(char c, int c1 , int c2)
{
    int k;
    if(!(isupper(c))) //If non-terminal, then it is the first, and therefore the follow
		f[m++]=c;
	else{
		int i=0,j=1;
		for(i=0;i<ct;i++)
		{
			if(calc_first[i][0] == c)
				break;
		}
		while(calc_first[i][j] != '!')
		{
			if(calc_first[i][j] != '#'){ 
				f[m++] = calc_first[i][j];
			}
			else{
				if(production[c1][c2] == '\0'){
					Follow(production[c1][0]);
				}
				else{
					followfirst(production[c1][c2],c1,c2+1);
				}
			}
			j++;
		}
	}
}