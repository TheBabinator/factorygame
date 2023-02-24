#include "core/graphics.hpp"
#include "core/sdlmanager.hpp"

namespace Graphics
{
    Rectangle::Rectangle(int cx, int cy, int cw, int ch)
    {
        x = cx;
        y = cy;
        w = cw;
        h = ch;
    }

    Rectangle::Rectangle(int cw, int ch)
    {
        x = 0;
        y = 0;
        w = cw;
        h = ch;
    }

    void Rectangle::middle()
    {
        x -= (int)((float)w * 0.5);
        y -= (int)((float)h * 0.5);
    }

    void Rectangle::dock(float dx, float dy)
    {
        x += (int)((float)SDLManager::screenWidth * dx);
        y += (int)((float)SDLManager::screenHeight * dy);
    }

    void Rectangle::scale(float dw, float dh)
    {
        w += (int)((float)SDLManager::screenWidth * dw);
        h += (int)((float)SDLManager::screenHeight * dh);
    }

    void Rectangle::add(int px)
    {
        x -= px;
        y -= px;
        w += px * 2;
        h += px * 2;
    }

    Rectanglef::Rectanglef(float cx, float cy, float cw, float ch)
    {
        x = cx;
        y = cy;
        w = cw;
        h = ch;
    }

    Rectanglef::Rectanglef(float cw, float ch)
    {
        x = 0;
        y = 0;
        w = cw;
        h = ch;
    }

    Region::Region(SDL_Surface* surface)
    {
        texture = SDL_CreateTextureFromSurface(SDLManager::renderer, surface);
        width = surface->w;
        height = surface->h;
    }

    Region::~Region()
    {
        // std::cout << "region destroyed" << std::endl;
        SDL_DestroyTexture(texture);
    }

    void Region::draw(int x, int y, int w, int h)
    {
        SDL_Rect rect;
        rect.x = x;
        rect.y = y;
        rect.w = w;
        rect.h = h;
        SDL_RenderCopy(SDLManager::renderer, texture, nullptr, &rect);
    }

    void Region::draw(int x, int y)
    {
        draw(x, y, width, height);
    }

    void Region::draw()
    {
        draw(0, 0, width, height);
    }

    void Region::draw(Rectangle rect)
    {
        draw(rect.x, rect.y, rect.w, rect.h);
    }

    Slice9::Slice9(
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
    )
    {
        size = sz;
        slice0 = s0;
        slice1 = s1;
        slice2 = s2;
        slice3 = s3;
        slice4 = s4;
        slice5 = s5;
        slice6 = s6;
        slice7 = s7;
        slice8 = s8;
    }

    Slice9::~Slice9()
    {
        // std::cout << "slice9 destroyed" << std::endl;
        delete slice0;
        delete slice1;
        delete slice2;
        delete slice3;
        delete slice4;
        delete slice5;
        delete slice6;
        delete slice7;
        delete slice8;
    }

    void Slice9::draw(int x, int y, int w, int h)
    {
        slice0->draw(x,            y           , size,            size);
        slice1->draw(x + size,     y           , w - size - size, size);
        slice2->draw(x + w - size, y           , size,            size);
        slice3->draw(x,            y + size    , size,            h - size - size);
        slice4->draw(x + size,     y + size    , w - size - size, h - size - size);
        slice5->draw(x + w - size, y + size    , size,            h - size - size);
        slice6->draw(x,            y + h - size, size,            size);
        slice7->draw(x + size,     y + h - size, w - size - size, size);
        slice8->draw(x + w - size, y + h - size, size,            size);
    }

    void Slice9::draw(Rectangle rect)
    {
        draw(rect.x, rect.y, rect.w, rect.h);
    }

    Sheet::Sheet(std::string path)
    {
        // std::cout << "loading sprite at " << path << std::endl;
        surface = IMG_Load(path.c_str());
    }

    Sheet::~Sheet()
    {
        // std::cout << "sheet destroyed" << std::endl;
        SDL_FreeSurface(surface);
    }

