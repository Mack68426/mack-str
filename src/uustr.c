#include "uustr.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

static char* OutputStream = NULL;
static uustr* uustr_constructor(void *, va_list);

static size_t uustr_len(uustr *);
static void uustr_appendc(uustr * , const char);
static void uustr_appends(uustr *, const char *);
static const char* uustr_cstr(uustr *);


static int vasprintf(char** buffer, const char* format, va_list ap);

// constructor and destructor
uustr* uustr_constructor(void* _Self, va_list ap)
{

    // ���w�ѼƳB�z
    size_t args_len = vsnprintf(NULL, 0, "%s", ap);

    OutputStream = (char* )malloc(++args_len * sizeof(char));

    vsnprintf(OutputStream, args_len, "%s", ap);

    // �إ߷s��string
	uustr* self = (uustr*)_Self;
    
    self->_length = 0;
    self->_capacity = N_INITIAL_CAPACITY;
    self->_str[0] = '\0';

    self->ctor = $uustr$;
    self->dtor = d$uustr$;
    self->appendc = uustr_appendc;
    self->appends = uustr_appends;
    self->len = uustr_len;
    self->cstr = uustr_cstr;
	
	return self;
}

// revise
uustr* $uustr$(void* addr, ...)
{
	if (addr == NULL) return NULL;

    va_list arglist;
    va_start(arglist, addr);
    
    
    vasprintf(
        &OutputStream, 
        "%s", 
        arglist);

    va_end(arglist);

    return uustr_constructor(addr, arglist);
}

void d$uustr$(uustr* _Self)
{
}


// memeber functions
size_t uustr_len(uustr * Self)
{
    return Self->_length;
}

void uustr_appendc(uustr* _Self, const char ch)
{
    if (_Self->_length + 1 > _Self->_capacity)
    {
        _Self->_capacity *= 2; // convension �O�⭿

        // _Self->_str = realloc(_Self->_str, _Self->_capacity * sizeof(char));
        _Self->_str = (char*)realloc(_Self->_str, _Self->_capacity * sizeof(char));
    }

    _Self->_str[_Self->_length++] = ch;
    _Self->_str[_Self->_length] = '\0';
}

void uustr_appends(uustr* _Self, const char* string)
{
    while (_Self->_str[0] != '\0')
    {
        _Self->appendc(_Self, *string);

        ++string;
    }
}

const char* uustr_cstr(uustr* _Self)
{
    return _Self->_str;
}


// support functions
int vasprintf(char** buffer, const char* format, va_list ap)
{
    // vsnprintf ���Nva_list�������e�g�D�r�ꤤ�A�åB����r�����
    // �Ĥ@���� NULL �u�O���F�n��r����צӤ��O���F�g�J

    int length = vsnprintf(NULL, 0, format, ap);
    // char* str = allocate(char, str, sizeof(char) * length + 1);
    char* str = (str = (char*)malloc(sizeof(char) * length)) ? str : NULL;

    vsnprintf(str, length + 1, format, ap);

    *buffer = str;
    
    return length;
}

