// rectangleArea.cpp
// Callum Howard, 2019

#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */
class Rectangle {
public:
    virtual void display() const {
        std::cout << width << " " << height << '\n';
    }
    virtual ~Rectangle() {}  //NOTE!!
protected:
    int width;
    int height;
};

class RectangleArea : public Rectangle {
public:
    virtual void display() const {
        std::cout << width * height << '\n';
    }

    void read_input() {
        std::cin >> width;
        std::cin >> height;
    }
};


int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;

    /*
     * Read the width and height
     */
    r_area.read_input();

    /*
     * Print the width and height
     */
    r_area.Rectangle::display();

    /*
     * Print the area
     */
    r_area.display();

    return 0;
}
