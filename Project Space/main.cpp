//
//  main.cpp
//  Project Space
//
//  Created by Fahim Rahman on 20/3/22.
//
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
void drawRocketLeftWing();
void drawRocketRightWing();
void drawCircle(float xOrigin, float yOrigin, float radius, int red, int green, int blue);
void drawSatelliteBody();
void drawSatelliteDishHolder();
void drawSatelliteDish(float xOrigin, float yOrigin, float radius, int red, int green, int blue);
void drawSatelliteTopPanel();
void drawSatelliteBottomPanel();


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
    drawRocketLeftWing();
    drawRocketRightWing();
    
    drawCircle(400, 600, 70, 255, 255, 255);  // xOrigin, yOrigin, radius, red, green, blue   // white
    drawCircle(-900, 800, 40, 186, 87, 62);   // xOrigin, yOrigin, radius, red, green, blue   // orange
    drawCircle(1180, -800, 90, 171, 127, 93); // xOrigin, yOrigin, radius, red, green, blue   // brown
    drawCircle(-600, -150, 20, 91, 93, 109);// xOrigin, yOrigin, radius, red, green, blue     // grey
    
    drawSatelliteDishHolder();
    drawSatelliteDish(760, 50, 18, 237, 110, 105);   // xOrigin, yOrigin, radius, red, green, blue   // red
    drawSatelliteTopPanel();
    drawSatelliteBottomPanel();
    drawSatelliteBody();
    
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


// draw rocket left wing
void drawRocketLeftWing() {
    // replaces the current matrix with the identity matrix (resets model view matrix)
    glLoadIdentity();
    
    // begin drawing
    glBegin(GL_POLYGON);
    
    // set content color
    // redish
    glColor3ub(237, 110, 105);
    
    // plot rocket left wing
    glVertex2f(-665, -250); // left top start
    glVertex2f(-790, -390); // left down start
    glVertex2f(-790, -460); // left down end
    glVertex2f(-665, -400); // left up end
    
    // end drawing
    glEnd();
}



// draw rocket right wing
void drawRocketRightWing() {
    // replaces the current matrix with the identity matrix (resets model view matrix)
    glLoadIdentity();
    
    // begin drawing
    glBegin(GL_POLYGON);
    
    // set content color
    // redish
    glColor3ub(237, 110, 105);
    
    // plot rocket right wing
    glVertex2f(-535, -250); // right top start
    glVertex2f(-410, -390); // right down start
    glVertex2f(-410, -460); // right down end
    glVertex2f(-535, -400); // right up end
    
    // end drawing
    glEnd();
}



// draw circle
void drawCircle(float xOrigin, float yOrigin, float radius, int red, int green, int blue) {
    
    // replaces the current matrix with the identity matrix (resets model view matrix)
    glLoadIdentity();
    
    // begin drawing
    glBegin(GL_POLYGON);
    
    // set content color
    // whiteish
    glColor3ub(red, green, blue);
    
    for (int i = 0; i <= 360; i++) {
        double angle = 2 * M_PI * i / 100;
        double x = cos(angle) * radius;
        double y = sin(angle) * radius;
        // plot circle
        glVertex2d(xOrigin + x, yOrigin + y);
    }
    
    // end drawing
    glEnd();
}



// draw satellite body
void drawSatelliteBody() {
    // replaces the current matrix with the identity matrix (resets model view matrix)
    glLoadIdentity();
    
    // begin drawing
    glBegin(GL_POLYGON);
    
    // set content color
    // greyish
    glColor3ub(200, 207, 224);
    
    // plot satellite body
    glVertex2f(800, 100); // left top start
    glVertex2f(800, 50); // left bottom end
    glVertex2f(900, 100); // right bottom end
    glVertex2f(900, 150); // right top start
    
    // end drawing
    glEnd();
}



// draw satellite dish holder
void drawSatelliteDishHolder() {
    // replaces the current matrix with the identity matrix (resets model view matrix)
    glLoadIdentity();
    
    // line width
    glLineWidth(3);
    
    // begin drawing
    glBegin(GL_LINES);
    
    // set content color
    // blueish
    glColor3ub(96, 179, 218);
    
    // plot satellite dish holder
    glVertex2f(770, 60); // start
    glVertex2f(800, 75); // end
    
    // end drawing
    glEnd();
}



// draw satellite dish
void drawSatelliteDish(float xOrigin, float yOrigin, float radius, int red, int green, int blue) {
    
    // replaces the current matrix with the identity matrix (resets model view matrix)
    glLoadIdentity();
    
    // begin drawing
    glBegin(GL_POLYGON);
    
    // set content color
    // whiteish
    glColor3ub(red, green, blue);
    
    for (int i = 0; i <= 50; i++) {
        double angle = 2 * M_PI * i / 100;
        double x = cos(angle) * radius;
        double y = sin(angle) * radius;
        // plot circle
        glVertex2d(xOrigin + x, yOrigin + y);
    }
    
    // end drawing
    glEnd();
}



// draw satellite top panel
void drawSatelliteTopPanel() {
    // replaces the current matrix with the identity matrix (resets model view matrix)
    glLoadIdentity();
    
    // begin drawing
    glBegin(GL_POLYGON);
    
    // set content color
    // blueish
    glColor3ub(60, 119, 188);
    
    // plot satellite panel body
    glVertex2f(840, 195); // top left start
    glVertex2f(870, 210); // top right start
    glVertex2f(870, 135); // top right end
    glVertex2f(840, 120); // top left end
    
    // end drawing
    glEnd();
}




// draw satellite bottom panel
void drawSatelliteBottomPanel() {
    // replaces the current matrix with the identity matrix (resets model view matrix)
    glLoadIdentity();
    
    // begin drawing
    glBegin(GL_POLYGON);
    
    // set content color
    // blueish
    glColor3ub(60, 119, 188);
    
    // plot satellite panel body
    glVertex2f(840, 125); // top left start
    glVertex2f(870, 140); // top right start
    glVertex2f(870, 35); // top right end
    glVertex2f(840, 20); // top left end
    
    // end drawing
    glEnd();
}




// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
