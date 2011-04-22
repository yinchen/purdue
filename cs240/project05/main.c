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
void invertBitmap(char *srcFileName, char *dstFileName);
pixel** readFile(struct header *h, struct information *i, pixel **pixelData, char *fileName);
void writeFile(struct header *h, struct information *i, pixel **pixelData, char *fileName);
int calculateBitmapSize(int width, int height);
char* itoa(int value);

int main(int argc, char **argv)
{
    #ifdef DEBUG
        printf("DEBUG: main()\n");
    #endif
    
    if (strcmp(argv[1], "-create") == 0)
    {
        createBitmap(atoi(argv[2]), atoi(argv[3]), argv[4]);
    }
    else if (strcmp(argv[1], "-invertcolor") == 0)
    {
        invertBitmap(argv[2], argv[3]);
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
    #ifdef DEBUG
        printf("DEBUG: createBitmap()\n");
    #endif
    
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
    pixelData = (pixel**)malloc(sizeof(pixel*) * height);
    
    int z;
    for (z = 0; z < height; z++)
        pixelData[z] = (pixel*)malloc(sizeof(pixel) * width);
    
    int y;
    for (y = 0; y < height; y++)
    {
        int x;
        for (x = 0; x < width; x++)
        {
            pixelData[y][x].r = 255;
            pixelData[y][x].g = 255;
            pixelData[y][x].b = 255;
        }
    }
    
    #ifdef DEBUG
        printf("DEBUG: Pixel data created.\n");
    #endif
    
    // write out file
    writeFile(h, i, pixelData, fileName);
}

void invertBitmap(char *srcFileName, char *dstFileName)
{
    #ifdef DEBUG
        printf("DEBUG: invertBitmap()\n");
    #endif
    
    // create header
    struct header *h;
    h = (struct header *)malloc(sizeof(struct header));
    
    // create information header
    struct information *i;
    i = (struct information *)malloc(sizeof(struct information));
    
    // create pixel data
    pixel **pixelData;
    
    // read in file
    pixelData = readFile(h, i, pixelData, srcFileName);
    
    #ifdef DEBUG
        printf("DEBUG: Source file read.\n");
    #endif
    
    // invert each pixel
    int y;
    for (y = 0; y < i->height; y++)
    {
        int x;
        for (x = 0; x < i->width; x++)
        {
            if (pixelData[y][x].r - 255 < 0)
                pixelData[y][x].r = -1 * (pixelData[y][x].r - 255);
            else
                pixelData[y][x].r = pixelData[y][x].r - 255;
            
            if (pixelData[y][x].g - 255 < 0)
                pixelData[y][x].g = -1 * (pixelData[y][x].g - 255);
            else
                pixelData[y][x].g = pixelData[y][x].g - 255;
                
            if (pixelData[y][x].b - 255 < 0)
                pixelData[y][x].b = -1 * (pixelData[y][x].b - 255);
            else
                pixelData[y][x].b = pixelData[y][x].b - 255;
        }
    }
    
    #ifdef DEBUG
        printf("DEBUG: Pixel data inverted.\n");
    #endif
    
    // write out new file
    writeFile(h, i, pixelData, dstFileName);
}

pixel** readFile(struct header *h, struct information *i, pixel **pixelData, char *fileName)
{
    #ifdef DEBUG
        printf("DEBUG: readFile() called.\n");
    #endif
    
    FILE *fp;
    fp = fopen(fileName, "rb");
    
    fread(h, sizeof(struct header), 1, fp);
    
    #ifdef DEBUG
        printf("DEBUG: Header read from file.\n");
    #endif
    
    fread(i, sizeof(struct information), 1, fp);
    
    #ifdef DEBUG
        printf("DEBUG: Information header read from file.\n");
    #endif
    
    pixelData = (pixel**)malloc(sizeof(pixel*) * i->height);
    
    int z;
    for (z = 0; z < i->height; z++)
        pixelData[z] = (pixel*)malloc(sizeof(pixel) * i->width);
    
    for (z = 0; z < i->height; z++)
        fread(pixelData[z], sizeof(pixel), i->width, fp);
    
    #ifdef DEBUG
        printf("DEBUG: Pixel data read from file.\n");
    #endif
    
    #ifdef DEBUG
        printf("DEBUG: Image dimensions are %dx%d.\n", i->width, i->height);
    #endif
    
    fclose(fp);
    
    return pixelData;
}

void writeFile(struct header *h, struct information *i, pixel **pixelData, char *fileName)
{
    #ifdef DEBUG
        printf("DEBUG: writeFile()\n");
    #endif
    
    FILE *fp;
    fp = fopen(fileName, "wb");
    
    int width, height;
    width = i->width;
    height = i->height;
    
    fwrite(h, sizeof(struct header), 1, fp);
    
    #ifdef DEBUG
        printf("DEBUG: Header written to file.\n");
    #endif
    
    fwrite(i, sizeof(struct information), 1, fp);
    
    #ifdef DEBUG
        printf("DEBUG: Information header written to file.\n");
    #endif
    
    int y;
    for (y = 0; y < height; y++)
    {
        fwrite(pixelData[y], sizeof(pixel), width, fp);
    }
    
    #ifdef DEBUG
        printf("DEBUG: Pixel data written to file.\n");
    #endif
    
    fclose(fp);
}

int calculateBitmapSize(int width, int height)
{
    return (14 + 40 + (width * height * 3));
}

char* itoa(int value)
{
    char* buff;
    buff = malloc(sizeof(char) * 16 + 1);
    
    sprintf(buff, "%d", value);
    
    return buff;
}

