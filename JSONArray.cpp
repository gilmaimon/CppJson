#include "JSONArray.h"
#include <iostream>>

JSONArray::JSONArray() : JSONType()
{
}

JSONArray::JSONArray(const JSONArray& jsonArray) : JSONArray() {
	for (size_t i = 0; i < jsonArray.items.size(); i++) {
		//items.push_back(jsonArray.items[i]->clone()); //
		items.push_back(jsonArray.items[i]->clone());
	}
}

JSONArray& JSONArray::operator=(const JSONArray& other) {
    // check for self-assignment
    if(&other == this)
        return *this;

    // reuse storage when possible
    items.clear();
    for (size_t i = 0; i < other.items.size(); i++) {
		//items.push_back(jsonArray.items[i]->clone()); //
		items.push_back(other.items[i]->clone());
	}
    return *this;
}

JSONType* JSONArray::clone() {
	return new JSONArray(*this);
}

JSONArray JSONArray::fromString(std::string& json) {
	return JSONParser().parseJsonArray(json);
}

void JSONArray::add(JSONObject val) { items.push_back(new JSONObject(val)); }
void JSONArray::add(JSONArray val) { items.push_back(new JSONArray(val)); }
void JSONArray::add(int val) { items.push_back(new Integer(val)); }
void JSONArray::add(bool val) { items.push_back(new Boolean(val)); }
void JSONArray::add(std::string val) { items.push_back(new String(val)); }
void JSONArray::add(char* val) { add(std::string(val)); }
void JSONArray::add(double val) { items.push_back(new Double(val)); }

int JSONArray::getInt(int index) {
	Integer* i = (Integer*) items[index];
	return *i;
}

bool JSONArray::getBool(int index) {
	Boolean* b = (Boolean*) items[index];
	return *b;
}

double JSONArray::getDouble(int index) {
	Double* d = (Double*) items[index];
	return *d;
}

std::string JSONArray::getString(int index) {
	String* s = (String*)items[index];
	return *s;
}
JSONObject JSONArray::getObject(int index) {
	JSONObject* obj = (JSONObject*)items[index];
	return *obj;
}
JSONArray JSONArray::getArray(int index) {
	JSONArray* a = (JSONArray*)items[index];
	return *a;
}

/*
JSONObject& JSONArray::get(int index) {
	return objects[index];
}


JSONObject& JSONArray::operator[](int index) {
	return get(index);
}
*/
int JSONArray::size() {
	return items.size();
}

std::string JSONArray::toString() {
	std::string result = "[";
	for (size_t i = 0; i < items.size(); i++) {
		Stringable* s = items[i];
		result += s->toString();
		if (i < items.size() - 1) result += ", ";
	}
	result += "]";
	return result;
}

JSONArray::~JSONArray()
{
	for (size_t i = 0; i < items.size(); i++) {
		delete items[i];
		items[i] = nullptr;
	}
}
