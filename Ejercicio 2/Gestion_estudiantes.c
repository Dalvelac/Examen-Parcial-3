#include <stdio.h>
#include <string.h>

// Definir la estructura Estudiante
typedef struct {
    char nombre[50];
    char materias[10][50];
    int num_materias;
} Estudiante;

// Función para mostrar los campos del estudiante
void mostrarEstudiante(const Estudiante* estudiante) {
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Materias: \n");
    for (int i = 0; i < estudiante->num_materias; i++) {
        printf("  - %s\n", estudiante->materias[i]);
    }
}

// Función para mostrar todos los estudiantes
void mostrarTodosEstudiantes(const Estudiante estudiantes[], int num_estudiantes) {
    for (int i = 0; i < num_estudiantes; i++) {
        mostrarEstudiante(&estudiantes[i]);
        printf("-------------------------\n");
    }
}

// Funcion para agregar un estudiante
void agregarEstudiante(Estudiante estudiantes[], int* num_estudiantes) {
    if (*num_estudiantes >= 100) {
        printf("No se pueden agregar mas estudiantes.\n");
        return;
    }

    Estudiante nuevoEstudiante;
    printf("Ingrese el nombre del estudiante: ");
    getchar();
    fgets(nuevoEstudiante.nombre, sizeof(nuevoEstudiante.nombre), stdin);
    nuevoEstudiante.nombre[strcspn(nuevoEstudiante.nombre, "\n")] = 0; // Eliminar salto de línea

    printf("Ingrese el numero de materias: ");
    scanf("%d", &nuevoEstudiante.num_materias);
    getchar();
    for (int i = 0; i < nuevoEstudiante.num_materias; i++) {
        printf("Ingrese el nombre de la materia %d: ", i + 1);
        fgets(nuevoEstudiante.materias[i], sizeof(nuevoEstudiante.materias[i]), stdin);
        nuevoEstudiante.materias[i][strcspn(nuevoEstudiante.materias[i], "\n")] = 0; // Eliminar salto de línea
    }

    estudiantes[*num_estudiantes] = nuevoEstudiante;
    (*num_estudiantes)++;
}

// Funcion para eliminar un estudiante por nombre
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

int main() {
    // Lista de estudiantes
    Estudiante estudiantes[100];
    int num_estudiantes = 0;

    int opcion;
    do {
        printf("\nMenu de gestion de materias de estudiantes:\n");
        printf("1. Agregar estudiante\n");
        printf("2. Eliminar estudiante\n");
        printf("3. Mostrar todos los estudiantes\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            agregarEstudiante(estudiantes, &num_estudiantes);
        } else if (opcion == 2) {
            char nombre[50];
            printf("Ingrese el nombre del estudiante a eliminar: ");
            getchar();
            fgets(nombre, sizeof(nombre), stdin);
            nombre[strcspn(nombre, "\n")] = 0; // Eliminar salto de línea
            eliminarEstudiante(estudiantes, &num_estudiantes, nombre);
        } else if (opcion == 3) {
            printf("\nLista de estudiantes:\n");
            mostrarTodosEstudiantes(estudiantes, num_estudiantes);
        } else if (opcion == 4) {
            printf("Saliendo...\n");
        } else {
            printf("Opcion invalida, intente de nuevo.\n");
        }
    } while (opcion != 4);

    return 0;
}
