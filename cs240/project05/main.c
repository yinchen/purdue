#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "bmp_header.h"

#define DEBUG 1
#define LORE 1

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

void createBitmap(int width, int height, char *fileName);
void invertBitmap(char *srcFileName, char *dstFileName);
void stackBitmapVertically(char *srcFileName1, char *srcFileName2, char *dstFileName);
void stackBitmapHorizontally(char *srcFileName1, char *srcFileName2, char *dstFileName);
void drawBitmapBorder(char *srcFileName, int width, int r, int g, int b, char *dstFileName);
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
    else if (strcmp(argv[1], "-stackvertically") == 0)
    {
	    stackBitmapVertically(argv[2], argv[3], argv[4]);
    }
    else if (strcmp(argv[1], "-stackhorizontally") == 0)
    {
	    stackBitmapHorizontally(argv[2], argv[3], argv[4]);
    }
    else if (strcmp(argv[1], "-drawborder") == 0)
    {
	    drawBitmapBorder(argv[2], atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), atoi(argv[6]), argv[7]);
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

void stackBitmapVertically(char *srcFileName1, char *srcFileName2, char *dstFileName)
{
    #ifdef DEBUG
        printf("DEBUG: stackBitmapVertically()\n");
    #endif
    
    // create headers
    struct header *h1;
    h1 = (struct header *)malloc(sizeof(struct header));
    
    struct header *h2;
    h2 = (struct header *)malloc(sizeof(struct header));
    
    // create information headers
    struct information *i1;
    i1 = (struct information *)malloc(sizeof(struct information));
    
    struct information *i2;
    i2 = (struct information *)malloc(sizeof(struct information));
    
    // create pixel datas
    pixel **pixelData1;
    pixel **pixelData2;
    
    // read in files
    pixelData1 = readFile(h1, i1, pixelData1, srcFileName1);
    
    #ifdef DEBUG
        printf("DEBUG: Source file 1 read.\n");
    #endif
    
    pixelData2 = readFile(h2, i2, pixelData2, srcFileName2);
    
    #ifdef DEBUG
        printf("DEBUG: Source file 2 read.\n");
    #endif
    
    // create header
    struct header *h;
    h = (struct header *)malloc(sizeof(struct header));
    
    h->type = 19778; // 'BM'
    h->size = calculateBitmapSize(i1->width, (i1->height + i2->height));
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
    i->width = i1->width;
    i->height = (i1->height + i2->height);
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
    
    // stack images vertically
    pixel **pixelData;
    pixelData = (pixel**)malloc(sizeof(pixel*) * (i1->height + i2->height));
    
    int z;
    for (z = 0; z < (i1->height + i2->height); z++)
        pixelData[z] = (pixel*)malloc(sizeof(pixel) * i1->width);
    
    int y;
    for (y = 0; y < i1->height; y++)
    {
        int x;
        for (x = 0; x < i1->width; x++)
        {
            pixelData[y][x].r = pixelData2[y - 0][x].r;
            pixelData[y][x].g = pixelData2[y - 0][x].g;
            pixelData[y][x].b = pixelData2[y - 0][x].b;
        }
    }
    for (y = i1->height; y < (i1->height + i2->height); y++)
    {
        int x;
        for (x = 0; x < i1->width; x++)
        {
            pixelData[y][x].r = pixelData1[y - i1->height][x].r;
            pixelData[y][x].g = pixelData1[y - i1->height][x].g;
            pixelData[y][x].b = pixelData1[y - i1->height][x].b;
        }
    }
    
    #ifdef DEBUG
        printf("DEBUG: Pixel data stacked vertically.\n");
    #endif
    
    // write out new file
    writeFile(h, i, pixelData, dstFileName);
}

void stackBitmapHorizontally(char *srcFileName1, char *srcFileName2, char *dstFileName)
{
    #ifdef DEBUG
        printf("DEBUG: stackBitmapHorizontally()\n");
    #endif
    
    // create headers
    struct header *h1;
    h1 = (struct header *)malloc(sizeof(struct header));
    
    struct header *h2;
    h2 = (struct header *)malloc(sizeof(struct header));
    
    // create information headers
    struct information *i1;
    i1 = (struct information *)malloc(sizeof(struct information));
    
    struct information *i2;
    i2 = (struct information *)malloc(sizeof(struct information));
    
    // create pixel datas
    pixel **pixelData1;
    pixel **pixelData2;
    
    // read in files
    pixelData1 = readFile(h1, i1, pixelData1, srcFileName1);
    
    #ifdef DEBUG
        printf("DEBUG: Source file 1 read.\n");
    #endif
    
    pixelData2 = readFile(h2, i2, pixelData2, srcFileName2);
    
    #ifdef DEBUG
        printf("DEBUG: Source file 2 read.\n");
    #endif
    
    // create header
    struct header *h;
    h = (struct header *)malloc(sizeof(struct header));
    
    h->type = 19778; // 'BM'
    h->size = calculateBitmapSize((i1->width + i2->width), i1->height);
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
    i->width = (i1->width + i2->width);
    i->height = i1->height;
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
    
    // stack images vertically
    pixel **pixelData;
    pixelData = (pixel**)malloc(sizeof(pixel*) * i1->height);
    
    int z;
    for (z = 0; z < i1->height; z++)
        pixelData[z] = (pixel*)malloc(sizeof(pixel) * (i1->width + i2->width));
    
    int y;
    for (y = 0; y < i1->height; y++)
    {
        int x;
        for (x = 0; x < i1->width; x++)
        {
            pixelData[y][x].r = pixelData1[y][x - 0].r;
            pixelData[y][x].g = pixelData1[y][x - 0].g;
            pixelData[y][x].b = pixelData1[y][x - 0].b;
        }
    }
    for (y = 0; y < i1->height; y++)
    {
        int x;
        for (x = i1->width; x < (i1->width + i2->width); x++)
        {
            pixelData[y][x].r = pixelData2[y][x - i1->width].r;
            pixelData[y][x].g = pixelData2[y][x - i1->width].g;
            pixelData[y][x].b = pixelData2[y][x - i1->width].b;
        }
    }
    
    #ifdef DEBUG
        printf("DEBUG: Pixel data stacked horizontally.\n");
    #endif
    
    // write out new file
    writeFile(h, i, pixelData, dstFileName);
}

void drawBitmapBorder(char *srcFileName, int width, int r, int g, int b, char *dstFileName)
{
    #ifdef DEBUG
        printf("DEBUG: drawBitmapBorder()\n");
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
            if (y < width ||
                (i->width - width) <= x ||
                (i->height - width) <= y ||
                (x < width))
            {
                pixelData[y][x].r = r;
                pixelData[y][x].g = g;
                pixelData[y][x].b = b;
            }
        }
    }
    
    #ifdef DEBUG
        printf("DEBUG: Image border drawn.\n");
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

