#pragma once

#include <vector>
#include <string>
#include "JSONObject.h"
#include "ExtendedTypes.h"

namespace json {
	class json_object;
	class json_array : public internals::json_type_t {
	private:
		std::vector<internals::json_type_t*> items;
	public:
		json_array();
		json_array(const json_array& jsonArray);
		json_array& operator=(const json_array& other);

		static json_array fromString(std::string& json);
		void add(json_object val);
		void add(json_array val);
		void add(int val);
		void add(bool val);
		void add(std::string val);
		void add(char* val);
		void add(double val);

		int getInt(int index);
		bool getBool(int index);
		double getDouble(int index);
		std::string getString(int index);
		json_object getObject(int index);
		json_array getArray(int index);

		int size();

		virtual std::string to_string();
		virtual internals::json_type_t* clone();
		~json_array();
	};
};