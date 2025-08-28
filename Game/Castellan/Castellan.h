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
    Castellan(MapObject obj, TVector<std::string> tasks,
        TVector<std::string> hints, bool isAppearance, int chance_of_appearance);

    ~Castellan();

    void reward_for_tasks();
    void give_hint();
    void provide_choice_of_action();
};

#endif  // GAME_CASTELLAN_CASTELLAN_H_
