#include <GL/glut.h>
#include <stdio.h>

#define VELMAX 3

float anguloX = 0.0, anguloY = 0.0, anguloZ = 0.0, anguloCamera = 0.0;
float c = 0;
int girar = 0;

enum
{
    X,
    Y,
    Z
} eixo = X;

void gira(void)
{
    switch (eixo)
    {
    case X:
        anguloX += 1.0;
        break;
    case Y:
        anguloY += 1.0;
        break;
    case Z:
        anguloZ += c;
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

void helices(){
    ///helice 1
    glColor3f(0.9,0.9,0.9);

    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glPushMatrix();
    glRotatef(120, 0.0, 1.0, 0.0);
    glutSolidCone(0.9, 16.0, 15, 15);
    glPopMatrix();
    glPopMatrix();

    ///helice 2
    glPushMatrix();
    glTranslatef(0.0, 0.0,0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glPushMatrix();
    glRotatef(-120, 0.0, 1.0, 0.0);
    glutSolidCone(0.9, 16.0, 15, 15);
    glPopMatrix();
    glPopMatrix();

    ///helice 3
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glutSolidCone(0.9, 16.0, 15, 15);
    glPopMatrix();

}

void corpo(){
    glPushMatrix();
    glScaled(0.5,8,0.5);
    glTranslated(0,-1.3,-3);
    glutSolidCube(3);
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(anguloCamera, 0.0, 1.0, 0.0);
    corpo();

    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glPopMatrix();
    glPopMatrix();
    glRotatef(anguloZ, 0.0, 0.0, 1.0);
    helices();

    glColor3f(0.5,0.5,0.5);
    glutSolidSphere(2,20,20);

    glutSwapBuffers();
}

void init(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-25.0, 25.0, -25.0, 25.0, -250.0, 250.0);
    glEnable(GL_NORMALIZE);
}

void keyboard(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
       eixo = Z;
        c -= 0.05;
        glutPostRedisplay();
        break;
    case GLUT_KEY_RIGHT:
        eixo = Z;
        c += 0.05;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

void acelera(){
    if(c!= VELMAX){
           eixo = Z;
    c+= 0.03;
    }else
    c = VELMAX;

}

void Timer(int value){
    if(girar == true){
    acelera();
    glutPostRedisplay();
    glutTimerFunc(1000,Timer, 0.001);
    }
}

void mouse_button(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        girar = true;
        glutTimerFunc(1,Timer,1);
    }
    else if (button == GLUT_RIGHT_BUTTON)
    {
        girar = false;
        eixo = Z;
        c = 0;
        glutPostRedisplay();
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 50);
    glutCreateWindow("Catavento");
    glutIdleFunc(gira);
    glutDisplayFunc(display);

    glutSpecialFunc(keyboard);
    glutMouseFunc(mouse_button);
    init();
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
