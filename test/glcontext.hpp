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
public:
    GLContext();
    ~GLContext();

public:
    void            create(int width, int height, bool fullscreen = false);
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
