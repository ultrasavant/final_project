#include "ecs36b_Common.h"
#include "Auto.h"

#ifndef _CAR_H_
#define _CAR_H_

class Car: public Auto {
  public:
    explicit Car();
    int getPassengerNumber();
    int getVehicleValue();
    bool isCollisionImminent();
    bool isCollisionAffected();

};

#endif