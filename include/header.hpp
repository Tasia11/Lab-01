// Copyright 2018 Osipova Anastasiya anastasiyaosipova2001@gmail.com

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "student.hpp"

struct Lengths_of_fields {
  size_t length_1_field;
  size_t length_2_field;
  size_t length_3_field;
  size_t length_4_field;
};
class Parser {
 public:
  Parser();
  explicit Parser(const std::vector<Student> &s);
  explicit Parser(const std::string &path);
  ~Parser();
  [[nodiscard]] const std::vector<Student> &getStudents() const;
  [[nodiscard]] const Lengths_of_fields &getL() const;
  void printRow(const Student &student) const;
  [[nodiscard]] std::string getSeparator() const;
  void parser(const std::string &path);
  void sortByName();
  void sortByAverageScore();
  bool emptyJSONobject() const;
  void setJSONstring(const std::string &JSON);

 private:
  std::vector<Student> students;
  Lengths_of_fields l{15, 8, 6, 15};
  void setLengths();
};
#endif // INCLUDE_HEADER_HPP_
