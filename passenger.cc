/*************************************************************************
Implementation File : passenger.cc
Author - Date       : Efstathios Siatras - 18/12/2017
Purpose             : Implementation file of class Passenger
*************************************************************************/
#include <iostream>
#include <cstdlib>

#include "passenger.h"

using namespace std;

Passenger::Passenger() 
: hasTicket(rand() % 2), reducedTicket(rand() % 2) {}

Passenger::~Passenger() {}

int Passenger::get_hasTicket() const {

	return hasTicket;
}

int Passenger::get_reducedTicket() const {

	return reducedTicket;
}