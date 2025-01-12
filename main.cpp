#include <GL/glut.h>
#include <math.h>

bool showAxes = true; // Penanda untuk menampilkan atau menyembunyikan garis sumbu

float bolaRotasi = 0.0f;  // Sudut rotasi bola
float bolaPosisiX = 0.0f; // Posisi bola di sumbu X
float bolaPosisiZ = 0.0f; // Posisi bola di sumbu Z

float cameraAngleX = 0.0f;
float cameraAngleY = 0.0f;
float cameraDistance = 15.0f;
int isDragging = 0; // Status mouse (dragging atau tidak)
int lastX, lastY;   // Posisi terakhir mouse

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0); // Latar belakang hitam
    glEnable(GL_DEPTH_TEST);          // Mengaktifkan depth test untuk tampilan 3D
}

void drawAxes()
{
    if (!showAxes) // Jika showAxes = false, keluar dari fungsi
        return;

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

void lahan()
{
    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3);
    glScalef(20, 0.2, 20);
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

void karpetOut()
{
    glPushMatrix();
    glColor3f(0, 0, 0.7);
    glTranslatef(0, 0.2, 4);
    glScalef(12, 0.15, 0.5);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0, 0, 0.7);
    glTranslatef(0, 0.2, -4);
    glScalef(12, 0.15, 0.5);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0, 0, 0.7);
    glTranslatef(0, 0.2, -4);
    glScalef(12, 0.15, 0.5);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0, 0, 0.7);
    glTranslatef(-5.75, 0.2, 0);
    glScalef(0.5, 0.15, 7.5);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0, 0, 0.7);
    glTranslatef(5.75, 0.2, 0);
    glScalef(0.5, 0.15, 7.5);
    glutSolidCube(1);
    glPopMatrix();
}

void papanBoard()
{
    glPushMatrix();

    glPopMatrix();
}

void tribunTimur()
{
    glPushMatrix();

    glPopMatrix();
}
void tribunBarat()
{
    glPushMatrix();

    glPopMatrix();
}

void tribunSelatan()
{
    glPushMatrix();

    glPopMatrix();
}

void tribunUtara()
{
    glPushMatrix();

    glPopMatrix();
}

void bola()
{
    glPushMatrix();

    // Translasi bola ke posisi
    glTranslatef(bolaPosisiX, 0.35f, bolaPosisiZ);
    // Rotasi bola di sekitar sumbu Z
    glRotatef(bolaRotasi, 0.0f, 0.0f, 1.0f);

    // Bola utama (warna putih)
    glColor3f(1.0f, 1.0f, 1.0f);
    glutSolidSphere(0.08, 20, 20);

    // Garis bola (wireframe)
    glColor3f(0.0f, 0.0f, 0.0f);
    glutWireSphere(0.07, 10, 10);

    glPopMatrix();
}

void awanSatu()
{
    glPushMatrix(); // Awan 1
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(-7.0f, 5.5f, 3.0f);
    glutSolidSphere(1.0, 10, 10);
    glPopMatrix();

    glPushMatrix(); // Awan 2
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(-6.5f, 5.9f, 2.4f);
    glutSolidSphere(1.15, 10, 11);
    glPopMatrix();

    glPushMatrix(); // Awan 3
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(-6.5f, 5.7f, 2.0f);
    glutSolidSphere(1.1, 10, 11);
    glPopMatrix();

    glPushMatrix(); // Awan 4
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(-5.2f, 5.7f, 2.7f);
    glutSolidSphere(1.5, 12, 10);
    glPopMatrix();
}

void awanDua()
{
    glPushMatrix(); // Awan 5
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(5.3f, 5.7f, -3.2f);
    glutSolidSphere(1.4, 12, 9.0);
    glPopMatrix();

    glPushMatrix(); // Awan 6
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(4.0f, 5.7f, -3.0f);
    glutSolidSphere(1.13, 12, 9.0);
    glPopMatrix();

    glPushMatrix(); // Awan 7
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(6.5f, 5.7f, -3.0f);
    glutSolidSphere(1.0, 12, 9.0);
    glPopMatrix();

    glPushMatrix(); // Awan 8
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(4.0f, 6.0f, -3.0f);
    glutSolidSphere(1.0, 12, 9.0);
    glPopMatrix();
}

