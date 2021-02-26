#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <ostream>
#include <istream>
using namespace std;

class Student {
 public:
  // default constructor initializes id to -1 and name to "None"
  Student();
  Student(int, string);
  int getID();
  void setID(int);
  string getName();
  void setName(string);

  // these overloaded operators compare two student objects based on their id only.
  // it's possible that you may need to overload additional operators (e.g., !=) depending on
  // how you implemented SortedList
  bool operator==(const Student& s) const;
  bool operator<(const Student& s) const;
  bool operator>(const Student& s) const;

  // There is nothing you need to do with these stream operators.
  // The implementations have already been given in the driver file.
  friend ostream& operator << (ostream& out, Student& s);
  friend istream& operator >> (istream& in, Student& s);

 private:
  int id;
  string name;
};

#endif
