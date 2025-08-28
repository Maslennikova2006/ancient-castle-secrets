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
    Player(MapObject obj, int _health, Backpack backpack);

    ~Player();

    void activate_hint();
    void raise_object();
    void throw_out_object();
};

#endif  // GAME_PLAYER_PLAYER_H_
