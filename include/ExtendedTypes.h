#pragma once
#include <string>

namespace json {
	namespace internals {
		typedef std::string key_t;
		
		class json_type_t {
		public:
			virtual std::string to_string() = 0;
			virtual json_type_t* clone() = 0;
			virtual ~json_type_t() {}
		};

		class json_string_t : public json_type_t {
		private:
			std::string _s;
		public:
			json_string_t() : _s("") {}
			json_string_t(std::string s) : _s(s) { }
			json_string_t(const char* s) : _s(s) { }
			virtual std::string to_string() {
				std::string s;
				for (char c : _s) {
					s += c;
				}
				return '\"' + s + '\"';
			}

			operator std::string() {
				return _s;
			}

			virtual json_type_t* clone() {
				return new json_string_t(_s);
			}
		};

		class json_integer_t : public json_type_t {
		private:
			int _n;
		public:
			json_integer_t() : _n(0) {}
			json_integer_t(const int& n) : _n(n) {}
			virtual std::string to_string() {
				return std::to_string(_n);
			}
			operator int() {
				return _n;
			}

			virtual json_type_t* clone() {
				return new json_integer_t(_n);
			}
		};

		class json_double_t : public json_type_t {
		private:
			double _d;
		public:
			json_double_t() : _d(0) {}
			json_double_t(double d) : _d(d) { }
			virtual std::string to_string() {
				return std::to_string(_d);
			}
			operator double() {
				return _d;
			}

			virtual json_type_t* clone() {
				return new json_double_t(_d);
			}
		};

		class json_bool_t : public json_type_t {
		private:
			bool _b;
		public:
			json_bool_t() : _b(false) {}
			json_bool_t(bool b) : _b(b) { }
			virtual std::string to_string() {
				return _b ? "true" : "false";
			}
			operator bool() {
				return _b;
			}

			virtual json_type_t* clone() {
				return new json_bool_t(_b);
			}
		};
	};
};