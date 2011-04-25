#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "bmp_header.h"

#define DEBUG 1
#define LORE 1

typedef struct {
    unsigned char b;
    unsigned char g;
    unsigned char r;
} pixel;

void createBitmap(int width, int height, char *fileName);
void invertBitmap(char *srcFileName, char *dstFileName);
void stackBitmapVertically(char *srcFileName1, char *srcFileName2, char *dstFileName);
void stackBitmapHorizontally(char *srcFileName1, char *srcFileName2, char *dstFileName);
void drawBitmapBorder(char *srcFileName, int width, int r, int g, int b, char *dstFileName);
pixel** readFile(struct header *h, struct information *i, pixel **pixelData, char *fileName);
void writeFile(struct header *h, struct information *i, pixel **pixelData, char *fileName);
void checkFile(char *fileName, struct header *h, struct information *i);
int isNumeric(char* value);
int calculateBitmapSize(int width, int height);
char* itoa(int value);

char command[32];

int main(int argc, char **argv)
{
    #ifdef DEBUG
        printf("DEBUG: main()\n");
    #endif
    
    strcpy(command, argv[1]);
    
    if (strcmp(argv[1], "-create") == 0)
    {
        if (argc != 5)
        {
            printf("Usage : bitmap_tool -create [height] [width] [output file name]\n");
            exit(1);
        }
        
        createBitmap(atoi(argv[2]), atoi(argv[3]), argv[4]);
    }
    else if (strcmp(argv[1], "-invertcolor") == 0)
    {
        if (argc != 4)
        {
            printf("Usage : bitmap_tool -invertcolor [input file] [output file name]\n");
            exit(1);
        }
        
        invertBitmap(argv[2], argv[3]);
    }
    else if (strcmp(argv[1], "-stackvertically") == 0)
    {
	    if (argc != 5)
        {
            printf("Usage : bitmap_tool -stackvertically [input file 1] [input file 2] [output file name]\n");
            exit(1);
        }
        
        stackBitmapVertically(argv[2], argv[3], argv[4]);
    }
    else if (strcmp(argv[1], "-stackhorizontally") == 0)
    {
	    if (argc != 5)
        {
            printf("Usage : bitmap_tool -stackhorizontally [input file 1] [input file 2] [output file name]\n");
            exit(1);
        }
        
        stackBitmapHorizontally(argv[2], argv[3], argv[4]);
    }
    else if (strcmp(argv[1], "-drawborder") == 0)
    {
	    if (argc != 8)
        {
            printf("Usage : bitmap_tool -drawborder [input file] [thickness] [b] [g] [r] [output file]\n");
            exit(1);
        }
        
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
            pixelData[y][x].b = 255;
            pixelData[y][x].g = 255;
            pixelData[y][x].r = 255;
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
            if (pixelData[y][x].b - 255 < 0)
                pixelData[y][x].b = -1 * (pixelData[y][x].b - 255);
            else
                pixelData[y][x].b = pixelData[y][x].b - 255;
            
            if (pixelData[y][x].g - 255 < 0)
                pixelData[y][x].g = -1 * (pixelData[y][x].g - 255);
            else
                pixelData[y][x].g = pixelData[y][x].g - 255;
                
            if (pixelData[y][x].r - 255 < 0)
                pixelData[y][x].r = -1 * (pixelData[y][x].r - 255);
            else
                pixelData[y][x].r = pixelData[y][x].r - 255;
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
    
    if (i1->width != i2->width ||
        i1->height != i2->height)
    {
        printf("Files %s %s do not have same dimensions, cannot continue\n", srcFileName1, srcFileName2);
        exit(1);
    }
    
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
            pixelData[y][x].b = pixelData2[y - 0][x].b;
            pixelData[y][x].g = pixelData2[y - 0][x].g;
            pixelData[y][x].r = pixelData2[y - 0][x].r;
        }
    }
    for (y = i1->height; y < (i1->height + i2->height); y++)
    {
        int x;
        for (x = 0; x < i1->width; x++)
        {
            pixelData[y][x].b = pixelData1[y - i1->height][x].b;
            pixelData[y][x].g = pixelData1[y - i1->height][x].g;
            pixelData[y][x].r = pixelData1[y - i1->height][x].r;
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
    
    if (i1->width != i2->width ||
        i1->height != i2->height)
    {
        printf("Files %s %s do not have same dimensions, cannot continue\n", srcFileName1, srcFileName2);
        exit(1);
    }
    
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
            pixelData[y][x].b = pixelData1[y][x - 0].b;
            pixelData[y][x].g = pixelData1[y][x - 0].g;
            pixelData[y][x].r = pixelData1[y][x - 0].r;
        }
    }
    for (y = 0; y < i1->height; y++)
    {
        int x;
        for (x = i1->width; x < (i1->width + i2->width); x++)
        {
            pixelData[y][x].b = pixelData2[y][x - i1->width].b;
            pixelData[y][x].g = pixelData2[y][x - i1->width].g;
            pixelData[y][x].r = pixelData2[y][x - i1->width].r;
        }
    }
    
    #ifdef DEBUG
        printf("DEBUG: Pixel data stacked horizontally.\n");
    #endif
    
    // write out new file
    writeFile(h, i, pixelData, dstFileName);
}

