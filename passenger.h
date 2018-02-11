/*************************************************************************
Header File   : passenger.h
Author - Date : Efstathios Siatras - 18/12/2017
Purpose       : Header file of class Passenger
*************************************************************************/
#ifndef PASSENGER_H
#define PASSENGER_H

class Passenger {
	private:
		const int hasTicket; // Flag if passenger has ticket
		const int reducedTicket; // Flag if passenger is entitled to reduced ticket

	public:
		Passenger(); // Constructor

		~Passenger(); // Destructor

		int get_hasTicket() const; // Gets if passenger has ticket
		int get_reducedTicket() const; // Gets if passenger is entitled to reduced ticket 
};

#endif