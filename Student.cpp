#include "Student.h"

Student::Student() {
    id = 0;
    name = "";
}

Student::Student(int a, string b) {
    id = a;
    name = b;
}

int Student::getID() {
    return id;
}

void Student::setID(int a) {
    id = a;
}

string Student::getName() {
    return name;
}

void Student::setName(string a) {
    name = a;
}

bool Student::operator==(const Student& s) const {
    if (s.id == this->id) {
        return true;
    }
    return false;
}

bool Student::operator<(const Student& s) const {
    if (this->id < s.id) {
        return true;
    }
    return false;
}

bool Student::operator>(const Student& s) const {
    if (this->id > s.id) {
        return true;
    }
    return false;
}
