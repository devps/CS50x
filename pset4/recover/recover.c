/**
 * @Author : Devendra Singh
 */
       
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include<cs50.h>


int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }
    // remember filenames
    char *infile = argv[1];

    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    // These are the starting bytes of a jpeg file.
		uint8_t checkjpg1[4] = {0xff, 0xd8, 0xff, 0xe0};
		uint8_t checkjpg2[4] = {0xff, 0xd8, 0xff, 0xe1};
    
     int JPGCount=0;
     
     int open=0;
     
     //open outfile
     FILE *outfile;
     
    uint8_t buffer[512];
	uint8_t check[4];
	fread(buffer, 512, 1, inptr);	
    while(fread(buffer,512,1,inptr)>0)
    {
        for(int i=0;i<4;i++)
        {
            check[i]=buffer[i];
        }
        if((memcmp(checkjpg1,check,4)==0)|| (memcmp(checkjpg2,check,sizeof(check))==0))
        {
            
            char filename[8];
            sprintf(filename,"%03d.jpg",JPGCount);
            if(open==0)
            {
                
                outfile=fopen(filename,"w");
                fwrite(buffer,sizeof(buffer),1,outfile);
                open=1;
                
                
                
            }
            if(open==1)
            {
                fclose(outfile);
                outfile=fopen(filename,"w");
                fwrite(buffer,sizeof(buffer),1,outfile);
                JPGCount++;
                
                
            }
        }
        else
        {
            
            if(open==1)
            {
                
                fwrite(buffer,sizeof(buffer),1,outfile);
                
            }
            
            
            
            
        }
        
        
        
    }
    if(outfile)
        fclose(outfile);
   
   
   

    // close infile
    fclose(inptr);

    // close outfile
   // fclose(outptr);

    // success
    return 0;
}
