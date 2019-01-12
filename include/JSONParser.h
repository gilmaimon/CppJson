#pragma once

#include "JSONObject.h"
#include "JSONArray.h"
#include "UnkownType.h"
#include "JsonTypeMismatch.h"

class JSONObject;
class JSONArray;

class JSONParser
{
private:
	enum type {
		Int,
		Double,
		Boolean,
		String,
		Object,
		Array
	};

	std::string trimOneChar(std::string& s);
	std::vector<std::string> smartSplit(std::string& data, char delimiter);
	type getType(std::string& data);
	std::string removeSpaces(std::string& data);
	int toInt(std::string& data);
	double toDouble(std::string& data);
	bool toBool(std::string& data);

public:
	JSONParser();
	JSONObject parseJsonObject(std::string& jsonString);
	JSONArray parseJsonArray(std::string& jsonString);
	~JSONParser();
};

