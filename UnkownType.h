#pragma once
#include <exception>
#include <string>

class UnkownType : public std::exception {
public:
	explicit UnkownType(std::string token) {
		this->token = token;
	}

	virtual const char* what() const throw () {
		return std::string("string \"" + token + "\" is of an unkown type and could not be parsed").c_str();
	}

	virtual ~UnkownType() throw () {}
protected:
	std::string token;
};