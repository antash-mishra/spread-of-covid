#include "texture.h"
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <string>
#include<iostream>

Texture::Texture(GLint width, GLint height,const  char * imagePath){
     this->width = width;
     this->height = height;
     this->imagePath = imagePath;
}

void Texture::configure(){
	     //create texture
     texId = SOIL_load_OGL_texture(
             this->imagePath,
             SOIL_LOAD_AUTO,
             SOIL_CREATE_NEW_ID,
             SOIL_FLAG_TEXTURE_REPEATS
     );
     glGenTextures(1, &texId);
     glBindTexture(GL_TEXTURE_2D, texId);
     imageData = SOIL_load_image(
            imagePath,
            &width,
            &height,
            0,
            SOIL_LOAD_RGBA
     );

     // set the texture wrapping parameters
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
     // Texture filter method
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
     if(imageData) {
     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
     }
     else {
     std::cout << "Failed to load front page" << std::endl;
     
     }

}

Texture::~Texture(){
     SOIL_free_image_data(imageData);
     glBindTexture(GL_TEXTURE_2D,0);
     glDisable(GL_TEXTURE_2D);

}

Tombstone::Tombstone(GLint width, GLint height, const char * imagePath)
	: Texture::Texture(width, height, imagePath){
}

void Tombstone::draw() {
	glEnable(GL_TEXTURE_2D);
     glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
     glBindTexture(GL_TEXTURE_2D, texId);
     //glColor2f(0.5,1.0,0.5, 1.0);
    // glColor3ub(255,229,0);
     glBegin(GL_QUADS);
     
     	glColor4f(0.8941,0.8549,0.7608,1.0);
	//glColor3ub(30,40,60);
	glTexCoord2f(1.0,1.0);glVertex2f(400, 400);
	glTexCoord2f(1.0, 0.0);glVertex2f(400, 200);
	glTexCoord2f(0.0,0.0);glVertex2f(200, 200);
	glTexCoord2f(0.0,1.0);glVertex2f(200, 400);
	glEnd();
     glDisable(GL_TEXTURE_2D);  
}

Tombstone::~Tombstone(){}




/*Member fucntion definition of Ground*/
Ground::Ground(GLint width, GLint height,const  char * imagePath)
                      : Texture::Texture(width, height, imagePath){
}
void Ground::draw(){
     glEnable(GL_TEXTURE_2D);
     glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
     glBindTexture(GL_TEXTURE_2D, texId);
     //glColor3f(1.0,1.0,1.0);
     glColor4f(0.8941,0.8549,0.7608,1.0);
     glBegin(GL_QUADS);
           glTexCoord2f(1.0,1.0);glVertex3f(400, 400, 0);
           glTexCoord2f(1.0,0.0);glVertex3f(400, 200, 0);
           glTexCoord2f(0.0,0.0);glVertex3f(200, 200, 0);
           glTexCoord2f(0.0,1.0);glVertex3f(200, 400, 0);
     glEnd(); 
     glDisable(GL_TEXTURE_2D);  
}
Ground::~Ground(){
}


