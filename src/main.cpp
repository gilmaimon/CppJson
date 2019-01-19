#include <iostream>
#include "json.h"

using namespace json;
using std::string;

int main(int argc, char** argv) {
	json_object object("{\"name\":\"Gil Maimon\",\"names\":{\"first\":\"Gil\",\"last\":\"maimon\",\"nick\":\"tapud\"}, \"age\":19,\"height\":1.820000}");
	std::cout << "name: " << object.get<string>("name") << std::endl
        << "age: " << object.get<int>("age") << std::endl
        << "height: " << object.get<double>("height") << std::endl;

    std::cout << "first name: " << object.get<json_object>("names").get<string>("first") << std::endl
        << "last: " << object.get<json_object>("names").get<string>("last") << std::endl
        << "nickname: " << object.get<json_object>("names").get<string>("nick") << std::endl;

	return 0;
}
