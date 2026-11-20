#include "student.h"
#include <algorithm>
#include <vector>

int main()
{
    std::vector<Student> students;

    Student s1("Mochalovsky Alexey", "B12-612");
    s1.addMark(7);
    s1.addMark(6);
    s1.addMark(5);

    Student s2("Garaev Ilnur", "B12-612");
    s2.addMark(3);
    s2.addMark(4);
    s2.addMark(7);

    Student s3("Tenishov Lev", "B12-612");
    s3.addMark(10);
    s3.addMark(9);
    s3.addMark(8);

    Student s4("Katelnikov Kirill", "B12-614");
    s4.addMark(2);
    s4.addMark(3);
    s4.addMark(6);

    Student s5("Murashov Andrey", "B12-611");
    s4.addMark(5);
    s4.addMark(3);
    s4.addMark(8);

    students.push_back(s1);
    students.push_back(s2);
    students.push_back(s3);
    students.push_back(s4);
    students.push_back(s5);

    std::cout << "=== Before sorting ===" << std::endl;
    for (const auto& s : students)
    {
        std::cout << s << std::endl;
    }

    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {return a.getAverageScore() < b.getAverageScore();});

    std::cout << "\n=== After sorting (by average score, asc) ===" << std::endl;
    for (const auto& s : students)
    {
        std::cout << s << std::endl;
    }

    return 0;
}