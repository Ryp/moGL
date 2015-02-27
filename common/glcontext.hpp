#ifndef GLCONTEXT_INCLUDED
#define GLCONTEXT_INCLUDED

#include <string>

class GLFWwindow;

struct Vect2u {
    unsigned int x;
    unsigned int y;
    Vect2u(unsigned int x_, unsigned int y_) : x(x_), y(y_) {}
};

class GLContext
{
public:
    GLContext();

public:
    void    create(unsigned int width, unsigned int height, unsigned int major, unsigned int minor, bool fullscreen = false, bool debug = false);
    void    destroy(); // Call this only when closing manually
    bool    isOpen();
    void    swapBuffers();
    void    makeCurrent();

public:
    const Vect2u&   getWindowSize() const;
    double          getTime() const;
    Vect2u          getCursorPosition() const;
    void            setCursorPosition(const Vect2u& position);
    void            centerCursor();
    void            setTitle(const std::string& title);

private:
    GLFWwindow* _window;
    Vect2u      _windowSize;
};

#endif // GLCONTEXT_INCLUDED
