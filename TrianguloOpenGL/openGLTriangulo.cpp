// Jose Alfonzo 17-10012

// Importamos las librerias necesarias para OpenGl y para manejar ventanas
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Creamos el color de fondo #1b1e2b de la ventana
void colorFondo() {
    glClearColor(0.105f, 0.117f, 0.169f, 1.0f); 
}

void display() {
    // Borramos la pantalla con el color de fondo definido
    glClear(GL_COLOR_BUFFER_BIT);
    // Dibujamos un triangulo,asignandole los colores del ejemplo y
    // asignamos las coordenadas del vertice rojo,verde y azul
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f); 
    glVertex2f(-0.5f, -0.5f);
    glColor3f(0.0f, 0.0f, 1.0f); 
    glVertex2f(0.5f, -0.5f);
    glColor3f(1.0f, 0.0f, 0.0f); 
    glVertex2f(0.0f, 0.87f);
    glEnd();
    // Verificamos que todas las operaciones de dibujo se ejecuten
    glFlush();
}

int main() {
    // Inicializamos GLFW
    if (!glfwInit()) {
        return -1;
    }
    // Creamos una ventana de 600x450 pixeles
    GLFWwindow* window = glfwCreateWindow(600,450, "Triangulo Equilatero OpenGL", NULL, NULL);
    
    if (!window) {
        glfwTerminate();
        return -1;
    }
    // Aseguramos que todas las operaciones de dibujo y OpenGL se apliquen
    // a nuestra ventana
    glfwMakeContextCurrent(window);
    glewInit();

    // Llamamos a colorFondo() para crear el fondo que queremos
    colorFondo();
    // Mientras este abierta la ventana, dibujamos el triangulo, cambiamos
    // los buffers de ventana y procesamos eventos
    while (!glfwWindowShouldClose(window)) {
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    // Destruimos la ventana
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
