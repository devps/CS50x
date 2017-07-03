/**
 * @Author : Devendra Singh
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }

    //check resize factor also
    int fac=atoi(argv[1]);
    if(fac<0 || fac>100)
    {
        
        fprintf(stderr,"The resize factor should be positive integer \n");
        return 2;
    }
    
    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    //bitmap header
    BITMAPFILEHEADER  outbf;
    BITMAPINFOHEADER  outbi;
    outbf=bf;
    outbi=bi;
    outbi.biWidth=bi.biWidth * fac;
     outbi.biHeight=bi.biHeight * fac;


    //padding for scanlines
    int inPadding=(4-(bi.biWidth* sizeof(RGBTRIPLE))%4)%4;
     int outPadding=(4-(outbi.biWidth* sizeof(RGBTRIPLE))%4)%4;
     
     //calculate file size and image size   https://code.google.com/p/kupl09/
     outbf.bfSize= 54 +outbi.biWidth * abs(outbi.biHeight)*3 +abs(outbi.biHeight)*outPadding;
    outbi.biSizeImage= ((((outbi.biWidth * outbi.biBitCount) + 31) & ~31) / 8) * abs(outbi.biHeight); 

    // write outfile's BITMAPFILEHEADER
    fwrite(&outbf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&outbi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
   // int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
      for(int n=0;n<fac;n++)
      {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile
            for(int m=0;m<fac;m++)
            {
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
        }

        // skip over padding, if any
        fseek(inptr, inPadding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < outPadding; k++)
        {
            fputc(0x00, outptr);
        }
        fseek(inptr, -(bi.biWidth * 3 + inPadding ), SEEK_CUR);
        
    }
    fseek(inptr, bi.biWidth*3+inPadding, SEEK_CUR);
    
    
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
