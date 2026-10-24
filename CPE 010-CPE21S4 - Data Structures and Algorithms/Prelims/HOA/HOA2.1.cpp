#include <iostream>
#include <string>

class Student {
private:
    std::string studentName;
    int studentAge;

public:
    // Constructor
    Student(std::string newName = "John Doe", int newAge = 18) {
        studentName = std::move(newName);
        studentAge = newAge;
        std::cout << "Constructor Called." << std::endl;
    }

    // Destructor
    ~Student() {
        std::cout << "Destructor Called." << std::endl;
    }

    // Copy Constructor
    Student(const Student &copyStudent) {
        std::cout << "Copy Constructor Called." << std::endl;
        studentName = copyStudent.studentName;
        studentAge = copyStudent.studentAge;
    }

    // Copy Assignment Operator
    Student& operator=(const Student &other) {
        std::cout << "Copy Assignment Operator Called." << std::endl;
        if (this != &other) {
            studentName = other.studentName;
            studentAge = other.studentAge;
        }
        return *this;
    }

    // Display Attributes
    void printDetails() {
        std::cout << studentName << " " << studentAge << std::endl;
    }
};

int main() {
    // Individual objects
    Student student1("Roman", 28);   
    Student student2(student1);      
    Student student3;                
    student3 = student2;             

    // Array of Students
    const size_t j = 5;
    Student studentList[j] = {};
    std::string namesList[j] = {"Carly", "Freddy", "Sam", "Zack", "Cody"};
    int ageList[j] = {15, 16, 18, 19, 16};

    // Loop A:
    for (int i = 0; i < j; i++) {
        Student *ptr = new Student(namesList[i], ageList[i]);
        studentList[i] = *ptr;   
        delete ptr;              
    }

    // Loop B
    for (int i = 0; i < j; i++) {
        studentList[i].printDetails();
    }

    return 0;
}
