// Copyright 2025 Maslennikova Mary

#include <string>
#include <stdexcept>
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/Hint/Hint.h"

Hint::Hint() {
    _text = "";
}
Hint::Hint(std::string text) {
    _text = text;
}
Hint::Hint(const Hint& other) {
    if (&other == NULL)
        throw std::invalid_argument("The object was not received!\n");
    _text = other._text;
}

Hint::~Hint() {

}

void Hint::set_text(std::string text) {
    _text = text;
}

const std::string Hint::get_text() noexcept {
    return _text;
}