#include <fplus/fplus.hpp>

class VehiclePart {};
class Wheel : public VehiclePart {};
class CarWheel : public Wheel {};
class TrainWheel : public Wheel {};

class Motor : public VehiclePart {};
class CarMotor : public Motor {};
class TrainMotor : public Motor {};

enum class vehicle_type {Car, Train};
enum class part_type {Motor, Wheel};

std::unique_ptr<VehiclePart> create_part(
    vehicle_type v_type, part_type p_type)
{
    using namespace std;
    switch (v_type) {
    case vehicle_type::Car:
        switch (p_type) {
        case part_type::Motor: return make_unique<CarMotor>(); break;
        case part_type::Wheel: return make_unique<CarWheel>(); break;
        }
    case vehicle_type::Train:
        switch (p_type) {
        case part_type::Motor: return make_unique<TrainMotor>(); break;
        case part_type::Wheel: return make_unique<TrainWheel>(); break;
        }
    }
}

const auto carPartFactory =
    fplus::bind_1st_of_2(create_part, vehicle_type::Car);

const auto trainPartFactory =
    fplus::bind_1st_of_2(create_part, vehicle_type::Train);

typedef std::function<std::unique_ptr<VehiclePart>(part_type)> Factory;

void UseFactory(const Factory& factory)
{
    const auto motor = factory(part_type::Motor);
    const auto leftWheel = factory(part_type::Wheel);
    // ...
}

int main()
{
    using namespace fplus;
    UseFactory(carPartFactory);
    UseFactory(trainPartFactory);
}
