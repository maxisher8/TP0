#include  <stdio.h>
#include  <stdbool.h>


bool validacion_respuesta_usuario_bool(char respuesta){
    while (respuesta != 'S' && respuesta != 'N'){
        printf("respuesta Invalida, vuelva a intentar: ");
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

void validacion_respuesta_usuario(char *respuesta){
    while (*respuesta != 'A' && *respuesta != 'B' && *respuesta != 'J' && *respuesta != 'S'){
        printf("respuesta Invalida, vuelva a intentar: ");
        scanf(" %c", respuesta);
    }
}

int correcion_respuesta_usuario(int intentos, int MAX_INTENTOS, char respuesta){
    intentos = intentos + 1;
    while(intentos < MAX_INTENTOS && respuesta != 'J'){
        printf("respuesta incorrecta, intente otra vez: ");
        scanf(" %c", &respuesta);
        intentos = intentos + 1;
        validacion_respuesta_usuario(&respuesta);
    }
    return intentos;
}

void validacion_pregunta_3(short int *respuesta_edad_usuario_año, short int *respuesta_edad_usuario_mes){
    while(*respuesta_edad_usuario_año > 2026 || *respuesta_edad_usuario_año < 1926 || *respuesta_edad_usuario_mes < 1 || *respuesta_edad_usuario_mes > 12 || (*respuesta_edad_usuario_año == 1926 && *respuesta_edad_usuario_mes < 3) || (*respuesta_edad_usuario_año == 2026 && *respuesta_edad_usuario_mes > 3)){     
        printf("La fecha esta fuera de rango, intente de nuevo: ");
        printf("¿Cuál es su fecha de nacimiento? (formato: yyyy/mm) \n");
        scanf("%d/%d", respuesta_edad_usuario_año, respuesta_edad_usuario_mes);
    }
}

void calcular_edad(short int AÑO_ACTUAL, short int MES_ACTUAL, short int respuesta_edad_usuario_año, short int respuesta_edad_usuario_mes){
    short int edad = 0;
    edad = AÑO_ACTUAL - respuesta_edad_usuario_año;
    if(MES_ACTUAL < respuesta_edad_usuario_mes){edad = edad - 1;}
    //sumar/restar puntos
}

void validacion_pregunta_4(short int donas_a_regalar){
    while(donas_a_regalar < 0 || donas_a_regalar > 12){
        printf("Respuesta invalida, ingrese un numero entre 0 y 12 \n);
        printf("pregunta 4 \n");
        scanf("%hd", &donas_a_regalar);
    }
}

int main(){
    const int MAX_INTENTOS = 3;
    int intentos_usuario = 0;
    char respuesta_usuario = 'B';
    bool respuesta_usuario_bool = true;
    short int respuesta_edad_usuario_año = 0;
    short int respuesta_edad_usuario_mes = 0;
    short int donas_a_regalar = 0;
    const short int AÑO_ACTUAL = 2026;
    const short int MES_ACTUAL = 3;
int puntaje_pregunta_1 = 0;
int puntaje_pregunta_2 = 0;
int puntaje_pregunta_3 = 0;
int puntaje_pregunta_4 = 0;
    printf("--prueba de iniciación para ingresar a los Magios iniciada-- \n ¿Quién fundó realmente Springfield? \n");
    printf(" [J] Jebediah Springfield \n [A] Los aliens \n [S] Los Magios \n [B] Sr. Burns \n");
    scanf(" %c", &respuesta_usuario);
    validacion_respuesta_usuario(&respuesta_usuario);
    intentos_usuario = correcion_respuesta_usuario(intentos_usuario, MAX_INTENTOS, respuesta_usuario);
    if(intentos_usuario <= MAX_INTENTOS){
        printf("¿Promete mantener en secreto la existencia de los Magios? \n [S] Sí \n [N] No \n ");
        scanf(" %c", &respuesta_usuario);
        respuesta_usuario_bool = validacion_respuesta_usuario_bool(respuesta_usuario);
        puntaje = correccion_respuesta_2(respuesta_usuario_bool, puntaje);
        printf("¿Cuál es su fecha de nacimiento? (formato: yyyy/mm)");
        scanf("%d/%d", &respuesta_edad_usuario_año, &respuesta_edad_usuario_mes);
        validacion_pregunta_3(&respuesta_edad_usuario_año, &respuesta_edad_usuario_mes);
        calcular_edad(AÑO_ACTUAL, MES_ACTUAL, respuesta_edad_usuario_año, respuesta_edad_usuario_mes);
        printf("pregunta 4");
        scanf("%hd", &donas_a_regalar);
        validacion_pregunta_4(donas_a_regalar);
    }
    else{
        printf("-RECHAZADO-");
    }
}
