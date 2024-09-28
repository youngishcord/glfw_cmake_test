#include <GLFW/glfw3.h>
#include <math.h>
#include <.leif/

const int WIDTH = 800;
const int HEIGHT = 600;

// Функция для отрисовки синусоиды
void drawGraph() {
    glBegin(GL_LINE_STRIP); // Используем GL_LINE_STRIP для рисования линий

    for (float x = -1.0f; x <= 1.0f; x += 0.01f) {
        float y = sin(2 * 3.14159f * x); // вычисляем синус
        glVertex2f(x, y); // Задаем координаты вершины
    }

    glEnd();
}

int main() {
    // Инициализация GLFW
    if (!glfwInit()) {
        return -1;
    }

    // Создаем окно с контекстом OpenGL
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Graph Example", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Делаем контекст OpenGL текущим
    glfwMakeContextCurrent(window);

    // Устанавливаем видовую матрицу
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    // Основной цикл
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // Отрисовываем график
        drawGraph();

        // Меняем буферы для отображения
        glfwSwapBuffers(window);

        // Обрабатываем события
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
