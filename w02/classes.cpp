// classes.cpp
// Callum Howard, 2019

#include <iostream>

class Student {
public:
    void set_age(int age) { m_age = age; }
    void set_first_name(std::string name) { m_first_name = name; }
    void set_last_name(std::string name) { m_last_name = name; }
    void set_standard(int standard) { m_standard = standard; }

    int get_age() const { return m_age; }
    std::string get_first_name() const { return m_first_name; }
    std::string get_last_name() const { return m_last_name; }
    int get_standard() const { return m_standard; }

    std::string to_string() const {
        return std::to_string(m_age) + "," + m_first_name + "," + m_last_name +
                "," + std::to_string(m_standard);
    }

private:
    int m_age;
    std::string m_first_name;
    std::string m_last_name;
    int m_standard;
};

int main() {
    int age, standard;
    std::string first_name, last_name;

    std::cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    std::cout << st.get_age() << "\n";
    std::cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    std::cout << st.get_standard() << "\n";
    std::cout << "\n";
    std::cout << st.to_string();

    return 0;
}

