/* @author : Devendra singh*/
// test the find function 
#include<stdio.h>
#include<cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 1000
int find(const char *word)
{
    
    int hash=0;
    int n;
    for(int i=0;word[i]!='\0';i++)
    {
        if(isalpha(word[i]))
        {
            
            n=word[i]-'a'+1;
        }
        else
            n=27; // comma case
        
        hash=((hash<<3)+n)%SIZE;
        printf("hash=%d\n",hash);
        
    }
    return hash;
}
int main()
{
    printf("%d\n",find("ab"));
    
    
}