#include <iostream>
#include <string>
#include <vector>
#include <regex>

struct Asistencia {
    std::string fecha;
    std::string materia;
    std::string estado; // asistio, falta, tardanza
};

struct Estudiante {
    std::string nombre;
    std::vector<std::string> materias;
    std::vector<Asistencia> asistencias;
};

void mostrarEstudiante(const Estudiante& estudiante) {
    std::cout << "Nombre: " << estudiante.nombre << std::endl;
    std::cout << "Materias: " << std::endl;
    for (const auto& materia : estudiante.materias) {
        std::cout << "  - " << materia << std::endl;
    }
    std::cout << "Asistencias: " << std::endl;
    for (const auto& asistencia : estudiante.asistencias) {
        std::cout << "  Fecha: " << asistencia.fecha << ", Materia: " << asistencia.materia << ", Estado: " << asistencia.estado << std::endl;
    }
}

// Función para mostrar todos los estudiantes
void mostrarTodosEstudiantes(const std::vector<Estudiante>& estudiantes) {
    for (const auto& estudiante : estudiantes) {
        mostrarEstudiante(estudiante);
        std::cout << "-------------------------" << std::endl;
    }
}

// Función para agregar un estudiante
void agregarEstudiante(std::vector<Estudiante>& estudiantes, const Estudiante& nuevoEstudiante) {
    estudiantes.push_back(nuevoEstudiante);
}

// Función para eliminar un estudiante por nombre
void eliminarEstudiante(std::vector<Estudiante>& estudiantes, const std::string& nombre) {
    for (auto it = estudiantes.begin(); it != estudiantes.end(); ++it) {
        if (it->nombre == nombre) {
            estudiantes.erase(it);
            std::cout << "Estudiante eliminado correctamente." << std::endl;
            return;
        }
    }
    std::cout << "Estudiante no encontrado." << std::endl;
}

// Validar si la fecha es válida (formato dd/mm/aaaa)
bool validarFecha(const std::string& fecha) {
    std::regex fechaRegex("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/\\d{4}$");
    return std::regex_match(fecha, fechaRegex);
}

// Validar si el estado es válido (asistio, falta, tardanza)
bool validarEstado(const std::string& estado) {
    return (estado == "asistio" || estado == "falta" || estado == "tardanza");
}

// Función para registrar asistencia
void registrarAsistencia(Estudiante& estudiante) {
    Asistencia nuevaAsistencia;
    std::cout << "Ingrese la fecha (dd/mm/aaaa): ";
    std::cin.ignore();
    std::getline(std::cin, nuevaAsistencia.fecha);
    if (!validarFecha(nuevaAsistencia.fecha)) {
        std::cout << "Error: Fecha invalida. Debe ser en formato dd/mm/aaaa." << std::endl;
        return;
    }

    std::cout << "Ingrese la materia: ";
    std::getline(std::cin, nuevaAsistencia.materia);

    std::cout << "Ingrese el estado (asistio, falta, tardanza): ";
    std::getline(std::cin, nuevaAsistencia.estado);
    if (!validarEstado(nuevaAsistencia.estado)) {
        std::cout << "Error: Estado invalido. Solo se permite: asistio, falta, tardanza." << std::endl;
        return;
    }

    estudiante.asistencias.push_back(nuevaAsistencia);
}

int main() {
    // Lista de estudiantes
    std::vector<Estudiante> estudiantes;

    int opcion;
    do {
        std::cout << "\nMenu de gestion de estudiantes y asistencias:" << std::endl;
        std::cout << "1. Agregar estudiante" << std::endl;
        std::cout << "2. Eliminar estudiante" << std::endl;
        std::cout << "3. Mostrar todos los estudiantes" << std::endl;
        std::cout << "4. Registrar asistencia" << std::endl;
        std::cout << "5. Salir" << std::endl;
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
            std::string nombre;
            std::cout << "Ingrese el nombre del estudiante para registrar asistencia: ";
            std::cin.ignore();
            std::getline(std::cin, nombre);

            for (auto& estudiante : estudiantes) {
                if (estudiante.nombre == nombre) {
                    registrarAsistencia(estudiante);
                    break;
                }
            }
        } else if (opcion == 5) {
            std::cout << "Saliendo..." << std::endl;
        } else {
            std::cout << "Opcion invalida, intente de nuevo." << std::endl;
        }
    } while (opcion != 5);

    return 0;
}
