#include <GL/glut.h>
#include <math.h>

bool showAxes = true;

float bolaRotasi = 0.0f; 
float bolaPosisiX = 0.0f; 
float bolaPosisiZ = 0.0f; 

float cameraAngleX = 0.0f;
float cameraAngleY = 0.0f;
float cameraDistance = 15.0f;
int isDragging = 0; 
int lastX, lastY;

void init()
{
    glClearColor(0.5, 0.5, 0.5, 1.0);
    glEnable(GL_DEPTH_TEST);
    
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void drawAxes()
{
    if (!showAxes)
    return;

    glLineWidth(2.0);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-100.0, 0.0, 0.0);
    glVertex3f(100.0, 0.0, 0.0);
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, -100.0, 0.0);
    glVertex3f(0.0, 100.0, 0.0);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, -100.0);
    glVertex3f(0.0, 0.0, 100.0);
    glEnd();
}

void lahan()
{
    glPushMatrix();
    glColor3f(0.6, 0.6, 0.6);
    glScalef(25, 0.2, 20);
    glutSolidCube(1);
    glPopMatrix();
}

void lapang1()
{
    glPushMatrix();
    glColor3f(0, 0.6, 0);
    glScalef(1.1, 0.15, 7.5);
    glutSolidCube(1);
    glPopMatrix();
}

void lapang2()
{
    glPushMatrix();
    glColor3f(0, 0.7, 0);
    glScalef(1.1, 0.15, 7.5);
    glutSolidCube(1);
    glPopMatrix();
}

void lapang()
{
    float x1 = 4.95;
    float x2 = 3.85;
    for (int i = 0; i < 5; i++)
    {
        glPushMatrix();
        glTranslatef(x1, 0.2, 0);
        lapang1();
        glPopMatrix();
        x1 -= 2.2;
    }
    for (int i = 0; i < 5; i++)
    {
        glPushMatrix();
        glTranslatef(x2, 0.2, 0);
        lapang2();
        glPopMatrix();
        x2 -= 2.2;
    }
}

void lapangOut()
{
    glPushMatrix();
    glColor3f(0,0.5,0);
    glTranslatef(0, 0.2, 4);
    glScalef(12, 0.15, 0.5);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,0.5,0);
    glTranslatef(0, 0.2, -4);
    glScalef(12, 0.15, 0.5);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,0.5,0);
    glTranslatef(-5.75,0.2,0);
    glScalef(0.5, 0.15, 7.5);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,0.5,0);
    glTranslatef(5.75, 0.2, 0);
    glScalef(0.5, 0.15, 7.5);
    glutSolidCube(1);
    glPopMatrix();
}

void papanIklan()
{
    glPushMatrix();
    glColor3f(0.9,0.9,0.9);
    glTranslatef(0,0.335,-4.255);
    glScalef(12.02,0.12,0.01);
    glutSolidCube(1);
    glPopMatrix();
    // glPushMatrix();
    // glColor3f(0.9,0.9,0.9);
    // glTranslatef(0,0.335,4.255);
    // glScalef(12.02,0.12,0.01);
    // glutSolidCube(1);
    // glPopMatrix();
    glPushMatrix();
    glColor3f(0.9,0.9,0.9);
    glTranslatef(-6.005,0.335,0);
    glScalef(0.01,0.12,8.5);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.9,0.9,0.9);
    glTranslatef(6.005,0.335,0);
    glScalef(0.01,0.12,8.5);
    glutSolidCube(1);
    glPopMatrix();
}

void tribunTimur()
{
    float yTranslasi = 0.465f;
    float zTranslasi = -6.31f;
    float zSkala = 2.9;
    float color = 0.95f;
    glPushMatrix();
    glColor3f(0,0,0.4);
    glTranslatef(0,0.23,-6.01);
    glScalef(12.02,0.2,3.5);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.25,0.25,0.25);
    glTranslatef(0,0.38,-6.26);
    glScalef(12.02,0.1,3);
    glutSolidCube(1);
    glPopMatrix();
    for(int i=0;i<25;i++){
        glPushMatrix();
        glColor3f(0, 0, color);
        glTranslatef(0,yTranslasi,zTranslasi);
        glScalef(12.02,0.07,zSkala);
        glutSolidCube(1);
        glPopMatrix();
        yTranslasi += 0.07;
        zTranslasi -= 0.05;
        zSkala -= 0.1;
        color -= 0.016;
    }
}
void tribunBarat()
{
    float yTranslasi = 0.465f;
    float zTranslasi = 6.31f;
    float zSkala = 2.9;
    float color = 0.95f;
    glPushMatrix();
    glColor3f(0,0,0.4);
    glTranslatef(0,0.23,6.01);
    glScalef(12.02,0.2,3.5);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.25,0.25,0.25);
    glTranslatef(0,0.38,6.26);
    glScalef(12.02,0.1,3);
    glutSolidCube(1);
    glPopMatrix();
    for(int i=0;i<25;i++){
        glPushMatrix();
        glColor3f(0,0,color);
        glTranslatef(0,yTranslasi,zTranslasi);
        glScalef(12.02,0.07,zSkala);
        glutSolidCube(1);
        glPopMatrix();
        yTranslasi += 0.07;
        zTranslasi += 0.05;
        zSkala -= 0.1;
        color -= 0.016;
    }
}