void drawBitmapBorder(char *srcFileName, int width, int b, int g, int r, char *dstFileName)
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
                pixelData[y][x].b = b;
                pixelData[y][x].g = g;
                pixelData[y][x].r = r;
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
    if ((fp = fopen(fileName, "rb")) == NULL)
    {
        printf("Unable to open BMP file %s\n", command);
        exit(1);
    }
    
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
    
    checkFile(fileName, h, i);
    
    return pixelData;
}

void writeFile(struct header *h, struct information *i, pixel **pixelData, char *fileName)
{
    #ifdef DEBUG
        printf("DEBUG: writeFile()\n");
    #endif
    
    checkFile(fileName, h, i);
    
    FILE *fp;
    if ((fp = fopen(fileName, "wb")) == NULL)
    {
        printf("Unable to open BMP file %s\n", command);
        exit(1);
    }
    
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

void readLittleEndian(struct header *h, struct information *i)
{
    #ifdef DEBUG
        printf("DEBUG: readLittleEndian()\n");
    #endif
    
    // h->type = lendianReadShort(h->type);
    // h->size = lendianReadInt(h->size);
    // h->reserved1 = lendianReadShort(h->reserved1);
    // h->reserved2 = lendianReadShort(h->reserved2);
    // h->offset = lendianReadInt(h->offset);
    
    // i->size = lendianReadInt(i->size);
    // i->width = lendianReadInt(i->width);
    // i->height = lendianReadInt(i->height);
    // i->planes = lendianReadShort(i->planes);
    // i->bits = lendianReadShort(i->bits);
    // i->compression = lendianReadInt(i->compression);
    // i->imagesize = lendianReadInt(i->imagesize);
    // i->xresolution = lendianReadInt(i->xresolution);
    // i->yresolution = lendianReadInt(i->yresolution);
    // i->ncolors = lendianReadInt(i->ncolors);
    // i->importantcolors = lendianReadInt(i->importantcolors);
}

void writeLittleEndian(struct header *h, struct information *i)
{
    #ifdef DEBUG
        printf("DEBUG: writeLittleEndian()\n");
    #endif
    
    // h->type = lendianWriteShort(h->type);
    // h->size = lendianWriteInt(h->size);
    // h->reserved1 = lendianWriteShort(h->reserved1);
    // h->reserved2 = lendianWriteShort(h->reserved2);
    // h->offset = lendianWriteInt(h->offset);
    
    // i->size = lendianWriteInt(i->size);
    // i->width = lendianWriteInt(i->width);
    // i->height = lendianWriteInt(i->height);
    // i->planes = lendianWriteShort(i->planes);
    // i->bits = lendianWriteShort(i->bits);
    // i->compression = lendianWriteInt(i->compression);
    // i->imagesize = lendianWriteInt(i->imagesize);
    // i->xresolution = lendianWriteInt(i->xresolution);
    // i->yresolution = lendianWriteInt(i->yresolution);
    // i->ncolors = lendianWriteInt(i->ncolors);
    // i->importantcolors = lendianWriteInt(i->importantcolors);
}

void checkFile(char *fileName, struct header *h, struct information *i)
{
    #ifdef DEBUG
        printf("DEBUG: checkFile()\n");
    #endif
    
    if (h->type != 19778)
    {
        printf("Invalid file type in header for %s\n", fileName);
        exit(1);
    }
    
    if(h->size == 0)
    {
        printf("Invalid size in header for %s\n", fileName);
        exit(1);
    }
    
    if(h->reserved1 != 0 ||
       h->reserved2 != 0)
    {
        printf("Invalid reserved field in header for %s\n", fileName);
        exit(1);
    }
    
    if(h->offset != 54)
    {
        printf("Invalid offset in header for %s\n", fileName);
        exit(1);
    }
    
    if(i->size != 40)
    {
        printf("Invalid size in header for %s\n", fileName);
        exit(1);
    }
    
    if(i->width == 0)
    {
        printf("Invalid width in header for %s\n", fileName);
        exit(1);
    }
    
    if(i->height == 0)
    {
        printf("Invalid height in header for %s\n", fileName);
        exit(1);
    }
    
    if(i->planes != 1)
    {
        printf("Invalid planes in header for %s\n", fileName);
        exit(1);
    }
    
    if(i->bits != 24)
    {
        printf("Invalid bits in header for %s\n", fileName);
        exit(1);
    }
    
    if(i->compression != 0)
    {
        printf("Invalid compression in header for %s\n", fileName);
        exit(1);
    }
    
    if(i->ncolors != 0)
    {
        printf("Invalid colors in header for %s\n", fileName);
        exit(1);
    }
    
    if(i->importantcolors != 0)
    {
        printf("Invalid importantcolors in header for %s\n", fileName);
        exit(1);
    }
}

int isNumeric(char* value)
{
    int i;
    for (i = 0; i < strlen(value) - 1; i++)
    {
        if (value[i] >= '0' && value[i] <= '9')
        {
            // do nothing
        }
        else
        {
            return 0;
        }
    }
    
    return 1;
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

