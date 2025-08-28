// Copyright 2025 Maslennikova Mary

#include <string>
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/Player/Player.h"
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/Castellan/Castellan.h"
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/TVector/TVector.h"
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/GameObject/GameObject.h"
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/GameCard/GameCard.h"

#ifndef GAME_GAMEPLAY_GAMEPLAY_H_
#define GAME_GAMEPLAY_GAMEPLAY_H_

class Gameplay {
    Player _player;
    Castellan _castellan;
    TVector<GameObject> _objects;
    GameCard _card;
    bool isGameOver;

public:
    Gameplay();
    Gameplay(Player _player, Castellan _castellan,
        TVector<GameObject> _objects, GameCard _card, bool isGameOver);

    ~Gameplay();

    void generate_game_object();
    void initializing_game();
    // еще методы
};

#endif  // GAME_GAMEPLAY_GAMEPLAY_H_
