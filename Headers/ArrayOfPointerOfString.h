#ifndef ARRAY_OF_POINTER_OF_STRING_H
#define ARRAY_OF_POINTER_OF_STRING_H

#include <stddef.h>
#include <stdlib.h>
#include <errno.h>

#define arrayOfPointerOfString unsigned char***

int aoposInit(arrayOfPointerOfString* map);
unsigned char** aoposGetPtr(arrayOfPointerOfString* map, char key);
int aoposSet(arrayOfPointerOfString* map, char key, unsigned char** ptr);
void aoposFree(arrayOfPointerOfString* map);

#endif /* ARRAY_OF_POINTER_OF_STRING_H */
