// Copyright 2025 Maslennikova Mary

#include <cstdlib>
#include <stdexcept>
#include <initializer_list>
#include <iostream>
#include <random>
#ifndef GAME_MYTVECTOR_TVECTOR_H_
#define GAME_MYTVECTOR_TVECTOR_H_

#define STEP_OF_CAPACITY 15
enum State { empty, busy, deleted };

template <class T> class TVector;
template <class T> void hoara_sort(TVector<T>& data);
template <class T> void hoara_sort_rec(TVector<T>&, size_t, size_t);
template <class T> int find_first_elem_by_index(const TVector<T>&, T);
template <class T> int find_last_elem_by_index(const TVector<T>& data, T value);
template <class T> int* find_elem_by_index(const TVector<T>& data, T value);
template <class T> T* find_first_elem_by_pointer(const TVector<T>&, T);
template <class T> T* find_last_elem_by_pointer(const TVector<T>&, T);
template <class T> TVector<T*> find_elem_by_pointer(const TVector<T>&, T);
template <class T> void shuffle(TVector<T>& data);

template <class T>
class TVector {
protected:
    T* _data;
    size_t _size;
    size_t _capacity;
    size_t _deleted;
    State* _states;

public:
    TVector();
    explicit TVector(size_t size);
    TVector(size_t size, const T* data);
    TVector(size_t size, std::initializer_list<T> data);
    TVector(std::initializer_list<T> data);
    TVector(const TVector<T>& other);

    ~TVector();

    inline T* data() noexcept;

    inline size_t size() const noexcept;
    inline size_t capacity() const noexcept;
    inline const T* data() const noexcept;
    inline const T& front();
    inline const T& back();
    inline const T* begin() const noexcept;
    inline const T* end() const noexcept;

    void reserve(size_t new_capacity) noexcept;
    void resize(size_t count) noexcept;
    void resize(size_t count, const T& value) noexcept;
    void shrink_to_fit() noexcept;

    void push_front(const T& value) noexcept;
    void insert(const size_t index, const T& value);
    void insert(const size_t index, size_t count, const T& value);
    void insert(const size_t index, std::initializer_list<T> data);
    void push_back(const T& value) noexcept;

    void pop_front();
    void erase(size_t index);
    void erase(const size_t first, const size_t last);
    void pop_back();
    void clear();

    void replace(size_t index, const T& value);
    void replace(const T* pointer, const T& value);

    const T& at(size_t index) const;
    void assign(size_t count, const T& value) noexcept;
    void assign(std::initializer_list<T> data) noexcept;

    TVector<T>& operator=(const TVector<T>& other) noexcept;
    bool operator!=(const TVector<T>& other) const noexcept;
    bool operator==(const TVector<T>& other) const noexcept;
    const T& operator[](size_t index) const;
    T& operator[](size_t index);

    inline bool is_empty() const noexcept;
    void print() const noexcept;

    friend void hoara_sort_rec<T>(TVector<T>& data, size_t left, size_t right);
    friend void hoara_sort<T>(TVector<T>& data);
    friend int find_first_elem_by_index<T>(const TVector<T>& data, T value);
    friend int find_last_elem_by_index<T>(const TVector<T>& data, T value);
    friend int* find_elem_by_index<T>(const TVector<T>& data, T value);
    friend T* find_first_elem_by_pointer<T>(const TVector<T>&, T);
    friend T* find_last_elem_by_pointer<T>(const TVector<T>& data, T value);
    friend TVector<T*> find_elem_by_pointer<T>(const TVector<T>& data, T value);
    friend void shuffle<T>(TVector<T>& data);

protected:
    inline bool is_full() const noexcept;
    void set_memory(size_t size) noexcept;
    void reallocation_memory(size_t count) noexcept;
    void reallocation_memory_for_deleted() noexcept;
    size_t rand_generation(size_t min, size_t max) const noexcept;
    size_t recalculate_the_position(size_t index) const noexcept;
    T* recalculate_the_address(size_t index) const noexcept;
    void move_the_elements(size_t begin, size_t end) noexcept;
    void shift_based_on_deleted(const size_t, const size_t) noexcept;
    void move_busy_cells(size_t new_capacity, size_t count) noexcept;
};

