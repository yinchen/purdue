
struct header {
	unsigned short int type;
	unsigned int size;
	unsigned short int reserved1, reserved2;
	unsigned int offset;
}__attribute__((packed)) ;

struct information{
	unsigned int size;
	int width,height;
	unsigned short int planes;
	unsigned short int bits;
	unsigned int compression;
	unsigned int imagesize;
	int xresolution, yresolution;
	unsigned int ncolors;
	unsigned int importantcolors;
};
unsigned int lendianReadInt(unsigned char *);
unsigned int lendianWriteInt(unsigned char *);
unsigned short int lendianWriteShort(unsigned char *);
unsigned short int lendianReadShort(unsigned char *);
