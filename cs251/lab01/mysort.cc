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
    void *tmp;
    tmp = alloca(elementSize);
    
    int changed;
    changed = 1;
    
    while (changed)
    {
        changed = 0;
        
        int i;
        for (i = 0; i < n; i++)
        {
            if (ascending)
            {
                if (compFunc(array[i], array[i + 1]) <= 0)
                {
                    tmp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = tmp;
                    
                    changed = 1;
                }
            }
            else
            {
                if (compFunc(array[i], array[i + 1]) >= 0)
                {
                    tmp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = tmp;
                    
                    changed = 1;
                }
            }
        }
    }
}

