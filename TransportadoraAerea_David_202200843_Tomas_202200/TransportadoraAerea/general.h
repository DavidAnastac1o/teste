#ifndef GENERAL_H_INCLUDED
#define GENERAL_H_INCLUDED

void closeFile(FILE *file);
void goBack();

char *askString(char *text, char *str);
float askFloat(char *text);
int askInt(char *text);


#endif // GENERAL_H_INCLUDED
