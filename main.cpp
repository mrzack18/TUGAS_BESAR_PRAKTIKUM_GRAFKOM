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

float scaleAwan = 1.0f; // Skala awan

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
    glColor3f(0,0,0.7);
    glTranslatef(-5.75,0.2,0);
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
    glColor3f(0.9,0.9,0.9);
    glTranslatef(0,0.335,-4.255);
    glScalef(12.02,0.12,0.01);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.9,0.9,0.9);
    glTranslatef(0,0.335,4.255);
    glScalef(12.02,0.12,0.01);
    glutSolidCube(1);
    glPopMatrix();
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
    float color = 0.0f;
    glPushMatrix();
    glColor3f(0.4,0.4,0.4);
    glTranslatef(0,0.23,-6.01);
    glScalef(12.02,0.2,3.5);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.4,0.4,0.4);
    glTranslatef(0,0.38,-6.26);
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
        zTranslasi -= 0.05;
        zSkala -= 0.1;
        color += 0.05;
    }
}
void tribunBarat()
{
    float yTranslasi = 0.465f;
    float zTranslasi = 6.31f;
    float zSkala = 2.9;
    float color = 0.0f;
    glPushMatrix();
    glColor3f(0.4,0.4,0.4);
    glTranslatef(0,0.23,6.01);
    glScalef(12.02,0.2,3.5);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.4,0.4,0.4);
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
        color += 0.05;
    }
}

void tribunSelatan()
{
    float yTranslasi = 0.465f;
    float xTranslasi = -8.06f;
    float xSkala = 2.9;
    float color = 0.0f;
    glPushMatrix();
    glColor3f(0.4,0.4,0.4);
    glTranslatef(-7.76,0.23,0);
    glScalef(3.5,0.2,8.52);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.4,0.4,0.4);
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
        color += 0.05;
    }
}

void tribunUtara()
{
    float yTranslasi = 0.465f;
    float xTranslasi = 8.06f;
    float xSkala = 2.9;
    float color = 0.0f;
    glPushMatrix();
    glColor3f(0.4,0.4,0.4);
    glTranslatef(7.76,0.23,0);
    glScalef(3.5,0.2,8.52);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.4,0.4,0.4);
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
        color += 0.05;
    }
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
    glutSolidSphere(0.05, 20, 20);

    // Garis bola (wireframe)
    glColor3f(0.0f, 0.0f, 0.0f);
    glutWireSphere(0.05, 10, 10);

    glPopMatrix();
}

void matahari(){
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 10.0f, 0.0f);
    glutSolidSphere(1.0, 10, 10);
    glPopMatrix();
}

void awanSatu()
{
    glPushMatrix(); // Awan 1
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(-7.0f, 6.5f, 3.0f);
    glScalef(scaleAwan, scaleAwan, scaleAwan);
    glutSolidSphere(1.0, 10, 10);
    glPopMatrix();

    glPushMatrix(); // Awan 2
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(-6.5f, 6.9f, 2.4f);
    glScalef(scaleAwan, scaleAwan, scaleAwan);
    glutSolidSphere(1.15, 10, 11);
    glPopMatrix();

    glPushMatrix(); // Awan 3
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(-6.5f, 6.5f, 2.0f);
    glScalef(scaleAwan, scaleAwan, scaleAwan);
    glutSolidSphere(1.1, 10, 11);
    glPopMatrix();

    glPushMatrix(); // Awan 4
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(-5.2f, 6.5f, 2.7f);
    glScalef(scaleAwan, scaleAwan, scaleAwan);
    glutSolidSphere(1.5, 12, 10);
    glPopMatrix();
}

void awanDua()
{
    glPushMatrix(); // Awan 5
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(5.3f, 6.5f, -3.2f);
    glScalef(scaleAwan, scaleAwan, scaleAwan);
    glutSolidSphere(1.4, 12, 9.0);
    glPopMatrix();

    glPushMatrix(); // Awan 6
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(4.0f, 6.5f, -3.0f);
    glScalef(scaleAwan, scaleAwan, scaleAwan);
    glutSolidSphere(1.13, 12, 9.0);
    glPopMatrix();

    glPushMatrix(); // Awan 7
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(6.5f, 6.5f, -3.0f);
    glScalef(scaleAwan, scaleAwan, scaleAwan);
    glutSolidSphere(1.0, 12, 9.0);
    glPopMatrix();

    glPushMatrix(); // Awan 8
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(4.0f, 6.8f, -3.0f);
    glScalef(scaleAwan, scaleAwan, scaleAwan);
    glutSolidSphere(1.0, 12, 9.0);
    glPopMatrix();
}

