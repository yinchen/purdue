#include "mysort.h"
#include <alloca.h>
#include <assert.h>
#include <string.h>

//
// Sort an array of element of any type
// it uses "compFunc" to sort the elements.
// The elements are sorted such as:
//
// if ascending != 0
//   compFunc( array[ i ], array[ i+1 ] ) <= 0
// else
//   compFunc( array[ i ], array[ i+1 ] ) >= 0
//
// See test_sort to see how to use mysort.
//
void mysort(int n,                      // Number of elements
            int elementSize,            // Size of each element
            void * array,               // Pointer to an array
            int ascending,              // 0 -> descending; 1 -> ascending
            CompareFunction compFunc)   // Comparison function.
{
    char *c_array;
    c_array = (char*)array;
    
    int *i_array;
    i_array = (int*)array;
    
    int tmp;
    
    int changed;
    changed = 1;
    
    while (changed)
    {
        changed = 0;
        
        int i;
        for (i = 0; i < n - 1; i++)
        {
            if (ascending)
            {
                if (compFunc(&i_array[i], &i_array[i + 1]) <= 0)
                {
                    tmp = i_array[i];
                    i_array[i] = i_array[i + 1];
                    i_array[i + 1] = tmp;
                    
                    changed = 1;
                }
            }
            else
            {
                if (compFunc(&i_array[i], &i_array[i + 1]) >= 0)
                {
                    tmp = i_array[i];
                    i_array[i] = i_array[i + 1];
                    i_array[i + 1] = tmp;
                    
                    changed = 1;
                }
            }
        }
    }
}

