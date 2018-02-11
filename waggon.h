/*************************************************************************
Header File   : Waggon.h
Author - Date : Efstathios Siatras - 18/12/2017
Purpose       : Header file of class Waggon
*************************************************************************/
#ifndef WAGGON_H
#define WAGGON_H

#include "passenger.h"

class Waggon {
	private:
		const int maxCapacity; // Maximum capacity of the waggon
		Passenger **seatsArray; // Seats of the waggon ; An array (size of 'maxCapacity') of pointers to Passengers

		int numberOfPassengers; // Current number of Passengers in the Waggon

		int foundOffenders; // Number of offenders that were found
		int notFoundOffenders; // Number of offenders that were not found

		int inspection; // Flag for ticket inspection

	public:
		Waggon(const int &); // Constructor

		~Waggon(); // Destructor

		void inStation(const int &); // Behaviour of the waggon in a station

		void betweenStations(int &, const int &, const int &); // Behaviour of the waggon between stations 

		void printStatistics(const int &) const; // Prints statistics about the waggon
};

#endif