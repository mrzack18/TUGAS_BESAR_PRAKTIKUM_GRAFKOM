#include <GL/glut.h>
#include <math.h>

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Latar belakang hitam
    glEnable(GL_DEPTH_TEST);           // Mengaktifkan depth test untuk tampilan 3D
}

void kotak(float x1,float y1,float z1,float x2,float y2,float z2){
    //depan
    glTexCoord2f(0.0, 0.0);
    glVertex3f(x1,y1,z1);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(x2,y1,z1);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(x2,y2,z1);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(x1,y2,z1);
    //atas
    glTexCoord2f(0.0, 0.0);
    glVertex3f(x1,y2,z1);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(x2,y2,z1);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(x2,y2,z2);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(x1,y2,z2);
    //belakang
    glTexCoord2f(0.0, 0.0);
    glVertex3f(x1,y2,z2);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(x2,y2,z2);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(x2,y1,z2);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(x1,y1,z2);
    //bawah
    glTexCoord2f(0.0, 0.0);
    glVertex3f(x1,y1,z2);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(x2,y1,z2);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(x2,y1,z1);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(x1,y1,z1);
    //samping kiri
    glTexCoord2f(0.0, 0.0);
    glVertex3f(x1,y1,z1);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(x1,y2,z1);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(x1,y2,z2);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(x1,y1,z2);
    //samping kanan
    glTexCoord2f(0.0, 0.0);
    glVertex3f(x2,y1,z1);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(x2,y2,z1);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(x2,y2,z2);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(x2,y1,z2);
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
    //antena router kiri
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    kotak(-15,0,-15,15,1,15);
    glEnd();
    glPopMatrix();
}

void lapang(){
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.6f,0.0f);
    kotak(-5.5,1,-3.25,5.5,1.02,3.25);
    glEnd();
    glPopMatrix();
}

void karpetOut(){
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.7f);
    kotak(-6,1,-3.25,6.01,1.025,-3.75);
    kotak(-6,1,3.25,6.01,1.025,3.75);
    kotak(-5.5,1,-3.25,-6,1.025,3.25);
    kotak(5.5,1,-3.25,6,1.025,3.25);
    glEnd();
    glPopMatrix();
}

void papanBoard(){
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.8f,0.8f,0.8f);
    kotak(-6,1,-3.75,6.01,1.1,-3.76);
    kotak(-6,1,3.75,6.01,1.1,3.76);
    kotak(-6,1,-3.76,-6.01,1.1,3.76);
    kotak(6,1,-3.76,6.01,1.1,3.76);
    glEnd();
    glPopMatrix();
}

void tribunTimur(){
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.5f,0.5f,0.5f);
    kotak(-6,1,-3.8,6.01,1.05,-5.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.05f);
    kotak(-6,1.05,-3.9,6.01,1.1,-3.98);
    glColor3f(0.0f,0.0f,0.1f);
    kotak(-6,1.1,-3.98,6.01,1.15,-4.06);
    glColor3f(0.0f,0.0f,0.15f);
    kotak(-6,1.15,-4.06,6.01,1.2,-4.14);
    glColor3f(0.0f,0.0f,0.2f);
    kotak(-6,1.2,-4.14,6.01,1.25,-4.22);
    glColor3f(0.0f,0.0f,0.25f);
    kotak(-6,1.25,-4.22,6.01,1.3,-4.3);
    glColor3f(0.0f,0.0f,0.3f);
    kotak(-6,1.3,-4.3,6.01,1.35,-4.38);
    glColor3f(0.0f,0.0f,0.35f);
    kotak(-6,1.35,-4.38,6.01,1.4,-4.46);
    glColor3f(0.0f,0.0f,0.4f);
    kotak(-6,1.4,-4.46,6.01,1.45,-4.54);
    glColor3f(0.0f,0.0f,0.45f);
    kotak(-6,1.45,-4.54,6.01,1.5,-4.62);
    glColor3f(0.0f,0.0f,0.5f);
    kotak(-6,1.5,-4.62,6.01,1.55,-4.7);
    glEnd();
    glPopMatrix();
}
void tribunBarat(){
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.5f,0.5f,0.5f);
    kotak(-6,1,3.8,6.01,1.1,5.8);

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.05f);
    kotak(-6,1.05,3.9,6.01,1.1,3.98);
    glColor3f(0.0f,0.0f,0.1f);
    kotak(-6,1.1,3.98,6.01,1.15,4.06);
    glColor3f(0.0f,0.0f,0.15f);
    kotak(-6,1.15,4.06,6.01,1.2,4.14);
    glColor3f(0.0f,0.0f,0.2f);
    kotak(-6,1.2,4.14,6.01,1.25,4.22);
    glColor3f(0.0f,0.0f,0.25f);
    kotak(-6,1.25,4.22,6.01,1.3,4.3);
    glColor3f(0.0f,0.0f,0.3f);
    kotak(-6,1.3,4.3,6.01,1.35,4.38);
    glColor3f(0.0f,0.0f,0.35f);
    kotak(-6,1.35,4.38,6.01,1.4,4.46);
    glColor3f(0.0f,0.0f,0.4f);
    kotak(-6,1.4,4.46,6.01,1.45,4.54);
    glColor3f(0.0f,0.0f,0.45f);
    kotak(-6,1.45,4.54,6.01,1.5,4.62);
    glColor3f(0.0f,0.0f,0.5f);
    kotak(-6,1.5,4.62,6.01,1.55,4.7);
    glEnd();
    glPopMatrix();
}

void tribunSelatan(){
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.5f,0.5f,0.5f);
    kotak(-6.04,1,-3.76,-8.04,1.1,3.76);

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.05f);
    kotak(-6.14,1.1,-3.76,-6.22,1.15,3.76);
    glColor3f(0.0f,0.0f,0.1f);
    kotak(-6.3,1.15,-3.76,-6.38,1.2,3.76);
    glEnd();
    glPopMatrix();
}

void tribunUtara(){
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.5f,0.5f,0.5f);
    kotak(6.04,1,-3.76,8.04,1.1,3.76);
    glEnd();
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Menggunakan posisi dan target kamera yang telah diupdate
    gluLookAt(9, 7, 7,     // Posisi kamera
              0, 0, 0,      // Titik yang dilihat
              0.0, 1.0, 0.0);                // Arah atas // Arah atas

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

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("TB STADION PERSIB");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}