#include "mysort.h"
#include <stdlib.h>
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
    void *tmp = malloc(elementSize);
    
    int changed;
    changed = 1;
    
    while (changed)
    {
        changed = 0;
        
        int i;
        for (i = 0; i < n - 1; i++)
        {
            void *p1 = (void*)((char*)array+i*elementSize);
            void *p2 = (void*)((char*)array+(i+1)*elementSize);
        
            if (ascending)
            {
                if (compFunc(p1, p2) > 0)
                {
                    memcpy(tmp, p1, elementSize);
                    memcpy(p1, p2, elementSize);
                    memcpy(p2, tmp, elementSize);
                    
                    changed = 1;
                }
            }
            else
            {
                if (compFunc(p1, p2) < 0)
                {
                    memcpy(tmp, p1, elementSize);
                    memcpy(p1, p2, elementSize);
                    memcpy(p2, tmp, elementSize);
                    
                    changed = 1;
                }
            }
        }
    }
    
    free(tmp);
}

