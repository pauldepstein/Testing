#ifndef PARKINGLOT_H_INCLUDED
#define PARKINGLOT_H_INCLUDED
#include <utility>
#include <vector>
class ParkingLot // Only made a start on this one.
{

    std::vector<double> feeStructure; // Hourly parking fees for different categories.
    std::pair<int, int> dimensions; // First dimension is width, second is length.
    double hours; // Time in hours that customer stays.
    double fee; // fee.

public:
    enum CarType{DISABLED, ABLE, VAN};
    void setFee()const; // Use other parameters to calculate fee.
    double getFee() const {return fee;}
};


#endif // PARKINGLOT_H_INCLUDED
