#include <stdio.h>
#include <string.h>

// Definir la estructura Estudiante
typedef struct {
    char nombre[50];
    int edad;
    float promedio;
} Estudiante;

// Función para mostrar los campos del estudiante
void mostrarEstudiante(const Estudiante* estudiante) {
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Edad: %d\n", estudiante->edad);
    printf("Promedio: %.2f\n", estudiante->promedio);
}

int main() {
    // Crear un objeto de la estructura Estudiante
    Estudiante estudiante1;

    // Asignar valores a los campos del estudiante
    strcpy(estudiante1.nombre, "Juan Perez");
    estudiante1.edad = 20;
    estudiante1.promedio = 8.5;
    mostrarEstudiante(&estudiante1);

    return 0;
}