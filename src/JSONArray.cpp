#include "JSONArray.h"
#include <iostream>

namespace json {
	JSONArray::JSONArray() : internals::json_type_t(){}

	JSONArray::JSONArray(const JSONArray& jsonArray) : JSONArray() {
		for (size_t i = 0; i < jsonArray.items.size(); i++) {
			items.push_back(jsonArray.items[i]->clone());
		}
	}

	JSONArray& JSONArray::operator=(const JSONArray& other) {
		// check for self-assignment
		if(&other == this)
			return *this;

		// reuse storage when possible
		items.clear();
		for (size_t i = 0; i < other.items.size(); i++) {
			items.push_back(other.items[i]->clone());
		}
		return *this;
	}

	internals::json_type_t* JSONArray::clone() {
		return new JSONArray(*this);
	}

	JSONArray JSONArray::fromString(std::string& json) {
		return JSONParser().parseJsonArray(json);
	}

	void JSONArray::add(JSONObject val) { items.push_back(new JSONObject(val)); }
	void JSONArray::add(JSONArray val) { items.push_back(new JSONArray(val)); }
	void JSONArray::add(int val) { items.push_back(new internals::json_integer_t(val)); }
	void JSONArray::add(bool val) { items.push_back(new internals::json_bool_t(val)); }
	void JSONArray::add(std::string val) { items.push_back(new internals::json_string_t(val)); }
	void JSONArray::add(char* val) { add(std::string(val)); }
	void JSONArray::add(double val) { items.push_back(new internals::json_double_t(val)); }

	int JSONArray::getInt(int index) {
		internals::json_integer_t* i = (internals::json_integer_t*) items[index];
		return *i;
	}

	bool JSONArray::getBool(int index) {
		internals::json_bool_t* b = (internals::json_bool_t*) items[index];
		return *b;
	}

	double JSONArray::getDouble(int index) {
		internals::json_double_t* d = (internals::json_double_t*) items[index];
		return *d;
	}

	std::string JSONArray::getString(int index) {
		internals::json_string_t* s = (internals::json_string_t*)items[index];
		return *s;
	}
	JSONObject JSONArray::getObject(int index) {
		JSONObject* obj = (JSONObject*)items[index];
		return *obj;
	}
	JSONArray JSONArray::getArray(int index) {
		JSONArray* a = (JSONArray*)items[index];
		return *a;
	}

	int JSONArray::size() {
		return items.size();
	}

	std::string JSONArray::to_string() {
		std::string result = "[";
		for (size_t i = 0; i < items.size(); i++) {
			internals::json_type_t* s = items[i];
			result += s->to_string();
			if (i < items.size() - 1) result += ", ";
		}
		result += "]";
		return result;
	}

	JSONArray::~JSONArray()
	{
		for (size_t i = 0; i < items.size(); i++) {
			delete items[i];
			items[i] = nullptr;
		}
	}
};