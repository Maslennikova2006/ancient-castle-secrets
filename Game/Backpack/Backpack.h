// Copyright 2025 Maslennikova Mary

#include <string>
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/GameObject/GameObject.h"
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/TVector/TVector.h"

#ifndef GAME_BACKPACK_BACKPACK_H_
#define GAME_BACKPACK_BACKPACK_H_

class Backpack {
    TVector<GameObject> _objects;
    const GameObject* _object_in_hand;
    const GameObject* _current_object;
    int _total_weight;
    int _max_weight;

public:
    Backpack();
    Backpack(TVector<GameObject> objects, GameObject* object_in_hand, GameObject* current_object,
        int total_weight, int max_weight);
    Backpack(const Backpack& other);

    ~Backpack();

    void set_objects(const TVector<GameObject>& objects);
    void set_object_in_hand(const GameObject* object_in_hand);
    void set_current_object(const GameObject* current_object);

    const TVector<GameObject>& get_objects() const noexcept;
    const GameObject* get_object_in_hand() const noexcept;
    const GameObject* get_current_object() const noexcept;
    const int get_total_weight() const noexcept;
    const int get_max_weight() const noexcept;

    void place_an_object(const GameObject& obj);
    void throw_out_current_object();
    void take_current_object();
};

#endif  // GAME_BACKPACK_BACKPACK_H_