template <class T>
TVector<T>::TVector() {
    set_memory(0);
    _deleted = 0;
}
template <class T>
TVector<T>::TVector(size_t size) {
    set_memory(size);
    _deleted = 0;
}
template <class T>
TVector<T>::TVector(size_t size, const T* data) {
    set_memory(size);
    _deleted = 0;
    for (size_t i = 0; i < _size; i++) {
        _data[i] = data[i];
        _states[i] = busy;
    }
}
template <class T>
TVector<T>::TVector(size_t size, std::initializer_list<T> data) {
    set_memory(size);
    _deleted = 0;
    size_t index = 0;
    auto it = data.begin();
    for (index; it != data.end(); index++, it++) {
        _data[index] = *it;
        _states[index] = busy;
    }
    while (index < _size) {
        _data[index++] = 0;
    }
}
template <class T>
TVector<T>::TVector(std::initializer_list<T> data) {
    size_t size = data.size();
    set_memory(size);
    _deleted = 0;
    size_t index = 0;
    auto it = data.begin();
    for (index; it != data.end(); index++, it++) {
        _data[index] = *it;
        _states[index] = busy;
    }
    while (index < _size) {
        _data[index++] = 0;
    }
}
template <class T>
TVector<T>::TVector(const TVector<T>& other) {
    if (&other == NULL)
        throw std::invalid_argument("The object was not received!\n");
    set_memory(other._size);
    for (size_t i = 0, j = 0; i < other._size + other._deleted; i++) {
        if (other._states[i] == busy) {
            _data[j] = other._data[i];
            _states[j] = busy;
            if (j == other._size) {
                break;
            }
            j++;
        }
    }
    _deleted = 0;
}
template <class T>
TVector<T>::~TVector() {
    delete[] _data;
    delete[] _states;
}

template <class T>
inline T* TVector<T>::data() noexcept {
    return _data;
}

template <class T>
inline size_t TVector<T>::size() const noexcept {
    return _size;
}
template <class T>
inline size_t TVector<T>::capacity() const noexcept {
    return _capacity;
}
template <class T>
inline const T* TVector<T>::data() const noexcept {
    if (is_empty()) return nullptr;
    T* new_address = recalculate_the_address(0);
    return new_address;
}
template <class T>
inline const T& TVector<T>::front() {
    if (is_empty())
        throw std::invalid_argument
        ("There is no first element in the empty vector!\n");
    size_t new_index = recalculate_the_position(0);
    return _data[new_index];
}
template <class T>
inline const T& TVector<T>::back() {
    if (is_empty())
        throw std::invalid_argument
        ("There is no last element in the empty vector!\n");
    size_t new_index = recalculate_the_position(_size - 1);
    return _data[new_index];
}
template <class T>
inline const T* TVector<T>::begin() const noexcept {
    if (is_empty()) return nullptr;
    T* new_address = recalculate_the_address(0);
    return new_address;
}
template <class T>
inline const T* TVector<T>::end() const noexcept {
    if (is_empty()) return nullptr;
    T* new_address = recalculate_the_address(_size - 1) + 1;
    return new_address;
}

