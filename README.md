https://github.com/Dalvelac/Examen-Parcial-3

# Condiciones de Entrega del Examen de Programación en C++

Estimado estudiante,

Para garantizar una correcta evaluación de tus habilidades y entendimiento en la programación en C++, hemos establecido un conjunto de condiciones que deberás seguir al momento de entregar tus respuestas al examen. La estructura y presentación de tu entrega son esenciales para facilitar el proceso de corrección y asegurarnos de que hemos evaluado todos tus esfuerzos de manera justa.

# Instrucciones para la entrega:

## 1.Repositorio en GitHub:

Todo tu trabajo debe estar contenido en un repositorio en GitHub.
Asegúrate de que el repositorio sea privado al inicio, y podrás hacerlo público después de que finalice el período de revisión del examen (si así lo deseas).

## 2.Fichero ZIP:

Una vez hayas terminado de resolver el examen, crea un archivo ZIP de todo el repositorio.
El nombre del archivo ZIP debe seguir el formato: Apellido_Nombre_ExamenCPP.zip (reemplaza Apellido y Nombre con tu apellido y nombre respectivamente).

## 3.Fichero README.md:

Dentro de tu repositorio, debes incluir un archivo README.md.
Este archivo debe contener:
El link directo a tu repositorio de GitHub.
Una descripción breve de cada uno de los ejercicios resueltos, con referencias a los archivos o carpetas específicos donde se puede encontrar cada solución.
El uso adecuado de Markdown en tu README.md para estructurar y formatear el contenido será valorado positivamente.

## 4.Envío:

Entrega el archivo ZIP a través de la plataforma o método que se te indique (por ejemplo, un sistema de gestión de aprendizaje, correo electrónico, etc.).
Asegúrate de enviar tu trabajo antes de la fecha y hora límite. Las entregas fuera de plazo pueden no ser evaluadas o incurrir en penalizaciones.

## 5.Otros aspectos a considerar:

Asegúrate de que tu código esté bien comentado, organizado y que sea fácil de leer y entender.
Si utilizas alguna referencia externa para resolver algún ejercicio, es esencial que lo cites en tu README.md.
Siguiendo estas condiciones y presentando tu trabajo de manera organizada, nos ayudarás a llevar a cabo un proceso de revisión más eficiente. Deseamos que demuestres todo tu conocimiento y habilidades en este examen. ¡Buena suerte!

# Parte 1: Preguntas de elección múltiple (20%)

## ¿Cuál es la principal diferencia entre la estructura básica del programa en C y C++?
b) C utiliza printf y scanf mientras que C++ utiliza std::cout y std::cin.

## ¿Qué es un espacio de nombres en C++?
a) Una característica que permite agrupar entidades como clases, objetos y funciones bajo un nombre.

## En programación orientada a objetos en C++, ¿qué es una clase?
d) Una plantilla para crear objetos, proporciona una definición inicial para el estado (miembros de datos) y el comportamiento (miembros de la función).

## ¿Qué son los templates en C++?
b) Permiten la creación de funciones y clases genéricas, es decir, que pueden trabajar con cualquier tipo de datos.





# Parte 2: Pregunta de desarrollo de código (80%)

En el marco de la globalización y la creciente tendencia de intercambio académico, las universidades internacionales están experimentando un auge en la diversidad de su población estudiantil. Estos estudiantes provienen de diferentes partes del mundo, con culturas, idiomas y antecedentes educativos distintos. Con tal diversidad, la administración académica enfrenta el desafío de gestionar de manera eficiente y personalizada la información de cada estudiante.

El "Centro Global de Estudios Avanzados" (CGEA) es una de esas universidades internacionales que ha decidido abordar este desafío. Con campus en cinco continentes y una comunidad estudiantil de más de 40,000 alumnos, el CGEA ha identificado la necesidad de modernizar su sistema de gestión académica para ofrecer un mejor servicio a sus estudiantes y, al mismo tiempo, optimizar sus procesos internos.

Para ello, han contratado a una firma de desarrollo de software especializada en soluciones educativas. La primera fase del proyecto consiste en evaluar y decidir qué lenguaje de programación es el más adecuado para implementar el nuevo sistema. Dado que el equipo de desarrollo tiene experiencia tanto en C como en C++, han decidido realizar una comparativa entre ambos lenguajes utilizando una estructura básica: la información del estudiante.

