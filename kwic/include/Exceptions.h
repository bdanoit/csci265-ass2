/********** Exceptions module---interface specification **********/
/*
**              Overview
**      Supports throw/catch/finally in C
**      
**      state:
**              EXenv__ is declared in Exceptions.c
**              EXnum__ is declared in Exceptions.c
**              Each exception is defined in the range [1..n]
**             
**      assumptions:
**              none
*/

#include <setjmp.h>

/***** constants *****/

extern jmp_buf EXenv__;
extern int EXnum__;

#define TRY do {EXnum__=setjmp(EXenv__); if(!EXnum__) {
#define CATCH } else {
#define FINALLY  } {
#define ETRY } }while(0)
#define THROW(x) longjmp(EXenv__, (x)); 

#define DuplicateExc (1)
#define FullExc (2)
#define NotFoundExc (3)

