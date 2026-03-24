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
        printf("respuesta Invalida, vuelva a intentar: ");
        scanf(" %c", &respuesta);
    }
}

int correcion_respuesta_usuario(int intentos, int MAX_INTENTOS, char respuesta){
    while(intentos < MAX_INTENTOS && respuesta != 'J'){
        printf("respuesta incorrecta, intente otra vez: ");
        scanf(" %c", &respuesta);
        validacion_respuesta_usuario(respuesta);
        intentos = intentos + 1;
        printf("%d", intentos);
    }
    return intentos;
}

void validacion_pregunta_3(short int edad_año, short int edad_mes){
    while(edad_año > 2026 || edad_año < 1926 || edad_mes < 1 || edad_mes > 12 || (edad_año == 2026 && edad_mes > 3)){ 
        printf("La fecha esta fuera de rango, intente de nuevo: ");
        printf("pregunta 3 (año)");
        scanf("%hd", &edad_año);
        printf("pregunta 3 (Mes)");
        scanf("%hd", &edad_mes);
    }
    //corregir y sumar/restar puntos
}

void validacion_pregunta_4(short int donas_a_regalar){
    while(donas_a_regalar < 0 || donas_a_regalar > 12){

    }
}

int main(){
    const int MAX_INTENTOS = 3;
    int intentos_usuario = 0;
    char respuesta_usuario = 'B';
    int puntaje = 0;
    bool respuesta_usuario_bool = true;
    short int respuesta_edad_usuario_año = 0;
    short int respuesta_edad_usuario_mes = 0;
    short int donas_a_regalar = 0;
    printf("--prueba de iniciación para ingresar a los Magios iniciada-- \n ¿Quién fundó realmente Springfield? \n");
    printf(" [J] Jebediah Springfield \n [A] Los aliens \n [S] Los Magios \n [B] Sr. Burns \n");
    scanf(" %c", &respuesta_usuario);
    validacion_respuesta_usuario(respuesta_usuario);
    intentos_usuario = correcion_respuesta_usuario(intentos_usuario, MAX_INTENTOS, respuesta_usuario);
    if(intentos_usuario < MAX_INTENTOS){
        printf("pregunta 2");
        scanf(" %c", &respuesta_usuario);
        respuesta_usuario_bool = validacion_respuesta_usuario_bool(respuesta_usuario);
        puntaje = correccion_respuesta_2(respuesta_usuario_bool, puntaje);
        printf("pregunta 3 (año)");
        scanf("%hd", &respuesta_edad_usuario_año);
        printf("pregunta 3 (Mes)");
        scanf("%hd", &respuesta_edad_usuario_mes);
        validacion_pregunta_3(respuesta_edad_usuario_año, respuesta_edad_usuario_mes);
        printf("pregunta 4");
        scanf("%hd", &donas_a_regalar);
        validacion_pregunta_4(donas_a_regalar);
    }
    else{
        printf("-RECHAZADO-");
    }
}
