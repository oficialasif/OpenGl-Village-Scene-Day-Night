#include <GL/gl.h>
#include<stdio.h>
#include<math.h>
#include <GL/glut.h>


float bx=0, by=0, degree=0, shift=0;
int tx=0,ty=0;
//float degree = 0;//rotation angle for turbine
float boatPosition = 100.0f;

void init(void)
{
 glClearColor(1.0, 1.0, 1.0, 0.0); // Set display window colour to black

 glMatrixMode(GL_PROJECTION);  // Set projection parameters
 gluOrtho2D(0.0, 100.0, 0.0, 80.0);
}
void drawFilledCircle(float cx, float cy, float radius) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy); // Center of circle
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159f / 180.0f; // Convert degrees to radians
        float x = cx + radius * cos(angle);
        float y = cy + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}
void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy, GLfloat startAngle, GLfloat endAngle)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (GLfloat i = startAngle; i <= endAngle; i += 1.0)
    {
        GLfloat angle = i * 3.1416 / 180;
        GLfloat x = rx * cos(angle);
        GLfloat y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}
//drawfish
void drawFish(float x, float y, float shift) {


}

void cloud1(){
 glColor3f(1, 1, 1);
    drawFilledCircle(40,73,4);

glColor3f(1, 1, 1);
    drawFilledCircle(45,73,5);

glColor3f(1, 1, 1);
    drawFilledCircle(50,73,4);

    //cloud4
    glColor3f(1, 1, 1);
    drawFilledCircle(65,73,5);

glColor3f(1, 1, 1);
    drawFilledCircle(70,73,4);


//cloud5
glColor3f(1, 1, 1);
    drawFilledCircle(80,73,4);

glColor3f(1, 1, 1);
    drawFilledCircle(85,73,5);

glColor3f(1, 1, 1);
    drawFilledCircle(90,73,4);
}

void cloudX(){
glPushMatrix();
    glTranslatef(bx, 0, 0);

    cloud1();

    glPopMatrix();
    bx += .009;
    if (bx > 100)
        bx = 0;
    glutPostRedisplay();
}

void cloud2(){
 glColor3f(1, 1, 1);
    drawFilledCircle(6,73,5);
    glColor3f(1, 1, 1);
    drawFilledCircle(11,73,5);

glColor3f(1, 1, 1);
    drawFilledCircle(16,73,5);

glColor3f(1, 1, 1);
    drawFilledCircle(22,73,4);
}

void cloudyX(){
glPushMatrix();
    glTranslatef(bx, 0, 0);

    cloud2();

    glPopMatrix();
    bx += .009;
    if (bx > 100)
        bx = 0;
    glutPostRedisplay();
}

//wheel
// Draw turbine blades
void drawTurbineBlades() {
    glPushMatrix();
    glTranslatef(42, 58, 0);  // Translate to the center of the turbine
    glRotatef(degree, 0, 0, 1);  // Rotate around the center
    glTranslatef(-42, -58, 0);  // Translate back

    glColor3f(1, 1, 1);
    glBegin(GL_TRIANGLES);
    glVertex2i(41, 59);
    glVertex2i(35, 52);
    glVertex2i(41, 57);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(43, 57);
    glVertex2i(49, 52);
    glVertex2i(43, 59);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(41, 59);
    glVertex2i(43, 59);
    glVertex2i(42, 68);
    glEnd();
    glPopMatrix();
}
// Draw turbine pole
void drawTurbinePole() {
    glColor3f(0.725, 0, 1);
    glBegin(GL_QUADS);
    glVertex2i(41, 57);
    glVertex2i(41, 43);
    glVertex2i(43, 43);
    glVertex2i(43, 57);
    glEnd();
}
// Draw turbine center
void drawTurbineCenter() {
    glColor3f(0, 0, 0);
    drawFilledCircle(42, 58, 1);
}

void update(int value) {
    degree += 2.0f; // Update rotation angle
    if (degree > 360) {
        degree -= 360;
    }
     // Update boat position
    boatPosition -= 0.1f;
    if (boatPosition < -20.0f) { // Reset position when the boat goes off screen
        boatPosition = 100.0f;
    }

    glutPostRedisplay(); // Trigger a redisplay
    glutTimerFunc(16, update, 0); // Call update again after 16 milliseconds
}


void car(){
//gari
// Draw body of the car (dark blue)
glColor3f(0.0, 0.0, 0.5);
glBegin(GL_QUADS);
glVertex2i(50 , 29);
glVertex2i(72 , 29);
glVertex2i(72 , 26);
glVertex2i(50 , 26);
glEnd();

// Draw top of the car (orange)
glColor3f(1.0, 0.6, 0.2);
glBegin(GL_QUADS);
glVertex2i(56 , 32);
glVertex2i(62 , 32);
glVertex2i(62 , 29);
glVertex2i(54 , 29);
glEnd();

// Draw roof of the car (light green)
glColor3f(0.4, 1.0, 0.4);
glBegin(GL_QUADS);
glVertex2i(62 , 32);
glVertex2i(67 , 32);
glVertex2i(69 , 29);
glVertex2i(62 , 29);
glEnd();

// Draw left wheel (dark gray)
glColor3f(0.4, 0.4, 0.4);
drawFilledCircle(54 , 26, 2);

// Draw right wheel (dark gray)
drawFilledCircle(66 , 26, 2);


}

