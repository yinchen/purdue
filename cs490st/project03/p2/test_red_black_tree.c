#include"red_black_tree.h"
#include<stdio.h>
#include<ctype.h>


/*  this file has functions to test a red-black tree of integers */

void IntDest(void* a) {
  my_free((int*)a);
}



int IntComp(const void* a,const void* b) {
  if( *(int*)a > *(int*)b) return(1);
  if( *(int*)a < *(int*)b) return(-1);
  return(0);
}

void IntPrint(const void* a) {
  printf("%i",*(int*)a);
}

void InfoPrint(void* a) {
  ;
}

void InfoDest(void *a){
  ;
}

int main(int argc, char** argv) {
  int option=0;
  int newKey;
  int* newInt;
  rb_red_blk_node* newNode;
  rb_red_blk_tree* tree;
  FILE* fp;
  int n=0;
  int i=0;

  if (argc != 2) {
    printf("Usage: %s infile\n", argv[0]);
    return 1;
  }

  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("File not found: %s\n", argv[1]);
    return 1;
  }
  
  tree=RBTreeCreate(IntComp,IntDest,InfoDest,IntPrint,InfoPrint);

  fread(&n,1,1,fp);

  for (i = 0; i < n; i++) {
    if (fread(&option,1,1,fp) == 0) break;
    if (fread(&newKey,1,1,fp) == 0) break;

    switch (option)
    {
      case 1:
	{
	  newInt = (int*)my_malloc(sizeof(int));
	  *newInt = newKey;
	  RBTreeInsert(tree,newInt,0);
	}
	break;
      case 2:
	{
	  if ( ( newNode=RBExactQuery(tree,&newKey ) ) ) RBDelete(tree,newNode);/*assignment*/
	}
	break;
      case 3:
	{
	  if ( ( newNode = RBExactQuery(tree,&newKey) ) ) {/*assignment*/
	    printf("data found in tree at location %p\n",(void*)newNode);
	  }
	  else {
	    printf("data not in tree\n");
	  }
	}
	break;
      case 4:
	{
	  if ( ( newNode = RBExactQuery(tree,&newKey) ) ) {/*assignment*/
	    newNode=TreePredecessor(tree,newNode);
	    if(tree->nil == newNode) {
	      printf("there is no predecessor for that node (it is a minimum)\n");
	    } else {
	      printf("predecessor at location %p\n",(void*)newNode);
	    }
	  } else {
	    printf("data not in tree\n");
	  }
	}
	break;
      case 5:
	{
	  if ( (newNode = RBExactQuery(tree,&newKey) ) ) {
	    newNode=TreeSuccessor(tree,newNode);
	    if(tree->nil == newNode) {
	      printf("there is no successor for that node (it is a maximum)\n");
	    } else {
	      printf("successor at location %p\n",(void*)newNode);
	    }
	  } else {
	    printf("data not in tree\n");
	  }
	}
	break;
      case 6:
	{
	  RBTreePrint(tree);
	}
	break;
      default:
	break;
    }
  }

  RBTreeDestroy(tree);
  fclose(fp);

  my_check_leak();

  return 0;
}




