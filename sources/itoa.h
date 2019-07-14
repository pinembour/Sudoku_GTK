#ifndef ITOA_H
#define ITOA_H

char *my_itoa(char*, int );

//Define pour utilisation plus concise
#define ITOA(n) my_itoa((char [41]) { 0 }, (n) )

#endif
