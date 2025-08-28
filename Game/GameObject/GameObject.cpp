// Copyright 2025 Maslennikova Mary

#include <string>
#include <stdexcept>
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/MapObject/MapObject.h"
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/GameObject/GameObject.h"


GameObject::GameObject() : MapObject() {
    _weight = 0;
}
GameObject::GameObject(int x, int y, std::string image,
    objectType type, int weight) : MapObject(x, y, image, type) {
    _weight = weight;
}
GameObject::GameObject(const GameObject& other) : MapObject(other) {
    _weight = other._weight;
}

GameObject::~GameObject() {

}