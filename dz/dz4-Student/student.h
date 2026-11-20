#pragma once

#include <string>
#include <vector>
#include <iostream>


class Student
{
private:
    std::string name_;
    std::string group_;
    std::vector<int> marks_;
    double averageScore_;

public:
    Student(const std::string& name, const std::string& group);

    ~Student() = default;
    Student(const Student& other) = default;
    Student(Student&& other) noexcept = default;
    Student& operator=(const Student& other) = default;
    Student& operator=(Student&& other) noexcept = default;

    void addMark(int mark);
    const std::vector<int>& getMarks() const;
    double getAverageScore() const;
    const std::string& getName() const;
    const std::string& getGroup() const;
};


std::ostream& operator<<(std::ostream& os, const Student& student);

bool operator<(const Student& lhs, const Student& rhs);