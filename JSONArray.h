#pragma once

#include <vector>
#include <string>
#include "JSONObject.h"
#include "ExtendedTypes.h"

class JSONObject;
class JSONArray : public JSONType {
private:
	std::vector<JSONType*> items;
public:
	JSONArray();
	JSONArray(const JSONArray& jsonArray);
	JSONArray& operator=(const JSONArray& other);

	static JSONArray fromString(std::string& json);
	void add(JSONObject val);
	void add(JSONArray val);
	void add(int val);
	void add(bool val);
	void add(std::string val);
	void add(char* val);
	void add(double val);

	int getInt(int index);
	bool getBool(int index);
	double getDouble(int index);
	std::string getString(int index);
	JSONObject getObject(int index);
	JSONArray getArray(int index);

	//JSONObject& get(int index);
	//JSONObject& operator[](int index);
	int size();

	virtual std::string toString();
	virtual JSONType* clone();
	~JSONArray();
};

