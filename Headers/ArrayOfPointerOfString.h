#ifndef ARRAY_OF_POINTER_OF_STRING_H
#define ARRAY_OF_POINTER_OF_STRING_H

#include <stddef.h>
#include <stdlib.h>
#include <errno.h>

#define ArrayOfPointerOfString_t unsigned char***

int aopos_init(ArrayOfPointerOfString_t* map);
unsigned char** aopos_get_ptr(ArrayOfPointerOfString_t* map, char key);
int aopos_set(ArrayOfPointerOfString_t* map, char key, unsigned char** ptr);
void aopos_free(ArrayOfPointerOfString_t* map);

#endif /* ARRAY_OF_POINTER_OF_STRING_H */
