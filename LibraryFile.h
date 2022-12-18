#ifndef LIBRARYFILE_H
#define LIBRARYFILE_H

#include <stdio.h>
#include <stdlib.h>

#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "UserType.h"


ErrorState AddNewBook (List_t *s);
ErrorState IsEmpty (List_t *S);
ErrorState DisplayBook(List_t *S);
ErrorState Newlist (List_t **S);
ErrorState DeletBook (List_t *S);






#endif