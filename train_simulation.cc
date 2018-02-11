/*************************************************************************
Implementation File : train_simulation.c
Author - Date       : Efstathios Siatras - 18/12/2017
Purpose             : Simulates a subway train
*************************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "train.h"

using namespace std;

Train *create_train(int&, char**&);
int destroy_train(Train*&);

int main(int argc, char** argv) {
	srand(time(NULL));

	Train *t = NULL;
	t = create_train(argc, argv);
	if (t == NULL) {

		cout << "Bad input from command line parameters. Exiting..." << endl;
		return 1;
	}

	t->operate();
	t->printStatistics();

	if(!destroy_train(t)) {

		cout << "There was no train to destroy. Exiting..." << endl;
		return 2;
	}
}

Train *create_train(int& argc, char**& argv) {
	Train *t = NULL;

	if (argc == 1) {
		
		t = new Train;
	}

	else if (argc == 2) {
		
		t = new Train(atoi(argv[1]));
	}

	else if (argc == 3) {
		
		t = new Train(atoi(argv[1]), atoi(argv[2]));
	}

	else if (argc == 4) {
		
		t = new Train(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
	}

	else if (argc == 5) {
		
		t = new Train(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
	}

	else if (argc == 6) {
		
		t = new Train(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]));
	}

	else {

		return NULL;
	}

	return t;
}

int destroy_train(Train*& t) {
	if (t == NULL) {

		return 0;
	}

	delete t;
	t = NULL;

	return 1;
}