#pragma once
#include <string>

class Stringable {
public:
	virtual std::string toString() = 0;
	virtual ~Stringable() {}
};

class JSONType : public Stringable {
public:
	virtual JSONType* clone() = 0;
	virtual ~JSONType() {}
};

typedef std::string Key;

class String : public JSONType {
private:
	std::string _s;
public:
	String() : _s("") {}
	String(std::string s) : _s(s) { }
	String(const char* s) : _s(s) { }
	virtual std::string toString() {
		std::string s;
		for (char c : _s) {
			s += c;
		}
		return '\"' + s + '\"';
	}

	operator std::string() {
		return _s;
	}

	virtual JSONType* clone() {
		return new String(_s);
	}
};

class Integer : public JSONType {
private:
	int _n;
public:
	Integer() : _n(0) {}
	Integer(const int& n) : _n(n) {}
	virtual std::string toString() {
		return std::to_string(_n);
	}
	operator int() {
		return _n;
	}

	virtual JSONType* clone() {
		return new Integer(_n);
	}
};

class Double : public JSONType {
private:
	double _d;
public:
	Double() : _d(0) {}
	Double(double d) : _d(d) { }
	virtual std::string toString() {
		return std::to_string(_d);
	}
	operator double() {
		return _d;
	}

	virtual JSONType* clone() {
		return new Double(_d);
	}
};

class Boolean : public JSONType {
private:
	bool _b;
public:
	Boolean() : _b(false) {}
	Boolean(bool b) : _b(b) { }
	virtual std::string toString() {
		return _b ? "true" : "false";
	}
	operator bool() {
		return _b;
	}

	virtual JSONType* clone() {
		return new Boolean(_b);
	}
};
