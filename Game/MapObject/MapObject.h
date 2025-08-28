// Copyright 2025 Maslennikova Mary

#include <string>

#ifndef GAME_MAPOBJECT_MAPOBJECT_H_
#define GAME_MAPOBJECT_MAPOBJECT_H_

enum objectType { room, people, game_object };

class MapObject {
 protected:
    int _coord_x;
    int _coord_y;
    std::string _image;
    objectType _type;

 public:
    MapObject();
    MapObject(int x, int y, std::string image, objectType type);

    ~MapObject();

    void move_object();
};

#endif  // GAME_MAPOBJECT_MAPOBJECT_H_
