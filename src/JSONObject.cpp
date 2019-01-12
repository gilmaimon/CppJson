#include "JSONObject.h"
#include <iostream>

namespace json {
	JSONObject::JSONObject() {}

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

	void JSONObject::throwInvalidKey(internals::key_t key) {
		throw internals::invalid_key(key);
	}

	internals::json_type_t* JSONObject::clone() {
		return new JSONObject(*this);
	}

	void JSONObject::put(internals::key_t key, bool val) { this->features[key] = new internals::json_bool_t(val); }
	void JSONObject::put(internals::key_t key, int val) { this->features[key] = new internals::json_integer_t(val); }
	void JSONObject::put(internals::key_t key, double val) { this->features[key] = new internals::json_double_t(val); }
	void JSONObject::put(internals::key_t key, JSONObject val) { this->features[key] = new JSONObject(val); }
	void JSONObject::put(internals::key_t key, JSONArray val) { this->features[key] = new JSONArray(val); }
	void JSONObject::put(internals::key_t key, std::string val) { this->features[key] = new internals::json_string_t(val); }
	void JSONObject::put(internals::key_t key, char* val) { put(key, std::string(val));  }

	bool JSONObject::getBool(internals::key_t key) {
		if (features.find(key) != features.end()) return *dynamic_cast<internals::json_bool_t*>(features[key]);
		else throwInvalidKey(key);
		return false;
	}
	int JSONObject::getInt(internals::key_t key) {
		if (features.find(key) != features.end()) return *dynamic_cast<internals::json_integer_t*>(features[key]);
		else throwInvalidKey(key);
		return 0;
	}
	double JSONObject::getDouble(internals::key_t key) {
		if (features.find(key) != features.end()) return *dynamic_cast<internals::json_double_t*>(features[key]);
		else throwInvalidKey(key);
		return 0;
	}
	JSONObject JSONObject::getObject(internals::key_t key) {
		if (features.find(key) != features.end()) return *dynamic_cast<JSONObject*>(features[key]);
		else throwInvalidKey(key);
		return JSONObject();
	}
	JSONArray JSONObject::getArray(internals::key_t key) {
		if (features.find(key) != features.end()) return *dynamic_cast<JSONArray*>(features[key]);
		else throwInvalidKey(key);
		return JSONArray();
	}
	std::string JSONObject::getString(internals::key_t key) {
		if (features.find(key) != features.end()) return *dynamic_cast<internals::json_string_t*>(features[key]);
		else throwInvalidKey(key);
		return "";
	}

	std::string JSONObject::to_string() {
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

	JSONObject::~JSONObject() {
		for (auto& p : features) {
			delete p.second;
		}
	}
};