#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int isDelimiter(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||  ch == '/' || ch == ',' || ch == ';' || ch == '>' ||  ch == '<' || 
        ch == '=' || ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}') 
        return 1;
    return 0;
}

int isKeyword(char * str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else") || !strcmp(str, "while") || !strcmp(str, "do") ||  !strcmp(str, "break") ||  
         !strcmp(str, "continue") || !strcmp(str, "int") || !strcmp(str, "double") || !strcmp(str, "float") || 
         !strcmp(str, "return") || !strcmp(str, "char") || !strcmp(str, "case") || !strcmp(str, "char") || 
         !strcmp(str, "sizeof") || !strcmp(str, "long") || !strcmp(str, "short") || !strcmp(str, "typedef") || 
         !strcmp(str, "switch") || !strcmp(str, "unsigned") || !strcmp(str, "void") || !strcmp(str, "static") || 
         !strcmp(str, "struct") || !strcmp(str, "goto")) 
        return 1; 
    return 0; 
}

int isOperator(char ch)
{    
    if (ch == '+' || ch == '-' || ch == '*' ||  ch == '/' || ch == '>' || ch == '<' ||  ch == '=') 
        return 1; 
    return 0; 
}

int isInteger(char* str) 
{ 
    int i, len = strlen(str); 
  
    if (len == 0) 
        return 0; 
    for (i = 0; i < len; i++) { 
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' || (str[i] == '-' && i > 0)) 
            return 0; 
    } 
    return 1; 
} 
    
int isRealNumber(char* str) 
{ 
    int i, len = strlen(str); 
    int hasDecimal = 0; 
  
    if (len == 0) 
        return (0); 

    for (i = 0; i < len; i++) { 
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' && (str[i] != '.' && hasDecimal == 0) ||  
            (str[i] == '-' && i > 0)) 
            return 0; 
        if (str[i] == '.') 
            hasDecimal = 1; 
    } 
    return (hasDecimal); 
} 

int validIdentifier(char* str) 
{ 
	if (str[0] == '0' || str[0] == '1' || str[0] == '2' || 
		str[0] == '3' || str[0] == '4' || str[0] == '5' || 
		str[0] == '6' || str[0] == '7' || str[0] == '8' || 
		str[0] == '9' || isDelimiter(str[0]) == 1) 
		return 0; 
	return 1; 
} 

int validString(char *str)
{
    if (str[0] == '"' && str[strlen(str)-1] == '"')
        return 1;
    return 0;
}

char* subStr(char *str, int l, int r)
{
    char *s = (char *) malloc(sizeof(char) * (r - l + 2));
    int i;
    for(i=l; i<=r; i++)
    {
        s[i-l] = str[i];
    }
    s[r-l+1] = '\0';
    return s;
}

void parser(char *str)
{
    int token = 0;
    int id = 0;
    int operator = 0;
    int constant = 0;
    int inv = 0;
    int keyword = 0;
    int l = 0, r = 0;
    int len = strlen(str);

    while(r<=len && l<=r)
    {
        if(isDelimiter(str[r]) == 0)
            r++;
        
        if (isDelimiter(str[r]) == 1 && l!=r || (r == len && l != r))
        {
            char *subString = subStr(str, l, r);
            if (isKeyword(subString) == 1)
                keyword++;
            else if (isInteger(subString) == 1 || isRealNumber(subString) == 1)
                constant++;
            else if (validIdentifier(subString) == 1 && isDelimiter(str[r-1]) == 0)
                id++;
            else if (validIdentifier(subString) == 0 && isDelimiter(str[r-1]) == 0)
                inv++;
            l = r;
        }

        else if (isDelimiter(str[r]) == 1 && l == r)
        {
            if (isOperator(str[r]) == 1)
                operator++;
            r++;
            l = r;
        }
    }
    token = keyword + constant + id + inv + operator;
    printf("\nNumber of Tokens: %d", token);
    printf("\nNumber of Keywords: %d", keyword);
    printf("\nNumber of Constants: %d", constant);
    printf("\nNumber of Operators: %d", operator);
    printf("\nNumber of Identifiers: %d", id);
    printf("\nNumber of Invalid Identifiers: %d", inv);
}

int main()
{
    char str[100];
    printf("\nEnter the line of program: ");
    scanf("%s", str);
    parser(str);
    return 0;
}