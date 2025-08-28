// Copyright 2025 Maslennikova Mary

#include <string>
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/MapObject/MapObject.h"
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/Backpack/Backpack.h"

#ifndef GAME_PLAYER_PLAYER_H_
#define GAME_PLAYER_PLAYER_H_

class Player : MapObject {
    int _health;
    Backpack _backpack;

public:
    Player();
    Player(int x, int y, std::string image, objectType type, int _health, Backpack backpack);
    Player(const Player& other);

    ~Player();

    void set_health(int health);
    void set_backpack(Backpack backpack);

    const int get_health() noexcept;
    const Backpack get_backpack() noexcept;

    void activate_hint();
    void raise_object();
    void throw_out_object();
};

#endif  // GAME_PLAYER_PLAYER_H_
