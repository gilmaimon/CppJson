#pragma once
#include <exception>
#include <string>

class JsonTypeMismatch : public std::exception {
public:
	explicit JsonTypeMismatch() {
	}

	virtual const char* what() const throw () {
		return "there is mismtach between json types while parsing. object or array was provided when was not expected.";
	}

	virtual ~JsonTypeMismatch() throw () {}
protected:
};