#include<GL/glut.h>
#include <SOIL/SOIL.h>
#include<iostream>
#include<stdio.h>

class Texture {
 protected:
        GLint width, height;
        GLubyte * imageData;
        const char * imagePath; 
        GLuint texId;
 public:
       Texture(GLint, GLint,const  char *);
       void configure();
       virtual void draw() = 0;
       ~Texture();
};

class Ground: public Texture{
 public:
        Ground(GLint, GLint,const  char *);
        void draw();
        ~Ground();
};

class Tombstone: public Texture{
 public:
        Tombstone(GLint, GLint,const  char *);
        void draw();
        ~Tombstone();
};


