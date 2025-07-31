#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#define TIEMPO_CICLO_MS 300

// Estructura de estado
typedef struct {
    bool encendido;
    bool pausa_sistema;
    bool detencion_emergencia;
    int piezas_procesadas;
    int piezas_defectuosas;
}  Estado_Sistema;

// Declaracion de prototipos
void iniciar_sistema(Estado_Sistema* sistema);
void imagen_menu();
void realizar_accion(Estado_Sistema* sistema, char tecla);
void mostrar_estado(Estado_Sistema sistema);
void procesar_pieza(Estado_Sistema* sistema);
void pausar_sistema(Estado_Sistema* sistema);
void reanudar_sistema(Estado_Sistema* sistema);
void detencion_emergencia(Estado_Sistema* sistema);
void proceso_principal(Estado_Sistema* sistema);
void guardar_defecto(int numero_pieza);


// -------------------MAIN--------------------

int main(){
    Estado_Sistema sistema = {false,false,false, 0, 0};
    proceso_principal(&sistema);

    return 0;
}

void imagen_menu(){
     printf("--- MENU CINTA INDUSTRIAL ---\n");
        printf("1. Encender sistema\n");
        printf("2. Apagar sistema\n");
        printf("3. Pausar sistema\n");
        printf("4. Reanudar sistema\n");
        printf("5. Mostrar estado\n");
        printf("6. Salir\n");
}

void proceso_principal(Estado_Sistema* sistema){
    imagen_menu();
    while (1) {
        if (sistema->encendido && !sistema->pausa_sistema && !sistema->detencion_emergencia) {
            procesar_pieza(sistema);
            mostrar_estado(*sistema);
            Sleep(TIEMPO_CICLO_MS);
        }
        if (_kbhit()){
                char tecla = _getch();
                realizar_accion(sistema, tecla);
        }
    }
}

void realizar_accion(Estado_Sistema* sistema, char tecla){
    switch(tecla) {
        case '1': iniciar_sistema(sistema); break;
        case '2': detencion_emergencia(sistema); break;
        case '3': pausar_sistema(sistema); break;
        case '4': reanudar_sistema(sistema); break;
        case '5': mostrar_estado(*sistema); break;
        case '6': exit(0); break;
        case 27 : exit(0); break; // ESC
        default: printf("Tecla inválida\n"); break;
    }
}

void iniciar_sistema (Estado_Sistema* sistema){
     sistema->encendido = true;
}

void mostrar_estado(Estado_Sistema sistema){
    printf ("\n----------------------------------------------------------\n");
    printf("        Sistema encendido: %s     [!]2[!] DETENCION DE EMERGENCIA [!]2[!]\n", sistema.encendido ? "Si" : "No");
    printf("        Sistema pausa: %s             [3] pausar sistema [3]\n", sistema.pausa_sistema ? "Si" : "No");
    printf("        Sistema emergencia: %s        [4] reanudar sistema [4]\n", sistema.detencion_emergencia ? "Si" : "No");
    printf("        Piezas procesadas  [%3d]      [5] estado actual [5] \n", sistema.piezas_procesadas);
    printf("        Piezas defectuosas [%3d]  [6][ESC] SALIR [6][ESC]\n", sistema.piezas_defectuosas);
    printf("--------------------------------------------------------------\n");
}

void procesar_pieza(Estado_Sistema* sistema){
    sistema->piezas_procesadas++;
    // Simulo las piezas defectuosas con una probabilidad del 10%
    if (rand() %10 < 1){
        sistema->piezas_defectuosas++;
        printf("[PIEZA DEFECTUOSA]\n");
        guardar_defecto(sistema->piezas_procesadas);
    } else {
        printf("Pieza analizada correctamente\n");
    }
    Sleep(TIEMPO_CICLO_MS);
}

void pausar_sistema(Estado_Sistema* sistema){
    if (!sistema->encendido || sistema->pausa_sistema || sistema->detencion_emergencia){
        printf("El sistema no se puede pausar porque :\n");
        if (!sistema->encendido) printf("El sistema se encuentra apagado\n");
        if (sistema->pausa_sistema) printf ("El sistema ya se encuentra pausado\n");
        if (sistema->detencion_emergencia) printf ("El sistema se encuentra en estado de emergencia y es necesario reiniciar [ESC]\n");
    } else {
        sistema->pausa_sistema = true;
        printf("\nSistema pausado correctamente\n");
        mostrar_estado(*sistema);
    }
}

void reanudar_sistema (Estado_Sistema* sistema){
    if (!sistema->encendido || !sistema->pausa_sistema || sistema->detencion_emergencia){
        printf("El sistema no se puede reanudar porque :\n");
        if (!sistema->encendido) printf("El sistema se encuentra apagado\n");
        if (!sistema->pausa_sistema) printf ("El sistema ya se encuentra funcionando\n");
        if (sistema->detencion_emergencia) printf ("El sistema se encuentra en estado de emergencia y es necesario reiniciar [ESC]\n");
    } else {
        sistema->pausa_sistema = false;
        printf("\nSistema reanudado correctamente\n");
        mostrar_estado(*sistema);
    }
}

void detencion_emergencia(Estado_Sistema* sistema){
    sistema->detencion_emergencia = true;
    printf("  [EMERGENCIA] se detecto un error critico [REINICIAR] -> [ESC]\n");
}

void guardar_defecto(int numero_pieza){
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);

    char nombre_archivo[50];
    strftime(nombre_archivo, sizeof(nombre_archivo), "registro_%Y-%m-%d.txt", tm_info);

    FILE *archivo = fopen(nombre_archivo, "a");
    if (archivo == NULL){
        printf("Error al abrir el archivo de registro\n");
        return;
    }
    char fecha_hora[30];
    strftime(fecha_hora, sizeof(fecha_hora), "%H:%M:%S", tm_info);
    fprintf(archivo, "Pieza %d: [DEFECTUOSA] - %s\n", numero_pieza, fecha_hora);
    fclose(archivo);
}

