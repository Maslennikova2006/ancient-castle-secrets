// Copyright 2025 Maslennikova Mary

#include <string>
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/MapObject/MapObject.h"

#ifndef GAME_ROOM_ROOM_H_
#define GAME_ROOM_ROOM_H_

enum roomType { riddle, test, final};

class Room : MapObject {
    roomType _type;
    std::string _task;
    std::string _answer;
    std::string _right_answer;
    std::string _hint;
    bool _isCompleted;

public:
    Room();
    Room(MapObject obj, roomType type, std::string task, std::string _answer,
        std::string _right_answer, std::string _hint, bool isCompleted);

    bool check_answer();
    void show_hint();
    void reward_for_passing();  // возможно лучше не награждение
};

#endif  // GAME_ROOM_ROOM_H_
