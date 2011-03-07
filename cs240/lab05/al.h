struct al;

struct al *al_create(int size);

void al_free(struct al *l);

int al_resize(struct al *l, int size);

int al_add(struct al *l, void *e);

int al_insertat(struct al *l, int i, void *e);

int al_clear(struct al *l);

int al_removeat(struct al *l, int i);

int al_remove(struct al *l, void *e);

void *al_get(struct al *l, int i);


