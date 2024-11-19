#include <iostream>

struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
};

// Función para mostrar los campos del estudiante
void mostrarEstudiante(const Estudiante& estudiante) {
    std::cout << "Nombre: " << estudiante.nombre << std::endl;
    std::cout << "Edad: " << estudiante.edad << std::endl;
    std::cout << "Promedio: " << estudiante.promedio << std::endl;
}

int main() {
    // Crear un objeto de la estructura Estudiante
    Estudiante estudiante1;

    // Asignar valores a los campos del estudiante
    estudiante1.nombre = "Juan Perez";
    estudiante1.edad = 20;
    estudiante1.promedio = 8.5;
    mostrarEstudiante(estudiante1);

    return 0;
}