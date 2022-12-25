#ifndef AERONAVE_H_INCLUDED
#define AERONAVE_H_INCLUDED

typedef struct{
	int id;
	int capacity;
    int totalFlights;

	char currentState[20];
	char location[20];
	char destiny[20];

	//passengers
    int passengerId1;
    int passengerId2;
    int passengerId3;
    int passengerId4;

    //last flight
	char lastFlight1[20];
	char lastFlight2[20];
	char lastFlight3[20];
}typeAirplane;

#endif // AERONAVE_H_INCLUDED
