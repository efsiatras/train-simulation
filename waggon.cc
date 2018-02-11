/*************************************************************************
Implementation File : waggon.cc
Author - Date       : Efstathios Siatras - 18/12/2017
Purpose             : Implementation file of class Waggon
*************************************************************************/
#include <iostream>
#include <cstdlib>

#include "waggon.h"

using namespace std;

Waggon::Waggon(const int &maxC)
	: maxCapacity(maxC), seatsArray(NULL), numberOfPassengers(0), foundOffenders(0), notFoundOffenders(0), inspection(0) {
	seatsArray = new Passenger*[maxCapacity];

	for (int i = 0; i < maxCapacity; i++) { // Fills array with NULL
		
		seatsArray[i] = NULL;
	}

	cout << "A waggon with capacity for " << maxCapacity << " passengers, was created" << endl;
}

Waggon::~Waggon() {
	cout << "A waggon was destroyed" << endl;
	for (int i = 0; i < maxCapacity; i++) { // Frees passengers in array
		if(seatsArray[i] != NULL) {

			delete seatsArray[i];
			seatsArray[i] = NULL;
		}
	}

	delete[] seatsArray; // Frees array
	seatsArray = NULL;
}

void Waggon::inStation(const int &remainingStations) {
	if (inspection != 0) { // If there is an inspector
		for (int i = 0; i < maxCapacity; i++) { // Checks all passengers
			if (seatsArray[i] != NULL) {
				if (seatsArray[i]->get_hasTicket() == 0) { // Checks if passenger has ticket
					delete seatsArray[i]; // Gets offender off
					seatsArray[i] = NULL;

					numberOfPassengers--;
				}
			}
		}
	}

	if (remainingStations != 1) { // If the train is not at the last station
		int getOff; // Number of people who are getting off the train
		int getOn; // Number of people who are getting on the train

		getOff = rand() % (numberOfPassengers + 1); // 0 <= getOff <= numberOfPassengers 

		int i = 0;
		while ((i < maxCapacity) && (getOff != 0)) { // Gets off passengers
			if (seatsArray[i] != NULL) {
				delete seatsArray[i];
				seatsArray[i] = NULL;

				getOff--;
				numberOfPassengers--;
			}

			i++;
		}

		getOn = rand() % (maxCapacity - numberOfPassengers + 1); // 0 <= getOn <= (maxCapacity - numberOfPassengers)

		i = 0;
		while ((i < maxCapacity) && (getOn != 0)) { // Gets on passengers
			if (seatsArray[i] == NULL) {
				seatsArray[i] = new Passenger;

				getOn--;
				numberOfPassengers++;
			}

			i++;
		}

		inspection = rand() % 2; // Decides if there will be an inspector 
	}

	else { // The train is at the last station
		for (int i = 0; i < maxCapacity; i++) { // Gets off all passengers
			if (seatsArray[i] != NULL) {
				delete seatsArray[i];
				seatsArray[i] = NULL;

				numberOfPassengers--;
			}
		}
	}
}

void Waggon::betweenStations(int &money, const int &fullFine, const int &reducedFine) {
	if (inspection != 0) { // If there is an inspector
		for (int i = 0; i < maxCapacity; i++) { // Checks all passengers
			if (seatsArray[i] != NULL) {
				if (seatsArray[i]->get_hasTicket() == 0) { // Checks if passenger has ticket
					foundOffenders++; // Finds founders

					if (seatsArray[i]->get_reducedTicket() == 0) {
						money += fullFine; // Full fine for lack of full ticket
					}

					else {
						money += reducedFine; // Reduced fine for lack of reduced ticket
					}
				}
			}
		}
	}

	else { // There is no inspector
		for (int i = 0; i < maxCapacity; i++) {
			if (seatsArray[i] != NULL) {
				if (seatsArray[i]->get_hasTicket() == 0) {

					notFoundOffenders++; // Offenders that have not been found
				}
			}
		}
	}
}

void Waggon::printStatistics(const int &i) const {
	cout << endl;
	cout << "--------- Waggon " << i+1 << " ---------" << endl;
	cout << "Offenders found: " << foundOffenders << endl;
	cout << "Offenders not found: " << notFoundOffenders << endl;
}