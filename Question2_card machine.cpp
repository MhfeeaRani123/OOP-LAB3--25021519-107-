#include <iostream>
using namespace std;

class TravelCard {
private:
    double amount;       //  current card balance
    bool tripStatus;     // check if trip is active
public:

//Constructor
    TravelCard(double money) {
        amount = money;
        tripStatus = false;
    }
//Function for starting journey
    void startJourney() {
        if (tripStatus) {
            cout << "Error: Trip already started!" << endl;
        }
        else if (amount < 2.50) {
            cout << "Error: Not enough balance." << endl;
        }
        else {
            tripStatus = true;
            cout << "Journey started successfully." << endl;
        }
    }
 // Function for  ending journey
    void endJourney() {
        if (!tripStatus) {
            cout << "Error: No active journey to end!" << endl;
        }
        else {
            amount = amount - 2.50;
            tripStatus = false;

            cout << "Journey ended. Balance left: $" 
                 << amount << endl;
        }
    }
// Operator overloading for penalty deduction
    void operator-=(double fine) {
        amount = amount - fine;
    }
 // Operator overloading to check if balance is zero
    bool operator!() {
        if (amount == 0)
            return true;
        else
            return false;
    }
};
int main() {
TravelCard myCard(5.00);
myCard.startJourney();
myCard.startJourney();
myCard.endJourney();
myCard.endJourney();
   if (!myCard)
        cout << "Card balance is empty." << endl;
}

