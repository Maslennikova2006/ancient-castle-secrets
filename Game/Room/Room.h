// Copyright 2025 Maslennikova Mary

#include <string>
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/MapObject/MapObject.h"

#ifndef GAME_ROOM_ROOM_H_
#define GAME_ROOM_ROOM_H_

enum roomType { riddle, test, final};

class Room : MapObject {
    roomType _room_type;
    std::string _task;
    std::string _answer;
    std::string _right_answer;
    std::string _hint;
    bool _isCompleted;

public:
    Room();
    Room(int x, int y, std::string image, objectType obj_type, roomType room_type,
        std::string task, std::string _answer,
        std::string _right_answer, std::string _hint, bool isCompleted);

    void set_task(const std::string task);
    void set_answer(const std::string answer);
    void set_hint(const std::string hint);

    const std::string get_task() noexcept;
    const std::string get_answer() noexcept;
    const std::string get_right_answer() noexcept;
    const std::string get_hint() noexcept;

    bool check_answer();
    //void show_hint();
    //void reward_for_passing();  // возможно лучше не награждение
};

#endif  // GAME_ROOM_ROOM_H_
