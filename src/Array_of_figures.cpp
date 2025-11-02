#include <initializer_list>
#include <iostream>
#include "../include/FigureArray.hpp"
#include <algorithm>
#include <stdexcept>
#include <utility>


FigureArray:: FigureArray() : figures(nullptr), cap(0), size(0) {}

FigureArray:: ~FigureArray() {
    for (size_t i = 0; i < size; ++i) {
        delete figures[i];
    }
    delete[] figures;
}
    
FigureArray:: FigureArray(const FigureArray& other)   {
    deep_copy(other);
}

FigureArray::FigureArray(FigureArray&& other) noexcept {
    figures = new Figure*[other.cap];
    cap = other.cap;
    size = other.size;
    for (size_t i = 0; i < size; ++i) {
        figures[i] = other.figures[i];
    }
    other.figures = nullptr;
    other.size = 0;
    other.cap = 0;
}

FigureArray& FigureArray::operator=(const FigureArray& other) {
    if (this != &other) {
        for (size_t i = 0; i < size; ++i) {
            delete figures[i];
        }
        delete[] figures;
        
        deep_copy(other);
    }
    return *this;
}

Figure*& FigureArray::operator[](size_t index) {
    if (index >= size) {
        throw out_of_range("Index out of range");
    }
    return figures[index];
}

Figure* FigureArray::operator[](size_t index) const {
    if (index >= size) {
        throw out_of_range("Index out of range");
    }
    return figures[index];
}

    
bool FigureArray::operator==(const FigureArray& other) const{
    if (size != other.size) return false;
    for (size_t i = 0; i < size; ++i){
        if (*figures[i] != *other.figures[i]) return false;
    }
    return true;
}

void FigureArray::add_figure(Figure* figure) {
    if (size >= cap) {
        resize();
    }
    figures[size++] = figure;
}
    
double FigureArray::total_area() const {
    double total = 0;
    for (size_t i = 0; i < size; ++i) {
        total += figures[i]->area();
    }
    return total;
    }
    
void FigureArray::total_center() const {
    for (size_t i = 0; i < size; ++i) {
        Point center = figures[i]->geometric_center();
        std::cout << "Figure " << i << " center: (" 
                    << center.getX() << ", " << center.getY() << ")" << std::endl;
    }
}
void FigureArray::resize() {
    cap = (cap == 0) ? 2 : cap * 2;
    Figure** newFigures = new Figure*[cap];
    
    for (size_t i = 0; i < size; ++i) {
        newFigures[i] = figures[i];
    }
    
    delete[] figures;
    figures = newFigures;
}
    
size_t FigureArray::size2() const {
    return size;
    }
    

Figure& FigureArray::get_figure(size_t index) {
    if (index >= size || figures[index] == nullptr) {
        throw std::out_of_range("Index out of range");
    }
    return *figures[index];
}
    
void FigureArray::remove_figure(size_t index) {
    if (index < size) {
        delete figures[index];
        for (size_t i = index; i < size - 1; ++i) {
            figures[i] = figures[i + 1];
        }
        --size;
    }
}

void FigureArray::deep_copy(const FigureArray& other) {
    cap = other.cap;
    size = other.size;
    figures = new Figure*[cap];
    for (size_t i = 0; i < size; ++i) {
        figures[i] = other.figures[i]->clone();
    }
}

FigureArray& FigureArray::operator=(FigureArray&& other) noexcept {
    if (this != &other){
        for (size_t i = 0; i < size; ++i) {
        delete figures[i];
        }
    delete[] figures;
    figures = other.figures;
    size = other.size;
    cap = other.cap;
    other.figures = nullptr;
    other.size = 0;
    other.cap = 0;
    }
    return *this;
}
