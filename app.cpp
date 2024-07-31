#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Booking
{
public:
    string guestName;
    int roomNumber;

    Booking(string name, int room) : guestName(name), roomNumber(room) {}
};

class HotelBookingSystem
{
private:
    vector<Booking> bookings;

public:
    void addBooking(const string &guestName, int roomNumber)
    {
        bookings.push_back(Booking(guestName, roomNumber));
    }

    void showBookings() const
    {
        cout << "Current Bookings:" << endl;
        for (const auto &booking : bookings)
        {
            cout << "Guest Name: " << booking.guestName << ", Room Number: " << booking.roomNumber << endl;
        }
    }
};

int main()
{
    HotelBookingSystem hotelSystem;

    while (true)
    {
        cout << "\n1. Add Booking" << endl;
        cout << "2. Show Bookings" << endl;
        cout << "3. Exit" << endl;
        int userChoice;
        cin >> userChoice;

        if (userChoice == 1)
        {
            string guestName;
            int roomNumber;
            cout << "Enter guest name: ";
            cin.ignore();
            getline(cin, guestName);
            cout << "Enter room number: ";
            cin >> roomNumber;
            hotelSystem.addBooking(guestName, roomNumber);
        }
        else if (userChoice == 2)
        {
            hotelSystem.showBookings();
        }
        else if (userChoice == 3)
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
