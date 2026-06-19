#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int length_first_word(char* command);
char* command_word(char* command, int length_word);
void to_lowercase(char* word);

int main(void){
    int command_length,buffer = 64;
    char command[64];
    while(1){
        printf("Personal Utilities\n -> "); //Title
        fgets(command, buffer, stdin);
        command_length = strlen(command);
        command[strcspn(command,"\n")] = '\0';
        int type_length = length_first_word(command); //store the length of the first word
        char* type = command_word(command,type_length); //store the actual word
        to_lowercase(type); //convert to lower case to make comparing esasier
        //if else ladder to check for commands
        if (strcmp(type, "exit") == 0){
            break;
        }
        else if (strcmp(type,"notes") == 0){
            int pass;
        }

    }
}

char* command_word(char* command, int length_word){
    char* command_type = (char*)malloc((length_word+1) * sizeof(char)); //length_word+1 to allocate for the '\0' and dynamically allocated so that it can be returned to the main function
    for (int i = 0; i < length_word; i++){
        command_type[i] = command[i];
    }
    command_type[length_word] = '\0'; //placing in the null terminator manually
    return command_type;

}
int length_first_word(char* command){ //function that finds the length of the first word and returns
    int i = 0;
    while (command[i] != ' ' && command[i] != '\0'){
        i++;
    }
    return i; //returns the length of the first word 
}
void to_lowercase(char* word){
    int length = strlen(word);
    for (int i = 0; i < length; i++){
        word[i] = tolower(word[i]);
    }
}
