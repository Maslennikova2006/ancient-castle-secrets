// Copyright 2025 Maslennikova Mary

#include <string>
#include <stdexcept>
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/MapObject/MapObject.h"

MapObject::MapObject() {
    _coord_x = 0;
    _coord_y = 0;
    _image = "";
    _obj_type = game_object;
}
MapObject::MapObject(int x, int y, std::string image, objectType type) {
    _coord_x = x;
    _coord_y = y;
    _image = image;
    _obj_type = type;
}
MapObject::MapObject(const MapObject& other) {
    if (&other == NULL)
        throw std::invalid_argument("The object was not received!\n");
    _coord_x = other._coord_x;
    _coord_y = other._coord_y;
    _image = other._image;
    _obj_type = other._obj_type;
}

MapObject::~MapObject() {

}

void MapObject::set_coord_x(const int x) {
    // добавить проверку на границы в форме
    _coord_x = x;
}
void MapObject::set_coord_y(const int y) {
    // добавить проверку на границы в форме
    _coord_y = y;
}
void MapObject::set_image(const std::string& image) {
    _image = image;
}
void MapObject::set_type(const objectType type) {
    _obj_type = type;
}

const int MapObject::get_coord_x() noexcept {
    return _coord_x;
}
const int MapObject::get_coord_y() noexcept {
    return _coord_y;
}
const std::string MapObject::get_image() noexcept {
    return _image;
}
const objectType MapObject::get_type() noexcept {
    return _obj_type;
}

void MapObject::move_object(Direction direction) {
    switch (direction)
    {
    case up:
        _coord_y--;
        break;
    case down:
        _coord_y++;
        break;
    case right:
        _coord_x++;
        break;
    case left:
        _coord_x--;
        break;
    default:
        break;
    }
}