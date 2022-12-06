#ifndef _ecs36b_JSON_H_
#define _ecs36b_JSON_H_

int myJSON2File (char *f_name, Json::Value * jv_ptr);
int myParseJSON (std::string input, Json::Value * jv_ptr);
char *myFile2String (char *f_name);
int myFile2JSON (char *f_name, Json::Value * jv_ptr);

#endif