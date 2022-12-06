#include "Motorcycle.h"

Motorcycle::Motorcycle() {}

std::map<std::string, int> Motorcycle::getProperty() {
    return this->property;
}

// Possible objects to include as vehicle property
int keyvaluePairs = 6;
std::string objectList[] {"Floor lamp", "Desk lamp", "Cat lamp", "Elevated table", "Plant", "Candles"};
int objectValue[] = {10, 20, 10, 40, 15, 30};

bool Motorcycle::initializeProperty(std::string option, std::string option2) {

    if (option.compare("reset") == 0) {
        this->property.clear();
        property["Headlights"] = 80;
        return true;
    }
    // Providing a seed value 
    // (source from https://www.digitalocean.com/community/tutorials/random-number-generator-c-plus-plus)
    if (option2.compare("another") == 0) {
        // std::cout << "called another" << std::endl;
        srand((unsigned) (time(NULL) + 10));
    }
    else {
        srand((unsigned) time(NULL));
    }
	
	// Get a random number
	int random = rand() % keyvaluePairs;
    int listIndex, valueIndex;

    // random can be zero but default map has a default
    for (int i = 0; i < random; i += 1) {
        listIndex = rand() % keyvaluePairs;
        valueIndex = rand() % keyvaluePairs;
        // Call add method
        this->addProperty(objectList[listIndex], objectValue[valueIndex]);
    }

    return true;
}

bool Motorcycle::addProperty(std::string name, int value) {
    (this->property)[name] = value;
    return true;
}

