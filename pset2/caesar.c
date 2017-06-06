
/*  
     @author: Devendra Singh   @date :  June 3, 2017 
*/
     
#include <stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

int main(int argc, string argv[])
{
      
       if(argc!=2)
       {
           printf("do not pass more than 2 parameters\n");
           return 1;
       }
       int k=atoi(argv[argc-1]);
       //printf("%d\n",k);
       printf("plaintext: ");
       string s=get_string();
       int n=strlen(s);
       printf("ciphertext: ");
       for(int i=0;i<n;i++)
       
       {
       
            if(s[i]>='A' && s[i]<='Z'){
           int p=((int)s[i]+k-65)%26;
            printf("%c",p+65);
            }
            else if(s[i]>='a' && s[i]<='z'){
           int p=((int)s[i]+k-97)%26;
            printf("%c",p+97);
            }
            else
            printf("%c",s[i]);
          
           
       }
       printf("\n");
        return 0;
}