    Region Sheet::getRegion(int x, int y, int w, int h)
    {
        SDL_Rect rect;
        rect.x = x;
        rect.y = y;
        rect.w = w;
        rect.h = h;
        #if SDL_BYTEORDER == SDL_BIG_ENDIAN
        SDL_Surface* regionSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, w, h, 32, 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
        #else
        SDL_Surface* regionSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, w, h, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
        #endif
        SDL_BlitSurface(surface, &rect, regionSurface, nullptr);
        Region region = Region(regionSurface);
        SDL_FreeSurface(regionSurface);
        return region;
    }

    Region* Sheet::getRegionPointer(int x, int y, int w, int h)
    {
        SDL_Rect rect;
        rect.x = x;
        rect.y = y;
        rect.w = w;
        rect.h = h;
        #if SDL_BYTEORDER == SDL_BIG_ENDIAN
        SDL_Surface* regionSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, w, h, 32, 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
        #else
        SDL_Surface* regionSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, w, h, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
        #endif
        SDL_BlitSurface(surface, &rect, regionSurface, nullptr);
        Region* region = new Region(regionSurface);
        SDL_FreeSurface(regionSurface);
        return region;
    }

    Slice9 Sheet::getSlice9(int x, int y, int size)
    {
        Region* r0 = getRegionPointer(x,               y,               size, size);
        Region* r1 = getRegionPointer(x + size,        y,               size, size);
        Region* r2 = getRegionPointer(x + size + size, y,               size, size);
        Region* r3 = getRegionPointer(x,               y + size,        size, size);
        Region* r4 = getRegionPointer(x + size,        y + size,        size, size);
        Region* r5 = getRegionPointer(x + size + size, y + size,        size, size);
        Region* r6 = getRegionPointer(x,               y + size + size, size, size);
        Region* r7 = getRegionPointer(x + size,        y + size + size, size, size);
        Region* r8 = getRegionPointer(x + size + size, y + size + size, size, size);
        return Slice9(size, r0, r1, r2, r3, r4, r5, r6, r7, r8);
    }

    Slice9* Sheet::getSlice9Pointer(int x, int y, int size)
    {
        Region* r0 = getRegionPointer(x,               y,               size, size);
        Region* r1 = getRegionPointer(x + size,        y,               size, size);
        Region* r2 = getRegionPointer(x + size + size, y,               size, size);
        Region* r3 = getRegionPointer(x,               y + size,        size, size);
        Region* r4 = getRegionPointer(x + size,        y + size,        size, size);
        Region* r5 = getRegionPointer(x + size + size, y + size,        size, size);
        Region* r6 = getRegionPointer(x,               y + size + size, size, size);
        Region* r7 = getRegionPointer(x + size,        y + size + size, size, size);
        Region* r8 = getRegionPointer(x + size + size, y + size + size, size, size);
        return new Slice9(size, r0, r1, r2, r3, r4, r5, r6, r7, r8);
    }

    void setDrawColor(int r, int g, int b, int a)
    {
        SDL_SetRenderDrawColor(SDLManager::renderer, r, g, b, a);
    }

    void setDrawColor(int r, int g, int b)
    {
        setDrawColor(r, g, b, 0xFF);
    }

    void drawRectangle(int x, int y, int w, int h)
    {
        SDL_Rect rect;
        rect.x = x;
        rect.y = y;
        rect.w = w;
        rect.h = h;

        SDL_RenderFillRect(SDLManager::renderer, &rect);
    }

    void drawRectangle(Rectangle rect)
    {
        drawRectangle(rect.x, rect.y, rect.w, rect.h);
    }

    float cameraX = 0;
    float cameraY = 0;
    float cameraZoom = 32.0;

    Rectangle project(Rectangle rect)
    {
        return Rectangle(
            (rect.x - cameraX - 0.5) * cameraZoom + SDLManager::screenWidth / 2.0 + 0.5,
            (rect.y - cameraY - 0.5) * cameraZoom + SDLManager::screenHeight / 2.0 + 0.5,
            rect.w * cameraZoom + 0.5,
            rect.w * cameraZoom + 0.5
        );
    }

    Rectangle project(Rectanglef rect)
    {
        return Rectangle(
            (rect.x - cameraX - 0.5) * cameraZoom + SDLManager::screenWidth / 2.0 + 0.5,
            (rect.y - cameraY - 0.5) * cameraZoom + SDLManager::screenHeight / 2.0 + 0.5,
            rect.w * cameraZoom + 0.5,
            rect.w * cameraZoom + 0.5
        );
    }
}
