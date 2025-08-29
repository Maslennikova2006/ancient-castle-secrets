// Copyright 2025 Maslennikova Mary

#include <string>

#ifndef GAME_MAPOBJECT_MAPOBJECT_H_
#define GAME_MAPOBJECT_MAPOBJECT_H_

enum objectType { room, people, game_object };
enum Direction { up, down, right, left};

class MapObject {
 protected:
    int _coord_x;
    int _coord_y;
    std::string _image;
    objectType _obj_type;

 public:
    MapObject();
    MapObject(int x, int y, std::string image, objectType type);
    MapObject(const MapObject& other);

    virtual ~MapObject();

    void set_coord_x(const int x);
    void set_coord_y(const int y);
    void set_image(const std::string& image);
    void set_type(const objectType type);

    const int get_coord_x() const noexcept;
    const int get_coord_y() const noexcept;
    const std::string get_image() const noexcept;
    const objectType get_type() const noexcept;

    void move_object(Direction direction);  // возможно стоит сделать виртуальным
};

#endif  // GAME_MAPOBJECT_MAPOBJECT_H_
