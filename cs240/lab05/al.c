#include <stdlib.h>

struct al
{
	int size;
	void **data;
	int count;
};

struct al* al_create(int size)
{
	if (size < 1)
		return NULL;
	
	struct al *l;
	
	l = (struct al*)malloc(sizeof(struct al));
	if (l == NULL)
	{
		printf("Error: malloc() failed!");
		exit(1);
	}
	
	l->size = size;
	l->data = (void**)malloc(size * sizeof(void*));
	l->count = 0;
	
	return l;
}

void al_free(struct al *l)
{
	// if (l == NULL)
	// 	return NULL;
	
	free(l->data);
	free(l);
}

int al_resize(struct al *l, int size)
{
	if (size < l->count)
		return NULL;
	
	l->data = (void*)realloc(l->data, size * sizeof(void*));
	
	if (l->data == NULL)
		return -1;
	
	return 0;
}

int al_add(struct al *l, void *e)
{
	if (l->count == l->size)
		al_resize(l, l->size * 2);
	
	l->data[l->count] == e;
	l->count++;
	
	return 0;
}

int al_insertat(struct al *l, int i, void *e)
{
	if (i < 0)
		return NULL;
	
	if (l->count == l->size)
		if (al_resize(l, l->size * 2) == NULL)
			return -1;
	
	int j;
	for (j = l->count; j > i; j--)
	{
		l->data[j] = l->data[j - 1];
	}
	
	l->data[i] == e;
	l->count++;
	
	return 0;
}

int al_clear(struct al *l)
{
	l->count == 0;	
	return 0;
}

int al_removeat(struct al *l, int i)
{
	if (i > l->count ||
	    i < 0)
		return NULL;
	
	int j;
	for (j = i; j < l->count; j++)
	{
		l->data[j - 1] = l->data[j];
	}
	
	l->count--;
	
	return 0;
}

int al_remove(struct al *l, void *e)
{
	int i;
	for (i = 0; i < l->count; i++)
	{
		if (l->data[i] == e)
		{
			return al_removeat(l, i);
		}
	}
	
	return NULL;
}

void *al_get(struct al *l, int i)
{
	if (i > l->count ||
	    i < 0)
		return NULL;
	
	return l->data[i];
}

void al_dump(struct al *l)
{
	int i;

	for (i = 0; i < l->count; i++)
	{
	    printf("%d ", al_get(l, i));
	}
	
	printf("\n");
}

