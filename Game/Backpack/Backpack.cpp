// Copyright 2025 Maslennikova Mary

#include <string>
#include <stdexcept>
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/Backpack/Backpack.h"


Backpack::Backpack() {
    _objects = TVector<GameObject>();
    _object_in_hand = nullptr;
    _current_object = nullptr;
    _total_weight = 0;
    _max_weight = 100;
}
Backpack::Backpack(TVector<GameObject> objects, GameObject* object_in_hand, GameObject* current_object,
    int total_weight, int max_weight) {
    _objects = objects;
    _object_in_hand = object_in_hand;
    _current_object = current_object;
    _total_weight = total_weight;
    _max_weight = max_weight;
}
Backpack::Backpack(const Backpack& other) {
    if (&other == NULL)
        throw std::invalid_argument("The object was not received!\n");
    _objects = other._objects;
    _object_in_hand = other._object_in_hand;
    _current_object = other._current_object;
    _total_weight = other._total_weight;
    _max_weight = other._max_weight;
}

Backpack::~Backpack() {
    _current_object = nullptr;
}

void Backpack::set_objects(const TVector<GameObject>& objects) {
    _objects = objects;
}
void Backpack::set_object_in_hand(const GameObject* object_in_hand) {
    _object_in_hand = object_in_hand;
}
void Backpack::set_current_object(const GameObject* current_object) {
    _current_object = current_object;
}

const TVector<GameObject>& Backpack::get_objects() const noexcept {
    return _objects;
}
const GameObject* Backpack::get_object_in_hand() const noexcept {
    return _object_in_hand;
}
const GameObject* Backpack::get_current_object() const noexcept {
    return _current_object;
}
const int Backpack::get_total_weight() const noexcept {
    return _total_weight;
}
const int Backpack::get_max_weight() const noexcept {
    return _max_weight;
}

void Backpack::place_an_object(const GameObject& obj) {
    if (_total_weight + obj.get_weight() > _max_weight)
        throw std::logic_error("There is not enough space in the backpack!");
    _objects.push_back(obj);
    _total_weight += obj.get_weight();
    _current_object = &_objects.back();
}
void Backpack::throw_out_current_object() {
    if (!_current_object || _objects.is_empty())
        return;
    for (size_t i = 0; i < _objects.size(); i++) {
        if (&_objects[i] == _current_object) {
            _total_weight -= _objects[i].get_weight();
            _objects.erase(i);
            if (_current_object == _object_in_hand)
                _object_in_hand = nullptr;
            _current_object = nullptr;
            return;
        }
    }
    throw std::logic_error("The object was not found in the backpack!");
}
void Backpack::take_current_object() {
    if (!_current_object)
        throw std::logic_error("The current object is not selected!");
    _object_in_hand = _current_object;
}