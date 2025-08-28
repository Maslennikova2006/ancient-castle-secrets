// Copyright 2025 Maslennikova Mary

#include <string>
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/GameObject/GameObject.h"
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/TVector/TVector.h"

#ifndef GAME_BACKPACK_BACKPACK_H_
#define GAME_BACKPACK_BACKPACK_H_

class Backpack {
    TVector<GameObject> _objects;
    GameObject* _object_in_hand;
    GameObject* _current_object;
    int _total_weight;
    int _max_weight;

public:
    Backpack();
    Backpack(TVector<GameObject> objects, GameObject* object_in_hand,
    GameObject* current_object, int total_weight, int max_weight);

    ~Backpack();

    void place_an_object(GameObject obj);
    void throw_out_current_object();
    void take_current_object();
};

#endif  // GAME_BACKPACK_BACKPACK_H_
