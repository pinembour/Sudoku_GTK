#include <stdio.h>
#include "itoa.h"

//Convertir int vers char*
char *my_itoa(char *dest, int i) {
	sprintf(dest, "%d", i);
	return dest;
}


