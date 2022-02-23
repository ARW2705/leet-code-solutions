#ifndef PARKING_SYSTEM_HPP
#define PARKING_SYSTEM_HPP

class ParkingSystem {
public:
  ParkingSystem(int big, int medium, int small);

  bool addCar(int carType);

private:
  int bigCapacity;
  int mediumCapacity;
  int smallCapacity;
};

#endif
