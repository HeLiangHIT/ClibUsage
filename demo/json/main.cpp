#include <iostream>
using namespace std;
#include <nlohmann/json.hpp>
using json = nlohmann::json;
/*
以下代码创建如下的JSON对象：
{
  "pi": 3.141,
  "happy": true,
  "name": "Niels",
  "nothing": null,
  "answer": {
    "everything": 42
  },
  "list": [1, 0, 2],
  "object": {
    "currency": "USD",
    "value": 42.99
  }
}
1. 编译：
g++ main.cpp -std=c++11 -o main.o -I../../github/json/include

2. 运行测试：
./main.o # 运行查看结果
*/


int main(int argc, char const *argv[]){
    // create an empty structure (null)
    json j1;
    // add a number that is stored as double (note the implicit conversion of j1 to an object)
    j1["pi"] = 3.141;
    // add a Boolean that is stored as bool
    j1["happy"] = true;
    // add a string that is stored as std::string
    j1["name"] = "Niels";
    // add another null object by passing nullptr
    j1["nothing"] = nullptr;
    // add an object inside the object
    j1["answer"]["everything"] = 42;
    // add an array that is stored as std::vector (using an initializer list)
    j1["list"] = { 1, 0, 2 };
    // add another object (using an initializer list of pairs)
    j1["object"] = { {"currency", "USD"}, {"value", 42.99} };
    // instead, you could also write (which looks very similar to the JSON above)
    json j2 = {
      {"pi", 3.141},
      {"happy", true},
      {"name", "Niels"},
      {"nothing", nullptr},
      {"answer", {
        {"everything", 42}
      }},
      {"list", {1, 0, 2}},
      {"object", {
        {"currency", "USD"},
        {"value", 42.99}
      }}
    };
    cout << j1 << endl << endl;
    cout << j2 << endl << endl;
/*
请注意，在所有上述情况下，不需要“告诉”编译器要使用哪个 JSON 值。如果想要明确或表达一些边缘的情况，可以使用 json::array 和 json::object

// a way to express the empty array []
json empty_array_explicit = json::array();

// ways to express the empty object {}
json empty_object_implicit = json({});
json empty_object_explicit = json::object();

// a way to express an _array_ of key/value pairs [["currency", "USD"], ["value", 42.99]]
json array_not_object = json::array({ {"currency", "USD"}, {"value", 42.99} });
*/
    return 0;
}