#include "Car.h"

Car::Car() {}

int Car::getPassengerNumber() {
    return this->Auto::getPassengerNumber();
}

int Car::getVehicleValue() {
    return this->Auto::getVehicleValue();
}

bool Car::isCollisionImminent() {
    return this->Auto::isCollisionImminent();
}

bool Car::isCollisionAffected() {
    return this->Auto::isCollisionAffected();
}