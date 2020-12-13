#include <GL/Glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592654

float dir = 0.0, tx = 0.0;

void pneu(){
    glColor3f(0.5,0.5,0.5);
    int i;
    float angulo = 0.0;
    glBegin(GL_POLYGON);
        for (i=0;i<=10;i++) {
            angulo= 2 * PI * i / 10.0;
            glVertex2f(0.125*cos(angulo), 0.125*sin(angulo));
        }
    glEnd ();
    glColor3f(0.95,0.95,0.95);

        glBegin(GL_POLYGON);
        for (i=0;i<=30;i++) {
            angulo= 2 * PI * i / 10.0;
            glVertex2f(0.07*cos(angulo), 0.07*sin(angulo));
        }
    glEnd ();
}

void carro(){
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(-0.25, 0);
        glVertex2f(-0.25, 0.25);
        glVertex2f(-0.10, 0.35);
        glVertex2f(0.45, 0.35);
        glVertex2f(0.55, 0.23);
        glVertex2f(0.75, 0.17);
        glVertex2f(0.78, 0);
    glEnd();
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
        glVertex2f(-0.20, 0.25);
        glVertex2f(-0.08, 0.32);
        glVertex2f(0.43, 0.32);
        glVertex2f(0.50, 0.25);
    glEnd();
}

void desenha(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glTranslatef(tx,0.0,0.0);
    glPushMatrix();
    carro();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5,0.0,0.0);
    glRotatef(dir,0.0,0.0,1.0);
    pneu();
    glPopMatrix();

    glPushMatrix();
    glRotatef(dir,0.0,0.0,1.0);
    pneu();
    glPopMatrix();

    glFlush();
}

void tecladoEspecial(int tecla, int x, int y){
    switch (tecla) {
        case GLUT_KEY_RIGHT:
            tx+=0.05;
            dir-=5;
            break;
        case GLUT_KEY_LEFT:
            tx-=0.05;
            dir+=5;
            break;
    }
    glutPostRedisplay();
}

int main ( int argc , char * argv [] ){
    glutInit(&argc , argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (50 ,100);
    glutInitWindowSize (400 ,400);
    glutCreateWindow ("Carro");
    glutDisplayFunc (desenha);
    glutSpecialFunc(tecladoEspecial);
    glutMainLoop ();
    return 0;
}
