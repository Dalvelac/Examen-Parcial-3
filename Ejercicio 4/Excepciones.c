En C, aunque no existe un sistema integrado de manejo de excepciones como en C++, se pueden implementar técnicas para manejar errores y situaciones inesperadas. Algunas formas comunes incluyen:

    Verificación de valores de retorno:
        En C, las funciones suelen devolver un valor que indica el estado de la operación. Por ejemplo, 0 o un valor positivo puede indicar éxito, mientras que -1 puede indicar error.
        Al utilizar funciones estándar como fopen() o malloc(), se debe verificar siempre el valor de retorno (por ejemplo, si fopen() devuelve NULL, indica que no se pudo abrir el archivo).

FILE *file = fopen("data.txt", "r");
if (file == NULL) {
    printf("Error: No se pudo abrir el archivo.\n");
    return 1;
}

Uso de códigos de error:

    Se pueden definir códigos de error específicos mediante constantes (#define) para cada posible error, lo cual permite a la función indicar el tipo de error producido.
    Los códigos de error se pueden gestionar con switch o if para responder adecuadamente a diferentes errores.

#define ERROR_FECHA_INVALIDA 1
#define ERROR_ESTADO_INVALIDO 2

int validarFecha(const char *fecha) {
    int dia, mes, anio;
    if (sscanf(fecha, "%d/%d/%d", &dia, &mes, &anio) != 3) {
        return ERROR_FECHA_INVALIDA;
    }
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || anio < 1000 || anio > 9999) {
        return ERROR_FECHA_INVALIDA;
    }
    return 0;  // No hay error
}

int main() {
    char fecha[11];
    printf("Ingrese la fecha (dd/mm/aaaa): ");
    scanf("%10s", fecha);
    int resultado = validarFecha(fecha);
    if (resultado == ERROR_FECHA_INVALIDA) {
        printf("Error: Fecha invalida. Intente de nuevo.\n");
    }
}

Uso de assert() para verificar condiciones:

    La macro assert() de la biblioteca <assert.h> se utiliza para verificar condiciones que deberían ser siempre verdaderas. Si la condición es falsa, el programa se detiene mostrando un mensaje de error que indica la línea donde falló.
    assert() es útil para encontrar errores de lógica durante el desarrollo.

#include <assert.h>

void calcularPromedio(int numEstudiantes) {
    assert(numEstudiantes > 0);  // Verificar que el número de estudiantes sea mayor que cero
    // Código para calcular el promedio
}

Manejo con setjmp() y longjmp():

    C proporciona funciones como setjmp() y longjmp() para manejar "saltos" en la ejecución, que pueden considerarse como un tipo primitivo de manejo de excepciones.
    setjmp() guarda el estado del programa y longjmp() permite volver a ese punto en caso de error.
    Esta técnica es más avanzada y rara vez se utiliza, ya que es difícil de mantener y puede complicar la lógica del programa.

#include <setjmp.h>
#include <stdio.h>

jmp_buf buffer;

void funcionQueFalla() {
    printf("Ocurrió un error. Saltando de vuelta.\n");
    longjmp(buffer, 1);
}

int main() {
    if (setjmp(buffer) == 0) {
        printf("Intentando hacer algo...\n");
        funcionQueFalla();  // Simular un error
    } else {
        printf("Error manejado y vuelto al punto seguro.\n");
    }
    return 0;
}

Uso de mensajes de error y stderr:

    Cuando ocurre un error, se debe proporcionar al usuario un mensaje significativo para entender qué falló. Se puede usar fprintf(stderr, "...") para enviar mensajes de error al flujo de error estándar.
    Esto es útil para diferenciar los mensajes normales de los errores.

if (numEstudiantes < 0) {
    fprintf(stderr, "Error: El número de estudiantes no puede ser negativo.\n");
    return -1;
}

Funciones de manejo de errores propias:

    Puedes definir funciones específicas para manejar errores en diferentes escenarios. Estas funciones imprimen mensajes o realizan limpiezas necesarias.

    void manejarError(const char *mensaje) {
        fprintf(stderr, "Error: %s\n", mensaje);
        // Realizar acciones adicionales si es necesario, como liberar recursos
    }

    int main() {
        if (/* alguna condición de error */) {
            manejarError("Algo salió mal");
            return 1;
        }
    }

En resumen, aunque C no tiene excepciones como C++, puedes manejar errores mediante verificación de códigos de retorno, uso de macros como assert(), manejo de errores mediante setjmp()/longjmp(), y funciones específicas para manejar errores. Esto hace que el manejo de errores en C sea más explícito y basado en convenciones, pero si se sigue un enfoque sistemático, se puede lograr un manejo adecuado de errores y situaciones inesperadas.