# Instrucciones para la Pregunta de Desarrollo de Código:

## Rúbrica

(30%) Implementación de la estructura Estudiante:

La estructura Estudiante está correctamente implementada tanto en C como en C++.
(20%) Implementación de la función mostrarEstudiante():

La función mostrarEstudiante() está correctamente implementada y muestra correctamente todos los campos de una instancia de Estudiante.
(30%) Comparación entre las dos implementaciones:

Se proporciona una comparación clara y correcta entre las implementaciones de C y C++.
(20%) Calidad del código:

Todo el código está bien comentado, bien organizado, sigue buenas prácticas de programación y se compila sin errores ni advertencias en CLion.

## Importante:
Todos los códigos deben ser originales. Se utilizarán herramientas de detección de plagio para verificar la originalidad del código.
El código debe estar bien documentado y organizado.
Se debe incluir un archivo README con instrucciones sobre cómo compilar y ejecutar el programa.
El código debe compilarse sin errores ni advertencias en CLion.

## Ejercicio 1 Estructura del Estudiante explicación del codigo realizado.

1. Estructura_Estudiantes.cpp

Este archivo contiene una implementación en C++ para gestionar información de estudiantes utilizando estructuras.
Descripción:

    Estructura: Define una estructura Estudiante con los campos:
        nombre: Almacena el nombre del estudiante (cadena de texto).
        edad: Almacena la edad del estudiante (entero).
        promedio: Almacena el promedio del estudiante (número decimal).
    Funciones:
        mostrarEstudiante: Muestra los valores de los campos de un estudiante en la consola.
    Flujo del programa:
        Crea un objeto de la estructura Estudiante.
        Asigna valores a los campos del objeto.
        Llama a la función mostrarEstudiante para imprimir los valores en la consola.

Ejemplo de salida:

Nombre: Juan Perez
Edad: 20
Promedio: 8.5

2. Estructura_Estudiantes.c

Este archivo contiene una implementación similar, pero utilizando C.
Descripción:

    Estructura: Define una estructura Estudiante con los mismos campos que en la versión de C++.
    Funciones:
        mostrarEstudiante: Recibe un puntero a un objeto Estudiante y muestra los valores de sus campos utilizando la función printf.
    Flujo del programa:
        Crea una variable de tipo Estudiante.
        Utiliza strcpy para asignar un valor al campo nombre.
        Asigna valores a los campos edad y promedio.
        Llama a la función mostrarEstudiante pasando la dirección del objeto.

Ejemplo de salida:

Nombre: Juan Perez
Edad: 20
Promedio: 8.50

Comparativa entre las implementaciones

    C++: Utiliza características modernas como cadenas de texto (std::string) y funciones miembro que hacen que el código sea más legible y seguro.
    C: Usa métodos más tradicionales, como arreglos de caracteres (char[]) y punteros, que requieren una gestión más manual pero son útiles en sistemas más básicos.


## Ejercicio 2 Gestión de Materias explicación del codigo realizado:
1. Gestion_estudiantes.c

Implementación en C para manejar información de estudiantes y las materias que cursan.
Funcionalidades:

    Estructura Estudiante:
        nombre: Nombre del estudiante (arreglo de caracteres).
        materias: Lista de materias que cursa (matriz de cadenas).
        num_materias: Número total de materias inscritas.
    Funciones principales:
        mostrarEstudiante: Muestra el nombre y las materias de un estudiante.
        mostrarTodosEstudiantes: Lista la información de todos los estudiantes.
        agregarEstudiante: Permite añadir un nuevo estudiante con sus materias.
        eliminarEstudiante: Elimina un estudiante especificado por su nombre.
    Flujo del programa:
        Permite al usuario agregar estudiantes, eliminarlos o mostrar la lista completa.
        Utiliza un menú interactivo con opciones numeradas.
        Maneja hasta un máximo de 100 estudiantes.

Ejemplo de menú:

Menu de gestion de materias de estudiantes:
1. Agregar estudiante
2. Eliminar estudiante
3. Mostrar todos los estudiantes
4. Salir
Seleccione una opcion:

2. Gestion_Estudiantes.cpp

