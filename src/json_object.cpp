#include "json_object.h"
#include "parse/json_parser.h"

namespace json {
	json_object::json_object() {}

	json_object::json_object(const json_object& other) {
		for (auto& pair : other.features) {
			features[pair.first] = pair.second->clone();
		}
	}
	
	json_object& json_object::operator=(const json_object& other) {
		features.clear();
		for (auto& pair : other.features) {
			features[pair.first] = pair.second->clone();
		}
		return *this;
	}
	json_object json_object::fromString(std::string json) {
		return json_parser().parseJsonObject(json);
	}

	void json_object::throwInvalidKey(internals::key_t key) {
		throw invalid_key(key);
	}

	internals::json_type_t* json_object::clone() {
		return new json_object(*this);
	}

	void json_object::put(internals::key_t key, bool val) { this->features[key] = new internals::json_bool_t(val); }
	void json_object::put(internals::key_t key, int val) { this->features[key] = new internals::json_integer_t(val); }
	void json_object::put(internals::key_t key, double val) { this->features[key] = new internals::json_double_t(val); }
	void json_object::put(internals::key_t key, json_object val) { this->features[key] = new json_object(val); }
	void json_object::put(internals::key_t key, json_array val) { this->features[key] = new json_array(val); }
	void json_object::put(internals::key_t key, std::string val) { this->features[key] = new internals::json_string_t(val); }
	void json_object::put(internals::key_t key, char* val) { put(key, std::string(val));  }

	bool json_object::getBool(internals::key_t key) {
		if (features.find(key) != features.end()) return *dynamic_cast<internals::json_bool_t*>(features[key]);
		else throwInvalidKey(key);
		return false;
	}
	int json_object::getInt(internals::key_t key) {
		if (features.find(key) != features.end()) return *dynamic_cast<internals::json_integer_t*>(features[key]);
		else throwInvalidKey(key);
		return 0;
	}
	double json_object::getDouble(internals::key_t key) {
		if (features.find(key) != features.end()) return *dynamic_cast<internals::json_double_t*>(features[key]);
		else throwInvalidKey(key);
		return 0;
	}
	json_object json_object::getObject(internals::key_t key) {
		if (features.find(key) != features.end()) return *dynamic_cast<json_object*>(features[key]);
		else throwInvalidKey(key);
		return json_object();
	}
	json_array json_object::getArray(internals::key_t key) {
		if (features.find(key) != features.end()) return *dynamic_cast<json_array*>(features[key]);
		else throwInvalidKey(key);
		return json_array();
	}
	std::string json_object::getString(internals::key_t key) {
		if (features.find(key) != features.end()) return *dynamic_cast<internals::json_string_t*>(features[key]);
		else throwInvalidKey(key);
		return "";
	}

	std::string json_object::to_string() {
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

	json_object::~json_object() {
		for (auto& p : features) {
			delete p.second;
		}
	}
};