#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "mapc_lib.h"

struct mapc_t *mapc_build() {
   struct mapc_t *m;
   m=(struct mapc_t *)malloc(sizeof(struct mapc_t));
   if(!m)
      return NULL;
   m->name=NULL;
   m->value=NULL;
   m->nxt=NULL;
   return m;
}

void mapc_free(struct mapc_t *mapc) {
   if(!mapc)
      return;

   struct mapc_t *m, *mp;

   m=mapc;
   while(m!=NULL) {
      if(m->name!=NULL)
         free(m->name);
      if(m->value!=NULL)
         free(m->value);
      mp=m;
      m=m->nxt;
      free(mp);
   }
}

void mapc_set(struct mapc_t *m,char *name,char *value) {
   struct mapc_t *mapc;

   if(m->name==NULL) {
      m->name=(char *)malloc(strlen(name)+1);
      if(!m->name)
         return;
      strcpy(m->name,name);
      m->value=(char *)malloc(strlen(value)+1);
      if(!m->value)
         return;
      strcpy(m->value,value);
      m->nxt=NULL;
      return;
   }
   for(mapc=m;;mapc=mapc->nxt) {
      if(!strcasecmp(name,mapc->name)) {
         if(mapc->value!=NULL) {
            free(mapc->value);
            mapc->value=(char *)malloc(strlen(value)+1);
            if(!mapc->value)
               return;
            strcpy(mapc->value,value);
            return;
         }
      }
      if(mapc->nxt==NULL) {
         mapc->nxt=(struct mapc_t *)malloc(sizeof(struct mapc_t));
         if(!mapc->nxt)
            return;
         mapc=mapc->nxt;
         mapc->name=(char *)malloc(strlen(name)+1);
	 if(!mapc->name)
            return;
         strcpy(mapc->name,name);
         mapc->value=(char *)malloc(strlen(value)+1);
         if(!mapc->value)
            return;
         strcpy(mapc->value,value);
         mapc->nxt=NULL;
         return;
      }
   }
}

char *mapc_get(struct mapc_t *m,char *name) {
   struct mapc_t *mapc;
   for(mapc=m;mapc!=NULL;mapc=mapc->nxt) {
      if(mapc->name && !strcasecmp(name,mapc->name)) {
         return mapc->value;
      }
   }
   return "";
}
 

