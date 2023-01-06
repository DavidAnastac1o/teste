#ifndef AERONAVE_H_INCLUDED
#define AERONAVE_H_INCLUDED

typedef struct{
	int id;
	int capacity;
    int totalFlights;

	char currentState[40];
	char location[20];
	char destiny[20];

	//passengers
    int passengerId1;
    int passengerId2;
    int passengerId3;
    int passengerId4;

    //last flight
	char lastFlight1[40];
	char lastFlight2[40];
	char lastFlight3[40];
}typeAirplane;

void printAirplaneById(typeAirplane airplane, FILE *file, int ID);

void printAirplane(typeAirplane airplane, FILE *file);

void writeinFileAirplane(typeAirplane *airplane, FILE *file, int repeatTimes);

void authorize(typeAirplane airplane, FILE *file);

void deleteAirplane(int id);

void replacePlaneStr(int id, const char *field, const char *newValue);

int replacePlaneAddFly(int id, const char *field);

void replacePlaneUpdateLastFlights(int id, const char *field);

void printAirplaneReady(typeAirplane airplane, FILE *file);

void printAirplaneWaiting(typeAirplane airplane, FILE *file);

void editAirplane(int id);

void subMenu();

void cancelUpdateInfo(int Id);

void subMenuAuthorization();

#endif // AERONAVE_H_INCLUDED
