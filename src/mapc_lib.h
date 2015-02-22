#ifndef MAPC_LIB_H
#define MAPC_LIB_H

struct mapc_t {
   struct mapc_t *nxt;
   char *name;
   char *value;
} ;

struct mapc_t *mapc_build();
void mapc_free(struct mapc_t *mapc);
void mapc_set(struct mapc_t *m,char *name,char *value);
char *mapc_get(struct mapc_t *m,char *name);

#endif