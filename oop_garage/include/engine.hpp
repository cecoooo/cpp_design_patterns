#pragma once

class Engine
{
private:
    int volume;
    int horse_powers;
public:
    Engine(int vol, int hp);
    int getVolumeInCubicCm();
    int getPower();
};