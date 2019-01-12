#pragma once

#include <map>
#include <string>
#include <exception>
#include <vector>
#include "Key.h"
#include "InvalidKey.h"
#include "ExtendedTypes.h"
#include "JSONArray.h"
#include "JSONParser.h"

class JSONArray;
class JSONParser;

class JSONObject : public JSONType
{
private:
	std::map<Key, JSONType*> features;

	void throwInvalidKey(Key key);

	std::vector<std::string> stringifyMap(std::map<Key, JSONType*> & map) {
		std::vector<std::string> result;
		for (auto& pair : map) {
			result.push_back(String(pair.first).toString() + " : " + pair.second->toString());
		}
		return result;
	}

	template <class T> void appendVectors(std::vector<T>& a, std::vector<T> b) {
		for (auto& item : b) a.push_back(item);
	}

public:
	JSONObject();
	JSONObject(const JSONObject& other);
	JSONObject& operator=(const JSONObject& other);

	static JSONObject fromString(std::string json);

	void put(Key key, bool val);
	void put(Key key, int val);
	void put(Key key, double val);
	void put(Key key, JSONObject val);
	void put(Key key, std::string val);
	void put(Key key, char* val);
	void put(Key key, JSONArray val);

	bool getBool(Key key);
	int getInt(Key key);
	double getDouble(Key key);
	JSONObject getObject(Key key);
	JSONArray getArray(Key key);
	std::string getString(Key key);

	virtual JSONType* clone();
	virtual std::string toString();
	~JSONObject();
};

