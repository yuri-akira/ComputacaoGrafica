#include <GL/Glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592654

float theta=0.0;
float right=0.0;

void robo(){
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
        glVertex2f(-0.2, 0.0);
        glVertex2f(-0.2, 0.5);
        glVertex2f(0.2, 0.5);
        glVertex2f(0.2, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(-0.1, 0.5);
        glVertex2f(-0.1, 0.7);
        glVertex2f(0.1, 0.7);
        glVertex2f(0.1, 0.5);
    glEnd();

    glColor3f(0,0,1);
    glPointSize(5);
    glBegin(GL_POINTS);
        glVertex2f(-0.05, 0.6);
    glEnd();

    glBegin(GL_POINTS);
        glVertex2f(0.05, 0.6);
    glEnd();
}

void bracoD(){
        glColor3f(0.9,0.9,0.9);

glBegin(GL_POLYGON);
        glVertex2f(0.2,0.35);
        glVertex2f(0.2,0.3);
        glVertex2f(0.5,0.3);
        glVertex2f(0.5,0.35);
    glEnd();
}

void bracoE(){
        glColor3f(0.9,0.9,0.9);

glBegin(GL_POLYGON);
        glVertex2f(-0.2,0.35);
        glVertex2f(-0.2,0.3);
        glVertex2f(-0.5,0.3);
        glVertex2f(-0.5,0.35);
    glEnd();

}

void pernaE(){
        glColor3f(0.9,0.9,0.9);

    glBegin(GL_POLYGON);
        glVertex2f(-0.15,0);
        glVertex2f(-0.15,-0.3);
        glVertex2f(-0.1,-0.3);
        glVertex2f(-0.1,0);
    glEnd();
}

void pernaD(){
    glColor3f(0.9,0.9,0.9);
    glBegin(GL_POLYGON);
        glVertex2f(0.15,0);
        glVertex2f(0.15,-0.3);
        glVertex2f(0.1,-0.3);
        glVertex2f(0.1,0);
    glEnd();

}

void desenha(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    robo();

    glPushMatrix();
    glRotatef(-theta,-0.2,0.325,0.0);
    bracoE();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-theta,0.2,0.325,0.0);
    bracoD();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-theta,-0.125,0.0,0.0);
    pernaE();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-theta,0.125,0.0,0.0);
    pernaD();
    glPopMatrix();

    glFlush();
}

void tecladoEspecial(int tecla, int x, int y){
    switch (tecla) {
        case GLUT_KEY_RIGHT:
            theta+=25;
            break;
        case GLUT_KEY_LEFT:
            theta-=25;
            break;

        default:
            break;
    }
    glutPostRedisplay();
}

int main ( int argc , char * argv [] ){
    glutInit(&argc , argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (50 ,100);
    glutInitWindowSize (400 ,400);
    glutCreateWindow ("Robo pulador");
    glutDisplayFunc (desenha);
    glutSpecialFunc(tecladoEspecial);
    glutMainLoop ();
    return 0;
}
