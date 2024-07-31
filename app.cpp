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

    void modifyBooking(int oldRoomNumber, int newRoomNumber, const string &newGuestName)
    {
        for (auto &booking : bookings)
        {
            if (booking.roomNumber == oldRoomNumber)
            {
                if (isRoomAvailable(newRoomNumber) || newRoomNumber == oldRoomNumber)
                {
                    booking.roomNumber = newRoomNumber;
                    booking.guestName = newGuestName;
                    cout << "Booking updated successfully." << endl;
                }
                else
                {
                    cout << "New room " << newRoomNumber << " is not available." << endl;
                }
                return;
            }
        }
        cout << "No booking found for room " << oldRoomNumber << "." << endl;
    }

    void searchBookingByRoom(int roomNumber) const
    {
        for (const auto &booking : bookings)
        {
            if (booking.roomNumber == roomNumber)
            {
                cout << "Booking found: Guest Name: " << booking.guestName << ", Room Number: " << booking.roomNumber << endl;
                return;
            }
        }
        cout << "No booking found for room " << roomNumber << "." << endl;
    }

    void searchBookingByName(const string &guestName) const
    {
        bool found = false;
        for (const auto &booking : bookings)
        {
            if (booking.guestName == guestName)
            {
                cout << "Booking found: Guest Name: " << booking.guestName << ", Room Number: " << booking.roomNumber << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "No bookings found for guest " << guestName << "." << endl;
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
        cout << "3. Modify Booking" << endl;
        cout << "4. Search Booking by Room Number" << endl;
        cout << "5. Search Booking by Guest Name" << endl;
        cout << "6. Check Room Availability" << endl;
        cout << "7. Show Bookings" << endl;
        cout << "8. Exit" << endl;
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
            int oldRoomNumber, newRoomNumber;
            string newGuestName;
            cout << "Enter old room number to modify: ";
            cin >> oldRoomNumber;
            cout << "Enter new room number: ";
            cin >> newRoomNumber;
            cout << "Enter new guest name: ";
            cin.ignore();
            getline(cin, newGuestName);
            hotelSystem.modifyBooking(oldRoomNumber, newRoomNumber, newGuestName);
        }
        else if (userChoice == 4)
        {
            int roomNumber;
            cout << "Enter room number to search: ";
            cin >> roomNumber;
            hotelSystem.searchBookingByRoom(roomNumber);
        }
        else if (userChoice == 5)
        {
            string guestName;
            cout << "Enter guest name to search: ";
            cin.ignore();
            getline(cin, guestName);
            hotelSystem.searchBookingByName(guestName);
        }
        else if (userChoice == 6)
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
        else if (userChoice == 7)
        {
            hotelSystem.showBookings();
        }
        else if (userChoice == 8)
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