void awanTiga()
{
    glPushMatrix(); // Awan 9
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(-5.0f, 6.5f, -3.2f);
    glScalef(scaleAwan, scaleAwan, scaleAwan);
    glutSolidSphere(1.4, 12, 9.0);
    glPopMatrix();

    glPushMatrix(); // Awan 10
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(-3.7f, 6.5f, -3.0f);
    glScalef(scaleAwan, scaleAwan, scaleAwan);
    glutSolidSphere(1.13, 12, 9.0);
    glPopMatrix();

    glPushMatrix(); // Awan 11
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(-6.2f, 6.5f, -3.0f);
    glScalef(scaleAwan, scaleAwan, scaleAwan);
    glutSolidSphere(1.0, 12, 9.0);
    glPopMatrix();

    glPushMatrix(); // Awan 12
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(-3.7f, 6.8f, -3.0f);
    glScalef(scaleAwan, scaleAwan, scaleAwan);
    glutSolidSphere(1.0, 12, 9.0);
    glPopMatrix();
}

void awanEmpat()
{
    glPushMatrix(); // Awan 13
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(5.3f, 6.5f, 3.2f);
    glScalef(scaleAwan, scaleAwan, scaleAwan);
    glutSolidSphere(1.4, 12, 9.0);
    glPopMatrix();

    glPushMatrix(); // Awan 14
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(4.0f, 6.5f, 3.0f);
    glScalef(scaleAwan, scaleAwan, scaleAwan);
    glutSolidSphere(1.13, 12, 9.0);
    glPopMatrix();

    glPushMatrix(); // Awan 15
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(6.5f, 6.5f, 3.0f);
    glScalef(scaleAwan, scaleAwan, scaleAwan);
    glutSolidSphere(1.0, 12, 9.0);
    glPopMatrix();

    glPushMatrix(); // Awan 16
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(4.0f, 6.8f, 3.0f);
    glScalef(scaleAwan, scaleAwan, scaleAwan);
    glutSolidSphere(1.0, 12, 9.0);
    glPopMatrix();
}

void pohon()
{
    glPushMatrix();
    glColor3f(0.5, 0.3, 0.0);
    glTranslatef(0, 0.15, 0);
    glScalef(0.3, 1.0, 0.3);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0, 0.5, 0);
    glTranslatef(0, 1.5, 0);
    glScalef(1.0, 1.0, 1.0);
    glutSolidSphere(1, 10, 7.0);
    glPopMatrix();
}

