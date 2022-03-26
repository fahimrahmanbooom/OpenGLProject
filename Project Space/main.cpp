//
//  main.cpp
//  Project Space
//
//  Created by Fahim Rahman on 20/3/22.
//
//  ID: 173-15-927 (PC-B)
//

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

#include <iostream>
#include <random>

void display();
void reshape(int, int);
int generateRandomDigit();
void generateSpaceObjects(int);
void drawDistantObjects(float);
void drawNearObjects(float);
void drawDustObjects(float);

int numberOfSpaceObjects = 80;

int main(int argc, char **argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 1000) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 1000) / 2);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Space");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glClearColor(0, 0, 0, 0);
    glutMainLoop();
    
    return 0;
}


// reshape
void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // set 2D orthographic viewing region
    gluOrtho2D(-1000, 1000, -1000, 1000);
    glMatrixMode(GL_MODELVIEW);
}


// display content
void display() {
    // clear the screen
    glClear(GL_COLOR_BUFFER_BIT);
    
    drawDistantObjects(1);
    drawNearObjects(1.2);
    drawDustObjects(1.2);
    
    // display framebuffer on the screen
    glFlush();
}


// generate space objects at random places
void generateSpaceObjects(int numberOfSpaceObjects) {
    // plot space objects at random range
    for (int i = 0; i < numberOfSpaceObjects; i++) {
        glVertex2d(generateRandomDigit(), generateRandomDigit());
    }
}


// generate random digit between 0 and 950
int generateRandomDigit() {
    return -1000 + ( std::rand() % ( 1000 - (-1000) + 1 ) );
}


// draw distant objects
void drawDistantObjects(float objectSize) {
    // replaces the current matrix with the identity matrix (resets model view matrix)
    glLoadIdentity();
    
    // point size
    glPointSize(objectSize);
    
    // begin drawing
    glBegin(GL_POINTS);
    
    // set content color
    // REDISH
    glColor3ub(220, 20, 60);
    
    // plot space objects
    generateSpaceObjects(60);
    
    // end drawing
    glEnd();
}


// draw near objects
void drawNearObjects(float objectSize) {
    // replaces the current matrix with the identity matrix (resets model view matrix)
    glLoadIdentity();
    
    // point size
    glPointSize(objectSize);
    
    // begin drawing
    glBegin(GL_POINTS);
    
    // set content color
    // BLUEISH
    glColor3ub(0, 191, 255);
    
    // plot space objects
    generateSpaceObjects(30);
    
    // end drawing
    glEnd();
}


// draw dust objects
void drawDustObjects(float objectSize) {
    // replaces the current matrix with the identity matrix (resets model view matrix)
    glLoadIdentity();
    
    // point size
    glPointSize(objectSize);
    
    // begin drawing
    glBegin(GL_POINTS);
    
    // set content color
    // WHITE
    glColor3ub(255, 255, 255);
    
    // plot space objects
    generateSpaceObjects(50);
    
    // end drawing
    glEnd();
}
