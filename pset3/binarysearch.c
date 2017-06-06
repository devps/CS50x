/*  
     @author: Devendra Singh   @date :  June 4, 2017 
*/
// binary search
#include<stdio.h>
#include<cs50.h>
bool binarysearch(int key,int val[], int n )
{
    
    if(n<0)return false;
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        int mid=start+(end-1)/2;
        
        if(key==val[mid])
            return true;
        if(key<val[mid])
            start=mid-1;
            
        else if(key>val[mid])
            end=mid+1;
    }
    return false;
    
    
}
int main()
{
    int n=get_int();
    int val[100];
    for(int i=0;i<n;i++)
        val[i]=get_int();
    printf("Enter key:");
    int key=get_int();
    if(binarysearch(key,val,n))
        printf("Found\n");
    else
    printf("Not found\n");
    
    return 0;
    
    
    
    
}

