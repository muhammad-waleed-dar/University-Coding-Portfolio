#include <iostream>
#include <string>
#include <cmath> // Required for the sqrt and pow functions

using namespace std;

// Convert the following code with 
// classes instead of structs
// You should add members to make
// the point class, a true blueprint
// for points

class Point 
{
    public:
    double x; // x-coordinate
    double y; // y-coordinate

    Point(double xpoint=0.0, double ypoint=0.0) : x(xpoint), y(ypoint)
    {
            cout << "Default and Parameterized constructor called\n";
    }

    double calculateDistance(Point p2) 
    {
    double dx = p2.x - x;
    
    double dy = p2.y - y;
    
    double distanceSquared = pow(dx, 2) + pow(dy, 2);
    
    return sqrt(distanceSquared);
    }
};


// // 1. Define the Point structure
// struct Point 
// {
//     double x; // x-coordinate
//     double y; // y-coordinate
// };

// // 2. Function to calculate the distance between two Point structures
// /**
//  * Calculates the Euclidean distance between two points (p1 and p2).
//  * The formula used is the distance formula: 
//  * distance = sqrt((x2 - x1)^2 + (y2 - y1)^2)
//  */
// double calculateDistance(Point p1, Point p2) 
// {
//     // Calculate the difference in x-coordinates (dx)
//     double dx = p2.x - p1.x;
    
//     // Calculate the difference in y-coordinates (dy)
//     double dy = p2.y - p1.y;
    
//     // Calculate (dx)^2 + (dy)^2
//     double distanceSquared = pow(dx, 2) + pow(dy, 2);
    
//     // Take the square root of the sum
//     return sqrt(distanceSquared);
// }

// 3. Main function
int main() 
{
    // Create two Point objects
    Point point1;
    Point point2;

    // --- Input for Point 1 ---
    cout << "Enter the coordinates for Point 1 (x y): ";
    // Use cin to read the x and y values directly into the struct members
    cin >> point1.x >> point1.y;

    // --- Input for Point 2 ---
    cout << "Enter the coordinates for Point 2 (x y): ";
    cin >> point2.x >> point2.y;

    // 4. Calculate the distance using the function
    double distance = point1.calculateDistance(point2);

    // 5. Output the result
    cout << "\n--- Results ---" << endl;
    cout << "Point 1: (" << point1.x << ", " << point1.y << ")" << endl;
    cout << "Point 2: (" << point2.x << ", " << point2.y << ")" << endl;
    cout << "The distance between the two points is: " << distance << endl;

    return 0;
}