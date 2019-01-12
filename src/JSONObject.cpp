#include "JSONObject.h"
#include <iostream>

JSONObject::JSONObject() {
}

JSONObject::JSONObject(const JSONObject& other) {
	for (auto& pair : other.features) {
		features[pair.first] = pair.second->clone();
	}
}
JSONObject& JSONObject::operator=(const JSONObject& other) {
	features.clear();
	for (auto& pair : other.features) {
		features[pair.first] = pair.second->clone();
	}
	return *this;
}
JSONObject JSONObject::fromString(std::string json) {
	return JSONParser().parseJsonObject(json);
}

void JSONObject::throwInvalidKey(Key key) {
	throw InvalidKey(key);
}

JSONType* JSONObject::clone() {
	return new JSONObject(*this);
}

void JSONObject::put(Key key, bool val) { this->features[key] = new Boolean(val); }
void JSONObject::put(Key key, int val) { this->features[key] = new Integer(val); }
void JSONObject::put(Key key, double val) { this->features[key] = new Double(val); }
void JSONObject::put(Key key, JSONObject val) { this->features[key] = new JSONObject(val); }
void JSONObject::put(Key key, JSONArray val) { this->features[key] = new JSONArray(val); }
void JSONObject::put(Key key, std::string val) { this->features[key] = new String(val); }
void JSONObject::put(Key key, char* val) { put(key, std::string(val));  }

bool JSONObject::getBool(Key key) {
	if (features.find(key) != features.end()) return *dynamic_cast<Boolean*>(features[key]);
	else throwInvalidKey(key);
	return false;
}
int JSONObject::getInt(Key key) {
	if (features.find(key) != features.end()) return *dynamic_cast<Integer*>(features[key]);
	else throwInvalidKey(key);
	return 0;
}
double JSONObject::getDouble(Key key) {
	if (features.find(key) != features.end()) return *dynamic_cast<Double*>(features[key]);
	else throwInvalidKey(key);
	return 0;
}
JSONObject JSONObject::getObject(Key key) {
	if (features.find(key) != features.end()) return *dynamic_cast<JSONObject*>(features[key]);
	else throwInvalidKey(key);
	return JSONObject();
}
JSONArray JSONObject::getArray(Key key) {
	if (features.find(key) != features.end()) return *dynamic_cast<JSONArray*>(features[key]);
	else throwInvalidKey(key);
	return JSONArray();
}
std::string JSONObject::getString(Key key) {
	if (features.find(key) != features.end()) return *dynamic_cast<String*>(features[key]);
	else throwInvalidKey(key);
	return "";
}

std::string JSONObject::toString() {
	std::string result = "{";
	std::vector<std::string> allMaps = stringifyMap(features);

	for (size_t i = 0; i < allMaps.size(); i++) {
		result += allMaps[i];
		if (i < allMaps.size() - 1) {
			result += ", ";
		}
	}

	result += "}";
	return result;
}

JSONObject::~JSONObject()
{
	for (auto& p : features) {
		delete p.second;
	}
}
