#include <iostream>
#include "JSON.h"

using namespace json;

struct Human : json_object {
	Human(std::string name, int age, double height) {
		put("name", name);
		put("age", age);
		put("height", height);
	}
};

struct Car : json_object {
	Car(std::string color, int maxSpeed) {
		put("color", color);
		put("maxSpeed", maxSpeed);
	}
};

int main(int argc, char** argv) {
	json_object object = json_object::fromString("{\"name\":\"Gil Maimon\",\"names\":{\"first\":\"Gil\",\"last\":\"maimon\",\"nick\":\"tapud\"}, \"age\":19,\"height\":1.820000}");
	std::cout << "name: " << object.getString("name") << std::endl
        << "age: " << object.getInt("age") << std::endl
        << "height: " << object.getDouble("height") << std::endl;

    std::cout << "first name: " << object.getObject("names").getString("first") << std::endl
        << "last: " << object.getObject("names").getString("last") << std::endl
        << "nickname: " << object.getObject("names").getString("nick") << std::endl;

	return 0;
}