void garisLapangan()
{
    glLineWidth(2.0);
    glColor3f(1.0f, 1.0f, 1.0f); // Warna putih untuk garis lapangan

    glBegin(GL_LINES);

    // Garis luar lapangan (persegi panjang)
    glVertex3f(-5.5f, 0.35f, -3.75f);
    glVertex3f(5.5f, 0.35f, -3.75f); // Garis bawah
    glVertex3f(5.5f, 0.35f, -3.75f);
    glVertex3f(5.5f, 0.35f, 3.75f); // Garis kanan
    glVertex3f(5.5f, 0.35f, 3.75f);
    glVertex3f(-5.5f, 0.35f, 3.75f); // Garis atas
    glVertex3f(-5.5f, 0.35f, 3.75f);
    glVertex3f(-5.5f, 0.35f, -3.75f); // Garis kiri

    // Garis tengah
    glVertex3f(0.0f, 0.35f, -3.75f);
    glVertex3f(0.0f, 0.35f, 3.75f); // Garis tengah vertikal

    // Kotak Penalti Kiri
    glVertex3f(-4.0f, 0.35f, -2.0f);
    glVertex3f(-4.0f, 0.35f, 2.0f); // Garis vertikal kiri
    glVertex3f(-4.0f, 0.35f, -2.0f);
    glVertex3f(-5.5f, 0.35f, -2.0f); // Garis horizontal atas
    glVertex3f(-4.0f, 0.35f, 2.0f);
    glVertex3f(-5.5f, 0.35f, 2.0f); // Garis horizontal bawah

    // Kotak Penalti Kanan
    glVertex3f(4.0f, 0.35f, -2.0f);
    glVertex3f(4.0f, 0.35f, 2.0f); // Garis vertikal kanan
    glVertex3f(4.0f, 0.35f, -2.0f);
    glVertex3f(5.5f, 0.35f, -2.0f); // Garis horizontal atas
    glVertex3f(4.0f, 0.35f, 2.0f);
    glVertex3f(5.5f, 0.35f, 2.0f); // Garis horizontal bawah

    glEnd();

    // Lingkaran tengah
    glBegin(GL_LINE_LOOP);
    float radius = 1.0f; // Radius lingkaran
    int segments = 100;  // Jumlah segmen untuk membuat lingkaran halus
    for (int i = 0; i < segments; i++)
    {
        float angle = 2.0f * M_PI * i / segments; // Sudut tiap segmen
        float x = radius * cos(angle);
        float z = radius * sin(angle);
        glVertex3f(x, 0.35f, z); // Y tetap untuk menjaga lingkaran di permukaan
    }
    glEnd();
}

void keyboard(unsigned char key, int x, int y)
{
    float step = 0.1f;     // Langkah translasi
    float rotStep = 10.0f; // Langkah rotasi

    switch (key)
    {
    case 'x':                 // Toggle garis sumbu
        showAxes = !showAxes; // Balik nilai showAxes
        break;
    case 'w': // Bola maju
        bolaPosisiZ -= step;
        bolaRotasi += rotStep; // Rotasi saat maju
        break;
    case 's': // Bola mundur
        bolaPosisiZ += step;
        bolaRotasi -= rotStep; // Rotasi saat mundur
        break;
    case 'a': // Bola ke kiri
        bolaPosisiX -= step;
        bolaRotasi += rotStep; // Rotasi saat ke kiri
        break;
    case 'd': // Bola ke kanan
        bolaPosisiX += step;
        bolaRotasi -= rotStep; // Rotasi saat ke kanan
        break;
    case 27: // ESC untuk keluar
        exit(0);
        break;
    }
    glutPostRedisplay(); // Render ulang
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Mengatur kamera menggunakan sudut dan jarak
    float eyeX = cameraDistance * sin(cameraAngleX) * cos(cameraAngleY);
    float eyeY = cameraDistance * sin(cameraAngleY);
    float eyeZ = cameraDistance * cos(cameraAngleX) * cos(cameraAngleY);

    gluLookAt(eyeX, eyeY, eyeZ, // Posisi kamera
              0, 0, 0,          // Titik yang dilihat
              0.0, 1.0, 0.0);   // Arah atas

    drawAxes();
    lahan();
    lapang();
    karpetOut();
    papanBoard();
    tribunTimur();
    tribunBarat();
    tribunSelatan();
    tribunUtara();
    bola();
    awanSatu();
    awanDua();
    garisLapangan();

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
        // Perhitungan perubahan sudut berdasarkan pergerakan mouse
        float deltaX = (x - lastX) * 0.005f;
        float deltaY = (y - lastY) * 0.005f;

        cameraAngleX += deltaX;
        cameraAngleY += deltaY;

        // Membatasi sudut vertikal agar tidak melewati batas tertentu
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