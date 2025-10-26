#pragma once

#include "Figure.hpp"
#include <cstddef>
#include <iostream>

class Array_of_figures{
    public:
        Array_of_figures() = default;

        Array_of_figures(size_t size);

        Array_of_figures(&&Array_of_figures other) noexcept;

        Array_of_figures(&Array_of_figures other);

        Array_of_figures& operator=(&Array_of_figures other);
        Array_of_figures& operator=(&Array_of_figures other);

        ~Array_of_figures();

        void add_figure(Figure* figure);
        void remove_figure(size_t index);

        Figure*& operator[](size_t index);
        Figure* operator[](size_t index);


    private:
        Figure** figures{nullptr};
        size_t size = 0;
        
        void resize();

}