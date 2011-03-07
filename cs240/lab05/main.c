#include <stdlib.h>
#include <stdio.h>
#include "al.h"

void* new_int(int num);
void al_dump(struct al *l);

main()
{
  struct al *l;
  int *u;
  l = al_create(5);
  al_add(l, new_int(1));
  al_add(l, new_int(2));
  al_add(l, new_int(3));
  printf("%d\n", al_resize(l, 3));
  al_dump(l);
  al_insertat(l, 0, new_int(4));
  al_dump(l);
  printf("%d\n", al_insertat(l, 6, NULL));
  printf("%d\n", al_insertat(l, 3, new_int(5)));
  al_dump(l);
  printf("%d\n", al_removeat(l, 5));
  printf("%d\n", al_removeat(l, 4));
  printf("%d\n", al_insertat(l, 2, u = new_int(6)));
  al_dump(l);
  printf("%d\n", al_remove(l, u));
  al_dump(l);
  free(l);
  return 0;
}

void* new_int(int num)
{
	int *ret;
	ret = (int*)malloc(sizeof(int));
	*ret = num;
	
	return ret;
}

void al_dump(struct al *l)
{
	int i;

	for (i = 0; i<(l->count); i++)
	{
		printf("%d ", *((int*)al_get(l, i)));
	}
}
