// Copyright 2025 Maslennikova Mary

#include <string>
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/MapObject/MapObject.h"

#ifndef GAME_GAMEOBJECT_GAMEOBJECT_H_
#define GAME_GAMEOBJECT_GAMEOBJECT_H_

class GameObject : MapObject {
    int _weight;

public:
    GameObject();
    GameObject(int x, int y, std::string image, objectType type, int weight);
    GameObject(const GameObject& other);

    ~GameObject();

    void set_weight(int weight);

    const int get_weight() noexcept;
};

#endif  // GAME_GAMEOBJECT_GAMEOBJECT_H_
