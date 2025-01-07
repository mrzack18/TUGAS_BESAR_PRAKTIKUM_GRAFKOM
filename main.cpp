#include <GL/glut.h>

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Latar belakang hitam
    glEnable(GL_DEPTH_TEST);           // Mengaktifkan depth test untuk tampilan 3D
}

void drawAxes() {
    glLineWidth(2.0);

    // Sumbu X (Merah)
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
        glVertex3f(-1.0, 0.0, 0.0);
        glVertex3f(1.0, 0.0, 0.0);
    glEnd();

    // Sumbu Y (Hijau)
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
        glVertex3f(0.0, -1.0, 0.0);
        glVertex3f(0.0, 1.0, 0.0);
    glEnd();

    // Sumbu Z (Biru)
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, -1.0);
        glVertex3f(0.0, 0.0, 1.0);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Atur kamera
    gluLookAt(2.0, 2.0, 2.0,  // Posisi kamera
              0.0, 0.0, 0.0,  // Titik yang dilihat
              0.0, 1.0, 0.0); // Arah atas

    drawAxes();

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
    glutCreateWindow("Garis Cartesius 3D");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}