#include <string>

class Room {
protected:
    int Nights;
    double ServiceFee;
    double OtherFee;

public:
    Room(int Nights, double ServiceFee = 0, double OtherFee = 0);
    virtual double CalculateRevenue() const = 0; // Abstract function
    virtual ~Room() {}
};

class Deluxe : public Room {
public:
    Deluxe(int Nights, double ServiceFee, double OtherFee);
    double CalculateRevenue() const override;
};

class Premium : public Room {
public:
    Premium(int Nights, double ServiceFee);
    double CalculateRevenue() const override;
};

class Business : public Room {
public:
    Business(int Nights);
    double CalculateRevenue() const override;
};


