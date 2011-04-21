#include "bmp_header.h"

int main(int argc, char **argv)
{
    if (argv[1] == "-create")
    {
        // create new bitmap
    }
    else if (argv[1] == "-invertcolor")
    {
        // invert color data
    }
    else if (argv[1] == "stackvertically")
      {
	// stack bitmaps vertically
      }
    else if (argv[1] == "-stackhorizontally")
      {
	// stack bitmaps horizontally
      }
    else if (argv[1] == "-drawborder")
      {

      }
    else
      {
	// invalid syntax
      }
    return 0;
}
