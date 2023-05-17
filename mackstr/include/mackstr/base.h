#ifndef BASE_H
#define BASE_H

#include <stddef.h>

// ooc 
#define container_of(ptr, type, member)					\
    ({														\
        const typeof(((type *)0)->member ) *__mptr = (ptr);	\
        (type *)((char *)__mptr - offsetof(type, member));	\
    })

#define new(TYPE, ...) TYPE ## _construct(malloc(sizeof(TYPE)), ## __VA_ARGS__)


#define delete(TYPE, ptr) do		\
        {							\
            TYPE ## _destruct(ptr);	\
            free(ptr);				\
        } while(0)



#endif // !BASE_H