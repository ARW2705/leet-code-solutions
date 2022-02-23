#include "parking-system.hpp"
#include "../../utilities/print-success.cpp"

int main() {
  ParkingSystem* ps1 = new ParkingSystem(1, 1, 0);
  printSuccess(ps1->addCar(1));
  printSuccess(ps1->addCar(2));
  printSuccess(!ps1->addCar(3));
  printSuccess(!ps1->addCar(1));

  return 0;
}
