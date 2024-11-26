#include "../Headers/ArrayOfPointerOfString.h"

int aoposInit(arrayOfPointerOfString* map) {
    *map = malloc(26 * sizeof(unsigned char**));
    for (int i = 0; i<26 ; ++i) {
        (*map)[i] = NULL;
    }
    return 0;
}

unsigned char** aoposGetPtr(arrayOfPointerOfString* map, char key_add_a) {
    if (key_add_a < 'a') { return NULL; }
    if (key_add_a > 'z') { return NULL; }
    return (*map)[key_add_a - 'a'];
}

int aoposSet(arrayOfPointerOfString* map, char key_add_a, unsigned char** ptr) {
    if (key_add_a < 'a') { return EINVAL; }
    if (key_add_a > 'z') { return EINVAL; }
    (*map)[key_add_a - 'a'] = ptr;
    return 0;
}


void aoposFree(arrayOfPointerOfString* map) {
    free(*map);
}
