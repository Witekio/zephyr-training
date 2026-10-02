#include <stdio.h>
#include <string.h>
#include <lib/mylib.h>

void mylib_get_val(char* output, int input) {
	if(input == CONFIG_MYLIB_UNIVERSAL_ANSWER) {
		strcpy(output, "Answer to the Ultimate Questipn of Life");
	} else {
		sprintf(output, "%d", input);
	}
}
