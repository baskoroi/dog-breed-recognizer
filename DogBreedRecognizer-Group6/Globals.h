#pragma once

#include <fann.h>
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Globals {

public:
	static fann *ann;
	static map<string, string> nameMap;
	static int pictureCount;

public:
	static void initializeNeuralNetwork();
	static void insertNewDog(string /*output*/, string /*name*/);
	static string getNameOfDog(string /*output*/);
	static void incrementPictureCount();
	static fann * getAnn();
	static void trainNeuralNetwork(struct fann_train_data *data, int max_epochs,
											   int epochs_between_reports,
											   float desired_error);
	static void saveNeuralNetwork();
	static fann_type *recognizeInput(fann_type * /*input*/);
	static int getPictureCount();

};