void tribunSelatan()
{
    float yTranslasi = 0.465f;
    float xTranslasi = -8.06f;
    float xSkala = 2.9;
    float color = 0.95f;
    glPushMatrix();
    glColor3f(0,0,0.4);
    glTranslatef(-7.76,0.23,0);
    glScalef(3.5,0.2,8.52);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.25,0.25,0.25);
    glTranslatef(-8.01,0.38,0);
    glScalef(3,0.1,8.52);
    glutSolidCube(1);
    glPopMatrix();
    for(int i=0;i<25;i++){
        glPushMatrix();
        glColor3f(0,0,color);
        glTranslatef(xTranslasi,yTranslasi,0);
        glScalef(xSkala,0.07,8.52);
        glutSolidCube(1);
        glPopMatrix();
        yTranslasi += 0.07;
        xTranslasi -= 0.05;
        xSkala -= 0.1;
        color -= 0.016;
    }
}

void tribunUtara()
{
    float yTranslasi = 0.465f;
    float xTranslasi = 8.06f;
    float xSkala = 2.9;
    float color = 0.95f;
    glPushMatrix();
    glColor3f(0,0,0.4);
    glTranslatef(7.76,0.23,0);
    glScalef(3.5,0.2,8.52);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.25,0.25,0.25);
    glTranslatef(8.01,0.38,0);
    glScalef(3,0.1,8.52);
    glutSolidCube(1);
    glPopMatrix();
    for(int i=0;i<25;i++){
        glPushMatrix();
        glColor3f(0,0,color);
        glTranslatef(xTranslasi,yTranslasi,0);
        glScalef(xSkala,0.07,8.52);
        glutSolidCube(1);
        glPopMatrix();
        yTranslasi += 0.07;
        xTranslasi += 0.05;
        xSkala -= 0.1;
        color -= 0.016;
    }
}

void tribun(){
    glPushMatrix();
    tribunTimur();
    tribunBarat();
    tribunSelatan();
    tribunUtara();
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,0,0.4);
    glTranslatef(-6.51,0.23,-4.76);
    glScalef(1,0.2,1);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,0,0.4);
    glTranslatef(6.51,0.23,-4.76);
    glScalef(1,0.2,1);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,0,0.4);
    glTranslatef(-6.51,0.23,4.76);
    glScalef(1,0.2,1);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,0,0.4);
    glTranslatef(6.51,0.23,4.76);
    glScalef(1,0.2,1);
    glutSolidCube(1);
    glPopMatrix();
}

void atapTribun(){
    glPushMatrix();
    glPopMatrix();
}

void gedung(){
    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(-7.76,0.455,-5.51);
    glScalef(1.5,0.65,2.5);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(-6.51,0.455,-6.01);
    glScalef(1,0.65,1.5);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(7.76,0.455,-5.51);
    glScalef(1.5,0.65,2.5);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(6.51,0.455,-6.01);
    glScalef(1,0.65,1.5);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(-7.76,0.455,5.51);
    glScalef(1.5,0.65,2.5);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(-6.51,0.455,6.01);
    glScalef(1,0.65,1.5);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(7.76,0.455,5.51);
    glScalef(1.5,0.65,2.5);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(6.51,0.455,6.01);
    glScalef(1,0.65,1.5);
    glutSolidCube(1);
    glPopMatrix();
}

void bola()
{
    glPushMatrix();
    glTranslatef(bolaPosisiX, 0.35f, bolaPosisiZ);
    glRotatef(bolaRotasi, 0.0f, 0.0f, 1.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glutSolidSphere(0.08, 20, 20);

    glColor3f(0.0f, 0.0f, 0.0f);
    glutWireSphere(0.07, 10, 10);

    glPopMatrix();
}

void matahari() {
    GLfloat light_position[] = { 0.0f, 18.0f, 0.0f, 1.0f };
    
    GLfloat light_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    
    glPushMatrix();
    glDisable(GL_LIGHTING);
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 10.0f, 0.0f);
    glutSolidSphere(1.0, 20, 20);
    glEnable(GL_LIGHTING);
    glPopMatrix();
}

