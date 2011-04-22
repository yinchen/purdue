#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "bmp_header.h"

#define DEBUG 1

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

void createBitmap(int width, int height, char *fileName);
void writeFile(struct header *h, struct information *i, pixel **pixelData, char *fileName);
int calculateBitmapSize(int width, int height);

int main(int argc, char **argv)
{
    if (strcmp(argv[1], "-create") == 0)
    {
        createBitmap(atoi(argv[2]), atoi(argv[3]), argv[4]);
    }
    else if (strcmp(argv[1], "-invertcolor") == 0)
    {
        // invert color data
    }
    else if (strcmp(argv[1], "stackvertically") == 0)
    {
	    // stack bitmaps vertically
    }
    else if (strcmp(argv[1], "-stackhorizontally") == 0)
    {
	    // stack bitmaps horizontally
    }
    else if (strcmp(argv[1], "-drawborder") == 0)
    {
	    // draw border
    }
    else
    {
	    printf("Usage : bitmap_tool <command> [argument 1] [argument 2] ...\n");
        exit(1);
    }

    return 0;
}

void createBitmap(int width, int height, char *fileName)
{
    // create header
    struct header *h;
    h = (struct header *)malloc(sizeof(struct header));
    
    h->type = 19778; // 'BM'
    h->size = calculateBitmapSize(width, height);
    h->reserved1 = 0;
    h->reserved2 = 0;
    h->offset = 54;
    
    #ifdef DEBUG
        printf("DEBUG: Header created.\n");
    #endif
    
    // create information header
    struct information *i;
    i = (struct information *)malloc(sizeof(struct information));
    
    i->size = 40;
    i->width = width;
    i->height = height;
    i->planes = 1;
    i->bits = 24;
    i->compression = 0;
    i->imagesize = h->size;
    i->xresolution = 100;
    i->yresolution = 100;
    i->ncolors = 0;
    i->importantcolors = 0;
    
    #ifdef DEBUG
        printf("DEBUG: Information header created.\n");
    #endif
    
    // create pixel data
    pixel **pixelData;
    pixelData = (pixel**)malloc(sizeof(pixel*) * width);
    
    int z;
    for (z = 0; z < height; z++)
        pixelData[z] = (pixel*)malloc(sizeof(pixel) * height);
    
    int x;
    for (x = 0; x < width; x++)
    {
        int y;
        for (y = 0; y < height; y++)
        {
            pixelData[x][y].r = 255;
            pixelData[x][y].g = 255;
            pixelData[x][y].b = 255;
        }
    }
    
    #ifdef DEBUG
        printf("DEBUG: Pixel data created.\n");
    #endif
    
    // write out file
    writeFile(h, i, pixelData, fileName);
}

void writeFile(struct header *h, struct information *i, pixel **pixelData, char *fileName)
{
    FILE *fp;
    fp = fopen(fileName, "wb");
    
    fwrite(&h, 14, 1, fp);
    fwrite(&i, 40, 1, fp);
    
    int x;
    for (x = 0; x < i->width; x++)
    {
        int y;
        for (y = 0; y < i->height; y++)
        {
            fwrite(&pixelData[x][y].r, 1, 1, fp);
            fwrite(&pixelData[x][y].g, 1, 1, fp);
            fwrite(&pixelData[x][y].b, 1, 1, fp);
        }
    }
    
    fclose(fp);
}

int calculateBitmapSize(int width, int height)
{
    return (14 + 40 + (width * height * 3));
}

