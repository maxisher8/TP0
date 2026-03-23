#include  <stdio.h>
#include  <stdbool.h>


bool validacion_respuesta_usuario_bool(char respuesta){
    while (respuesta != 'S' || respuesta != 'N'){
        printf("respuesta incorrecta, vuelva a intentar: ");
        scanf(" %c", &respuesta);
    }
    if(respuesta == 'S'){
        return true;
    }
    else{
        return false;
    }
}
int correccion_respuesta_2(bool respuesta_usuario_2, int puntaje){
    if(respuesta_usuario_2){
        return puntaje + 50;
    }
    else{
        return puntaje - 300;
    }
}

void validacion_respuesta_usuario(char respuesta){
    while (respuesta != 'A' || respuesta != 'B' || respuesta != 'J' || respuesta != 'S'){
        printf("respuesta incorrecta, vuelva a intentar: ");
        scanf(" %c", &respuesta);
    }
}
/*Enviar un puntero del puntaje del usuario y dentro de correccion_respuesta sumarle o restarle los puntos*/
int correcion_respuesta_usuario(int intentos, int MAX_INTENTOS, char respuesta){
    while(intentos < MAX_INTENTOS && respuesta != 'J'){
        printf("respuesta incorrecta, intente otra vez: ");
        scanf(" %c", &respuesta);
        validacion_respuesta_usuario(respuesta);
        intentos = intentos + 1;
    }
    return intentos;
}

int main(){
    const int MAX_INTENTOS = 3;
    int intentos_usuario = 0;
    char respuesta_usuario = 'B';
    int puntaje = 0;
    bool respuesta_usuario_bool = true;
    printf("--prueba de iniciación para ingresar a los Magios iniciada--");
    printf("pregunta 1");
    scanf(" %c", &respuesta_usuario);
    validacion_respuesta_usuario(respuesta_usuario);
    intentos_usuario = correcion_respuesta_usuario(intentos_usuario, MAX_INTENTOS, respuesta_usuario);
    if(intentos_usuario < MAX_INTENTOS){
        printf("pregunta 2");
        scanf(" %c", &respuesta_usuario);
        respuesta_usuario_bool = validacion_respuesta_usuario_bool(respuesta_usuario);
        correccion_respuesta_2(respuesta_usuario_bool, puntaje);
    }
    else{
        printf("-RECHAZADO-");
    }
}
