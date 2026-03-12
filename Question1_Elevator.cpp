#include <iostream>
using namespace std;
class SmartLift {
private:
int floorPosition;
double totalLoad;
const double LIMIT = 500.0;
public:
//Constructor
SmartLift(int f = 1, double w = 0.0) {
floorPosition = f;
totalLoad = w;
}
//Function to add passenger weight
SmartLift& addLoad(double w) {
if (totalLoad + w > LIMIT) {
cout << "Load limit exceeded. Passenger not allowed." << endl;
}
else {
totalLoad = totalLoad + w;
}
return *this;
}
//Function to move lift
SmartLift& moveLift(int f) {

if (f < 1 || f > 10) {
cout << "Invalid floor: " << f << endl;
}
else {
floorPosition = f;
}
return *this;
}
//Overloading operator
bool operator==(SmartLift obj) {
return floorPosition == obj.floorPosition;
}
//Destructor
~SmartLift() {
cout << "Lift shutting down at floor " << floorPosition << endl;
}
};
int main() {
SmartLift lift1(1,0);
lift1.addLoad(400)
.addLoad(150)
.moveLift(5)
.moveLift(12);
return 0;
}
