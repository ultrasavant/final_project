#include "ecs36b_Common.h"

#ifndef _AUTO_H_
#define _AUTO_H_

class Auto {
private:
    int passenger_number = 3;
    int vehicle_value = 0;
    bool collision_imminent = false;
    bool collision_affected = false;
  
public:
  explicit Auto();
  void initializePassengerNumber(std::string option = "none");
  int getPassengerNumber();
  int getVehicleValue();
  bool isCollisionImminent();
  bool isCollisionAffected();

};

#endif