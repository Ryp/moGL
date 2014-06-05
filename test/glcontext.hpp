#ifndef GLCONTEXT_INCLUDED
#define GLCONTEXT_INCLUDED

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>

typedef struct {
    unsigned int x;
    unsigned int y;
} Vect2u;

class GLContext
{
    static const int DefaultWindowWidth = 1280;
    static const int DefaultWindowHeight = 768;
    static const bool DefaultFullscreen = false;

public:
    GLContext();
    ~GLContext();

public:
    void            create(int width = DefaultWindowWidth, int height = DefaultWindowHeight, bool fullscreen = DefaultFullscreen);
    void            destroy();
    bool            isOpen();
    void            swapBuffers();

public:
    const Vect2u&   getWindowSize() const;
    double          getTime() const;
    Vect2u          getCursorPosition() const;
    void            setCursorPosition(const Vect2u& position);
    void            centerCursor();
    void            setTitle(const std::string& title);

public:
    void    printLog(bool full);

private:
    GLFWwindow*   _window;
    Vect2u        _windowSize;
};

#endif // GLCONTEXT_INCLUDED
