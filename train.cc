/*************************************************************************
Implementation File : train.cc
Author - Date       : Efstathios Siatras - 18/12/2017
Purpose             : Implementation file of class Train
*************************************************************************/
#include <iostream>

#include "train.h"

using namespace std;

Train::Train(const int &remainingS, const int &totalW, const int &maxC, const int &fullF, const int &reducedF)
: remainingStations(remainingS), totalWaggons(totalW), waggonsArray(NULL), money(0), fullFine(fullF), reducedFine(reducedF) {
	waggonsArray = new Waggon*[totalWaggons];

	for (int i = 0; i < totalWaggons; i++) { // Fills array with waggons

		waggonsArray[i] = new Waggon(maxC);
	}

	cout << "A train with " << totalWaggons << " waggons, was created" << endl;
}

Train::~Train() {
	cout << "A train was destroyed" << endl;
	for (int i = 0; i < totalWaggons; i++) { // Frees waggons in array
			delete waggonsArray[i];
			waggonsArray[i] = NULL;
		}

	delete[] waggonsArray; // Frees array
	waggonsArray = NULL;
}

void Train::operate() {
	for (int i = 0; i < totalWaggons; i++) { // Visits first station

		waggonsArray[i]->inStation(remainingStations);
	}

	remainingStations--;

	while (remainingStations != 0) { // Visits the rest of the stations
		for (int i = 0; i < totalWaggons; i++) {
			waggonsArray[i]->betweenStations(money, fullFine, reducedFine); // Operates between the stations
			waggonsArray[i]->inStation(remainingStations); // Operates in the stations
		}

		remainingStations--;
	}
}

void Train::printStatistics() const {
	for (int i = 0; i < totalWaggons; i++) { // Prints statistics about each waggon

		waggonsArray[i]->printStatistics(i);
	}

	cout << endl << "Total money collected in fines: " << money << endl << endl;
}