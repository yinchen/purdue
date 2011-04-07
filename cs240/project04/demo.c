
#include "bmpfile.h"

bmpfile_t *bmp;
rgb_pixel_t pixelW = {255, 255, 255, 0};
rgb_pixel_t pixelB = {0, 0, 0, 0};

int main(void)
{
	int CX, CY;

	// create the bmp object
	bmp = bmp_create(300, 300, 32);
	// clear the bmp to all black
	for (CX = 0; CX < 300; CX++)
		for (CY = 0; CY < 300; CY++)
			bmp_set_pixel(bmp, CX, CY, pixelB);
	// draw a white line from top left to bottom right
	for (CX = 0; CX < 300; CX++)
		bmp_set_pixel(bmp, CX, CX, pixelW);
	// save bitmap to demo.BMP
	bmp_save(bmp, "demo.BMP");
	// free bmp object
	bmp_destroy(bmp);
}

