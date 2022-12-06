#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "core/sdlmanager.hpp"

namespace Graphics
{
    class Rectangle {
    public:
        Rectangle(int x, int y, int w, int h);
        Rectangle(int w, int h);
        int x;
        int y;
        int w;
        int h;
        void middle();
        void dock(float x, float y);
        void scale(float w, float h);
        void add(int px);
    };

    class Region
    {
    public:
        Region(SDL_Surface* surface);
        ~Region();
        void draw(int x, int y, int w, int h);
        void draw(int x, int y);
        void draw();
        void draw(Rectangle rect);
    private:
        SDL_Texture* texture;
        int width;
        int height;
    };

    class Slice9
    {
    public:
        Slice9(
            int sz,
            Region* s0,
            Region* s1,
            Region* s2,
            Region* s3,
            Region* s4,
            Region* s5,
            Region* s6,
            Region* s7,
            Region* s8
        );
        ~Slice9();
        void draw(int x, int y, int w, int h);
        void draw(Rectangle rect);
    private:
        int size;
        Region* slice0;
        Region* slice1;
        Region* slice2;
        Region* slice3;
        Region* slice4;
        Region* slice5;
        Region* slice6;
        Region* slice7;
        Region* slice8;
    };

    class Sheet
    {
    public:
        Sheet(std::string path);
        ~Sheet();
        Region getRegion(int x, int y, int w, int h);
        Region* getRegionPointer(int x, int y, int w, int h);
        Slice9 getSlice9(int x, int y, int size);
        Slice9* getSlice9Pointer(int x, int y, int size);
    private:
        SDL_Surface* surface;
    };

    void setDrawColor(int r, int g, int b, int a);
    void setDrawColor(int r, int g, int b);
    void drawRectangle(int x, int y, int w, int h);
    void drawRectangle(Rectangle rect);
};
