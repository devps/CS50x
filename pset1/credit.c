/*  
     @author: Devendra Singh   @date :  June 2, 2017 
*/
     
#include <stdio.h>
#include<cs50.h>

int main(void)
{
        long int sum=0,sum1=0,ans=0;
        printf("Number:");
        
        long long int cardN =get_long_long();
        int p=0;
        while(cardN)
        {
            if(cardN<9)
                p=cardN;
            sum+=cardN%10;
            cardN=cardN/10;
            if(cardN<9 && cardN!=0)
                p=cardN;
            ans=(cardN%10)*2;
            if(ans>9)
            {
                while(ans)
                {
                    sum1+=ans%10;
                    ans/=10;
                }
            }
            else
            sum1+=ans;
            cardN=cardN/10;
        }
        //printf("%ld  %ld %d",sum ,sum1,p);
        if((sum+sum1)%10==0){
            if(p==3)
            {
                printf("AMEX\n");
            }
            if(p==5)
            {
                printf("MASTERCARD\n");
                
            }
            if(p==4)
            {
                printf("VISA\n");
                
            }
        }
        else
            printf("INVALID\n");
       
        
        return 0;
}