#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ESTUDIANTES 100
#define MAX_MATERIAS 10
#define MAX_ASISTENCIAS 100

// Definir la estructura Asistencia
typedef struct {
    char fecha[11];
    char materia[50];
    char estado[10]; // asistio, falta, tardanza
} Asistencia;

// Definir la estructura Estudiante
typedef struct {
    char nombre[50];
    char materias[MAX_MATERIAS][50];
    int num_materias;
    Asistencia asistencias[MAX_ASISTENCIAS];
    int num_asistencias;
} Estudiante;

// Función para validar si la fecha es válida (formato dd/mm/aaaa)
bool validarFecha(const char* fecha) {
    int dia, mes, anio;
    if (sscanf(fecha, "%d/%d/%d", &dia, &mes, &anio) != 3) {
        return false;
    }
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || anio < 1000 || anio > 9999) {
        return false;
    }
    return true;
}

// Validar si el estado es válido (asistio, falta, tardanza)
bool validarEstado(const char* estado) {
    return (strcmp(estado, "asistio") == 0 || strcmp(estado, "falta") == 0 || strcmp(estado, "tardanza") == 0);
}

// Función para mostrar los campos del estudiante
void mostrarEstudiante(const Estudiante* estudiante) {
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Materias: \n");
    for (int i = 0; i < estudiante->num_materias; i++) {
        printf("  - %s\n", estudiante->materias[i]);
    }
    printf("Asistencias: \n");
    for (int i = 0; i < estudiante->num_asistencias; i++) {
        printf("  Fecha: %s, Materia: %s, Estado: %s\n", estudiante->asistencias[i].fecha, estudiante->asistencias[i].materia, estudiante->asistencias[i].estado);
    }
}

// Función para mostrar todos los estudiantes
void mostrarTodosEstudiantes(const Estudiante estudiantes[], int num_estudiantes) {
    for (int i = 0; i < num_estudiantes; i++) {
        mostrarEstudiante(&estudiantes[i]);
        printf("-------------------------\n");
    }
}

// Función para agregar un estudiante
void agregarEstudiante(Estudiante estudiantes[], int* num_estudiantes) {
    if (*num_estudiantes >= MAX_ESTUDIANTES) {
        printf("No se pueden agregar mas estudiantes.\n");
        return;
    }

    Estudiante nuevoEstudiante;
    printf("Ingrese el nombre del estudiante: ");
    getchar();
    fgets(nuevoEstudiante.nombre, sizeof(nuevoEstudiante.nombre), stdin);
    nuevoEstudiante.nombre[strcspn(nuevoEstudiante.nombre, "\n")] = 0;

    printf("Ingrese el numero de materias: ");
    scanf("%d", &nuevoEstudiante.num_materias);
    getchar();
    for (int i = 0; i < nuevoEstudiante.num_materias; i++) {
        printf("Ingrese el nombre de la materia %d: ", i + 1);
        fgets(nuevoEstudiante.materias[i], sizeof(nuevoEstudiante.materias[i]), stdin);
        nuevoEstudiante.materias[i][strcspn(nuevoEstudiante.materias[i], "\n")] = 0;
    }

    nuevoEstudiante.num_asistencias = 0;
    estudiantes[*num_estudiantes] = nuevoEstudiante;
    (*num_estudiantes)++;
}

// Función para eliminar un estudiante por nombre
void eliminarEstudiante(Estudiante estudiantes[], int* num_estudiantes, const char* nombre) {
    for (int i = 0; i < *num_estudiantes; i++) {
        if (strcmp(estudiantes[i].nombre, nombre) == 0) {
            for (int j = i; j < *num_estudiantes - 1; j++) {
                estudiantes[j] = estudiantes[j + 1];
            }
            (*num_estudiantes)--;
            printf("Estudiante eliminado correctamente.\n");
            return;
        }
    }
    printf("Estudiante no encontrado.\n");
}

// Función para registrar asistencia
void registrarAsistencia(Estudiante* estudiante) {
    if (estudiante->num_asistencias >= MAX_ASISTENCIAS) {
        printf("No se pueden agregar mas asistencias.\n");
        return;
    }

    Asistencia nuevaAsistencia;
    do {
        printf("Ingrese la fecha (dd/mm/aaaa): ");
        fgets(nuevaAsistencia.fecha, sizeof(nuevaAsistencia.fecha), stdin);
        nuevaAsistencia.fecha[strcspn(nuevaAsistencia.fecha, "\n")] = 0; // Eliminar salto de línea
        if (!validarFecha(nuevaAsistencia.fecha)) {
            printf("Fecha invalida. Intente de nuevo.\n");
        }
    } while (!validarFecha(nuevaAsistencia.fecha));

    printf("Ingrese la materia: ");
    fgets(nuevaAsistencia.materia, sizeof(nuevaAsistencia.materia), stdin);
    nuevaAsistencia.materia[strcspn(nuevaAsistencia.materia, "\n")] = 0; // Eliminar salto de línea

    do {
        printf("Ingrese el estado (asistio, falta, tardanza): ");
        fgets(nuevaAsistencia.estado, sizeof(nuevaAsistencia.estado), stdin);
        nuevaAsistencia.estado[strcspn(nuevaAsistencia.estado, "\n")] = 0; // Eliminar salto de línea
        if (!validarEstado(nuevaAsistencia.estado)) {
            printf("Estado invalido. Intente de nuevo.\n");
        }
    } while (!validarEstado(nuevaAsistencia.estado));

    estudiante->asistencias[estudiante->num_asistencias] = nuevaAsistencia;
    estudiante->num_asistencias++;
}

int main() {
    // Lista de estudiantes
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int num_estudiantes = 0;

    int opcion;
    do {
        printf("\nMenu de gestion de estudiantes y asistencias:\n");
        printf("1. Agregar estudiante\n");
        printf("2. Eliminar estudiante\n");
        printf("3. Mostrar todos los estudiantes\n");
        printf("4. Registrar asistencia\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar();

        if (opcion == 1) {
            agregarEstudiante(estudiantes, &num_estudiantes);
        } else if (opcion == 2) {
            char nombre[50];
            printf("Ingrese el nombre del estudiante a eliminar: ");
            fgets(nombre, sizeof(nombre), stdin);
            nombre[strcspn(nombre, "\n")] = 0; // Eliminar salto de línea
            eliminarEstudiante(estudiantes, &num_estudiantes, nombre);
        } else if (opcion == 3) {
            printf("\nLista de estudiantes:\n");
            mostrarTodosEstudiantes(estudiantes, num_estudiantes);
        } else if (opcion == 4) {
            char nombre[50];
            printf("Ingrese el nombre del estudiante para registrar asistencia: ");
            fgets(nombre, sizeof(nombre), stdin);
            nombre[strcspn(nombre, "\n")] = 0; // Eliminar salto de línea

            for (int i = 0; i < num_estudiantes; i++) {
                if (strcmp(estudiantes[i].nombre, nombre) == 0) {
                    registrarAsistencia(&estudiantes[i]);
                    break;
                }
            }
        } else if (opcion == 5) {
            printf("Saliendo...\n");
        } else {
            printf("Opcion invalida, intente de nuevo.\n");
        }
    } while (opcion != 5);

    return 0;
}