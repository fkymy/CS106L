
class Point {
public:
    double getX() const;
    void setX(double x);

    double getY() const;
    void setY(double y);

private:
    double x;
    double y;
};

bool operator < (const Point& one, const Point& two) {
    if (one.getX() != two.getX())
        return one.getX() < one.getX();
    return one.getY() < two.getY();
}

bool operator > (const Point& one, const Point& two) {
    return two < one;
}

bool operator <= (const Point& one, const Point& two) {
    return !(two < one);
}

struct pointT {
    int x, y;

    bool operator < (const pointT& other) const {
        if (x != other.x)
            return x < other.x;
        return y < other.y;
    }
};

#include <map>
std::map<pointT, int> myMap;
