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

void drawRocketHead();
void drawRocketNeck();
void drawRocketUpperBody();
void drawRocketLowerBody();
void drawRocketFin();
void drawHighExhaustFlame();
void drawLowExhaustFlame();



int numberOfSpaceObjects = 80;


int main(int argc, char **argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 1200) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 1200) / 2);
    glutInitWindowSize(1200, 1200);
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
    gluOrtho2D(-1200, 1200, -1200, 1200);
    glMatrixMode(GL_MODELVIEW);
}


// display content
void display() {
    // clear the screen
    glClear(GL_COLOR_BUFFER_BIT);
    
    drawDistantObjects(1);
    drawNearObjects(1.2);
    drawDustObjects(1.2);
    
    drawRocketHead();
    drawRocketNeck();
    drawRocketUpperBody();
    drawRocketLowerBody();
    drawRocketFin();
    drawHighExhaustFlame();
    drawLowExhaustFlame();
    
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


// generate random digit between 0 and 1200
int generateRandomDigit() {
    return -1200 + ( std::rand() % ( 1200 - (-1200) + 1 ) );
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



// draw rocket head
void drawRocketHead() {
    // replaces the current matrix with the identity matrix (resets model view matrix)
    glLoadIdentity();
    
    // begin drawing
    glBegin(GL_POLYGON);
    
    // set content color
    // greyish
    glColor3ub(91, 93, 109);
    
    // plot rocket head upper part
    glVertex2f(-600, 0); // top
    glVertex2f(-650, -70); // left
    glVertex2f(-550, -70); // right
    glVertex2f(-600, 0); // top
    
    // end drawing
    glEnd();
}


// draw rocket neck
void drawRocketNeck() {
    // replaces the current matrix with the identity matrix (resets model view matrix)
    glLoadIdentity();
    
    // begin drawing
    glBegin(GL_POLYGON);
    
    // set content color
    // redish
    glColor3ub(237, 110, 105);
    
    // plot rocket neck
    glVertex2f(-650, -70); // left start
    glVertex2f(-550, -70); // right start
    glVertex2f(-535, -95); // right end
    glVertex2f(-665, -95); // left end
    
    // end drawing
    glEnd();
}


// draw rocket upper body
void drawRocketUpperBody() {
    // replaces the current matrix with the identity matrix (resets model view matrix)
    glLoadIdentity();
    
    // begin drawing
    glBegin(GL_POLYGON);
    
    // set content color
    // redish
    glColor3ub(237, 110, 105);
    
    // plot rocket upper body
    glVertex2f(-665, -95); // left start
    glVertex2f(-665, -150); // left end
    glVertex2f(-535, -150); // right end
    glVertex2f(-535, -95); // right start
    
    // end drawing
    glEnd();
}


// draw rocket lower body
void drawRocketLowerBody() {
    // replaces the current matrix with the identity matrix (resets model view matrix)
    glLoadIdentity();
    
    // begin drawing
    glBegin(GL_POLYGON);
    
    // set content color
    // whitish
    glColor3ub(200, 207, 224);
    
    // plot rocket upper body
    glVertex2f(-665, -150); // left start
    glVertex2f(-665, -520); // left end
    glVertex2f(-535, -520); // right end
    glVertex2f(-535, -150); // right start
    
    // end drawing
    glEnd();
}


// draw rocket fin
void drawRocketFin() {
    // replaces the current matrix with the identity matrix (resets model view matrix)
    glLoadIdentity();
    
    // begin drawing
    glBegin(GL_POLYGON);
    
    // set content color
    // greyish
    glColor3ub(91, 93, 109);
    
    // plot rocket fin
    glVertex2f(-655, -520); // left start
    glVertex2f(-675, -558); // left end
    glVertex2f(-525, -558); // right end
    glVertex2f(-545, -520); // right start
    
    // end drawing
    glEnd();
}


// draw high exhaust flame
void drawHighExhaustFlame() {
    // replaces the current matrix with the identity matrix (resets model view matrix)
    glLoadIdentity();
    
    // begin drawing
    glBegin(GL_POLYGON);
    
    // set content color
    // yellowish
    glColor3ub(251, 225, 120);
    
    // plot high exhaust flame
    glVertex2f(-650, -560); // left start
    glVertex2f(-600, -790); // mid end
    glVertex2f(-550, -560); // right start
    
    // end drawing
    glEnd();
}



// draw low exhaust flame
void drawLowExhaustFlame() {
    // replaces the current matrix with the identity matrix (resets model view matrix)
    glLoadIdentity();
    
    // begin drawing
    glBegin(GL_POLYGON);
    
    // set content color
    // whiteish
    glColor3ub(255, 255, 255);
    
    // plot low exhaust flame
    glVertex2f(-650, -560); // left start
    glVertex2f(-600, -650); // mid end
    glVertex2f(-550, -560); // right start
    
    // end drawing
    glEnd();
}
