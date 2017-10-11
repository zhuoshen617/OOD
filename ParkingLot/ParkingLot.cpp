#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

typedef pair<int, int> Spot;

class Vehicle
{
public:
    enum VehicleType
    {
        CAR,
        BUS,
        NO_VEHICLE
    };

    Vehicle(const string & id) {}
    virtual ~Vehicle() {}
    virtual VehicleType getType() = 0;
    virtual void print() = 0;
    string id;
    int size;
    vector<Spot> parkAtSpots;
};

class Car : public Vehicle
{
public:
    Car(const string & id) : Vehicle(id) { size = 1; }
    VehicleType getType() {return VehicleType::CAR;}
    void print() { cout << "C"; }
};

class Bus : public Vehicle
{
public:
    Bus(const string & id) : Vehicle(id) { size = 5; }
    VehicleType getType() {return VehicleType::BUS;}
    void print() { cout << "B"; }
};


class NoVehicle : public Vehicle
{
public:
    NoVehicle() : Vehicle("") { size = 1; }
    VehicleType getType() {return VehicleType::NO_VEHICLE;}
    void print() { cout << "."; }
};


class ParkingLot
{
public:
    static const int MAX_ROW = 20;
	static const int MAX_COL = 20;
    shared_ptr<Vehicle> lot[MAX_ROW][MAX_COL];

    ParkingLot()
    {
        for (int i = 0; i < MAX_ROW; i++)
        {
            for (int j = 0; j < MAX_COL; j++)
            {
                lot[i][j] = make_shared<NoVehicle>();
            }
        }
    }

    vector<Spot> findAvaiableSpot(const shared_ptr<Vehicle> & v)
    {
        for (int i = 0; i < MAX_ROW; i++)
        {
            for (int j = 0; j < MAX_COL; j++)
            {
                if (lot[i][j].get()->getType() == Vehicle::VehicleType::NO_VEHICLE)
                {
                    int size = v.get()->size;

                    bool okToPark = true;
                    vector<Spot> result;
                    for (int k = 0; k < size && i + k < MAX_COL; k++)
                    {
                        if (lot[i][j + k].get()->getType() != Vehicle::VehicleType::NO_VEHICLE)
                        {
                            okToPark = false;
                            break;
                        }

                        result.push_back(Spot(i, j+k));
                    }

                    if (okToPark)
                        return result;
                }
            }
        }

        return vector<Spot>();
    }

    void parkVehcile(const shared_ptr<Vehicle> & v, const vector<Spot> & spots)
    {
        for (const auto & spot : spots)
            lot[spot.first][spot.second] = v;

        v.get()->parkAtSpots = spots;
    }

    void removeVehcile(const shared_ptr<Vehicle> & v)
    {
        for (const auto & spot : v.get()->parkAtSpots)
            lot[spot.first][spot.second] = make_shared<NoVehicle>();

        v.get()->parkAtSpots.clear();
    }

    void print()
    {
        for (int i = 0; i < MAX_ROW; i++)
        {
            for (int j = 0; j < MAX_COL; j++)
            {
                lot[i][j].get()->print();
            }

            cout << endl;
        }

        cout << endl;
    }
};


int main()
{
    cout << "Hello world!" << endl;

    ParkingLot pl;
    pl.print();

    shared_ptr<Vehicle> v1 = make_shared<Car>("car1");
    shared_ptr<Vehicle> v2 = make_shared<Car>("car2");
    shared_ptr<Vehicle> v3 = make_shared<Bus>("bus1");
    shared_ptr<Vehicle> v4 = make_shared<Bus>("bus2");

    vector<shared_ptr<Vehicle> > vehcileToAdd({v1, v2, v3, v4});
    for (auto v : vehcileToAdd)
    {
        vector<Spot> vec = pl.findAvaiableSpot(v);
        if (vec.size())
            pl.parkVehcile(v, vec);

        pl.print();
    }

    vector<shared_ptr<Vehicle> > vehcileToRmove({v4, v2, v1, v3});
    for (auto v : vehcileToRmove)
    {
        pl.removeVehcile(v);
        pl.print();
    }

    return 0;
}
