# MoGL [![Build Status](https://travis-ci.org/Ryp/moGL.svg?branch=master)](https://travis-ci.org/Ryp/moGL) [![Join the chat at https://gitter.im/Ryp/moGL](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/Ryp/moGL?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

Modern OpenGL wrapper, thin C++14 header-only layer on top of the OpenGL 4.5+ core spec.

Doxygen available [here](http://ryp.github.io/moGL/).

## Features

MoGL takes **full advantage of the 4.5 core spec**, using [DSA](https://www.opengl.org/registry/specs/ARB/direct_state_access.txt) an RAII idioms in all object wrappers, limiting effectively side effects from OpenGL states. Say goodbye to `glBind*()` !

It keeps most of the **syntax intact**, including enums and types, but improving and shortening it when it makes the most sense. Porting existing GL code to MoGL is **easy** !

**Performance is predictable**, as it is a thin layer that doesn't do a lot of processing behind your back. In most cases, one MoGL call = one gl* call.

### Practical example

Texture creation
```cpp
GLuint myTex;

glGenTextures(1, &myTex);
glBindTexture(GL_TEXTURE_2D, myTex);
glTexStorage2D(GL_TEXTURE_2D, 1, GL_RGB16F, 1024, 1024);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

glDeleteTextures(1, &myTex);
```
To MoGL
```cpp
mogl::Texture   myTex(GL_TEXTURE_2D);

myTex.setStorage2D(1, GL_RGB16F, 1024, 1024);
myTex.set(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
myTex.set(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
```
Actual GL calls
```cpp
GLuint myTex;

glCreateTextures(GL_TEXTURE_2D, 1, &myTex);
glTextureStorage2D(myTex, 1, GL_RGB16F, 1024, 1024);
glTextureParameteri(myTex, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
glTextureParameteri(myTex, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

glDeleteTextures(1, &myTex);
```
