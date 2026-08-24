#include "engine.hpp"


Engine::Engine(int vol, int hp): volume(vol), horse_powers(hp){}
    
int Engine::getVolumeInCubicCm()
{
    return volume;
}
    
int Engine::getPower()
{
    return horse_powers;
}
