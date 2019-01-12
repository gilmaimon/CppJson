#pragma once

#include <exception>
#include <string>

namespace json {
	namespace internals {
		class type_mismatch : public std::exception {
		public:
			explicit type_mismatch() {}

			virtual const char* what() const throw () {
				return "there is mismtach between json types while parsing. object or array was provided when was not expected.";
			}

			virtual ~type_mismatch() throw () {}
		protected:
		};
	};
};