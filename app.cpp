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

    void cancelBooking(int roomNumber)
    {
        for (auto it = bookings.begin(); it != bookings.end(); ++it)
        {
            if (it->roomNumber == roomNumber)
            {
                bookings.erase(it);
                cout << "Booking for room " << roomNumber << " has been canceled." << endl;
                return;
            }
        }
        cout << "No booking found for room " << roomNumber << "." << endl;
    }

    bool isRoomAvailable(int roomNumber) const
    {
        for (const auto &booking : bookings)
        {
            if (booking.roomNumber == roomNumber)
            {
                return false;
            }
        }
        return true;
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
        cout << "2. Cancel Booking" << endl;
        cout << "3. Check Room Availability" << endl;
        cout << "4. Show Bookings" << endl;
        cout << "5. Exit" << endl;
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
            if (hotelSystem.isRoomAvailable(roomNumber))
            {
                hotelSystem.addBooking(guestName, roomNumber);
                cout << "Booking added successfully." << endl;
            }
            else
            {
                cout << "Room " << roomNumber << " is already booked." << endl;
            }
        }
        else if (userChoice == 2)
        {
            int roomNumber;
            cout << "Enter room number to cancel booking: ";
            cin >> roomNumber;
            hotelSystem.cancelBooking(roomNumber);
        }
        else if (userChoice == 3)
        {
            int roomNumber;
            cout << "Enter room number to check availability: ";
            cin >> roomNumber;
            if (hotelSystem.isRoomAvailable(roomNumber))
            {
                cout << "Room " << roomNumber << " is available." << endl;
            }
            else
            {
                cout << "Room " << roomNumber << " is already booked." << endl;
            }
        }
        else if (userChoice == 4)
        {
            hotelSystem.showBookings();
        }
        else if (userChoice == 5)
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
