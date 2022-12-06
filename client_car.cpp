
#include <iostream>
#include "ecs36b_Exception.h"

// JSON RPC part
#include "client_car.h"
#include <jsonrpccpp/client/connectors/httpclient.h>

using namespace jsonrpc;
using namespace std;

#include "Car.h"
#include "Motorcycle.h"


int
main()
{

  // Port number for left motorcycle
  HttpClient httpclient("http://127.0.0.1:8000");
  HttpClient httpclient2("http://127.0.0.1:8001");
  client_car myClient(httpclient, JSONRPC_CLIENT_V2);
  client_car myClient2(httpclient2, JSONRPC_CLIENT_V2);

  // Retrieve left and right motorcycle info
  Json::Value left_motorcycle_info;
  Json::Value right_motorcycle_info;

  try {
    left_motorcycle_info = myClient.get_vehicle_info("Get Left Motorcycle Info");
  } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }

  std::cout << left_motorcycle_info.toStyledString() << std::endl;

  try {
    right_motorcycle_info = myClient2.get_vehicle_info("Get Right Motorcycle Info");
  } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }

  std::cout << right_motorcycle_info.toStyledString() << std::endl;


  // Determine collision priority (passenger count, then property value)
  Json::Value left_motorcycle = left_motorcycle_info["Left Motorcycle"];
  Json::Value right_motorcycle = right_motorcycle_info["Right Motorcycle"];

  if (left_motorcycle["Passenger Number"] > right_motorcycle["Passenger Number"]) {
    std::cout << "Client car will collide with right motorcycle\n" << "Reason: Less Passenger Count" << std::endl;
    return 0;
  }
  else if (left_motorcycle["Passenger Number"] < right_motorcycle["Passenger Number"]) {
    std::cout << "Client car will collide with left motorcycle\n" << "Reason: Less Passenger Count" << std::endl;
    return 0;
  }

  // Passenger count equal, inspect property value
  int left_property_value = 0;
  int right_property_value = 0;

  Json::Value left_property = left_motorcycle["Property"];
  Json::Value right_property = right_motorcycle["Property"];

  for (auto it : left_property)
    {
        // source from https://json.nlohmann.me/features/iterators/#access-object-key-during-iteration
        // std::cout << "value: " << it << '\n';
        left_property_value += it.asInt();
    }

  std::cout << "Left Motorcycle value is: " << left_property_value << std::endl;

  for (auto it : right_property) {
    right_property_value += it.asInt();
  }

  std::cout << "Right Motorcycle value is: " << right_property_value << std::endl;

  if (left_property_value > right_property_value) {
    std::cout << "\nClient car will collide with right motorcycle\n" << "Reason: Less Property Value" << std::endl;
    return 0;
  }
  else if (left_property_value < right_property_value) {
    std::cout << "\nClient car will collide with left motorcycle\n" << "Reason: Less Property Value" << std::endl;
    return 0;
  }

  // Both equal
  std::cout << "\nClient car will collide with truck\n" << "Reason: Motorcycle information insufficient" << std::endl;

  return 0;

}


