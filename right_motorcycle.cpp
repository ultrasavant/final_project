
// for Json::value
#include </usr/include/jsoncpp/json/json.h>
#include </usr/include/jsoncpp/json/reader.h>
#include </usr/include/jsoncpp/json/writer.h>
#include </usr/include/jsoncpp/json/value.h>
#include <string>

// for JsonRPCCPP
#include <iostream>
#include "right_motorcycle.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
#include "client_car.h"
#include <jsonrpccpp/client/connectors/httpclient.h>

// ecs36b
#include "ecs36b_Common.h"

#include "Motorcycle.h"

using namespace jsonrpc;
using namespace std;

class Myhw6Server : public right_motorcycle
{
public:
  Myhw6Server(AbstractServerConnector &connector, serverVersion_t type);
  virtual Json::Value get_vehicle_info(const std::string& action);
};

Myhw6Server::Myhw6Server(AbstractServerConnector &connector, serverVersion_t type)
  : right_motorcycle(connector, type)
{
  std::cout << "Right motorcycle server created" << std::endl;
}

// GLOBAL right motorcycle
Motorcycle right_motorcycle;

// member functions

Json::Value
Myhw6Server::get_vehicle_info
(const std::string& action)
{
  Json::Value info;
  extern Motorcycle right_motorcycle;

  right_motorcycle.initializePassengerNumber("another");
  info["Right Motorcycle"]["Passenger Number"] = right_motorcycle.getPassengerNumber();

  // Initialize left motorcycle
  right_motorcycle.initializeProperty("reset");
  right_motorcycle.initializeProperty("generate", "another");

  std::map<std::string, int> retrievedMap = right_motorcycle.getProperty();

  for (std::map<std::string, int>::const_iterator it = retrievedMap.begin();
    it != retrievedMap.end(); ++it)
    {
        info["Right Motorcycle"]["Property"][it->first] = it->second;
    }

  std::cout << "Right motorcycle info sent successfully." << std::endl;
  
  return info;
}


int
main(void)
{
  HttpServer httpserver(8001);
  Myhw6Server s(httpserver,
		JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
  s.StartListening();
  std::cout << "Hit enter to stop the server" << endl;
  getchar();

  s.StopListening();
  return 0;
}
