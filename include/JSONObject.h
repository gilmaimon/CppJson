#pragma once

#include <map>
#include <string>
#include <exception>
#include <vector>
#include "InvalidKey.h"
#include "internals/ExtendedTypes.h"
#include "JSONArray.h"

namespace json {
	class json_array;
	class json_parser;

	class json_object : public internals::json_type_t {
	private:
		std::map<internals::key_t, internals::json_type_t*> features;

		void throwInvalidKey(internals::key_t key);

		std::vector<std::string> stringifyMap(std::map<internals::key_t, internals::json_type_t*> & map) {
			std::vector<std::string> result;
			for (auto& pair : map) {
				result.push_back(pair.first + " : " + pair.second->to_string());
			}
			return result;
		}

		template <class T> void appendVectors(std::vector<T>& a, std::vector<T> b) {
			for (auto& item : b) a.push_back(item);
		}

	public:
		json_object();
		json_object(const json_object& other);
		json_object& operator=(const json_object& other);

		static json_object fromString(std::string json);

		void put(internals::key_t key, bool val);
		void put(internals::key_t key, int val);
		void put(internals::key_t key, double val);
		void put(internals::key_t key, json_object val);
		void put(internals::key_t key, std::string val);
		void put(internals::key_t key, char* val);
		void put(internals::key_t key, json_array val);

		bool getBool(internals::key_t key);
		int getInt(internals::key_t key);
		double getDouble(internals::key_t key);
		json_object getObject(internals::key_t key);
		json_array getArray(internals::key_t key);
		std::string getString(internals::key_t key);

		virtual internals::json_type_t* clone();
		virtual std::string to_string();
		~json_object();
	};
};