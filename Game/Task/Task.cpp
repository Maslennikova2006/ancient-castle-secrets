// Copyright 2025 Maslennikova Mary

#include <string>
#include <stdexcept>
#include "/GitHub/Summer_game/ancient-castle-secrets/Game/Task/Task.h"

Task::Task() {
    _text = "";
    _answer = "";
    _right_answer = "";
}
Task::Task(std::string text, std::string answer, std::string right_answer) {
    _text = text;
    _answer = answer;
    _right_answer = right_answer;
}
Task::Task(const Task& other) {
    if (&other == NULL)
        throw std::invalid_argument("The object was not received!\n");
    _text = other._text;
    _answer = other._answer;
    _right_answer = other._right_answer;
}

Task::~Task() {

}

void Task::set_text(std::string text) {
    _text = text;
}
void Task::set_answer(std::string answer) {
    _answer = answer;
}
void Task::set_right_answer(std::string answer) {
    _right_answer = answer;
}

const std::string Task::get_text() noexcept {
    return _text;
}
const std::string Task::get_answer() noexcept {
    return _answer;
}
const std::string Task::get_right_answer() noexcept {
    return _right_answer;
}