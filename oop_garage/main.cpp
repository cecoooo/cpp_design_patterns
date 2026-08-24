#include "player.hpp"
#include "car.hpp"
#include "race.hpp"
#include "garage.hpp"
#include <iostream>

std::vector<Tire> produceTires(int t)
{
    std::string tType;
    switch (t)
    {
    case 0:
        tType == "cheep";
        break;
    case 1:
        tType == "middle";
        break;
    case 2:
        tType == "expensive";
        break;
    default:
        break;
    }

    std::vector<Tire> res;
    for (size_t i = 0; i < 4; i++)
    {
        res.push_back(Tire(tType));
    }
    return res;
} 


int main()
{
    std::shared_ptr<Player> playerA(new Player("PlayerA"));
    std::shared_ptr<Player> playerB(new Player("PlayerB"));
    std::shared_ptr<Player> playerC(new Player("PlayerC"));
    std::shared_ptr<Player> playerD(new Player("PlayerD"));

    std::shared_ptr<Car> carPlayerA1(new Car(Engine(2000, 150), produceTires(0)));
    std::shared_ptr<Car> carPlayerB1(new Car(Engine(1900, 150), produceTires(2)));
    std::shared_ptr<Car> carPlayerC1(new Car(Engine(3000, 240), produceTires(1)));
    std::shared_ptr<Car> carPlayerD1(new Car(Engine(1200, 60), produceTires(0)));
    std::shared_ptr<Car> carPlayerA2(new Car(Engine(3200, 300), produceTires(1)));
    std::shared_ptr<Car> carPlayerB2(new Car(Engine(2500, 190), produceTires(2)));
    std::shared_ptr<Car> carPlayerC2(new Car(Engine(2200, 180), produceTires(0)));
    std::shared_ptr<Car> carPlayerD2(new Car(Engine(1300, 135), produceTires(1)));
    
    playerA->addCar(carPlayerA1);
    playerA->addCar(carPlayerA2);
    playerB->addCar(carPlayerB1);
    playerB->addCar(carPlayerB2);
    playerC->addCar(carPlayerC1);
    playerC->addCar(carPlayerC2);
    playerD->addCar(carPlayerD1);
    playerD->addCar(carPlayerD2);

    Race race("f1", 100000);

    std::vector<std::pair<std::shared_ptr<Player>, int>> participants;
    participants.push_back({playerA, 1});
    participants.push_back({playerB, 0});
    participants.push_back({playerC, 0});
    participants.push_back({playerD, 1});

    race.startRace(participants);
    std::cout << "Winner from " << race.getName() << ": " 
    << race.getLastWinner()->getName() << std::endl
    << "Current winner money balance: " << race.getLastWinner()->getBankBalance() << std::endl;

    Garage garage;

    garage.changeTires("expensive", *playerC, 0);
    garage.updateEngine(6300, 500, *playerC, 0);

    race.startRace(participants);
    std::cout << "Winner from " << race.getName() << ": " 
    << race.getLastWinner()->getName() << std::endl
    << "Current winner money balance: " << race.getLastWinner()->getBankBalance() << std::endl;

    race.updateAward(-10000);

    race.startRace(participants);
    std::cout << "Winner from " << race.getName() << ": " 
    << race.getLastWinner()->getName() << std::endl
    << "Current winner money balance: " << race.getLastWinner()->getBankBalance() << std::endl;

    return 0;
}
