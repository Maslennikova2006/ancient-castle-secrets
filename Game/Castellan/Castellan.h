// Copyright 2025 Maslennikova Mary

#include <string>
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/MapObject/MapObject.h"
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/TVector/TVector.h"

#ifndef GAME_CASTELLAN_CASTELLAN_H_
#define GAME_CASTELLAN_CASTELLAN_H_

class Castellan : MapObject {
    TVector<std::string> _tasks;
    TVector<std::string> _hints;
    bool _isAppearance;
    int _chance_of_appearance;

public:
    Castellan();
    Castellan(int x, int y, std::string image, objectType type, TVector<std::string> tasks,
        TVector<std::string> hints, bool isAppearance, int chance_of_appearance);
    Castellan(const Castellan& other);

    ~Castellan();

    void reward_for_tasks();
    void give_hint();
    void define_an_action();
    void calculate_chance();
};

#endif  // GAME_CASTELLAN_CASTELLAN_H_
