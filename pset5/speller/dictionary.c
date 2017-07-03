/**
 * Implements a dictionary's functionality.
 */


#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dictionary.h"


#define SIZE 1000000
typedef struct node{
        
        char word[LENGTH+1];
        struct node *next;
}node;
node *HashTable[SIZE]={NULL};
int dictSize=0;
/**
 * Returns true if word is in dictionary else false.
 */
int find(const char *word);
bool check(const char *word)
{
    char tmp[LENGTH+1]; //use to store lower version of word
    int n=strlen(word);
    for(int i=0;i<n;i++)
    {
        tmp[i]=tolower(word[i]);
        
    }
    tmp[n]='\0';
    int ind=find(tmp); // find the index of array the word should be in
    
    if(HashTable[ind]==NULL)  // if hash table empty
    {
        return false;
    }
    
    //if not empty than compare the word
    node *node2=HashTable[ind];
    
    while(node2!=NULL)
    {
        if(strcmp(tmp,node2->word)==0)
        {
            return true;
        }
        node2=node2->next;
    }
    
    
    
    // if you do not find the word return false 
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    
    
    //code start here 
    FILE *fp=fopen(dictionary,"r");
    
    //check for error
    if(fp==NULL)
    {
        printf("dictionary could not load");
        return false;
        
    }
    
    char arr[LENGTH+1]; // for word to be sorted 
    while(fscanf(fp,"%s\n",arr)!=EOF)
    {
        
        dictSize++;   //increase dict size
        
        //allocate memory for new node
        node *node1=malloc(sizeof(node1));
        
        strcpy(node1->word,arr);    
        
        //find what index of the array should go
        int ind=find(arr);
        
        //if hastable is empty at index,
        if(HashTable[ind]==NULL)
        {
            HashTable[ind]=node1;
            node1->next=NULL;
            
        }
        else
        {
            node1->next=HashTable[ind];
            HashTable[ind]=node1;
            
            
        }
     
        
        
    }
    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    // if dict loaded return no of words
    if(dictSize>0)
     return dictSize;
    
    // else return zero
    return 0;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    
    int ind=0;  // to go through index
    // go though entire hash table
    while(ind<SIZE)
    {
        
        if(HashTable[ind]==NULL)  // if empty , go to next step
            ind++;
        
        
        // if hashtable is not empty , iterate through nodes nd start freeing
        else
        {
            
            while(HashTable[ind]!=NULL)
            {
                node *node2=HashTable[ind];
                HashTable[ind]=node2->next;
                free(node2);
                
                
            }
            
            // once previous index free go to next index
            ind++;
            
        }
        
        
        
        
        
        
    }
    
    
    // return true if sucess
    return true;
}
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
        
    }
    return hash;
    
    
    
    
}