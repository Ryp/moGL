#ifndef GLCONTEXT_INCLUDED
#define GLCONTEXT_INCLUDED

#include <string>

#include <glbinding/gl/gl.h>
using namespace gl;

class GLFWwindow;

typedef struct {
    unsigned int x;
    unsigned int y;
} Vect2u;

class GLContext
{
public:
    GLContext();

public:
    void            create(unsigned int width, unsigned int height, bool fullscreen = false);
    void            destroy(); // Call this only when closing manually
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
