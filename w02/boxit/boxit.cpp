// boxit.cpp
// Callum Howard, 2019

#include <iostream>

using namespace std;

void check2();

class Box {
public:
    // friends
    friend std::ostream& operator<<(std::ostream& out, Box& B);

    // constructors
    Box() : Box{0, 0, 0} {}  // default constructor
    Box(int length, int breadth, int height) : mLength{length}, mBreadth{breadth}, mHeight{height} {}
    //Box(Box b) : Box{b.mLength, b.mBreadth, b.mHeight} {}

    // return box's length
    int getLength() const { return mLength; }

    // return box's breadth
    int getBreadth() const { return mBreadth; }

    // return box's height
    int getHeight() const { return mHeight; }

    // return the volume of the box
    long long CalculateVolume() const {
        return mLength * mBreadth * mHeight;
    }

    bool operator<(Box& b) const {
        return (mLength < b.mLength) or
                (mBreadth < b.mBreadth and mLength == b.mLength) or
                (mHeight < b.mHeight and mLength == b.mLength and mBreadth == b.mBreadth);
    }

private:
    int mLength = 0;
    int mBreadth = 0;
    int mHeight = 0;
};


std::ostream& operator<<(std::ostream& out, Box& B) {
    out << B.getLength() << ' ' << B.getBreadth() << ' ' << B.getHeight();
    return out;
}

void check2() {
    int n;
    cin>>n;
    Box temp;
    for(int i=0;i<n;i++)
    {
        int type;
        cin>>type;
        if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser\n";
            }
            else
            {
                cout<<"Greater\n";
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }

    }
}

int main()
{
    check2();
}
