#include "../Headers/ArrayOfPointerOfString.h"

int aopos_init(ArrayOfPointerOfString_t* map) {
    *map = malloc(26 * sizeof(unsigned char**));
    for (int i = 0; i<26 ; ++i) {
        (*map)[i] = NULL;
    }
    return 0;
}

unsigned char** aopos_get_ptr(ArrayOfPointerOfString_t* map, char key_add_a) {
    if (key_add_a < 'a') { return NULL; }
    if (key_add_a > 'z') { return NULL; }
    return (*map)[key_add_a - 'a'];
}

int aopos_set(ArrayOfPointerOfString_t* map, char key_add_a, unsigned char** ptr) {
    if (key_add_a < 'a') { return EINVAL; }
    if (key_add_a > 'z') { return EINVAL; }
    (*map)[key_add_a - 'a'] = ptr;
    return 0;
}


void aopos_free(ArrayOfPointerOfString_t* map) {
    free(*map);
}
