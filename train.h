/*************************************************************************
Header File   : train.h
Author - Date : Efstathios Siatras - 18/12/2017
Purpose	      : Header file of class Train
*************************************************************************/
#ifndef TRAIN_H
#define TRAIN_H

#include "waggon.h"

class Train {
	private:
		int remainingStations; // Current remaining stations
		const int totalWaggons; // Total number of waggons
		Waggon **waggonsArray; // Waggons of the train ; An array (size of 'totalWaggons') of pointers to Waggons

		int money; // Current money collected
		const int fullFine; // Full fine
		const int reducedFine; // Reduced fine

	public:
		Train(const int & = 10, const int & = 10, const int & = 50, const int & = 100, const int & = 50); // Constructor

		~Train(); // Destructor

		void operate(); // Operates the train

		void printStatistics() const; // Prints statistics about the train
};

#endif