void awanSatu()
{
    glPushMatrix();
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(-7.0f, 5.5f, 3.0f);
    glutSolidSphere(1.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(-6.5f, 5.9f, 2.4f);
    glutSolidSphere(1.15, 10, 11);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(-6.5f, 5.7f, 2.0f);
    glutSolidSphere(1.1, 10, 11);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(-5.2f, 5.7f, 2.7f);
    glutSolidSphere(1.5, 12, 10);
    glPopMatrix();

}

void awanDua() 
{
    glPushMatrix();
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(5.3f, 5.7f, -3.2f);
    glutSolidSphere(1.4, 12, 9.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(4.0f, 5.7f, -3.0f);
    glutSolidSphere(1.13, 12, 9.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(6.5f, 5.7f, -3.0f);
    glutSolidSphere(1.0, 12, 9.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(4.0f, 6.0f, -3.0f);
    glutSolidSphere(1.0, 12, 9.0);
    glPopMatrix();
}

void garisLapangan()
{
    glDisable(GL_LIGHTING);
    glLineWidth(2.0);
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_LINES);

    // Garis luar lapangan (persegi panjang)
    glVertex3f(-5.5f, 0.275f, -3.75f);
    glVertex3f(5.5f, 0.275f, -3.75f);
    glVertex3f(5.5f, 0.275f, -3.75f);
    glVertex3f(5.5f, 0.275f, 3.75f);
    glVertex3f(5.5f, 0.275f, 3.75f);
    glVertex3f(-5.5f, 0.275f, 3.75f);
    glVertex3f(-5.5f, 0.275f, 3.75f);
    glVertex3f(-5.5f, 0.275f, -3.75f);

    // Garis tengah
    glVertex3f(0.0f, 0.275f, -3.75f);
    glVertex3f(0.0f, 0.275f, 3.75f);

    // Kotak Penalti Kiri
    glVertex3f(-4.0f, 0.275f, -2.0f);
    glVertex3f(-4.0f, 0.275f, 2.0f);
    glVertex3f(-4.0f, 0.275f, -2.0f);
    glVertex3f(-5.5f, 0.275f, -2.0f);
    glVertex3f(-4.0f, 0.275f, 2.0f);
    glVertex3f(-5.5f, 0.275f, 2.0f);

    // Kotak Penalti Kanan
    glVertex3f(4.0f, 0.275f, -2.0f);
    glVertex3f(4.0f, 0.275f, 2.0f);
    glVertex3f(4.0f, 0.275f, -2.0f);
    glVertex3f(5.5f, 0.275f, -2.0f);
    glVertex3f(4.0f, 0.275f, 2.0f);
    glVertex3f(5.5f, 0.275f, 2.0f);

    // Kotak Gawang Kiri (dekat titik penalti kiri)
    glVertex3f(-5.5f, 0.275f, -1.0f); glVertex3f(-4.8f, 0.275f, -1.0f);
    glVertex3f(-5.5f, 0.275f, 1.0f);  glVertex3f(-4.8f, 0.275f, 1.0f);
    glVertex3f(-4.8f, 0.275f, -1.0f); glVertex3f(-4.8f, 0.275f, 1.0f);
    glVertex3f(-5.5f, 0.275f, -1.0f); glVertex3f(-5.5f, 0.275f, 1.0f);

    // Kotak Gawang Kanan (dekat titik penalti kanan)
    glVertex3f(5.5f, 0.275f, -1.0f);  glVertex3f(4.8f, 0.275f, -1.0f);
    glVertex3f(5.5f, 0.275f, 1.0f);   glVertex3f(4.8f,0.275f, 1.0f);
    glVertex3f(4.8f, 0.275f, -1.0f);  glVertex3f(4.8f, 0.275f, 1.0f);
    glVertex3f(5.5f, 0.275f, -1.0f);  glVertex3f(5.5f, 0.275f, 1.0f);

    glEnd();

    // Lingkaran tengah
    glBegin(GL_LINE_LOOP);
    float radius = 1.0f;
    int segments = 100;
    for (int i = 0; i < segments; i++)
    {
        float angle = 2.0f * M_PI * i / segments;
        float x = radius * cos(angle);
        float z = radius * sin(angle);
        glVertex3f(x, 0.35f, z);
    }
    glEnd();
}
void gawangKiri()
{
    float tiangTebal = 0.05f;
    float tiangTinggi = 0.8f;
    float tiangLebar = 1.2f;

    // Tiang Vertikal Kiri
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-5.5f, tiangTinggi / 2.0f, -tiangLebar / 2.0f);
    glScalef(tiangTebal, tiangTinggi, tiangTebal);
    glutSolidCube(1);
    glPopMatrix();

    // Tiang Vertikal Kanan
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-5.5f, tiangTinggi / 2.0f, tiangLebar / 2.0f);
    glScalef(tiangTebal, tiangTinggi, tiangTebal);
    glutSolidCube(1);
    glPopMatrix();

    // Tiang Horizontal Atas
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-5.5f, tiangTinggi, 0.0f);
    glScalef(tiangTebal, tiangTebal, tiangLebar);
    glutSolidCube(1);
    glPopMatrix();
}

