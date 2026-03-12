#include <iostream>
using namespace std;
class MovieRow {
private:
    bool* seatStatus;
    int totalSeats;

public:
// Constructor
    MovieRow(int n) {
        totalSeats = n;
        seatStatus = new bool[totalSeats];   

        for (int i = 0; i < totalSeats; i++) {
            seatStatus[i] = false;           // all seats initially free
        }
    }
 // Function to reserve seat
    void reserveSeat(int position) {

        if (position < 0 || position >= totalSeats) {
            cout << "Invalid seat number: " << position << endl;
        }

        else if (seatStatus[position]) {
            cout << "Seat " << position << " is already reserved." << endl;
        }

        else {
            seatStatus[position] = true;
            cout << "Seat " << position << " reserved successfully." << endl;
        }
    }
 // [] operator overloading
    bool operator[](int position) {
        return seatStatus[position];
    }
 // Destructor
    ~MovieRow() {
        delete[] seatStatus;
        cout << "Seat memory released." << endl;
    }
};
int main() {
    MovieRow seats(5);   // create row with 5 seats
    seats.reserveSeat(2);
    seats.reserveSeat(2);
    seats.reserveSeat(8);
    cout << "Seat 2 booked? "
         << (seats[2] ? "Yes" : "No") << endl;
    return 0;
}
