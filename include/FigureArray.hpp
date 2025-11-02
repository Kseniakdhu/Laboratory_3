#pragma once

#include "Figure.hpp"
#include <cstddef>
#include <iostream>

class FigureArray{
    public:
        FigureArray();

        FigureArray(size_t size);

        FigureArray(FigureArray&& other) noexcept;

        FigureArray(const FigureArray& other);

        FigureArray& operator=(const FigureArray& other);

        FigureArray& operator=(FigureArray&& other) noexcept;

        bool operator==(const FigureArray& other) const;


        ~FigureArray();

        void add_figure(Figure* figure);
        void remove_figure(size_t index);


        Figure*& operator[](size_t index);
        Figure* operator[](size_t index) const;
        void deep_copy(const FigureArray& other);
        double total_area() const;
        void total_center() const;
        Figure& get_figure(size_t index);
        size_t size2() const;


    private:
        Figure** figures{nullptr}; 
        size_t size = 0;
        int cap = 0;
        void resize();
};