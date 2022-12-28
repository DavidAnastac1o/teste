#include <stdio.h>
#include <stdlib.h>
#include "saveFiles.h"
#include "general.h"

int saveFiles() {
    cloneFile("data/passenger.txt", "data/BUpassenger.txt");
    cloneFile("data/aeronaves.txt", "data/BUaeronaves.txt");
    cloneFile("data/idFile.txt", "data/BUidFile.txt");
    goBack();
}

void cloneFile(char *sourceText, char *targetText){
    FILE *sourceFile, *targetFile;
    char content;

    // Open one file for reading
    sourceFile = fopen(sourceText, "r");
    if (sourceFile == NULL){
      printf("Cannot open source file.");
      exit(0);
    }
    // Open another file for writing
    targetFile = fopen(targetText, "w");
    if (targetFile == NULL){
      printf("Cannot open target file.");
      exit(0);
    }
    // Read contents from file (EOF = end of file)
    content = fgetc(sourceFile);
    while (content != EOF){
      fputc(content, targetFile);
      content = fgetc(sourceFile);
    }
    printf("Contents copied to %s", targetText);
    fclose(sourceFile);
    fclose(targetFile);
}


