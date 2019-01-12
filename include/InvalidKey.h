#pragma once

#include <exception>
#include <string>

class InvalidKey : public std::exception {
public:
	explicit InvalidKey(std::string key) {
		this->key = key;
	}

	virtual const char* what() const throw () {
		return std::string("Key \"" + key + "\" Does not exist.").c_str();
	}

	virtual ~InvalidKey() throw () {}
protected:
	Key key;
};