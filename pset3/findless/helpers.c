/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
 
// binary search 
bool search(int value, int values[], int n)
{
    if(n<=0) return false;
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        
        if(value==values[mid])
        
            return true;
            
        else if(value<values[mid])
        
            end=mid-1;
            
        else if(value>values[mid])
            start=mid+1;
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
   int swap=0;
     for(int i=0;i<n-1;i++)
     {
         swap=0;
         for(int j=0;j<n-i-1;j++)
         {
             if(values[j]>values[j+1])
             {
                
                int temp=values[j];
                values[j]=values[j+1];
                values[j+1]=temp;
                swap++;
             }
         }
         if(swap==0)
           return;
     }
  return;
}
