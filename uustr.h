#pragma once

#ifndef UUSTR_H
#define UUSTR_H

#include <stddef.h>

#define N_INITIAL_CAPACITY 5

// #define $uustr(T, ...)	$new(T)

typedef struct __uustr uustr;

struct __uustr
{
	// field
	size_t _length;
	size_t _capacity;
	char * _str;

	size_t (*len)(uustr *);
	void (*appendc)(uustr *, const char);
	void (*appends)(uustr *, const char *);
	const char* (*cstr)(uustr *);
	uustr* (*ctor)(void *, ...);
	void (*dtor)(uustr *);
} ;

extern uustr* $uustr$(void *, ...);
extern void d$uustr$(uustr *);

#endif