#include "ecs36b_Common.h"
#include "Auto.h"

#ifndef _MOTORCYCLE_H_
#define _MOTORCYCLE_H_


class Motorcycle: public Auto {
  private:
    // property randomly determined in Motorcycle.cpp
    std::map<std::string, int> property{{"Headlights", 80}};

  public:
    explicit Motorcycle();
    std::map<std::string, int> getProperty();
    // "generate" or "reset" options, "another" to generate another random seed
    bool initializeProperty(std::string option, std::string option2 = "none");
    bool addProperty(std::string name, int value);

};

#endif