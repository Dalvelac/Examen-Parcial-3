#include <iostream>
#include <string>
#include <vector>

// Definir la estructura Estudiante
struct Estudiante {
    std::string nombre;
    std::vector<std::string> materias;
};

// Funcion para mostrar los campos del estudiante
void mostrarEstudiante(const Estudiante& estudiante) {
    std::cout << "Nombre: " << estudiante.nombre << std::endl;
    std::cout << "Materias: " << std::endl;
    for (const auto& materia : estudiante.materias) {
        std::cout << "  - " << materia << std::endl;
    }
}

// Funcion para mostrar todos los estudiantes
void mostrarTodosEstudiantes(const std::vector<Estudiante>& estudiantes) {
    for (const auto& estudiante : estudiantes) {
        mostrarEstudiante(estudiante);
        std::cout << "-------------------------" << std::endl;
    }
}

// Funcion para agregar un estudiante
void agregarEstudiante(std::vector<Estudiante>& estudiantes, const Estudiante& nuevoEstudiante) {
    estudiantes.push_back(nuevoEstudiante);
}

// Funcion para eliminar un estudiante por nombre
void eliminarEstudiante(std::vector<Estudiante>& estudiantes, const std::string& nombre) {
    for (auto it = estudiantes.begin(); it != estudiantes.end(); ++it) {
        if (it->nombre == nombre) {
            estudiantes.erase(it);
            break;
        }
    }
}

int main() {
    // Lista de estudiantes
    std::vector<Estudiante> estudiantes;

    int opcion;
    do {
        std::cout << "\nMenu de gestion de materias de estudiantes:" << std::endl;
        std::cout << "1. Agregar estudiante" << std::endl;
        std::cout << "2. Eliminar estudiante" << std::endl;
        std::cout << "3. Mostrar todos los estudiantes" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        if (opcion == 1) {
            Estudiante nuevoEstudiante;
            std::cout << "Ingrese el nombre del estudiante: ";
            std::cin.ignore();
            std::getline(std::cin, nuevoEstudiante.nombre);

            int numMaterias;
            std::cout << "Ingrese el numero de materias: ";
            std::cin >> numMaterias;
            nuevoEstudiante.materias.resize(numMaterias);
            std::cin.ignore();
            for (int i = 0; i < numMaterias; ++i) {
                std::cout << "Ingrese el nombre de la materia " << i + 1 << ": ";
                std::getline(std::cin, nuevoEstudiante.materias[i]);
            }

            agregarEstudiante(estudiantes, nuevoEstudiante);
        } else if (opcion == 2) {
            std::string nombre;
            std::cout << "Ingrese el nombre del estudiante a eliminar: ";
            std::cin.ignore();
            std::getline(std::cin, nombre);
            eliminarEstudiante(estudiantes, nombre);
        } else if (opcion == 3) {
            std::cout << "\nLista de estudiantes:" << std::endl;
            mostrarTodosEstudiantes(estudiantes);
        } else if (opcion == 4) {
            std::cout << "Saliendo..." << std::endl;
        } else {
            std::cout << "Opcion invalida, intente de nuevo." << std::endl;
        }
    } while (opcion != 4);

    return 0;
}
