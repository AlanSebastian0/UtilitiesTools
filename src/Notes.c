#include <stdio.h>
#include <string.h>

#include "Notes.h"

void notes_main(char* action, char* subject)
{
    if (strcmp(action, "create") == 0) {
        printf("Creating note: %s\n", subject);
    }

    else if (strcmp(action, "view") == 0){
        printf("Viewing note: %s\n", subject);
    }

    else{
        printf("Unknown notes action.\n");
    }
}
