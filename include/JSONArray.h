#pragma once

#include <vector>
#include <string>
#include "JSONObject.h"
#include "ExtendedTypes.h"

namespace json {
	class JSONObject;
	class JSONArray : public internals::json_type_t {
	private:
		std::vector<internals::json_type_t*> items;
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

		virtual std::string to_string();
		virtual internals::json_type_t* clone();
		~JSONArray();
	};
};