#include "bai2.h"
using namespace std;
Room::Room(int Nights, double ServiceFee, double OtherFee)
        : Nights(Nights), ServiceFee(ServiceFee), OtherFee(OtherFee) {}

Deluxe::Deluxe(int Nights, double ServiceFee, double OtherFee)
        : Room(Nights, ServiceFee, OtherFee) {}

double Deluxe::CalculateRevenue() const {
    return Nights * 750000 + ServiceFee + OtherFee;
}

Premium::Premium(int Nights, double ServiceFee)
        : Room(Nights, ServiceFee) {}

double Premium::CalculateRevenue() const {
    return Nights * 500000 + ServiceFee;
}

Business::Business(int Nights)
        : Room(Nights) {}

double Business::CalculateRevenue() const {
    return Nights * 300000;
}
