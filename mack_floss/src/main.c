#include <stdio.h>
#include <mackstr/base.h>
#include <mackstr/mackstr.h>

// 待處理
// stackdump

int main(int argc, char* argv[])
{
	uustr *s = new(uustr, "Hello");

	puts(s->cstr(s));

	delete(uustr, s);

	return 0;
}