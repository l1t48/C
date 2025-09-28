#include "io.h"
//
// Private
//
static void empty_stream()
{
	int c;

	while ((c = getchar()) != EOF && c != '\n')
		;
}

//
// Public
//
int read_line(char *buf, int n)
{
	int buf_size;

	if (!fgets(buf, n, stdin)) {
		empty_stream();
		return 0; 
	}

	buf_size = strlen(buf);
	if (buf[buf_size-1] != '\n') {
		empty_stream();
		return 0; 
	}


	buf[buf_size-1] = '\0';
	return buf_size-1;
}
