// Copyright 2018 Osipova Anastasiya anastasiyaosipova2001@gmail.com
#ifndef INCLUDE_STUDENT_HPP_
#define INCLUDE_STUDENT_HPP_

#include <any>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

using nlohmann::json;

class Student {
 public:
  explicit Student(const json& js);
  const std::string& getName() const;
  const std::any& getGroup() const;
  const std::any& getAvg() const;
  const std::any& getDebt() const;

 private:
  std::string Name;
  std::any Group;
  std::any Avg;
  std::any Debt;
};


#endif  // INCLUDE_STUDENT_HPP_