Versión del programa escrita en C++, utilizando características modernas del lenguaje.
Funcionalidades:

    Estructura Estudiante:
        nombre: Nombre del estudiante (cadena std::string).
        materias: Lista de materias que cursa (vector std::vector<std::string>).
    Funciones principales:
        mostrarEstudiante: Muestra el nombre y las materias de un estudiante.
        mostrarTodosEstudiantes: Lista la información de todos los estudiantes.
        agregarEstudiante: Añade un nuevo estudiante a la lista.
        eliminarEstudiante: Elimina un estudiante por su nombre utilizando iteradores.
    Flujo del programa:
        Ofrece un menú interactivo similar al de la versión en C.
        Utiliza contenedores dinámicos (std::vector) para manejar un número ilimitado de estudiantes.
        Implementa funcionalidades modernas como la gestión de memoria automática.

Ejemplo de menú:

Menu de gestion de materias de estudiantes:
1. Agregar estudiante
2. Eliminar estudiante
3. Mostrar todos los estudiantes
4. Salir
Seleccione una opcion:

Comparativa entre las implementaciones

    C: Más básica, con gestión manual de memoria y limitaciones en el tamaño de los datos (arreglos fijos).
    C++: Más flexible, utiliza cadenas dinámicas y contenedores STL para mayor eficiencia y facilidad de uso.

## Ejercicio 3 Registro de Asistencia explicación del codigo realizado :
1. Asistencia.cpp

Implementación en C++ para manejar estudiantes, materias y asistencias.
Funcionalidades:

    Estructuras:
        Asistencia: Almacena los detalles de asistencia, incluyendo:
            fecha (formato dd/mm/aaaa).
            materia.
            estado (asistió, falta, tardanza).
        Estudiante: Contiene:
            nombre.
            Lista de materias (vector dinámico).
            Lista de registros de asistencia (vector dinámico).
    Funciones principales:
        mostrarEstudiante: Muestra la información del estudiante, incluyendo sus materias y asistencias.
        mostrarTodosEstudiantes: Lista todos los estudiantes y sus detalles.
        agregarEstudiante: Añade un nuevo estudiante y sus materias.
        eliminarEstudiante: Elimina un estudiante por su nombre.
        registrarAsistencia: Añade un registro de asistencia validando la fecha y el estado.
    Validación:
        Verifica que la fecha cumpla el formato dd/mm/aaaa.
        Asegura que el estado sea uno de los valores permitidos.
    Flujo del programa:
        Ofrece un menú interactivo con opciones para gestionar estudiantes y sus asistencias.
        Utiliza contenedores STL (std::vector) para manejar listas dinámicas de estudiantes y asistencias.

Ejemplo de menú:

Menu de gestion de estudiantes y asistencias:
1. Agregar estudiante
2. Eliminar estudiante
3. Mostrar todos los estudiantes
4. Registrar asistencia
5. Salir
Seleccione una opcion:

2. Asistenciac.c

Versión en C para gestionar estudiantes, materias y asistencias.
Funcionalidades:

    Estructuras:
        Asistencia: Similar a la versión en C++, incluye:
            fecha (arreglo de caracteres, formato dd/mm/aaaa).
            materia.
            estado (asistió, falta, tardanza).
        Estudiante: Contiene:
            nombre.
            Lista de materias (arreglo fijo).
            Lista de registros de asistencia (arreglo fijo).
            Contadores para materias y asistencias.
    Funciones principales:
        mostrarEstudiante: Imprime la información del estudiante.
        mostrarTodosEstudiantes: Lista todos los estudiantes y sus detalles.
        agregarEstudiante: Permite añadir un nuevo estudiante con sus materias.
        eliminarEstudiante: Elimina un estudiante por su nombre.
        registrarAsistencia: Añade un registro de asistencia validando datos.
    Validación:
        Comprueba que la fecha tenga el formato correcto y que el estado sea válido.
    Flujo del programa:
        Ofrece un menú interactivo similar al de la versión en C++.
        Usa arreglos estáticos para manejar estudiantes y asistencias, limitados por tamaño máximo.

Ejemplo de menú:

Menu de gestion de estudiantes y asistencias:
1. Agregar estudiante
2. Eliminar estudiante
3. Mostrar todos los estudiantes
4. Registrar asistencia
5. Salir
Seleccione una opcion:

Comparativa entre las implementaciones

    C++:
        Utiliza contenedores dinámicos (std::vector), lo que permite gestionar un número variable de estudiantes y registros sin restricciones.
        Emplea cadenas de texto (std::string) y expresiones regulares para la validación.
    C:
        Depende de arreglos estáticos para estudiantes, materias y asistencias, con tamaños máximos definidos.
        Usa funciones tradicionales de C para manipulación de cadenas (strcpy, strcmp) y validación de datos.