void gawangKanan()
{
    float tiangTebal = 0.05f; 
    float tiangTinggi = 0.8f; 
    float tiangLebar = 1.2f;  

    // Tiang Vertikal Kiri
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(5.5f, tiangTinggi / 2.0f, -tiangLebar / 2.0f);
    glScalef(tiangTebal, tiangTinggi, tiangTebal);
    glutSolidCube(1);
    glPopMatrix();

    // Tiang Vertikal Kanan
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(5.5f, tiangTinggi / 2.0f, tiangLebar / 2.0f);
    glScalef(tiangTebal, tiangTinggi, tiangTebal);
    glutSolidCube(1);
    glPopMatrix();

    // Tiang Horizontal Atas
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(5.5f, tiangTinggi, 0.0f);
    glScalef(tiangTebal, tiangTebal, tiangLebar);
    glutSolidCube(1);
    glPopMatrix();
}

void keyboard(unsigned char key, int x, int y)
{
    float step = 0.1f; 
    float rotStep = 10.0f; 

    switch (key)
    {
    case 'x': // Toggle garis sumbu
        showAxes = !showAxes; 
        break;
    case 'w': // Bola maju
        bolaPosisiZ -= step;
        bolaRotasi += rotStep; 
        break;
    case 's': // Bola mundur
        bolaPosisiZ += step;
        bolaRotasi -= rotStep; 
        break;
    case 'a': // Bola ke kiri
        bolaPosisiX -= step;
        bolaRotasi += rotStep; 
        break;
    case 'd': // Bola ke kanan
        bolaPosisiX += step;
        bolaRotasi -= rotStep;
        break;
    case 27: // ESC untuk keluar
        exit(0);
        break;
    }
    glutPostRedisplay();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    float eyeX = cameraDistance * sin(cameraAngleX) * cos(cameraAngleY);
    float eyeY = cameraDistance * sin(cameraAngleY);
    float eyeZ = cameraDistance * cos(cameraAngleX) * cos(cameraAngleY);

    gluLookAt(eyeX, eyeY, eyeZ,
              0, 0, 0,
              0.0, 1.0, 0.0);

    // Pastikan normal vector dihitung dengan benar
    glEnable(GL_NORMALIZE);
    
    drawAxes();
    matahari();
    lahan();
    lapang();
    lapangOut();
    papanIklan();
    tribun();
    gedung();
    bola();
    awanSatu();
    awanDua();
    garisLapangan();
    gawangKiri();
    gawangKanan();
    
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (double)w / (double)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void mouseMotion(int x, int y)
{
    if (isDragging)
    {
        float deltaX = (x - lastX) * 0.005f;
        float deltaY = (y - lastY) * 0.005f;

        cameraAngleX += deltaX;
        cameraAngleY += deltaY;

        if (cameraAngleY > 1.5f)
            cameraAngleY = 1.5f;
        if (cameraAngleY < -1.5f)
            cameraAngleY = -1.5f;

        lastX = x;
        lastY = y;

        glutPostRedisplay();
    }
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            isDragging = 1;
            lastX = x;
            lastY = y;
        }
        else if (state == GLUT_UP)
        {
            isDragging = 0;
        }
    }

    // Zoom in dan zoom out menggunakan scroll mouse
    if (button == 3)
    {
        cameraDistance -= 0.5f;
        if (cameraDistance < 2.0f)
            cameraDistance = 2.0f;
        glutPostRedisplay();
    }
    else if (button == 4)
    {
        cameraDistance += 0.5f;
        if (cameraDistance > 50.0f)
            cameraDistance = 50.0f;
        glutPostRedisplay();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("TB STADION PERSIB");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}