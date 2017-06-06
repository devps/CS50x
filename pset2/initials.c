/*  
     @author: Devendra Singh   @date :  June 3, 2017 
*/
     
#include <stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

int main()
{
      
       string s=get_string();
       int n=strlen(s),i;
      //string ans;
       for(i=0;i<n;i++)
       {
            if(s[i]!=' ')
             printf("%c",toupper(s[i]));
             while(s[i]!=' ' && i<n-1)
             {
                 i++;
             }
          //printf("%d",i);
       }
       printf("\n");
       
        
        return 0;
}