## Ejercicio 4 Manejo de Excepciones  explicación del codigo realizado:
1. Excepciones.cpp

Implementación en C++ con manejo de excepciones.
Funcionalidades:

    Excepciones personalizadas:
        FechaInvalidaException: Lanzada cuando la fecha no cumple el formato dd/mm/aaaa.
        EstadoInvalidoException: Lanzada cuando el estado no es asistió, falta o tardanza.
    Estructuras:
        Asistencia: Almacena detalles como:
            fecha (formato dd/mm/aaaa).
            materia.
            estado.
        Estudiante: Contiene:
            nombre.
            Lista dinámica de materias.
            Lista dinámica de registros de asistencia.
    Funciones principales:
        validarFecha: Verifica que la fecha cumpla el formato correcto.
        validarEstado: Asegura que el estado sea uno de los valores válidos.
        registrarAsistencia: Registra una nueva asistencia, lanzando excepciones en caso de errores.
        mostrarEstudiante, mostrarTodosEstudiantes, agregarEstudiante, eliminarEstudiante: Para gestionar estudiantes y sus registros.
    Flujo del programa:
        Presenta un menú interactivo para añadir, eliminar y listar estudiantes, así como para registrar asistencias.
        Maneja errores mediante excepciones, mejorando la robustez del programa.

Ejemplo de menú:

Menu de gestion de estudiantes y asistencias:
1. Agregar estudiante
2. Eliminar estudiante
3. Mostrar todos los estudiantes
4. Registrar asistencia
5. Salir
Seleccione una opcion:

2. ExcepcionesC.c

Versión en C con validaciones manuales.
Funcionalidades:

    Estructuras:
        Asistencia: Similar a la versión en C++, incluye:
            fecha (arreglo de caracteres, formato dd/mm/aaaa).
            materia.
            estado.
        Estudiante: Contiene:
            nombre.
            Lista de materias (arreglo fijo).
            Lista de registros de asistencia (arreglo fijo).
            Contadores para materias y asistencias.
    Funciones principales:
        validarFecha: Comprueba que la fecha tenga el formato correcto.
        validarEstado: Asegura que el estado sea válido.
        registrarAsistencia: Solicita datos del usuario y valida entradas antes de registrar la asistencia.
        mostrarEstudiante, mostrarTodosEstudiantes, agregarEstudiante, eliminarEstudiante: Gestionan estudiantes y registros.
    Flujo del programa:
        Presenta un menú interactivo para gestionar estudiantes y asistencias.
        Realiza validaciones manuales y notifica errores mediante mensajes.

Ejemplo de menú:

Menu de gestion de estudiantes y asistencias:
1. Agregar estudiante
2. Eliminar estudiante
3. Mostrar todos los estudiantes
4. Registrar asistencia
5. Salir
Seleccione una opcion:

Comparativa entre las implementaciones

    C++:
        Usa excepciones para manejar errores, lo que simplifica la gestión y mejora la legibilidad.
        Implementa listas dinámicas con std::vector.
    C:
        Depende de validaciones manuales y notificaciones de errores mediante mensajes.
        Utiliza arreglos estáticos, limitados por tamaños predefinidos.

# Conclusión:
Con base en tu experiencia y las implementaciones desarrolladas:
## ¿Cuál de los dos lenguajes consideras más adecuado para el proyecto del CGEA?
Si bien C es eficiente y adecuado para tareas de bajo nivel, su enfoque procedimental limita la capacidad de construir sistemas complejos y escalables. C++ es la opción ideal para el proyecto del CGEA debido a su equilibrio entre rendimiento, flexibilidad y herramientas modernas que simplifican el desarrollo y mantenimiento del sistema.(Realizada con chat gpt)
## ¿Qué recomendaciones harías al equipo de desarrollo del CGEA para la siguiente fase del proyecto?
Siguiendo estas recomendaciones, el CGEA podrá garantizar un desarrollo eficiente y exitoso de su sistema de gestión académica, ofreciendo un servicio moderno, seguro y escalable que responda a las necesidades de su diversa población estudiantil y optimice los procesos internos de la universidad.(Realizada con chat gpt)
