#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void notes_main(char* action, char* subject){
    char file_path[256];
    snprintf(file_path, sizeof(file_path),"data/notes/%s.txt", subject);
    if (strcmp(action, "create") == 0) {
        printf("Creating note: %s\n", subject);
        write_append_file(file_path, "w");
    }
    else if (strcmp(action, "view") == 0) {
        printf("Viewing note: %s\n", subject);
        char buffer[256];
        FILE* file = fopen(file_path, "r");
        if (file == NULL){
            printf("Note does not exist.\n");
            return;
        }
        while (fgets(buffer, sizeof(buffer), file) != NULL){
            printf("%s", buffer);
        }

        fclose(file);
    }
    else if (strcmp(action, "append") == 0){
        printf("Appending note: %s\n", subject);
        write_append_file(file_path, "a");
    }

    else if (strcmp(action, "delete") == 0){
        if (remove(file_path) == 0){
            printf("Note deleted successfully.\n");
        }
        else {
            printf("Could not delete note.\n");
        }
    }
    else{
        printf("Unknown notes action.\n");
    }
}
void write_append_file(char* file_path, const char* mode)
    char line[512];
    FILE* file = fopen(file_path, mode);
    if (file == NULL){
        printf("Could not open file.\n");
        return;
    }
    printf("Enter note content (type 'quit' to save and exit):\n");
    while (1){
        if (fgets(line, sizeof(line), stdin) == NULL){
            break;
        }
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line, "quit") == 0){
            break;
        }
        fprintf(file, "%s\n", line);
    }
    fclose(file);
}
