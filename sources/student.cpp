#include <iostream>

#include "student.hpp"
using nlohmann::json;

Student::Student(const json &obj) {
  if (obj.empty()) {
    throw std::invalid_argument("Object for Student cannot be empty");
  }
  Name = obj.at("name").get<std::string>();
  Group = std::any{obj.at("group")};
  if (obj.at("avg").is_string()) {
    Avg = std::stod(obj.at("avg").get<std::string>());
  } else if (obj.at("avg").is_number()) {
    Avg = obj.at("avg").get<double>();
  } else {
    throw std::invalid_argument("The type of the Avg variable is undefined!!!");
  }
  Debt = std::any{obj.at("debt")};
}
Student::Student() = default;
const std::string &Student::getName() const { return Name; }
void Student::setName(const json &name) { Name = name.get<std::string>(); }
const std::any &Student::getGroup() const { return Group; }
void Student::setGroup(const json &group) { Group = std::any{group}; }
double Student::getAvg() const { return Avg; }
void Student::setAvg(const json &avg) {
  if (avg.at("avg").is_string()) {
    Avg = std::stod(avg.at("avg").get<std::string>());
  } else if (avg.at("avg").is_number()) {
    Avg = avg.at("avg").get<double>();
  } else {
    throw std::invalid_argument("The type of the Avg variable is undefined!!!");
  }
}
const std::any &Student::getDebt() const { return Debt; }
void Student::setDebt(const json &debt) { Debt = std::any{debt}; }
void Student::from_json(const json &obj) {
  if (obj.empty()) {
    throw std::invalid_argument("Object for Student cannot be empty");
  }
  Name = obj.at("name").get<std::string>();
  Group = std::any{obj.at("group")};
  if (obj.at("avg").is_string()) {
    Avg = std::stod(obj.at("avg").get<std::string>());
  } else if (obj.at("avg").is_number()) {
    Avg = obj.at("avg").get<double>();
  } 
  else {
    throw std::invalid_argument("The type of the Avg variable is undefined!!!");
  }
  Debt = std::any{obj.at("debt")};
}
