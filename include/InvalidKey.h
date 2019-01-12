#pragma once

#include <exception>
#include <string>

namespace json {
	class invalid_key : public std::exception {
	public:
		explicit invalid_key(std::string key) {
			this->key = key;
		}

		virtual const char* what() const throw () {
			return std::string("Key \"" + key + "\" Does not exist.").c_str();
		}

		virtual ~invalid_key() throw () {}
	protected:
		std::string key;
	};
};