#include <iostream>
using namespace std;
class CoffeeMaker {
private:
    int waterAmount;
    int beanAmount;
public:
// Constructor
    CoffeeMaker(int w, int b) {
        waterAmount = w;
        beanAmount = b;
    }
 // Function to make coffee
    void makeCoffee() {

        if (waterAmount < 30 || beanAmount < 10) {
            cout << "Not enough resources. Please refill." << endl;
        }
        else {

            waterAmount = waterAmount - 30;
            beanAmount = beanAmount - 10;

            cout << "Coffee prepared. Remaining -> Water: "
                 << waterAmount
                 << "ml, Beans: "
                 << beanAmount
                 << "g" << endl;
        }
    }
 // operator overloading(+)
    CoffeeMaker operator+(CoffeeMaker other) {

        CoffeeMaker result(
            waterAmount + other.waterAmount,
            beanAmount + other.beanAmount
        );

        return result;
    }
// Destructor
    ~CoffeeMaker() {
        cout << "Coffee machine turned off." << endl;
    }
};
int main() {

   CoffeeMaker machine1(20,5);
   CoffeeMaker machine2(20,10);
   machine1.makeCoffee();
   CoffeeMaker machine3 = machine1 + machine2;
   machine3.makeCoffee();
}
