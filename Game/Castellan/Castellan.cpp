// Copyright 2025 Maslennikova Mary

#include <string>
#include <stdexcept>
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/Castellan/Castellan.h"
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/MapObject/MapObject.h"

Castellan::Castellan() : MapObject() {
    _tasks = {};
    _hints = {};
    _isAppearance = false;
    _chance_of_appearance = 0;
}
Castellan::Castellan(int x, int y, std::string image, objectType type, TVector<std::string> tasks,
    TVector<std::string> hints, bool isAppearance, int chance_of_appearance) : MapObject(x, y, image, type) {
    _tasks = tasks;
    _hints = hints;
    _isAppearance = isAppearance;
    _chance_of_appearance = chance_of_appearance;
}
Castellan::Castellan(const Castellan& other) : MapObject(other) {
    _tasks = other._tasks;
    _hints = other._hints;
    _isAppearance = other._isAppearance;
    _chance_of_appearance = other._chance_of_appearance;
}

Castellan::~Castellan() {

}

//void Castellan::reward_for_tasks() {  // перенести в игрока
//
//}
//void Castellan::give_hint();  // наверное в форме уже
//void Castellan::define_an_action() {
//
//}
void Castellan::calculate_chance() {
    _chance_of_appearance = 1 + rand() % 100;
}