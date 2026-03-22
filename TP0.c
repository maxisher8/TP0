#include  <stdio.h>
#include  <stdbool.h>

main(){
    const int MAX_INTENTOS = 3;
    int intentos_usuario = 0;
    char respuesta = 'B';
    char respuesta = 'J';
    int puntaje = 0;
    printf("--prueba de iniciación para ingresar a los Magios iniciada--");
    printf("pregunta 1");
    scanf(" %c", &respuesta);
    validacion_respuesta(respuesta);
    intentos_usuario = correcion_respuesta(intentos_usuario, MAX_INTENTOS, &puntaje, respuesta, respuesta_correcta);
    if(intentos_usuario < MAX_INTENTOS){
        printf("pregunta 2");
        scanf(" %c", &respuesta);
    }
}
void validacion_respuesta(char respuesta){
    while (respuesta != 'A' || respuesta != 'B' || respuesta != 'J' || respuesta != 'S'){
        printf("respuesta incorrecta, vuelva a intentar: ");
        scanf(" %c", respuesta);
    }
}
int correcion_respuesta(int intentos, int MAX_INTENTOS, char respuesta, char respuesta_correcta){
    while(intentos < MAX_INTENTOS && respuesta != respuesta_correcta){
        printf("respuesta incorrecta, intente otra vez: ");
        respuesta = scanf(" %c");
        validacion_respuesta(respuesta);
        intentos = intentos + 1;
    }
    return intentos;
}
