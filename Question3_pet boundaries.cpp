#include <iostream>
using namespace std;
class VirtualPet {
private:
    int hungerLevel;
    int energyLevel;
public:
 // Constructor
    VirtualPet(int h, int e) {
        hungerLevel = h;
        energyLevel = e;
    }
 // Function to give food
    VirtualPet& giveFood() {
        hungerLevel = hungerLevel - 20;

        if (hungerLevel < 0) {
            hungerLevel = 0;
            cout << "Minimum hunger limit reached (0)." << endl;
        }

        return *this;
    }
  // Function for rest
    VirtualPet& rest() {
        energyLevel = energyLevel + 30;

        if (energyLevel > 100) {
            energyLevel = 100;
            cout << "Energy cannot exceed 100." << endl;
        }

        return *this;
    }
 // Prefix ++ operator
    VirtualPet& operator++() {
        energyLevel = energyLevel - 10;
        hungerLevel = hungerLevel + 10;
        return *this;
    }
// Postfix ++ operator
    VirtualPet operator++(int) {
        VirtualPet copy = *this;

        energyLevel = energyLevel - 10;
        hungerLevel = hungerLevel + 10;

        return copy;
    }
 // Function to show pet stat
    void showStatus() {
        cout << "Pet Status -> Hunger: "
             << hungerLevel
             << " , Energy: "
             << energyLevel << endl;
    }
};

int main() {

  VirtualPet myPet(10, 90);
  myPet.giveFood().rest();
  myPet.showStatus();
}
