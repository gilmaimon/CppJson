#pragma once

#include <exception>
#include <string>

namespace json {
	namespace internals {
		class unknown_type : public std::exception {
		public:
			explicit unknown_type(std::string token) {
				this->token = token;
			}

			virtual const char* what() const throw () {
				return std::string("string \"" + token + "\" is of an unkown type and could not be parsed").c_str();
			}

			virtual ~unknown_type() throw () {}
		protected:
			std::string token;
		};
	};
};