#include <stdio.h>
#include "../include/uustr.h"

// 待處理
// stackdump

int main(int argc, char* argv[])
{
	uustr *s = $new(uustr);

	
	s->appends(s, "1234");
	puts(s->cstr(s));

	$delete(uustr, s);

	return 0;
}