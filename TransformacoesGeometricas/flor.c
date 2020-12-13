#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n = 30, direcao = 1;
float ang = 0;

void petala(float posX, float posY){
    int i;
        glBegin(GL_POLYGON);
            for(i=0;i<n;i++){
                glVertex2f(0.25*cos(ang)+posX,0.25*sin(ang)+posY);
                ang = ang+(2*M_PI)/n;
            }
        glEnd();
}

void flor(){
    glClear(GL_COLOR_BUFFER_BIT);

    int i;
    glClearColor(0, 0, 0, 0);
    glColor3f(1.0,0.0,0.0);

    petala(0,0.5);
    petala(0,-0.5);
    petala(0.5,0);
    petala(-0.5,0);
    petala(-0.35,-0.35);
    petala(0.35,0.35);
    petala(0.35,-0.35);
    petala(-0.35,0.35);

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
        for(i=0;i<n;i++){
            glVertex2f(0.3*cos(ang),0.3*sin(ang));
            ang = ang+(2*M_PI)/n;
        }
    glEnd();
    glFlush();

    glRotatef(20.0f*direcao, 0.0f, 0.0f, 1.0f);
    glFlush();
}

void tecladoEspecial(int tecla, int x, int y){
    switch (tecla) {
        case GLUT_KEY_RIGHT:
        case GLUT_KEY_UP:
            direcao=-1;
            break;
        case GLUT_KEY_LEFT:
        case GLUT_KEY_DOWN:
            direcao=1;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0,1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char **argv)
{
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(400,400);
    glutInit(&argc, argv);
    glutCreateWindow("Flor");
    init();
    glutDisplayFunc(flor);
    glutSpecialFunc(tecladoEspecial);
    glutMainLoop ();
    return 0;
}
