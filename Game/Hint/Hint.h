// Copyright 2025 Maslennikova Mary

#include <string>

#ifndef GAME_HINT_HINT_H_
#define GAME_HINT_HINT_H_

class Hint {
    std::string _text;

public:
    Hint();
    Hint(std::string text);
    Hint(const Hint& other);

    ~Hint();

    void set_text(std::string text);

    const std::string get_text() const noexcept;
};

#endif  // GAME_HINT_HINT_H_