void carX(){
glPushMatrix();
    glTranslatef(bx, 0, 0);

    car();

    glPopMatrix();
    bx += .009;
    if (bx > 100)
        bx = -80;
    glutPostRedisplay();
}


void drawBoat(float shift) {
    // Original boat with slight adjustments
    glColor3f(0.878, 0.447, 0.067);
    glBegin(GL_QUADS);
    glVertex2i(85 + shift, 20);
    glVertex2i(90 + shift, 15);
    glVertex2i(100 + shift, 15);
    glVertex2i(105 + shift, 20);
    glEnd();

    glColor3f(1, 0, 1);
    glBegin(GL_QUADS);
    glVertex2i(90 + shift, 22);
    glVertex2i(90 + shift, 20);
    glVertex2i(100 + shift, 20);
    glVertex2i(100 + shift, 22);
    glEnd();
}
void drawSailingBoat(float position) {
    // Boat hull
    glColor3f(0.5, 0.25, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(position + 4, 14);
    glVertex2f(position + 6, 10);
    glVertex2f(position + 14, 10);
    glVertex2f(position + 16, 14);
    glEnd();

     // Boat deck
    glColor3f(0.6, 0.3, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(position + 6, 14);
    glVertex2f(position + 6, 16);
    glVertex2f(position + 14, 16);
    glVertex2f(position + 14, 14);
    glEnd();

     // Mast
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_QUADS);
    glVertex2f(position + 10, 16);
    glVertex2f(position + 10.5, 16);
    glVertex2f(position + 10.5, 24);
    glVertex2f(position + 10, 24);
    glEnd();

    // Sail
    glColor3f(1, 1, 1);
    glBegin(GL_TRIANGLES);
    glVertex2f(position + 10.25, 24);
    glVertex2f(position + 10.25, 16);
    glVertex2f(position + 15, 16);
    glEnd();

}

void drawShapes()
{
 glClear(GL_COLOR_BUFFER_BIT); // Clear display window

 glColor3f(0.576, 0.635, 0.753);
 // Draw a sky line
 glBegin(GL_QUADS);
  glVertex2i(0,80);
  glVertex2i(0,55);
  glVertex2i(100,55);
  glVertex2i(100,80);
 glEnd();
 cloudyX();

//sun
glColor3f(1, 0.988, 0);
    drawFilledCircle(60,73,5);

cloudX();




//hill1
glColor3f(0.82, 0.82, 0.706);

 glBegin(GL_TRIANGLES);
  glVertex2i(9,64);
  glVertex2i(2,55);
  glVertex2i(16,55);
 glEnd();

//HILL2
glColor3f(0.82, 0.82, 0.706);

 glBegin(GL_TRIANGLES);
  glVertex2i(31,70);
  glVertex2i(19,55);
  glVertex2i(43,55);
 glEnd();

 //GIJIBIJI12
 glColor3f(1,1,1);
  glBegin(GL_POLYGON);
   glVertex2i(9,62);
  glVertex2i(9,64);
  glVertex2i(7,61);
  glVertex2i(9,60);
  glVertex2i(9,61);
  glVertex2i(10,60);
  glVertex2i(11,61);
 glVertex2i(9,64);
 glEnd();

 //2
 glBegin(GL_POLYGON);
  glVertex2i(31,66);
  glVertex2i(31,70);
  glVertex2i(27,65);
  glVertex2i(31,63);
  glVertex2i(32,65);
  glVertex2i(34,63);
 glVertex2i(36,64);
  glVertex2i(31,70);
 glEnd();

 //PAKHI



glColor3f(0, 0, 0);
 glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(28,77);
    glVertex2f(30, 75);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(30,75);
    glVertex2f(32, 77);
    glEnd();


 glColor3f(0.067, 1, 0);
 // Draw a land field line
 glBegin(GL_QUADS);
  glVertex2i(0,55);
  glVertex2i(0,40);
  glVertex2i(100,40);
  glVertex2i(100,55);
 glEnd();

//TWO TREE
//TREES DAL


 glColor3f(0.557, 0.769, 0.278);

glColor3f(1, 0.541, 0);

 glBegin(GL_QUADS);
  glVertex2i(80,50);
  glVertex2i(80,40);
  glVertex2i(82,40);
  glVertex2i(82,50);
 glEnd();

 glColor3f(1, 0.541, 0);

 glBegin(GL_QUADS);
  glVertex2i(93,52);
  glVertex2i(93,40);
  glVertex2i(95,40);
  glVertex2i(95,52);
 glEnd();

 //tree

 //SINGLE TREE
 glColor3f(1, 0.541, 0);

 glBegin(GL_QUADS);
  glVertex2i(17,61);
  glVertex2i(17,45);
  glVertex2i(19,45);
  glVertex2i(19,61);
 glEnd();
 //PATA
 glColor3f(0.286, 0.678, 0.239);
    drawFilledCircle(78,53,4);

    drawFilledCircle(83,53,4);

    drawFilledCircle(78,58,4);

    drawFilledCircle(85,58,4);
    drawFilledCircle(81,62,3);
//PATA2
 glColor3f(0.286, 0.678, 0.239);
    drawFilledCircle(92,54,3);

    drawFilledCircle(93,58,4);

    drawFilledCircle(96,58,4);

    drawFilledCircle(96,54,3);

    drawFilledCircle(94,62,3);

//SINGLE PATA

    drawFilledCircle(15,61,2);

    drawFilledCircle(17,58,2);

    drawFilledCircle(17,61,2);

    drawFilledCircle(15,63,2);

    drawFilledCircle(20,63,2);

    drawFilledCircle(20,60,2);

    drawFilledCircle(17,64,2);

    //bari2box

    glColor3f(0.961, 0.949, 0.259);
 glBegin(GL_QUADS);
  glVertex2i(19,50);
  glVertex2i(19,43);
  glVertex2i(35,43);
  glVertex2i(35,50);
 glEnd();
    glColor3f(0.851, 0.835, 0.031);

 glBegin(GL_QUADS);
  glVertex2i(4,46);
  glVertex2i(4,40);
  glVertex2i(20,40);
  glVertex2i(20,46);
 glEnd();
glColor3f(0.851, 0.459, 0.031);
 //2noBarirjanala
  glBegin(GL_QUADS);
  glVertex2i(20,49);
  glVertex2i(20,47);
  glVertex2i(23,47);
  glVertex2i(23,49);
 glEnd();

 glBegin(GL_QUADS);
  glVertex2i(31,49);
  glVertex2i(31,47);
  glVertex2i(34,47);
  glVertex2i(34,49);
 glEnd();

 //2nobarirDorja
 glBegin(GL_QUADS);
  glVertex2i(25,49);
  glVertex2i(25,43);
  glVertex2i(29,43);
  glVertex2i(29,49);
 glEnd();


 //baritriangle1
  glColor3f(1, 0, 0.133);

 glBegin(GL_TRIANGLES);
  glVertex2i(12,53);
  glVertex2i(3,46);
  glVertex2i(21,46);
 glEnd();
//BARI2
 glBegin(GL_TRIANGLES);
  glVertex2i(27,57);
  glVertex2i(18,50);
  glVertex2i(36,50);
 glEnd();

 //JANLA1 ER
 glColor3f(0.851, 0.459, 0.031);
 glBegin(GL_QUADS);
  glVertex2i(5,45);
  glVertex2i(5,43);
  glVertex2i(8,43);
  glVertex2i(8,45);
 glEnd();

  glBegin(GL_QUADS);
  glVertex2i(16,45);
  glVertex2i(16,43);
  glVertex2i(19,43);
  glVertex2i(19,45);
 glEnd();
 //DORJA1
  glBegin(GL_QUADS);
  glVertex2i(10,45);
  glVertex2i(10,40);
  glVertex2i(14,40);
  glVertex2i(14,45);
 glEnd();


// //wheel

//drawTurbineWheel();

drawTurbineBlades();
    drawTurbinePole();
    drawTurbineCenter();

//man
//suta
glColor3f(0, 0, 0);
 glLineWidth(7.0);

    // Draw the line from (8,19) to (10,12)
    glBegin(GL_LINES);
    glVertex2f(57,45);
    glVertex2f(70, 60);
    glEnd();


//body
glColor3f(0.725, 0, 1);
 glBegin(GL_QUADS);
  glVertex2i(53,47);
  glVertex2i(51,45);
  glVertex2i(57,45);
  glVertex2i(55,47);
 glEnd();
//pet
glColor3f(1, 0.557, 0);
 glBegin(GL_QUADS);
  glVertex2i(51,45);
  glVertex2i(51,42);
  glVertex2i(57,42);
  glVertex2i(57,45);
 glEnd();
 //golla
 glColor3f(0, 0, 0);
    drawFilledCircle(54,48,1);
//leg
glColor3f(0, 1, 0.835);
 glBegin(GL_QUADS);
  glVertex2i(52,42);
  glVertex2i(52,40);
  glVertex2i(53,40);
  glVertex2i(53,42);
 glEnd();

  glBegin(GL_QUADS);
  glVertex2i(55,42);
  glVertex2i(55,40);
  glVertex2i(56,40);
  glVertex2i(56,42);
 glEnd();
//GHURI
glColor3f(1, 0.043, 0);
 glBegin(GL_QUADS);
  glVertex2i(70,65);
  glVertex2i(70,60);
  glVertex2i(75,60);
  glVertex2i(75,65);
 glEnd();


 glColor3f(0, 0, 0);
 // Draw a filled road line
 glBegin(GL_QUADS);
  glVertex2i(0,40);
  glVertex2i(0,25);
  glVertex2i(100,25);
  glVertex2i(100,40);
 glEnd();

 glColor3f(1, 1, 1);
 // Draw white line of road line
 glBegin(GL_QUADS);
  glVertex2i(5,35);
  glVertex2i(5,32);
  glVertex2i(20,32);
  glVertex2i(20,35);
 glEnd();
 glColor3f(1, 1, 1);
 // Draw white line of road line
 glBegin(GL_QUADS);
  glVertex2i(25,35);
  glVertex2i(25,32);
  glVertex2i(40,32);
  glVertex2i(40,35);
 glEnd();
 glColor3f(1, 1, 1);
 // Draw white line of road line
 glBegin(GL_QUADS);
  glVertex2i(45,35);
  glVertex2i(45,32);
  glVertex2i(60,32);
  glVertex2i(60,35);
 glEnd();
 glColor3f(1, 1, 1);
 // Draw white line of road line
 glBegin(GL_QUADS);
  glVertex2i(65,35);
  glVertex2i(65,32);
  glVertex2i(80,32);
  glVertex2i(80,35);
 glEnd();
 glColor3f(1, 1, 1);
 // Draw white line of road line
 glBegin(GL_QUADS);
  glVertex2i(85,35);
  glVertex2i(85,32);
  glVertex2i(100,32);
  glVertex2i(100,35);
 glEnd();

carX();

 glColor3f(0, 0.694, 0.91);
 // Draw a filled river line
 glBegin(GL_QUADS);
  glVertex2i(0,25);
  glVertex2i(0,0);
  glVertex2i(100,0);
  glVertex2i(100,25);
 glEnd();
 //BOAT
  glColor3f(0.878, 0.447, 0.067);

 // Draw original boat
    drawBoat(shift);



//DATA
       glColor3f(0.176, 0.769, 0.267);
          glLineWidth(7.0);

    // Draw the line from (8,19) to (10,12)
    glBegin(GL_LINES);
    glVertex2f(8, 19);
    glVertex2f(20, 0);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(13, 26);
    glVertex2f(30, 0);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(23,26);
    glVertex2f(5,0);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(32, 18);
    glVertex2f(25,0);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(36,9);
    glVertex2f(30,0);
    glEnd();
//ghash1
  glColor3f(0.243, 0.89, 0.047);
glBegin(GL_TRIANGLES);
  glVertex2i(16,20);
  glVertex2i(0,0);
  glVertex2i(5,0);
 glEnd();
 //GHASH2
 glBegin(GL_TRIANGLES);
  glVertex2i(1,17);
  glVertex2i(10,0);
  glVertex2i(15,0);
 glEnd();
  //GHASH3
 glBegin(GL_TRIANGLES);
  glVertex2i(22,24);
  glVertex2i(10,0);
  glVertex2i(13,0);
 glEnd();
//GHASH4
 glBegin(GL_TRIANGLES);
  glVertex2i(12,21);
  glVertex2i(20,0);
  glVertex2i(25,0);
 glEnd();
 //GHASH5
 glBegin(GL_TRIANGLES);
  glVertex2i(27,20);
  glVertex2i(10,0);
  glVertex2i(15,0);
 glEnd();
//GHASH6
 glBegin(GL_TRIANGLES);
  glVertex2i(29,20);
  glVertex2i(20,0);
  glVertex2i(24,0);
 glEnd();
//GHASH7
 glBegin(GL_TRIANGLES);
  glVertex2i(17,21);
  glVertex2i(30,0);
  glVertex2i(35,0);
 glEnd();
 //GHASH8
 glBegin(GL_TRIANGLES);
  glVertex2i(39,23);
  glVertex2i(28,0);
  glVertex2i(31,0);
 glEnd();

 //fish


//FISH1
glColor3f(0.878, 0.878, 0.878);
 glBegin(GL_POLYGON);
  glVertex2i(49+shift,18);
  glVertex2i(49+shift,22);
  glVertex2i(47+shift,20);

  glVertex2i(47+shift,16);
   glVertex2i(49+shift,14);
  glVertex2i(52+shift,16);
  glVertex2i(55+shift,14);
   glVertex2i(54+shift,18);
  glVertex2i(55+shift,22);
   glVertex2i(52+shift,20);
  glVertex2i(49+shift,22);
 glEnd();

 circle(4,2, 47+shift, 18, 90, 270);
//LINE
 glColor3f(0.749, 0.439, 0.29);
          glLineWidth(1.0);

    // Draw the line
    glBegin(GL_LINES);
    glVertex2f(47+shift, 20);
    glVertex2f(47+shift,16);

    glEnd();
    glBegin(GL_LINES);
    glVertex2f(52+shift, 16);
    glVertex2f(47+shift,16);
    glEnd();

     glBegin(GL_LINES);
    glVertex2f(52+shift,16);
    glVertex2f(52+shift,20);
    glEnd();

     glBegin(GL_LINES);
    glVertex2f(52+shift,20);
   glVertex2f(47+shift, 20);

    glEnd();
    glColor3f(0,0, 0);
    drawFilledCircle(45+shift,18,1);
     glColor3f(1,1,1);
    drawFilledCircle(45+shift,18,0.5);


//FUL

 glColor3f(1, 0, 0.643);
 glBegin(GL_POLYGON);
  glVertex2i(24,27);
  glVertex2i(24,30);
  glVertex2i(23,28);
  glVertex2i(21,27);
  glVertex2i(23,26);
  glVertex2i(24,24);
  glVertex2i(25,26);
   glVertex2i(27,27);
  glVertex2i(25,28);
  glVertex2i(24,30);
 glEnd();
 //FULL2
  glBegin(GL_POLYGON);
  glVertex2i(12,27);
  glVertex2i(12,30);
  glVertex2i(11,28);
  glVertex2i(9,27);
  glVertex2i(11,26);
  glVertex2i(12,24);
  glVertex2i(13,26);
   glVertex2i(15,27);
  glVertex2i(13,28);
  glVertex2i(12,30);
 glEnd();
 //FUL3
  glBegin(GL_POLYGON);
  glVertex2i(7,20);
  glVertex2i(7,23);
  glVertex2i(6,21);
  glVertex2i(4,20);
  glVertex2i(6,19);
  glVertex2i(7,17);
  glVertex2i(8,19);
   glVertex2i(10,20);
  glVertex2i(8,21);
  glVertex2i(7,23);
 glEnd();

 //FUL4
  glBegin(GL_POLYGON);
  glVertex2i(33,19);
  glVertex2i(33,22);
  glVertex2i(32,20);
  glVertex2i(30,19);
  glVertex2i(32,18);
  glVertex2i(33,16);
  glVertex2i(34,18);
   glVertex2i(36,19);
  glVertex2i(34,20);
  glVertex2i(33,22);
 glEnd();
 //FUL5
  glBegin(GL_POLYGON);
  glVertex2i(37,10);
  glVertex2i(37,13);
  glVertex2i(36,11);
  glVertex2i(34,10);
  glVertex2i(36,9);
  glVertex2i(37,7);
  glVertex2i(38,9);
   glVertex2i(40,10);
  glVertex2i(38,11);
  glVertex2i(37,13);
 glEnd();


 glColor3f(0.98, 1, 0);
    drawFilledCircle(24,27,1);
        drawFilledCircle(12,27,1);
        drawFilledCircle(7,20,1);
        drawFilledCircle(33,19,1);
        drawFilledCircle(37,10,1);

        // Draw sailing boat
    drawSailingBoat(boatPosition);


glFlush(); // Process all OpenGL routines

}


//Night Scene

void drawNight()
{
 glClear(GL_COLOR_BUFFER_BIT); // Clear display window

 //Set colour to black
 //glColor3f(0.0, 0.0, 0.0);
 //Adjust the point size
 //glPointSize(100.100);

 //1
 glColor3f(0, 0, 0);
 // Draw a sky line
 glBegin(GL_QUADS);
  glVertex2i(0,80);
  glVertex2i(0,55);
  glVertex2i(100,55);
  glVertex2i(100,80);
 glEnd();

//sun
glColor3f(1,1,1);
    drawFilledCircle(60,70,5);
glColor3f(0, 0, 0);
    drawFilledCircle(60,73,5);

//star
glColor3f(1,1,1);
glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(5, 75);
    glVertex2f(5, 75.5);
 glEnd();

 glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(7, 72);
    glVertex2f(7, 72.5);
 glEnd();

 glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(1, 70);
    glVertex2f(1, 70.5);
 glEnd();

 glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(3, 71);
    glVertex2f(3, 71.5);
 glEnd();

 glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(67, 75);
    glVertex2f(67, 75.5);
 glEnd();

  glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(69, 71);
    glVertex2f(69, 71.5);
 glEnd();
  glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(76, 72);
    glVertex2f(76, 72.5);
 glEnd();
  glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(57, 77);
    glVertex2f(57, 77.5);
 glEnd();
  glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(53, 65);
    glVertex2f(53, 65.5);
 glEnd();
  glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(40, 62);
    glVertex2f(40, 62.5);
 glEnd();
  glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(9, 75);
    glVertex2f(9, 75.5);
 glEnd();
  glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(9, 75);
    glVertex2f(9, 75.5);
 glEnd();
  glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(9, 75);
    glVertex2f(9, 75.5);
 glEnd();
  glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(9, 75);
    glVertex2f(9, 75.5);
 glEnd();
  glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(9, 75);
    glVertex2f(9, 75.5);
 glEnd();
  glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(9, 75);
    glVertex2f(9, 75.5);
 glEnd();
  glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(9, 75);
    glVertex2f(9, 75.5);
 glEnd(); glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(9, 75);
    glVertex2f(9, 75.5);
 glEnd(); glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(9, 75);
    glVertex2f(9, 75.5);
 glEnd(); glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(9, 75);
    glVertex2f(9, 75.5);
 glEnd(); glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(9, 75);
    glVertex2f(9, 75.5);
 glEnd(); glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(9, 75);
    glVertex2f(9, 75.5);
 glEnd(); glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(89, 65);
    glVertex2f(89, 65.5);
 glEnd(); glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(90, 67);
    glVertex2f(90, 67.5);
 glEnd(); glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(78, 74);
    glVertex2f(78, 74.5);
 glEnd(); glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(75, 65);
    glVertex2f(75, 65.5);
 glEnd(); glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(63, 79);
    glVertex2f(63, 79.5);
 glEnd(); glLineWidth(3.0);
glBegin(GL_LINES);
    glVertex2f(60, 75);
    glVertex2f(60, 75.5);
 glEnd();

//cloudX();
 //cloud1
 glColor3f(0.82, 0.82, 0.706);
    drawFilledCircle(40+shift,73,5);

    drawFilledCircle(45+shift,74,5);


    drawFilledCircle(48+shift,76,5);


    drawFilledCircle(52+shift,75,4);

    //cloud4

    drawFilledCircle(65+shift,73,5);


    drawFilledCircle(70+shift,73,4);


//cloud5

    drawFilledCircle(80+shift,73,4);


    drawFilledCircle(85+shift,73,5);


    drawFilledCircle(90+shift,73,4);
//sun
//glColor3f(1, 0.988, 0);
    //drawFilledCircle(60,73,5);


//hill1
glColor3f(0.584, 0.612, 0.576);

 glBegin(GL_TRIANGLES);
  glVertex2i(9,64);
  glVertex2i(2,55);
  glVertex2i(16,55);
 glEnd();

//HILL2
glColor3f(0.584, 0.612, 0.576);

 glBegin(GL_TRIANGLES);
  glVertex2i(31,70);
  glVertex2i(19,55);
  glVertex2i(43,55);
 glEnd();

 //GIJIBIJI12
 glColor3f(0.945, 0.961, 0.941);
  glBegin(GL_POLYGON);
   glVertex2i(9,62);
  glVertex2i(9,64);
  glVertex2i(7,61);
  glVertex2i(9,60);
  glVertex2i(9,61);
  glVertex2i(10,60);
  glVertex2i(11,61);
 glVertex2i(9,64);
 glEnd();

 //2
 glBegin(GL_POLYGON);
  glVertex2i(31,66);
  glVertex2i(31,70);
  glVertex2i(27,65);
  glVertex2i(31,63);
  glVertex2i(32,65);
  glVertex2i(34,63);
 glVertex2i(36,64);
  glVertex2i(31,70);
 glEnd();




 glColor3f(0.114, 0.369, 0.035);
 // Draw a filled field line
 glBegin(GL_QUADS);
  glVertex2i(0,55);
  glVertex2i(0,40);
  glVertex2i(100,40);
  glVertex2i(100,55);
 glEnd();

  glColor3f(0.0, 0.0, 0.0);

     glColor3f(0.0, 0.0, 0.0);

      // Draw a road lamp post
    glBegin(GL_LINES);
    glVertex2i(54, 47); // Post
    glVertex2i(54, 25);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(54, 25); // Base
    glVertex2i(52, 25);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(54, 25);
    glVertex2i(56, 25);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(54, 47); // Light fixture
    glVertex2i(52, 45);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(54, 47);
    glVertex2i(56, 45);
    glEnd();

    // Draw a light bulb
    glColor3f(1.0, 1.0, 0.0);
    drawFilledCircle(54, 45, 2);

//TWO TREE
//TREES DAL


 glColor3f(0.557, 0.769, 0.278);

glColor3f(0.659, 0.298, 0.043);

 glBegin(GL_QUADS);
  glVertex2i(80,50);
  glVertex2i(80,40);
  glVertex2i(82,40);
  glVertex2i(82,50);
 glEnd();



 glBegin(GL_QUADS);
  glVertex2i(93,52);
  glVertex2i(93,40);
  glVertex2i(95,40);
  glVertex2i(95,52);
 glEnd();
 //SINGLE TREE


 glBegin(GL_QUADS);
  glVertex2i(17,61);
  glVertex2i(17,45);
  glVertex2i(19,45);
  glVertex2i(19,61);
 glEnd();
 //PATA
 glColor3f(0.192, 0.451, 0.082);
    drawFilledCircle(78,53,4);

    drawFilledCircle(83,53,4);

    drawFilledCircle(78,58,4);

    drawFilledCircle(85,58,4);
    drawFilledCircle(81,62,3);
//PATA2

    drawFilledCircle(92,54,3);

    drawFilledCircle(93,58,4);

    drawFilledCircle(96,58,4);

    drawFilledCircle(96,54,3);

    drawFilledCircle(94,62,3);

//SINGLE PATA

    drawFilledCircle(15,61,2);
     drawFilledCircle(15,65,2);
     drawFilledCircle(18,66,2);


    drawFilledCircle(17,58,2);

    drawFilledCircle(17,61,2);

    drawFilledCircle(15,63,2);

    drawFilledCircle(20,63,2);

    drawFilledCircle(20,60,2);

    drawFilledCircle(17,64,2);

    //bari2box

    glColor3f(0.749, 0.749, 0.565);
 glBegin(GL_QUADS);
  glVertex2i(19,50);
  glVertex2i(19,43);
  glVertex2i(35,43);
  glVertex2i(35,50);
 glEnd();
    glColor3f(0.714, 0.714, 0.329);

 glBegin(GL_QUADS);
  glVertex2i(4,46);
  glVertex2i(4,40);
  glVertex2i(20,40);
  glVertex2i(20,46);
 glEnd();
glColor3f(0.431, 0.22, 0.047);
 //2noBarirjanala
  glBegin(GL_QUADS);
  glVertex2i(20,49);
  glVertex2i(20,47);
  glVertex2i(23,47);
  glVertex2i(23,49);
 glEnd();

 glBegin(GL_QUADS);
  glVertex2i(31,49);
  glVertex2i(31,47);
  glVertex2i(34,47);
  glVertex2i(34,49);
 glEnd();

 //2nobarirDorja
 glBegin(GL_QUADS);
  glVertex2i(25,49);
  glVertex2i(25,43);
  glVertex2i(29,43);
  glVertex2i(29,49);
 glEnd();


 //baritriangle1
  glColor3f(0.431, 0.22, 0.047);

 glBegin(GL_TRIANGLES);
  glVertex2i(12,53);
  glVertex2i(3,46);
  glVertex2i(21,46);
 glEnd();
//BARI2
 glBegin(GL_TRIANGLES);
  glVertex2i(27,57);
  glVertex2i(18,50);
  glVertex2i(36,50);
 glEnd();

 //JANLA1 ER
 glColor3f(0.361, 0.263, 0.188);
 glBegin(GL_QUADS);
  glVertex2i(5,45);
  glVertex2i(5,43);
  glVertex2i(8,43);
  glVertex2i(8,45);
 glEnd();

  glBegin(GL_QUADS);
  glVertex2i(16,45);
  glVertex2i(16,43);
  glVertex2i(19,43);
  glVertex2i(19,45);
 glEnd();
 //DORJA1
  glBegin(GL_QUADS);
  glVertex2i(10,45);
  glVertex2i(10,40);
  glVertex2i(14,40);
  glVertex2i(14,45);
 glEnd();


 glColor3f(0.2, 0.188, 0.18);
 // Draw a filled road line
 glBegin(GL_QUADS);
  glVertex2i(0,40);
  glVertex2i(0,25);
  glVertex2i(100,25);
  glVertex2i(100,40);
 glEnd();

 glColor3f(0.671, 0.647, 0.627);
 // Draw white line of road line
 glBegin(GL_QUADS);
  glVertex2i(5,35);
  glVertex2i(5,32);
  glVertex2i(20,32);
  glVertex2i(20,35);
 glEnd();

 // Draw white line of road line
 glBegin(GL_QUADS);
  glVertex2i(25,35);
  glVertex2i(25,32);
  glVertex2i(40,32);
  glVertex2i(40,35);
 glEnd();

 // Draw white line of road line
 glBegin(GL_QUADS);
  glVertex2i(45,35);
  glVertex2i(45,32);
  glVertex2i(60,32);
  glVertex2i(60,35);
 glEnd();

 // Draw white line of road line
 glBegin(GL_QUADS);
  glVertex2i(65,35);
  glVertex2i(65,32);
  glVertex2i(80,32);
  glVertex2i(80,35);
 glEnd();

 // Draw white line of road line
 glBegin(GL_QUADS);
  glVertex2i(85,35);
  glVertex2i(85,32);
  glVertex2i(100,32);
  glVertex2i(100,35);
 glEnd();
//gari
glColor3f(0.0, 0.0, 0.5);
glBegin(GL_QUADS);
glVertex2i(50 , 29);
glVertex2i(72 , 29);
glVertex2i(72, 26);
glVertex2i(50, 26);
glEnd();

// Draw top of the car (orange)

glColor3f(1.0, 0.6, 0.2);
glBegin(GL_QUADS);
glVertex2i(56, 32);
glVertex2i(62, 32);
glVertex2i(62, 29);
glVertex2i(54, 29);
glEnd();

// Draw roof of the car (light green)
glColor3f(0.4, 1.0, 0.4);
glBegin(GL_QUADS);
glVertex2i(62 , 32);
glVertex2i(67, 32);
glVertex2i(69, 29);
glVertex2i(62, 29);
glEnd();

// Draw left wheel (dark gray)
glColor3f(0.4, 0.4, 0.4);
drawFilledCircle(54, 26, 2);

// Draw right wheel (dark gray)
drawFilledCircle(66, 26, 2);




 glColor3f(0.067, 0.58, 0.671);
 // Draw a filled river line
 glBegin(GL_QUADS);
  glVertex2i(0,25);
  glVertex2i(0,0);
  glVertex2i(100,0);
  glVertex2i(100,25);
 glEnd();
 //BOAT
  glColor3f(0.878, 0.447, 0.067);
 glBegin(GL_QUADS);
  glVertex2i(87+shift,20);
  glVertex2i(89+shift,17);
  glVertex2i(96+shift,17);
  glVertex2i(98+shift,20);
 glEnd();

  glColor3f(1, 0, 1);
 glBegin(GL_QUADS);
  glVertex2i(89+shift,22);
  glVertex2i(89+shift,20);
  glVertex2i(96+shift,20);
  glVertex2i(96+shift,22);
 glEnd();

 // Draw sailing boat
   drawSailingBoat(boatPosition);





//DATA
       glColor3f(0.192, 0.42, 0.129);
          glLineWidth(7.0);

    // Draw the line from (8,19) to (10,12)
    glBegin(GL_LINES);
    glVertex2f(8, 19);
    glVertex2f(20, 0);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(13, 26);
    glVertex2f(30, 0);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(23,26);
    glVertex2f(5,0);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(32, 18);
    glVertex2f(25,0);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(36,9);
    glVertex2f(30,0);
    glEnd();
//ghash1
  glColor3f(0.184, 0.451, 0.11);
glBegin(GL_TRIANGLES);
  glVertex2i(16,20);
  glVertex2i(0,0);
  glVertex2i(5,0);
 glEnd();
 //GHASH2
 glBegin(GL_TRIANGLES);
  glVertex2i(1,17);
  glVertex2i(10,0);
  glVertex2i(15,0);
 glEnd();
  //GHASH3
 glBegin(GL_TRIANGLES);
  glVertex2i(22,24);
  glVertex2i(10,0);
  glVertex2i(13,0);
 glEnd();
//GHASH4
 glBegin(GL_TRIANGLES);
  glVertex2i(12,21);
  glVertex2i(20,0);
  glVertex2i(25,0);
 glEnd();
 //GHASH5
 glBegin(GL_TRIANGLES);
  glVertex2i(27,20);
  glVertex2i(10,0);
  glVertex2i(15,0);
 glEnd();
//GHASH6
 glBegin(GL_TRIANGLES);
  glVertex2i(29,20);
  glVertex2i(20,0);
  glVertex2i(24,0);
 glEnd();
//GHASH7
 glBegin(GL_TRIANGLES);
  glVertex2i(17,21);
  glVertex2i(30,0);
  glVertex2i(35,0);
 glEnd();
 //GHASH8
 glBegin(GL_TRIANGLES);
  glVertex2i(39,23);
  glVertex2i(28,0);
  glVertex2i(31,0);
 glEnd();

//FUL

 glColor3f(0.651, 0.125, 0.506);
 glBegin(GL_POLYGON);
  glVertex2i(24,27);
  glVertex2i(24,30);
  glVertex2i(23,28);
  glVertex2i(21,27);
  glVertex2i(23,26);
  glVertex2i(24,24);
  glVertex2i(25,26);
   glVertex2i(27,27);
  glVertex2i(25,28);
  glVertex2i(24,30);
 glEnd();
 //FULL2
  glBegin(GL_POLYGON);
  glVertex2i(12,27);
  glVertex2i(12,30);
  glVertex2i(11,28);
  glVertex2i(9,27);
  glVertex2i(11,26);
  glVertex2i(12,24);
  glVertex2i(13,26);
   glVertex2i(15,27);
  glVertex2i(13,28);
  glVertex2i(12,30);
 glEnd();
 //FUL3
  glBegin(GL_POLYGON);
  glVertex2i(7,20);
  glVertex2i(7,23);
  glVertex2i(6,21);
  glVertex2i(4,20);
  glVertex2i(6,19);
  glVertex2i(7,17);
  glVertex2i(8,19);
   glVertex2i(10,20);
  glVertex2i(8,21);
  glVertex2i(7,23);
 glEnd();

 //FUL4
  glBegin(GL_POLYGON);
  glVertex2i(33,19);
  glVertex2i(33,22);
  glVertex2i(32,20);
  glVertex2i(30,19);
  glVertex2i(32,18);
  glVertex2i(33,16);
  glVertex2i(34,18);
   glVertex2i(36,19);
  glVertex2i(34,20);
  glVertex2i(33,22);
 glEnd();
 //FUL5
  glBegin(GL_POLYGON);
  glVertex2i(37,10);
  glVertex2i(37,13);
  glVertex2i(36,11);
  glVertex2i(34,10);
  glVertex2i(36,9);
  glVertex2i(37,7);
  glVertex2i(38,9);
   glVertex2i(40,10);
  glVertex2i(38,11);
  glVertex2i(37,13);
 glEnd();


 glColor3f(0.98, 1, 0);
    drawFilledCircle(24,27,1);
        drawFilledCircle(12,27,1);
        drawFilledCircle(7,20,1);
        drawFilledCircle(33,19,1);
        drawFilledCircle(37,10,1);

//FISH1




glColor3f(0.431, 0.439, 0.443);
 glBegin(GL_POLYGON);
  glVertex2i(49 +shift,18);
  glVertex2i(49+shift,22);
  glVertex2i(47+shift,20);

  glVertex2i(47+shift,16);
   glVertex2i(49+shift,14);
  glVertex2i(52+shift,16);
  glVertex2i(55+shift,14);
   glVertex2i(54+shift,18);
  glVertex2i(55+shift,22);
   glVertex2i(52+shift,20);
  glVertex2i(49+shift,22);
 glEnd();

 circle(4,2, 47+shift, 18, 90, 270);

    glColor3f(0,0, 0);
    drawFilledCircle(45+shift,18,1);
     glColor3f(1,1,1);
    drawFilledCircle(45+shift,18,0.5);

    // Draw sailing boat
    drawSailingBoat(boatPosition);

glFlush(); // Process all OpenGL routines



}
void SpecialInput(int key, int x, int y)
{
    switch(key){
    case GLUT_KEY_DOWN:
    glutDisplayFunc(drawShapes);
    break;
    case GLUT_KEY_UP:
    glutDisplayFunc(drawNight);
    break;

    glutPostRedisplay();

     case GLUT_KEY_LEFT:
            shift -= 5;
            if (shift < -70) {
                shift = -70;
            }
            break;

        case GLUT_KEY_RIGHT:
            shift += 5;
            if (shift > 100) {
                shift = 100;
            }
            break;

        default:
            return;  // Ignore other keys
    }
}


int main(int argc, char* argv[])
{
 glutInit(&argc, argv);      // Initalise GLUT
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); // Set display mode

 glutInitWindowPosition(10, 10);    // Set window position
 glutInitWindowSize(1200, 1200);     // Set window size
 glutCreateWindow("A Village Scenerio"); // Create display window

 init();  // Execute initialisation procedure
 glutSpecialFunc(SpecialInput);
 glutDisplayFunc(drawShapes);  // Send graphics to display window
 glutDisplayFunc(drawNight);
 glutTimerFunc(16, update, 0); // Call update function every 16 milliseconds


 glutMainLoop();     // Display everything and wait

 return 0;
}
