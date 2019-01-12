#include "json_array.h"
#include "parse/json_parser.h"

namespace json {
	json_array::json_array() : internals::json_type_t(){}

	json_array::json_array(const json_array& jsonArray) : json_array() {
		for (size_t i = 0; i < jsonArray.items.size(); i++) {
			items.push_back(jsonArray.items[i]->clone());
		}
	}

	json_array& json_array::operator=(const json_array& other) {
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

	internals::json_type_t* json_array::clone() {
		return new json_array(*this);
	}

	json_array json_array::fromString(std::string& json) {
		return json_parser().parseJsonArray(json);
	}

	void json_array::add(json_object val) { items.push_back(new json_object(val)); }
	void json_array::add(json_array val) { items.push_back(new json_array(val)); }
	void json_array::add(int val) { items.push_back(new internals::json_integer_t(val)); }
	void json_array::add(bool val) { items.push_back(new internals::json_bool_t(val)); }
	void json_array::add(std::string val) { items.push_back(new internals::json_string_t(val)); }
	void json_array::add(char* val) { add(std::string(val)); }
	void json_array::add(double val) { items.push_back(new internals::json_double_t(val)); }

	int json_array::getInt(int index) {
		internals::json_integer_t* i = (internals::json_integer_t*) items[index];
		return *i;
	}

	bool json_array::getBool(int index) {
		internals::json_bool_t* b = (internals::json_bool_t*) items[index];
		return *b;
	}

	double json_array::getDouble(int index) {
		internals::json_double_t* d = (internals::json_double_t*) items[index];
		return *d;
	}

	std::string json_array::getString(int index) {
		internals::json_string_t* s = (internals::json_string_t*)items[index];
		return *s;
	}
	json_object json_array::getObject(int index) {
		json_object* obj = (json_object*)items[index];
		return *obj;
	}
	json_array json_array::getArray(int index) {
		json_array* a = (json_array*)items[index];
		return *a;
	}

	int json_array::size() {
		return items.size();
	}

	std::string json_array::to_string() {
		std::string result = "[";
		for (size_t i = 0; i < items.size(); i++) {
			internals::json_type_t* s = items[i];
			result += s->to_string();
			if (i < items.size() - 1) result += ", ";
		}
		result += "]";
		return result;
	}

	json_array::~json_array()
	{
		for (size_t i = 0; i < items.size(); i++) {
			delete items[i];
			items[i] = nullptr;
		}
	}
};