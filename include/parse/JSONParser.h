#pragma once

#include "../JSONObject.h"
#include "../JSONArray.h"
#include "UnkownType.h"
#include "JsonTypeMismatch.h"

namespace json {
	class json_object;
	class json_array;

	class json_parser {
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
		json_parser();
		json_object parseJsonObject(std::string& jsonString);
		json_array parseJsonArray(std::string& jsonString);
		~json_parser();
	};
};