#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main() {
    char gameName[256];
    char cueFileSource[256];
    char cueFileDestination[256];
    char m3uFilePath[300];
    FILE *m3uFile;

    printf("   _____           __          __ _                      _ \n");
    printf("  / ____|          \\ \\        / /(_)                    | |\n");
    printf(" | |     _   _   ___\\ \\  /\\  / /  _  ____ __ _  _ __  __| |\n");
    printf(" | |    | | | | / _ \\\\ \\/  \\/ /  | ||_  // _` || '__|/ _` |\n");
    printf(" | |____| |_| ||  __/ \\  /\\  /   | | / /| (_| || |  | (_| |\n");
    printf("  \\_____|\\__,_| \\___|  \\/  \\/    |_|/___|\\__,_||_|   \\__,_|\n");
    printf("                                                           \n");
    printf("                                                           \n");

    // Get the game name frome user
    printf("Enter the game name: ");
    fgets(gameName,sizeof(gameName), stdin);
    gameName[strcspn(gameName, "\n")] = 0; // Remove any trailing new lines

    // Get the source directory for the .cue files
    printf("Enter the source directory for the .cue files: ");
    scanf("%255s", cueFileSource);

    // Get the destination directory for the .cue files
    printf("Enter the destination directory for the .cue files: ");
    scanf("%255s", cueFileDestination);

    // Clear the input buffer
    // Important for scanf and if mixing both scaf and fgets
    while (getchar() != '\n');

    // Create the .m3u file
    sprintf(m3uFilePath, "%s/%s.m3u", cueFileSource, gameName);
    m3uFile = fopen(m3uFilePath, "w");
    if (m3uFile == NULL) {
        perror("Error creating .m3u file");
        return 1;
    }

    // Open the source directory
    DIR *dir = opendir(cueFileSource);
    if (dir == NULL) {
        perror("Error opening the source directory");
        fclose(m3uFile);
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Check if the is a .cue file
        if (strstr(entry->d_name, ".cue") != NULL) {
            char sourcePath[300];
            char destinationPath [300];

            // Construct the source and destination paths
            sprintf(sourcePath, "%s/%s", cueFileSource, entry->d_name);
            sprintf(destinationPath, "%s/%s", cueFileDestination,entry->d_name);

            // Move the .cue files
            if (rename(sourcePath, destinationPath) !=0) {
                perror("Error moving .cue file");
                continue;
            }

            // write the new paths to the .m3u fules
            fprintf(m3uFile, "%s\n", destinationPath);

        }
    }
    closedir(dir);
    fclose(m3uFile);

    printf("Operation completed successfully.\n");
    return 0;

}
