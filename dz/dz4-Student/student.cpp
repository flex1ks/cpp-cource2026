#include "student.h"
#include <numeric>

Student::Student(const std::string& name, const std::string& group)
    : name_(name), group_(group), averageScore_(0.0)
{
}

void Student::addMark(int mark)
{
    marks_.push_back(mark);
    
    int sum = 0;
    for (int m : marks_) {
        sum += m;
    }
    averageScore_ = static_cast<double>(sum) / marks_.size();
}

const std::vector<int>& Student::getMarks() const
{
    return marks_;
}

double Student::getAverageScore() const
{
    return averageScore_;
}

const std::string& Student::getName() const
{
    return name_;
}

const std::string& Student::getGroup() const
{
    return group_;
}

std::ostream& operator<<(std::ostream& os, const Student& student)
{
    os << "Student: " << student.getName() 
       << " | Group: " << student.getGroup() 
       << " | Average: " << student.getAverageScore()
       << " | Marks: [";
       
    const auto& marks = student.getMarks();
    for (size_t i = 0; i < marks.size(); ++i) {
        os << marks[i];
        if (i < marks.size() - 1) os << ", ";
    }
    os << "]";
    return os;
}

bool operator<(const Student& lhs, const Student& rhs)
{
    return lhs.getAverageScore() < rhs.getAverageScore();
}