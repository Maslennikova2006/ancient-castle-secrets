// Copyright 2025 Maslennikova Mary

#include <string>
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/TVector/TVector.h"
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/GameObject/GameObject.h"

#ifndef GAME_GAMECARD_GAMECARD_H_
#define GAME_GAMECARD_GAMECARD_H_

class GameCard {
    TVector<TVector<GameObject>> _objects;

public:
    GameCard();
    GameCard(TVector<TVector<GameObject>> objects);

    ~GameCard();

    void place_object(int x, int y);
    void place_object(GameObject obj);
    // �������� ������ � ��������� ������������
    // ��������� �������� �� ������� �������� ������ � ��������� ������������
    // ������������� ��������� ��������� ����� � ��������� ����������� � ���������
};

#endif  // GAME_GAMECARD_GAMECARD_H_
