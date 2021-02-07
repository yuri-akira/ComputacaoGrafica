#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

GLfloat light0_pos[] = {2.0f, 2.0f, 2.0f, 1.0f};
GLfloat white[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat black[] = {0.0f, 0.0f, 0.0f, 1.0f};

GLfloat angleX = 0.0f;
GLfloat angleY = 0.0f;
GLfloat angleZ = 0.0f;
GLfloat mouseX = 0.0;
GLfloat mouseY = 0.0;

void lightning(){
    glLightfv(GL_LIGHT0, GL_POSITION,light0_pos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, black);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, black);
    glLightfv(GL_LIGHT0, GL_SPECULAR, black);

    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.5f);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.15f);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.1f);

    GLfloat light1_pos[] = {mouseX, mouseY, 6.0f, 1.0f};
    glLightfv(GL_LIGHT1, GL_POSITION, light1_pos);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT1, GL_SPECULAR, white);
    GLfloat direction[] = {0.0f, 0.0f, -1.0f};
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direction);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 15.0f);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 5.0f);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
}


void init(){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 1.0,
    0.0, 0.0, 0.0,
    0.0, 1.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
    glViewport(0, 0, 500, 500);
    lightning();
    glPushMatrix();
}

void drawSphere(){
    GLfloat shininess;   //Coeficiente de reflexão da luz ambiente k_a
    GLfloat diffuse[4];  //Coeficiente de reflexão difusa k_d
    GLfloat specular[4]; //Coeficiente de reflexão especular k_s

    shininess = 65.0;
    diffuse[0] = 0.65;
    diffuse[1] = 0.0;
    diffuse[2] = 0.0;
    diffuse[3] = 1.0;
    specular[0] = 1.0;
    specular[1] = 1.0;
    specular[2] = 1.0;
    specular[3] = 1.0;
    glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,specular);
    glMaterialf(GL_FRONT,GL_SHININESS,shininess);

    glutSolidSphere(0.25,40,40);

    glEnd();
}

void displayFunc() {
        GLfloat diffuse[4];
        GLfloat specular[4];
        GLfloat ns;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa o buffer

        glMatrixMode(GL_MODELVIEW); //define que a matrix È a model view
        glLoadIdentity(); //carrega a matrix de identidade
        gluLookAt(0.0, 0.0, 1.0,   //posiÁ„o da c‚mera
                  0.0, 0.0, 0.0,   //para onde a c‚mera aponta
                  0.0, 1.0, 0.0);  //vetor view-up

        glPushMatrix();
        glRotatef(0.0,1.0,0.0,0.0);
        glRotatef(0.0,0.0,1.0,0.0);
        glRotatef(angleZ,0.0,0.0,1.0);

        glPushMatrix();
        glTranslatef(-1.5,0.0,0.0);
        drawSphere();
        glPopMatrix();

        glPushMatrix();
        glTranslatef (1.5,0.0,0.0);
        drawSphere();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.0,-1.5,0.0);
        drawSphere();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.0,1.5,0.0);
        drawSphere();
        glPopMatrix();

        glPopMatrix();

        lightning();

        glFlush();
}

void keyboard (unsigned char key, int x, int y){
    switch(key){
       case 'x':
       case 'X':
            angleX+=5.0f;
          break;
       case 'y':
       case 'Y':
            angleY+=5.0f;
          break;
      case 'z':
      case 'Z':
            angleZ+=5.0f;
          break;
      default:
          break;
    }
    glutPostRedisplay();
}

void mouseFunc(int botao, int estado, int x, int y){
    switch(botao){
    case GLUT_LEFT_BUTTON:
        if(estado== GLUT_DOWN){
            mouseX=(((float)x/((float)500/2))-1)*2;
            mouseY=-(((float)y/((float)500/2))-1)*2;
        }
                break;
    default:
        break;
    }
    glutPostRedisplay();
}


int main(int argc, char *argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(500,500);
    glutCreateWindow("Iluminacao");
    glutDisplayFunc(displayFunc);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouseFunc);
    init();
    glutMainLoop();
    return 0;
}
