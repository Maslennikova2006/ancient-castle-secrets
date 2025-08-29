// Copyright 2025 Maslennikova Mary

#include <string>

#ifndef GAME_TASK_TASK_H_
#define GAME_TASK_TASK_H_

class Task {
    std::string _text;
    std::string _answer;
    std::string _right_answer;

public:
    Task();
    Task(std::string text, std::string answer, std::string right_answer);
    Task(const Task& other);

    ~Task();

    void set_text(std::string text);
    void set_answer(std::string answer);
    void set_right_answer(std::string answer);

    const std::string get_text() const noexcept;
    const std::string get_answer() const noexcept;
    const std::string get_right_answer() const noexcept;
};

#endif  // GAME_TASK_TASK_H_

