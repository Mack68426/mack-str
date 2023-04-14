#pragma once

#ifndef UURUNTIME_NEW_H
#define UURUNTIME_NEW_H

#include <stddef.h>
#include <stdlib.h>

// ooc 
#define container_of(ptr, type, member)					    \
    ({								                        \
        const typeof(((type *)0)->member ) *__mptr = (ptr);	\
        (type *)((char *)__mptr - offsetof(type, member));	\
    })


#define new(TYPE, ...) TYPE ## _construct(malloc(sizeof(TYPE)), ## __VA_ARGS__)
#define delete(TYPE, ptr) do { TYPE ## _destruct(ptr); free(ptr); } while(0)

// conbined ideas 
#define $new(TYPE, ...) $ ## TYPE ## $(malloc(sizeof(TYPE)), ## __VA_ARGS__)
#define $delete(TYPE, ptr) do { d$ ## TYPE ## $(ptr); free(ptr); } while(0)
#define printfit(T, format, ...) T ## _print(format, ## __VA_ARGS__)


#endif