template <class T>
void TVector<T>::reserve(size_t new_capacity) noexcept {
    if (new_capacity <= _capacity) {
        return;
    }
    move_busy_cells(new_capacity, _size);
}
template <class T>
void TVector<T>::resize(size_t count) noexcept {
    if (count == _size) {
        return;
    }
    if (count < _size) {
        size_t new_capacity = (count / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;
        move_busy_cells(new_capacity, count);
    }
    if (count > _capacity) {
        reallocation_memory(count);
    }
    _size = count;
}
template <class T>
void TVector<T>::resize(size_t count, const T& value) noexcept {
    if (count == _size) {
        return;
    }
    if (count < _size) {
        size_t new_capacity = (count / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;
        move_busy_cells(new_capacity, count);
        return;
    }
    if (count > _capacity) {
        reallocation_memory(count);
    }
    size_t size = _size;
    _size = count;
    for (size_t i = size; i < _size; i++) {
        _data[i] = value;
        _states[i] = busy;
    }
}
template <class T>
void TVector<T>::shrink_to_fit() noexcept {
    if (_size == _capacity) {
        return;
    }
    move_busy_cells(_size, _size);
}

template <class T>
void TVector<T>::push_front(const T& value) noexcept {
    if (is_full()) {
        if (_deleted > 0) {
            size_t new_index = recalculate_the_position(0);
            shift_based_on_deleted(new_index, 1);
            _data[0] = value;
            _states[0] = busy;
            _size++;
            return;
        }
        else {
            reallocation_memory(_size + 1);
        }
    }
    size_t new_index = recalculate_the_position(0);
    _size++;
    move_the_elements(new_index, _size + _deleted - 1);
    _data[new_index] = value;
    _states[new_index] = busy;
}
template <class T>
void TVector<T>::insert(const size_t index, const T& value) {
    if (index > _size + _deleted)
        throw std::invalid_argument("The index goes beyond the boundaries\n");
    if (is_full()) {
        if (_deleted > 0) {
            size_t new_index = recalculate_the_position(index);
            shift_based_on_deleted(new_index, 1);
            _data[index] = value;
            _states[index] = busy;
            _size++;
            return;
        }
        else {
            reallocation_memory(_size + 1);
        }
    }
    size_t new_index = recalculate_the_position(index);
    _size++;
    move_the_elements(new_index, _size + _deleted - 1);
    _data[new_index] = value;
    _states[new_index] = busy;
}
template <class T>
void TVector<T>::insert(const size_t index, size_t count, const T& value) {
    if (index > _size + _deleted)
        throw std::invalid_argument("The index goes beyond the boundaries\n");
    if (_size + _deleted + count >= _capacity) {
        if (_deleted >= count) {
            size_t new_index = recalculate_the_position(index);
            shift_based_on_deleted(new_index, count);
            for (size_t i = 0; i < count; i++) {
                _data[index + i] = value;
                _states[index + i] = busy;
            }
            _size += count;
            return;
        }
        else {
            reallocation_memory(_size + count);
        }
    }
    size_t new_index = recalculate_the_position(index);
    for (size_t i = _size + _deleted; i > new_index; i--) {
        _data[i + count - 1] = _data[i - 1];
        _states[i + count - 1] = _states[i - 1];
    }
    for (size_t i = 0; i < count; i++) {
        _data[new_index + i] = value;
        _states[new_index + i] = busy;
    }
    _size += count;
}
template <class T>
void TVector<T>::insert(const size_t index, std::initializer_list<T> data) {
    if (index > _size)
        throw std::invalid_argument("The index goes beyond the boundaries\n");
    if (_size + _deleted + data.size() >= _capacity) {
        if (_deleted >= data.size()) {
            size_t new_index = recalculate_the_position(index);
            shift_based_on_deleted(new_index, data.size());
            auto it = data.begin();
            for (size_t i = 0; i < data.size(); i++) {
                _data[index + i] = *(it + i);
                _states[index + i] = busy;
            }
            _size += data.size();
            return;
        }
        else {
            reallocation_memory(_size + data.size());
        }
    }
    size_t new_index = recalculate_the_position(index);
    for (size_t i = _size + _deleted; i > new_index; i--) {
        _data[i + data.size() - 1] = _data[i - 1];
        _states[i + data.size() - 1] = _states[i - 1];
    }
    auto it = data.begin();
    for (size_t i = 0; i < data.size(); i++) {
        _data[new_index + i] = *(it + i);
        _states[new_index + i] = busy;
    }
    _size += data.size();
}
template <class T>
void TVector<T>::push_back(const T& value) noexcept {
    if (is_full()) {
        if (_deleted > 0) {
            size_t new_index = recalculate_the_position(_size - 1) + 1;
            shift_based_on_deleted(new_index, 1);
            _data[_size] = value;
            _states[_size] = busy;
            _size++;
            return;
        }
        else {
            reallocation_memory(_size + 1);
        }
    }
    size_t new_index = recalculate_the_position(_size - 1) + 1;
    _data[new_index] = value;
    _states[new_index] = busy;
    _size++;
}

template <class T>
void TVector<T>::pop_front() {
    if (is_empty())
        throw std::invalid_argument("Cannot be deleted from an empty vector\n");
    size_t new_index = recalculate_the_position(0);
    _states[new_index] = deleted;
    _deleted++;
    _size--;
    if (_deleted >= 0.10 * (_size + _deleted)) {
        reallocation_memory_for_deleted();
    }
}
template <class T>
void TVector<T>::erase(size_t index) {
    if (is_empty())
        throw std::invalid_argument("Cannot be deleted from an empty vector\n");
    if (index >= _size)
        throw std::invalid_argument("The index goes beyond the boundaries\n");
    size_t new_index = recalculate_the_position(index);
    if (index == _size - 1) {
        _states[new_index] = empty;
    }
    else {
        _states[new_index] = deleted;
        _deleted++;
    }
    _size--;
    if (_deleted >= 0.10 * (_size + _deleted)) {
        reallocation_memory_for_deleted();
    }
}
template <class T>
void TVector<T>::erase(const size_t first, const size_t last) {
    if (is_empty())
        throw std::invalid_argument("Cannot be deleted from an empty vector\n");
    if (first > last || last >= _size)
        throw std::invalid_argument("The index goes beyond the boundaries\n");
    size_t new_first = recalculate_the_position(first);
    size_t new_last = recalculate_the_position(last);
    size_t count_busy_deleted = 0;
    for (size_t i = new_first; i <= new_last; i++) {
        if (_states[i] == busy) {
            _states[i] = deleted;
            count_busy_deleted++;
        }
    }
    _deleted += count_busy_deleted;
    _size -= count_busy_deleted;
    if (_deleted >= 0.10 * (_size + _deleted)) {
        reallocation_memory_for_deleted();
    }
}
template <class T>
void TVector<T>::pop_back() {
    if (is_empty())
        throw std::invalid_argument("Cannot be deleted from an empty vector\n");
    size_t new_index = recalculate_the_position(_size - 1);
    _states[new_index] = empty;
    _size--;
}
template <class T>
void TVector<T>::clear() {
    if (is_empty())
        throw std::invalid_argument("Cannot be deleted from an empty vector\n");
    for (size_t i = 0; i < _size + _deleted; i++) {
        _states[i] = empty;
    }
    _deleted = 0;
    _size = 0;
}

template <class T>
void TVector<T>::replace(size_t index, const T& value) {
    if (is_empty())
        throw std::invalid_argument
        ("It is impossible to replace an element in an empty vector\n");
    if (index >= _size + _deleted)
        throw std::invalid_argument("The index goes beyond the boundaries\n");
    size_t new_index = recalculate_the_position(index);
    _data[new_index] = value;
}
template <class T>
void TVector<T>::replace(const T* pointer, const T& value) {
    if (is_empty())
        throw std::invalid_argument
        ("It is impossible to replace an element in an empty vector\n");
    if (pointer < begin() || pointer >= end())
        throw std::invalid_argument("The index goes beyond the boundaries\n");
    size_t index = pointer - begin();
    if (_states[index] != busy)
        throw std::invalid_argument("The item has already been deleted\n");
    T* new_pointer = recalculate_the_address(index);
    *new_pointer = value;
}

template <class T>
const T& TVector<T>::at(size_t index) const {
    if (index >= _size + _deleted) {
        throw std::invalid_argument("The index goes beyond the boundaries\n");
    }
    size_t new_index = recalculate_the_position(index);
    return _data[new_index];
}
template <class T>
void TVector<T>::assign(size_t count, const T& value) noexcept {
    size_t capacity = (count / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;
    if (_capacity != capacity) {
        reallocation_memory(count);
    }
    else {
        _size = count;
    }
    size_t i = 0;
    while (i < count) {
        _data[i] = value;
        _states[i] = busy;
        i++;
    }
    while (i < _capacity) {
        _states[i++] = empty;
    }
    _deleted = 0;
}
template <class T>
void TVector<T>::assign(std::initializer_list<T> data) noexcept {
    size_t size = data.size();
    size_t capacity = (size / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;
    if (_capacity != capacity) {
        reallocation_memory(size);
    }
    else {
        _size = size;
    }
    size_t i = 0;
    auto it = data.begin();
    for (i; it != data.end(); i++, it++) {
        _data[i] = *it;
        _states[i] = busy;
    }
    while (i < _capacity) {
        _states[i++] = empty;
    }
    _deleted = 0;
}

template <class T>
TVector<T>& TVector<T>::operator=(const TVector<T>& other) noexcept {
    if (this == &other)
        return *this;
    size_t size = other._size;
    size_t capacity = (size / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;
    if (_capacity != capacity) {
        reallocation_memory(size);
    }
    else {
        _size = size;
    }
    size_t j = 0;
    for (size_t i = 0; i < size + other._deleted; i++) {
        if (other._states[i] == busy) {
            _data[j] = other._data[i];
            _states[j] = busy;
            if (j == size) {
                break;
            }
            j++;
        }
    }
    while (j < _capacity) {
        _states[j++] = empty;
    }
    _deleted = 0;
    return *this;
}
template <class T>
bool TVector<T>::operator!=(const TVector<T>& other) const noexcept {
    return !(this->operator==(other));
}
template <class T>
bool TVector<T>::operator==(const TVector<T>& other) const noexcept {
    if (_size != other._size) {
        return false;
    }
    size_t i = 0, j = 0;

    while (i < _capacity && j < other._capacity) {
        while (i < _capacity && _states[i] != busy)
            i++;
        while (j < other._capacity && other._states[j] != busy)
            j++;
        if (_data[i] != other._data[j]) {
            return false;
        }
        i++;
        j++;
    }
    return true;
}
template <class T>
const T& TVector<T>::operator[](size_t index) const {
    size_t new_index = recalculate_the_position(index);
    return _data[new_index];
}
template <class T>
T& TVector<T>::operator[](size_t index) {
    size_t new_index = recalculate_the_position(index);
    return _data[new_index];
}

template <class T>
inline bool TVector<T>::is_empty() const noexcept {
    return _size == 0;
}
template <class T>
void TVector<T>::print() const noexcept {
    for (size_t i = 0; i < _size + _deleted; i++) {
        if (_states[i] == busy)
            std::cout << _data[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
inline bool TVector<T>::is_full() const noexcept {
    return (_size + 1 + _deleted) >= _capacity;
}
template <class T>
void TVector<T>::set_memory(size_t size) noexcept {
    _size = size;
    _capacity = (_size / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;
    _data = new T[_capacity];
    _states = new State[_capacity];
    for (size_t i = 0; i < _capacity; i++) {
        _states[i] = empty;
    }
}
template <class T>
void TVector<T>::reallocation_memory(size_t count) noexcept {
    size_t new_capacity = (count / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;
    reserve(new_capacity);
}
template <class T>
void TVector<T>::reallocation_memory_for_deleted() noexcept {
    size_t capacity = (_size / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;
    if (_capacity == capacity) return;
    _capacity = capacity;
    T* new_data = new T[_capacity];
    State* new_states = new State[_capacity];
    for (int i = 0, j = 0; i < _size + _deleted; i++) {
        if (_states[i] == busy) {
            new_data[j] = _data[i];
            new_states[j] = busy;
            j++;
        }
    }
    set_memory(_size);
    for (int i = 0; i < _size; i++) {
        _data[i] = new_data[i];
        _states[i] = new_states[i];
    }
    delete[] new_data;
    delete[] new_states;
    _deleted = 0;
}
template <class T>
void my_swap(T& first_number, T& second_number) noexcept {
    T tmp = first_number;
    first_number = second_number;
    second_number = tmp;
}
template <class T>
size_t TVector<T>::rand_generation(size_t min, size_t max) const noexcept {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dist(min, max);
    return dist(gen);
}
template <class T>
size_t TVector<T>::recalculate_the_position(size_t index) const noexcept {
    if (_deleted == 0) return index;
    size_t count_busy = 0;
    for (size_t i = 0; i < _size + _deleted; i++) {
        if (_states[i] == busy) {
            if (index == count_busy)
                return i;
            count_busy++;
        }
    }
}
template <class T>
T* TVector<T>::recalculate_the_address(size_t index) const noexcept {
    if (_deleted == 0) return &_data[index];
    size_t count_busy = 0;
    for (size_t i = 0; i < _size + _deleted; i++) {
        if (_states[i] == busy) {
            if (index == count_busy)
                return &_data[i];
            count_busy++;
        }
    }
}
template <class T>
void TVector<T>::move_the_elements(size_t begin, size_t end) noexcept {
    for (size_t i = end; i > begin; i--) {
        _data[i] = _data[i - 1];
        _states[i] = _states[i - 1];
    }
}
template <class T>
void TVector<T>::shift_based_on_deleted
(const size_t start_index, const size_t count) noexcept {
    size_t busy_count = 0;
    for (size_t i = 0; i < _size + _deleted; i++) {
        if (_states[i] == busy) {
            _data[busy_count] = _data[i];
            _states[busy_count] = busy;
            busy_count++;
        }
    }
    if (start_index < busy_count) {
        for (size_t i = busy_count; i > start_index; i--) {
            _data[i + count - 1] = _data[i - 1];
            _states[i + count - 1] = busy;
        }
        for (size_t i = start_index; i < start_index + count; i++) {
            _states[i] = deleted;
        }
    }
    _deleted -= count;
}
template <class T>
void TVector<T>::move_busy_cells(size_t new_capacity, size_t count) noexcept {
    T* new_data = new T[new_capacity];
    State* new_states = new State[new_capacity];
    size_t j = 0;
    for (size_t i = 0; i < _size + _deleted; i++) {
        if (_states[i] == busy) {
            new_data[j] = _data[i];
            new_states[j] = busy;
            if (j == count) {
                break;
            }
            j++;
        }
    }
    for (int i = j; i < new_capacity; i++) {
        new_states[i] = empty;
    }
    delete[] _data;
    delete[] _states;
    _data = new_data;
    _states = new_states;
    _capacity = new_capacity;
    _deleted = 0;
}

template <class T>
void hoara_sort(TVector<T>& data) {
    if (data.size() < 2) return;
    hoara_sort_rec(data, 0, data.size() - 1);
}
template <class T>
void hoara_sort_rec(TVector<T>& data, size_t left, size_t right) {
    if (left < right) {
        size_t base = (left + right) / 2;
        size_t l = left, r = right;
        const T base_value = data[base];
        while (l <= r) {
            while (data._data[l] < base_value) {
                l++;
            }
            while (data._data[r] > base_value) {
                r--;
            }
            if (l <= r) {
                my_swap(data._data[l], data._data[r]);
                my_swap(data._states[l], data._states[r]);
                l++;
                if (r > 0)
                    r--;
            }
            else {
                break;
            }
        }
        hoara_sort_rec(data, left, r);
        hoara_sort_rec(data, l, right);
    }
}
template<class T>
int find_first_elem_by_index(const TVector<T>& data, T value) {
    size_t count_deleted = 0;
    for (size_t i = 0; i < data._size + data._deleted; i++) {
        if (data._states[i] == deleted)
            count_deleted++;
        if (data._data[i] == value && data._states[i] == busy) {
            return i - count_deleted;
        }
    }
    return -1;
}
template <class T>
int find_last_elem_by_index(const TVector<T>& data, T value) {
    size_t count_deleted = 0;
    for (int i = data._size + data._deleted - 1; i >= 0; i--) {
        if (data._states[i] != busy)
            count_deleted++;
        if (data._data[i] == value && data._states[i] == busy)
            return i - data._deleted + count_deleted;
    }
    return -1;
}
template <class T>
int* find_elem_by_index(const TVector<T>& data, T value) {
    int count_repetitions = 0;
    for (size_t i = 0; i < data._size + data._deleted; i++) {
        if (data._data[i] == value && data._states[i] == busy) {
            count_repetitions++;
        }
    }
    size_t count_deleted = 0;
    int* result = new int[count_repetitions + 1];
    result[0] = count_repetitions;
    if (count_repetitions > 0) {
        size_t  index = 1;
        for (size_t i = 0; i < data._size + data._deleted; i++) {
            if (data._states[i] == deleted)
                count_deleted++;
            if (data._data[i] == value && data._states[i] == busy) {
                result[index++] = i - count_deleted;
            }
        }
    }
    return result;
}
template <class T>
T* find_first_elem_by_pointer(const TVector<T>& data, T value) {
    size_t count_deleted = 0;
    for (size_t i = 0; i < data._size + data._deleted; i++) {
        if (data._data[i] == value && data._states[i] == busy) {
            return &data._data[i];
        }
    }
    return nullptr;
}
template <class T>
T* find_last_elem_by_pointer(const TVector<T>& data, T value) {
    size_t count_deleted = 0;
    for (int i = data._size + data._deleted - 1; i >= 0; i--) {
        if (data._data[i] == value && data._states[i] == busy)
            return &data._data[i];
    }
    return nullptr;
}
template <class T>
TVector<T*> find_elem_by_pointer(const TVector<T>& data, T value) {
    size_t count_repetitions = 0;
    for (size_t i = 0; i < data._size + data._deleted; i++) {
        if (data._data[i] == value && data._states[i] == busy) {
            count_repetitions++;
        }
    }
    size_t count_deleted = 0;
    TVector<T*> result;
    if (count_repetitions > 0) {
        size_t  index = 0;
        for (size_t i = 0; i < data._size + data._deleted; i++) {
            if (data._data[i] == value && data._states[i] == busy) {
                result.insert(index, &data._data[i]);
                index++;
            }
        }
    }
    return result;
}
template <class T>
void shuffle(TVector<T>& data) {
    int i, rand_i;
    for (i = 0; i < data._size + data._deleted; i++) {
        rand_i = data.rand_generation(0, data._size + data._deleted - 1);
        my_swap(data._data[i], data._data[rand_i]);
        my_swap(data._states[i], data._states[rand_i]);
    }
}
#endif  // GAME_MYTVECTOR_TVECTOR_H_

