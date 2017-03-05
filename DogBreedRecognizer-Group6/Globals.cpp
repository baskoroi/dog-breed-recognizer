#include "StdAfx.h"
#include "Globals.h"

using namespace std;

fann* Globals::ann = fann_create_from_file("ann.net");
map<string, string> Globals::nameMap;
int Globals::pictureCount = 0;

void Globals::initializeNeuralNetwork() {
	if (!ann) {
		ann = fann_create_standard(3, 49, 41, 8);
	}

	fann_set_activation_function_layer(ann, FANN_SIGMOID, 0);
	fann_set_activation_function_layer(ann, FANN_SIGMOID, 1);
	fann_set_activation_function_layer(ann, FANN_SIGMOID, 2);
}

void Globals::insertNewDog(string output, string name) {
	nameMap.insert( pair<string, string>(output, name) );
}

string Globals::getNameOfDog(string output) {
	if (nameMap.empty()) return "Train at least a dog";
	
	string result = (nameMap.count(output)) ? nameMap[output] : "Dog not found";
	return result;
}

fann * Globals::getAnn() {
	return ann;
}

void Globals::trainNeuralNetwork(struct fann_train_data *data, 
		int max_epochs, int epochs_between_reports, float desired_error) {

	fann_train_on_data(ann, data, max_epochs, epochs_between_reports, desired_error);
}

void Globals::saveNeuralNetwork() {
	fann_save(ann, "ann.net");
}

fann_type * Globals::recognizeInput(fann_type * input) {
	return fann_run(ann, input);
}

void Globals::incrementPictureCount() {
	pictureCount++;
}

int Globals::getPictureCount() {
	return pictureCount;
}