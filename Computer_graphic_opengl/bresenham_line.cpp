#include <GL/glut.h>
#include<iostream>
#include <cmath>
#define M_PI       3.14159265358979323846
using namespace std;

void pushPixel(int x, int y){
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}


void calcul_angle(float a){
    double angle_in_radiant = atan(a);
    cout << "Goc : " << angle_in_radiant * 180 / M_PI;
}
void Bresenham(int x1, int y1, int x2, int y2)
{
    pushPixel(x1, y1);
    float dx = x2 - x1;
    float dy = y2 - y1;
    float a;
    if(dx){ 
        a = dy / dx;
        calcul_angle(a);
        float b = y1 - a*x1;
        float d1, d2;
        if(0 <= a && a <= 1 ){     // đường thẳng hợp với trục Ox một góc alpha với 0 <= alpha <= 45, x y đồng biến 
        
            glBegin(GL_POINTS);
            for(int x = x1; x < x2; x++)
            {
                d1 = a*(x + 1) + b - y1;
                d2 = y1 + 1 - a*(x + 1) - b;
                // float d = d1 - d2;
                if(d2 < d1)
                {
                    y1 += 1;
                }
            
                cout << "y = " << y1 << "  d = " << d1 - d2 << endl;
        
                glVertex2i(x, y1);
            
            } 
            glEnd();
            
            
        }
        else if(a > 1){     // đường thẳng hợp với trục Ox một góc alpha với 45 < alpha < 90, x đồng biến y
            glBegin(GL_POINTS);
            for(int y = y1; y < y2; y++){
                d1 = (y + 1 - b) / a - x1;
                d2 = x1 + 1 - (y + 1 -b) / a;
                if(d2 < d1)
                {
                    x1 += 1;
                }
                glVertex2i(x1, y);
            }
            glEnd();
            
        }
        else if(-1 <= a && a < 0){ // đường thẳng hợp với trục Ox một góc alpha với 0 < alpha <= 45, x y nghịch biến
            cout << "HIHIHI";
            glBegin(GL_POINTS);
            for(int x = x1; x < x2; x++)
            {
                d1 = a * (x+1) + b - y1 + 1;
                d2 = y1 - a*x - b;
                if(d1 < d2)
                {
                    y1 -= 1;
                }
                glVertex2i(x, y1);
            }
            glEnd();
        }
        else if(a < -1){ // đường thẳng hợp với trục Ox một góc alpha với 45 < alpha < 90, x y nghịch biến
            glBegin(GL_POINTS);
            for (int y = y1; y > y2; y--)
            {
                d1 = (y - 1 - b) / a - x1;
                d2 = x1 + 1 - (y - 1 - b) / a;
                if(d2 < d1)
                {
                    x1 += 1;
                }
                glVertex2i(x1, y);
            }


            glEnd();
        }
    }
    else{
        glBegin(GL_POINTS); 
        for(int y = y1; y < y2; y++){
            glVertex2i(x1, y);
        }
        glEnd();
    }
}
void init() {
    // Thiet lap che do chieu 2D
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    // glTranslatef()
    
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0); // Màu xanh dương
    // Bresenham( 100, 300, 300, 300);
    // Bresenham(300, 100, 300, 300);
    // Bresenham(100, 300, 300, 100);
    // glColor3f(1.0, 0.0, 0.0);
    // Bresenham(100, 100, 300, 100);
    // Bresenham(100, 300, 300, 100);
    // Bresenham(100, 100, 100, 300);
    // Bresenham(250, 500, 500, 250);
    Bresenham(132, 86, 250, 450);
    Bresenham(132, 86, 440, 308);
    Bresenham(250, 450, 368, 86);
    Bresenham(60, 308, 440, 308);
    Bresenham(60, 308, 368, 86);
    // Bresenham(420, 100, 400, 350);
    // Bresenham(100, 250, 400, 350);
    // Bresenham(100, 250, 500, 250);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Vẽ đường thẳng bằng Bresenham và OpenGL");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
