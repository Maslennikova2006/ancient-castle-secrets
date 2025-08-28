// Copyright 2025 Maslennikova Mary

#include <string>
#include <stdexcept>
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/Room/Room.h"
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/MapObject/MapObject.h"

Room::Room() : MapObject() {
    _room_type = test;
    _task = "";
    _answer = "";
    _right_answer = "";
    _hint = "";
    _isCompleted = false;
}
Room::Room(int x, int y, std::string image, objectType obj_type, roomType room_type,
    std::string task, std::string answer, std::string right_answer,
    std::string hint, bool isCompleted) : MapObject(x, y, image, obj_type) {
    _room_type = room_type;
    _task = task;
    _answer = answer;
    _right_answer = right_answer;
    _hint = hint;
    _isCompleted = isCompleted;
}
Room::Room(const Room& other) : MapObject(other) {
    _room_type = other._room_type;
    _task = other._task;
    _answer = other._answer;
    _right_answer = other._right_answer;
    _hint = other._hint;
    _isCompleted = other._isCompleted;
}

Room::~Room() {

}

void Room::set_task(const std::string task) {
    _task = task;
}
void Room::set_answer(const std::string answer) {
    _answer = answer;
}
void Room::set_hint(const std::string hint) {
    _hint = hint;
}

const std::string Room::get_task() noexcept {
    return _task;
}
const std::string Room::get_answer() noexcept {
    return _answer;
}
const std::string Room::get_right_answer() noexcept {
    return _right_answer;
}
const std::string Room::get_hint() noexcept {
    return _hint;
}

bool Room::check_answer() {
    if (_answer == _right_answer)
        return true;
    else
        return false;
}
//void Room::show_hint() {  // наверное это уже в форме
//
//}
//void Room::reward_for_passing() {  // это в игрока перенести
//
//}