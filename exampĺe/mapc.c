#include <stdio.h>
#include "mapc_lib.h"

void display_both(struct mapc_t *m,char *key);

void display_both(struct mapc_t *m,char *first) {
   printf("%s %s\n",first,mapc_get(m,first));
}

int main(int argc,char **argv) {
   struct mapc_t *array;

   // Let's create a map array
   array=mapc_create();
   mapc_set(array,"Cow","Muuuuu");
   mapc_set(array,"Dog","Guau");
   mapc_set(array,"Cat","Miau");

   // Display it without order
   display_both(array,"Dog");
   display_both(array,"Cat");
   display_both(array,"Cow");
   printf("\n");

   // Reset an existing entry
   mapc_set(array,"Dog","Guau Guau");

   // Display them again to see
   // the change
   display_both(array,"Dog");
   display_both(array,"Cat");
   display_both(array,"Cow");
   printf("\n");

   // Display a non existing entry.
   display_both(array,"Fox");
   printf("\n");

   // Add a new entry
   // What does the fox say?
   mapc_set(array,"Fox","Ding Ding Ding");

   // Display de entry recently
   // created.
   display_both(array,"Fox");
}