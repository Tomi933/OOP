#include <iostream>
#include "Man.h"
#include "Student.h"

using namespace std;

int main() {
    
    Man m1; 
    Man m2("Ivan", 25, "Male", 70.5);  
    Man m3 = m2;  

    cout << "\n--- Man: Init + Display ---" << endl;
    m1.Init("Oleh", 30, "Male", 80.0);
    m1.Display();

    cout << "\n--- Man: Setters ---" << endl;
    m1.setName("Petro");
    m1.setAge(35);
    m1.setWeight(85.2);
    m1.Display();

    cout << "\n--- Man: operator string() and << ---" << endl;
    cout << m1 << endl;

    cout << "\n--- Man: Read() from user ---" << endl;
    m1.Read();
    m1.Display();

    cout << "\n--- Student: Constructor ---" << endl;
    Student s1(m1, 2);
    s1.Display();

    cout << "\n--- Student: Init() ---" << endl;
    s1.Init(m2, 1);  
    s1.Display();

    cout << "\n--- Student: IncreaseCourse() ---" << endl;
    s1.IncreaseCourse();
    s1.Display();

    cout << "\n--- Student: setCourse(5) ---" << endl;
    s1.setCourse(5);
    s1.Display();

    cout << "\n--- Student: Read() ---" << endl;
    Student s2;
    s2.Read();
    s2.Display();

    cout << "\n--- Student: Copy and Assignment ---" << endl;
    Student s3 = s2;
    s3.Display();

    cout << "\n--- Student: operator string() and << ---" << endl;
    cout << s3 << endl;

    return 0;
}
