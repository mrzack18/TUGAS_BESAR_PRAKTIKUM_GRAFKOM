#include <GL/glut.h>
#include <math.h>

float cameraAngleX = 0.0f;
float cameraAngleY = 0.0f;
float cameraDistance = 15.0f;
int isDragging = 0; // Status mouse (dragging atau tidak)
int lastX, lastY;   // Posisi terakhir mouse

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Latar belakang hitam
    glEnable(GL_DEPTH_TEST);           // Mengaktifkan depth test untuk tampilan 3D
}

void drawAxes() {
    glLineWidth(2.0);

    // Sumbu X (Merah)
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
        glVertex3f(-100.0, 0.0, 0.0);
        glVertex3f(100.0, 0.0, 0.0);
    glEnd();

    // Sumbu Y (Hijau)
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
        glVertex3f(0.0, -100.0, 0.0);
        glVertex3f(0.0, 100.0, 0.0);
    glEnd();

    // Sumbu Z (Biru)
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, -100.0);
        glVertex3f(0.0, 0.0, 100.0);
    glEnd();
}

void lahan(){
    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3);
    glScalef(20,0.2,20);
    glutSolidCube(1);
    glPopMatrix();
}

void lapang1(){
    glPushMatrix();
    glColor3f(0,0.6,0);
    glScalef(1.1,0.15,7.5);
    glutSolidCube(1);
    glPopMatrix();
}

void lapang2(){
    glPushMatrix();
    glColor3f(0,0.7,0);
    glScalef(1.1,0.15,7.5);
    glutSolidCube(1);
    glPopMatrix();
}

void lapang(){
    float x1 = 4.95;
    float x2 = 3.85;
    for (int i=0; i<5; i++){
        glPushMatrix();
        glTranslatef(x1,0.2,0);
        lapang1();
        glPopMatrix();
        x1 -= 2.2;
    }
    for (int i=0; i<5; i++){
        glPushMatrix();
        glTranslatef(x2,0.2,0);
        lapang2();
        glPopMatrix();
        x2 -= 2.2;
    }
}

void karpetOut(){
    glPushMatrix();
    
    glPopMatrix();
}

void papanBoard(){
    glPushMatrix();
    
    glPopMatrix();
}

void tribunTimur(){
    glPushMatrix();
    
    glPopMatrix();
}
void tribunBarat(){
    glPushMatrix();
    
    glPopMatrix();
}

void tribunSelatan(){
    glPushMatrix();
    
    glPopMatrix();
}

void tribunUtara(){
    glPushMatrix();
    
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Mengatur kamera menggunakan sudut dan jarak
    float eyeX = cameraDistance * sin(cameraAngleX) * cos(cameraAngleY);
    float eyeY = cameraDistance * sin(cameraAngleY);
    float eyeZ = cameraDistance * cos(cameraAngleX) * cos(cameraAngleY);

    gluLookAt(eyeX, eyeY, eyeZ,  // Posisi kamera
              0, 0, 0,           // Titik yang dilihat
              0.0, 1.0, 0.0);    // Arah atas

    drawAxes();
    lahan();
    lapang();
    karpetOut();
    papanBoard();
    tribunTimur();
    tribunBarat();
    tribunSelatan();
    tribunUtara();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (double)w / (double)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void mouseMotion(int x, int y) {
    if (isDragging) {
        // Perhitungan perubahan sudut berdasarkan pergerakan mouse
        float deltaX = (x - lastX) * 0.005f;
        float deltaY = (y - lastY) * 0.005f;

        cameraAngleX += deltaX;
        cameraAngleY += deltaY;

        // Membatasi sudut vertikal agar tidak melewati batas tertentu
        if (cameraAngleY > 1.5f) cameraAngleY = 1.5f;
        if (cameraAngleY < -1.5f) cameraAngleY = -1.5f;

        lastX = x;
        lastY = y;

        glutPostRedisplay();
    }
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            isDragging = 1;
            lastX = x;
            lastY = y;
        } else if (state == GLUT_UP) {
            isDragging = 0;
        }
    }
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("TB STADION PERSIB");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutMainLoop();
    return 0;
}