void pohonSudut()
{
    // Pohon di sudut kiri depan
    glPushMatrix();
    glTranslatef(-6.1, 0.5, 4.3);
    pohon();
    glPopMatrix();

    // Pohon di sudut kanan depan
    glPushMatrix();
    glTranslatef(6.1, 0.5, 4.3);
    pohon();
    glPopMatrix();

    // Pohon di sudut kiri belakang
    glPushMatrix();
    glTranslatef(-6.1, 0.5, -4.3);
    pohon();
    glPopMatrix();

    // Pohon di sudut kanan belakang
    glPushMatrix();
    glTranslatef(6.1, 0.5, -4.3);
    pohon();
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

    // Kotak Gawang Kiri (dekat titik penalti kiri)
    glVertex3f(-5.5f, 0.35f, -1.0f);
    glVertex3f(-4.8f, 0.35f, -1.0f); // Garis atas horizontal
    glVertex3f(-5.5f, 0.35f, 1.0f);
    glVertex3f(-4.8f, 0.35f, 1.0f); // Garis bawah horizontal
    glVertex3f(-4.8f, 0.35f, -1.0f);
    glVertex3f(-4.8f, 0.35f, 1.0f); // Garis vertikal kanan
    glVertex3f(-5.5f, 0.35f, -1.0f);
    glVertex3f(-5.5f, 0.35f, 1.0f); // Garis vertikal kiri

    // Kotak Gawang Kanan (dekat titik penalti kanan)
    glVertex3f(5.5f, 0.35f, -1.0f);
    glVertex3f(4.8f, 0.35f, -1.0f); // Garis atas horizontal
    glVertex3f(5.5f, 0.35f, 1.0f);
    glVertex3f(4.8f, 0.35f, 1.0f); // Garis bawah horizontal
    glVertex3f(4.8f, 0.35f, -1.0f);
    glVertex3f(4.8f, 0.35f, 1.0f); // Garis vertikal kiri
    glVertex3f(5.5f, 0.35f, -1.0f);
    glVertex3f(5.5f, 0.35f, 1.0f); // Garis vertikal kanan

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
void gawangKiri()
{
    float tiangTebal = 0.05f; // Ketebalan tiang
    float tiangTinggi = 0.8f; // Tinggi tiang vertikal
    float tiangLebar = 1.2f;  // Lebar gawang (tiang horizontal atas)

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
    float tiangTebal = 0.05f; // Ketebalan tiang
    float tiangTinggi = 0.8f; // Tinggi tiang vertikal
    float tiangLebar = 1.2f;  // Lebar gawang (tiang horizontal atas)

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

void benchKiri()
{
    glColor3f(1.0f, 1.0f, 1.0f);

    // Gambar bangku pemain di sisi kiri lapangan
    for (int i = 0; i < 5; i++) {
        glPushMatrix();
        glTranslatef(-2.0f + i * 1.0f, 0.2f, -4.50f);   // Bangku kiri sejajar sisi lapangan
        glScalef(0.4f, 0.3f, 0.5f);
        glutSolidCube(1.0f);
        glPopMatrix();
    }

    // Gambar atap pelindung
    glPushMatrix();
    glTranslatef(0.0f, 0.7f, -4.50f);  // Posisi atap di atas kursi kiri
    glScalef(3.0f, 0.1f, 1.0f);      // Ukuran atap horizontal lebih kecil
    glutSolidCube(1.0f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-1.4f, 0.35f, -4.50f);  // Posisi tiang kiri
    glScalef(0.1f, 0.7f, 0.1f);         // Ukuran tiang tipis vertikal
    glutSolidCube(1.0f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.4f, 0.35f, -4.50f);  // Posisi tiang kanan
    glScalef(0.1f, 0.7f, 0.1f);         // Ukuran tiang tipis vertikal
    glutSolidCube(1.0f);
    glPopMatrix();
}

void benchKanan() {
    glColor3f(1.0f, 1.0f, 1.0f);

    // Gambar bangku pemain di sisi kanan lapangan (berhadapan)
    for (int i = 0; i < 5; i++) {
        glPushMatrix();
        glTranslatef(-2.0f + i * 1.0f, 0.2f, 4.50f);   // Posisi bangku kanan sejajar lapangan
        glScalef(0.4f, 0.3f, 0.5f);
        glutSolidCube(1.0f);
        glPopMatrix();
    }

    // Gambar atap pelindung untuk bangku kanan
    glPushMatrix();
    glTranslatef(0.0f, 0.7f, 4.50f);  // Posisi atap di atas kursi kanan
    glScalef(3.0f, 0.1f, 1.0f);      // Ukuran atap horizontal lebih kecil
    glutSolidCube(1.0f);
    glPopMatrix();

    // Gambar tiang kiri bangku kanan
    glPushMatrix();
    glTranslatef(-1.4f, 0.35f, 4.50f);
    glScalef(0.1f, 0.7f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Gambar tiang kanan bangku kanan
    glPushMatrix();
    glTranslatef(1.4f, 0.35f, 4.50f);
    glScalef(0.1f, 0.7f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();
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
    case '+': // Perbesar skala awan
        scaleAwan += 0.1f;
        break;
    case '-': // Perkecil skala awan
        scaleAwan -= 0.1f;
        if (scaleAwan < 0.1f)
            scaleAwan = 0.1f; // Batas minimum skala
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
    matahari();
    awanSatu();
    awanDua();
    awanTiga();
    awanEmpat();
    pohonSudut(); // Tambahkan pohon di sudut
    garisLapangan();
    gawangKiri();
    gawangKanan();
    benchKanan();
    benchKiri();
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

    // Zoom in dan zoom out menggunakan scroll mouse
    if (button == 3) // Scroll ke atas
    {
        cameraDistance -= 0.5f;
        if (cameraDistance < 2.0f) // Membatasi zoom in
            cameraDistance = 2.0f;
        glutPostRedisplay();
    }
    else if (button == 4) // Scroll ke bawah
    {
        cameraDistance += 0.5f;
        if (cameraDistance > 50.0f) // Membatasi zoom out
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