#include <iostream>
#include <vector>
#include <iomanip>
#include "bai2.h"
using namespace std;

int main() {
    Deluxe A(5, 200000, 100000);
    Deluxe B(3, 150000, 50000);
    Premium C(4, 100000);
    Premium D(6, 250000);
    Business E(7);

    vector<Room*> Rooms = { &A, &B, &C, &D, &E };

    double MaxRevenue = 0;
    string RoomType;

    for (Room* Room : Rooms) {
        double Revenue = Room->CalculateRevenue();
        if (Revenue > MaxRevenue) {
            MaxRevenue = Revenue;

            if (dynamic_cast<Deluxe*>(Room)) {
                RoomType = "Deluxe";
            }
            else if (dynamic_cast<Premium*>(Room)) {
                RoomType = "Premium";
            }
            else if (dynamic_cast<Business*>(Room)) {
                RoomType = "Business";
            }
        }
    }
    
    cout << "Room type with the highest revenue: " << RoomType
         << " (Revenue: " << fixed << setprecision(0) << MaxRevenue << " VND)" << endl;

    return 0;
}
