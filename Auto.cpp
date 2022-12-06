#include "Auto.h"

#include "ecs36b_Common.h"

Auto::Auto() {}

int Auto::getPassengerNumber() {
    return this->passenger_number;
}

void Auto::initializePassengerNumber(std::string option) {
    if (option.compare("another") == 0) {
        srand((unsigned) (time(NULL) + 10));
    }
    else {
        srand((unsigned) time(NULL));
    }

    int random = rand() % 7;
    this->passenger_number = random;

}

int Auto::getVehicleValue() {
    return this->vehicle_value;
}

bool Auto::isCollisionImminent() {
    return this->collision_imminent;
}

bool Auto::isCollisionAffected() {
    return this->collision_affected;
}
