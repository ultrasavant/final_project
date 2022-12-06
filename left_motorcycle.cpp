
// for Json::value
#include </usr/include/jsoncpp/json/json.h>
#include </usr/include/jsoncpp/json/reader.h>
#include </usr/include/jsoncpp/json/writer.h>
#include </usr/include/jsoncpp/json/value.h>
#include <string>

// for JsonRPCCPP
#include <iostream>
#include "left_motorcycle.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
#include "client_car.h"
#include <jsonrpccpp/client/connectors/httpclient.h>

// ecs36b
#include "ecs36b_Common.h"

#include "Motorcycle.h"

using namespace jsonrpc;
using namespace std;

class Myhw6Server : public left_motorcycle
{
public:
  Myhw6Server(AbstractServerConnector &connector, serverVersion_t type);
  virtual Json::Value get_vehicle_info(const std::string& action);
};

Myhw6Server::Myhw6Server(AbstractServerConnector &connector, serverVersion_t type)
  : left_motorcycle(connector, type)
{
  std::cout << "Left motorcycle server created" << std::endl;
}

// GLOBAL left motorcycle
Motorcycle left_motorcycle;

// member functions

Json::Value
Myhw6Server::get_vehicle_info
(const std::string& action)
{
  Json::Value info;
  extern Motorcycle left_motorcycle;

  left_motorcycle.initializePassengerNumber();
  info["Left Motorcycle"]["Passenger Number"] = left_motorcycle.getPassengerNumber();

  // Initialize left motorcycle properties
  left_motorcycle.initializeProperty("reset");
  left_motorcycle.initializeProperty("generate");

  std::map<std::string, int> retrievedMap = left_motorcycle.getProperty();

  for (std::map<std::string, int>::const_iterator it = retrievedMap.begin();
    it != retrievedMap.end(); ++it)
    {
        info["Left Motorcycle"]["Property"][it->first] = it->second;
    }

  std::cout << "Left motorcycle info sent successfully." << std::endl;
  
  return info;
}


int
main()
{
  // left_motorcycle.addProperty("testing", 12);

  // Start server
  HttpServer httpserver(8000);
  Myhw6Server s(httpserver,
	JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)

  s.StartListening();
  std::cout << "Hit enter to stop the server" << endl;
  getchar();

  s.StopListening();
  return 0;
}
