#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Notes.c"
#include "Notes.h"
void to_lowercase(char* word);

int main(void){
    int command_length,buffer = 64;
    char command[64];
    while(1){
        printf("Personal Utilities\n -> "); //Title
        fgets(command, buffer, stdin);
        command_length = strlen(command);
        command[strcspn(command,"\n")] = '\0';
        char section[20],action[20],subject[20];
        int count = sscanf(command, "%19s %19s %19s", section, action, subject);
        //changes to lower for easy comparison 
        to_lowercase(section);
        to_lowercase(action);
        to_lowercase(subject);
        //if else ladder to check for commands
        if (strcmp(section, "exit") == 0){
            break;
        }
        else if (strcmp(section,"notes") == 0){
            if (count != 3){
                printf("Usage: notes requires 3 inputs an action and subject");
            }
            else{
                notes_main(action,subject);
            }
        }

    }
}
void to_lowercase(char* word){
    int length = strlen(word);
    for (int i = 0; i < length; i++){
        word[i] = tolower(word[i]);
    }
}
