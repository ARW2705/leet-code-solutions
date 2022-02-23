#include "parking-system.hpp"

ParkingSystem::ParkingSystem(int big, int medium, int small) {
  bigCapacity = big;
  mediumCapacity = medium;
  smallCapacity = small;
}

bool ParkingSystem::addCar(int carType) {
  switch (carType) {
    case 1:
      if (bigCapacity < 1) return false;
      --bigCapacity;
      return true;
    case 2:
      if (mediumCapacity < 1) return false;
      --mediumCapacity;
      return true;
    case 3:
      if (smallCapacity < 1) return false;
      --smallCapacity;
      return true;
    default:
      return false;
  }
}
