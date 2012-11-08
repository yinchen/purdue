#include "misc.h"
#include <assert.h>

/***********************************************************************/
/*  FUNCTION:  void Assert(int assertion, char* error)  */
/**/
/*  INPUTS: assertion should be a predicated that the programmer */
/*  assumes to be true.  If this assumption is not true the message */
/*  error is printed and the program exits. */
/**/
/*  OUTPUT: None. */
/**/
/*  Modifies input:  none */
/**/
/*  Note:  If DEBUG_ASSERT is not defined then assertions should not */
/*         be in use as they will slow down the code.  Therefore the */
/*         compiler will complain if an assertion is used when */
/*         DEBUG_ASSERT is undefined. */
/***********************************************************************/


void Assert(int assertion, char* error) {
  if(!assertion) {
    printf("Assertion Failed: %s\n",error);
    abort();
    exit(-1);
  }
}



/***********************************************************************/
/*  FUNCTION:  SafeMalloc */
/**/
/*    INPUTS:  size is the size to malloc */
/**/
/*    OUTPUT:  returns pointer to allocated memory if succesful */
/**/
/*    EFFECT:  mallocs new memory.  If malloc fails, prints error message */
/*             and terminates program. */
/**/
/*    Modifies Input: none */
/**/
/***********************************************************************/

int index = 0;
void* footprint[1024];

void * SafeMalloc(size_t size) {
  void * result;

  if ( (result = malloc(size)) ) { /* assignment intentional */
    return(result);
  } else {
    printf("memory overflow: malloc failed in SafeMalloc.");
    printf("  Exiting Program.\n");
    exit(-1);
    return(0);
  }
}
/*  NullFunction does nothing it is included so that it can be passed */
/*  as a function to RBTreeCreate when no other suitable function has */
/*  been defined */

void NullFunction(void * junk) { ; }

void * my_malloc(size_t size) {
  void * result = malloc(size);

  footprint[index] = result;
  index++;
  
  return result;
}

void   my_free(void* ptr) {
  free (ptr);

  int i = 0;
  for (i = 0; i < 1024; i++) {
    if (footprint[i] == ptr)
      footprint[i] = NULL;
  }
}

void my_check_leak() {
  int isEmpty = 1;

  int i = 0;
  for (i = 0; i < 1024; i++) {
    if (footprint[i] != NULL)
    {
      isEmpty = 0;
      break;
    }
  }

  Assert(isEmpty==1,"memory leak!");
}

