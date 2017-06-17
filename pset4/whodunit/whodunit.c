/* @Author: Devendra Singh @date: 17-06-2017 */

#include<stdio.h>
#include<cs50.h>


#include "bmp.h"

int main(int argc, char *argv[])
{
    //check argument 
    if(argc!=3)
    {
        
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
        
    }
     
    char *inputfile = argv[1];
    

    // open input file 
    FILE *inputptr = fopen(inputfile, "r");
    if (inputptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", inputfile);
        return 2;
    }
    char *outputfile = argv[2];
    
    FILE *outputptr =fopen(outputfile,"w");
     if (outputptr == NULL)
    {
        fclose(inputptr);
        fprintf(stderr, "Could not write %s.\n", outputfile);
        return 3;
    }
     // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inputptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inputptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outputptr);
        fclose(inputptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    return 0;
    
    
    
    
}