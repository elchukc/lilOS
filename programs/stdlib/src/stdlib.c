#include "stdlib.h"
#include "lilos.h"

void* malloc(size_t size) {
    return lilos_malloc(size);
}

void free(void* ptr) {

}
