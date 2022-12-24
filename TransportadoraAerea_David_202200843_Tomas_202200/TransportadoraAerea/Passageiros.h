#ifndef LISTARPASSAGEIROS_H_INCLUDED
#define LISTARPASSAGEIROS_H_INCLUDED

typedef struct
{
	int id;
	int nif;
	char firstName[20];
	char lastName[20];
}typePassenger;

void printPassangers(typePassenger passengers, FILE *file);

void writeinFile(typePassenger *passengers, FILE *file, int repeatTimes);


#endif // LISTARPASSAGEIROS_H_INCLUDED
