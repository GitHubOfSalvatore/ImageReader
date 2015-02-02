#ifndef DATATYPES_H
#define DATATYPES_H

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char ubyte;
typedef unsigned short int ubyte2;
typedef unsigned long ubyte4;

#ifndef WIN32
typedef char                    byte; 
#endif
typedef signed short int byte2;
typedef signed long byte4;

#endif