
#include <PA9.h>

#include "graficos_3d/texto/letras.h"

/*
void Convertir_Nombre(void)
{
    // Vaciar
    for (int i = 0; i <= 9; i++)
        nombre_jugador[i] = 255;

    // Convertir
    for (int i = 0; i <= PA_UserInfo.NameLength; i++)
    {
        switch (PA_UserInfo.Name[i])
        {
            case 33:
                nombre_jugador[i] = CHAR_CERRARINTERROGACION;
                break;

            case 44:
                nombre_jugador[i] = CHAR_COMA;
                break;
            case 46:
                nombre_jugador[i] = CHAR_PUNTO;
                break;

            case 63:
                nombre_jugador[i] = CHAR_CERRAREXCLAMACION;
                break;
            case 64:
                nombre_jugador[i] = CHAR_ARROBA;
                break;

            case 65:
                nombre_jugador[i] = CHAR_A;
                break;
            case 66:
                nombre_jugador[i] = CHAR_B;
                break;
            case 67:
                nombre_jugador[i] = CHAR_C;
                break;
            case 68:
                nombre_jugador[i] = CHAR_D;
                break;
            case 69:
                nombre_jugador[i] = CHAR_E;
                break;
            case 70:
                nombre_jugador[i] = CHAR_F;
                break;
            case 71:
                nombre_jugador[i] = CHAR_G;
                break;
            case 72:
                nombre_jugador[i] = CHAR_H;
                break;
            case 73:
                nombre_jugador[i] = CHAR_I;
                break;
            case 74:
                nombre_jugador[i] = CHAR_J;
                break;
            case 75:
                nombre_jugador[i] = CHAR_K;
                break;
            case 76:
                nombre_jugador[i] = CHAR_L;
                break;
            case 77:
                nombre_jugador[i] = CHAR_M;
                break;
            case 78:
                nombre_jugador[i] = CHAR_N;
                break;
            case 79:
                nombre_jugador[i] = CHAR_O;
                break;
            case 80:
                nombre_jugador[i] = CHAR_P;
                break;
            case 81:
                nombre_jugador[i] = CHAR_Q;
                break;
            case 82:
                nombre_jugador[i] = CHAR_R;
                break;
            case 83:
                nombre_jugador[i] = CHAR_S;
                break;
            case 84:
                nombre_jugador[i] = CHAR_T;
                break;
            case 85:
                nombre_jugador[i] = CHAR_U;
                break;
            case 86:
                nombre_jugador[i] = CHAR_V;
                break;
            case 87:
                nombre_jugador[i] = CHAR_W;
                break;
            case 88:
                nombre_jugador[i] = CHAR_X;
                break;
            case 89:
                nombre_jugador[i] = CHAR_Y;
                break;
            case 90:
                nombre_jugador[i] = CHAR_Z;
                break;


            case 95:
                nombre_jugador[i] = CHAR_BARRABAJA;
                break;


            case 97:
                nombre_jugador[i] = CHAR_A;
                break;
            case 98:
                nombre_jugador[i] = CHAR_B;
                break;
            case 99:
                nombre_jugador[i] = CHAR_C;
                break;
            case 100:
                nombre_jugador[i] = CHAR_D;
                break;
            case 101:
                nombre_jugador[i] = CHAR_E;
                break;
            case 102:
                nombre_jugador[i] = CHAR_F;
                break;
            case 103:
                nombre_jugador[i] = CHAR_G;
                break;
            case 104:
                nombre_jugador[i] = CHAR_H;
                break;
            case 105:
                nombre_jugador[i] = CHAR_I;
                break;
            case 106:
                nombre_jugador[i] = CHAR_J;
                break;
            case 107:
                nombre_jugador[i] = CHAR_K;
                break;
            case 108:
                nombre_jugador[i] = CHAR_L;
                break;
            case 109:
                nombre_jugador[i] = CHAR_M;
                break;
            case 110:
                nombre_jugador[i] = CHAR_N;
                break;
            case 111:
                nombre_jugador[i] = CHAR_O;
                break;
            case 112:
                nombre_jugador[i] = CHAR_P;
                break;
            case 113:
                nombre_jugador[i] = CHAR_Q;
                break;
            case 114:
                nombre_jugador[i] = CHAR_R;
                break;
            case 115:
                nombre_jugador[i] = CHAR_S;
                break;
            case 116:
                nombre_jugador[i] = CHAR_T;
                break;
            case 117:
                nombre_jugador[i] = CHAR_U;
                break;
            case 118:
                nombre_jugador[i] = CHAR_V;
                break;
            case 119:
                nombre_jugador[i] = CHAR_W;
                break;
            case 120:
                nombre_jugador[i] = CHAR_X;
                break;
            case 121:
                nombre_jugador[i] = CHAR_Y;
                break;
            case 122:
                nombre_jugador[i] = CHAR_Z;
                break;




            case 209:
                nombre_jugador[i] = CHAR_NN;
                break;
            case 241:
                nombre_jugador[i] = CHAR_NN;
                break;

            case 191:
                nombre_jugador[i] = CHAR_ABRIRINTERROGACION;
                break;
            case 161:
                nombre_jugador[i] = CHAR_ABRIREXCLAMACION;
                break;
        }
    }
}
*/

int Convertir_Letra(int letra)
{
    int letraaux = 0;

    switch (letra)
    {
        case 33:
            letraaux = CHAR_CERRARINTERROGACION;
            break;

        case 44:
            letraaux = CHAR_COMA;
            break;
        case 46:
            letraaux = CHAR_PUNTO;
            break;

        case 63:
            letraaux = CHAR_CERRAREXCLAMACION;
            break;
        case 64:
            letraaux = CHAR_ARROBA;
            break;

        case 65:
            letraaux = CHAR_A;
            break;
        case 66:
            letraaux = CHAR_B;
            break;
        case 67:
            letraaux = CHAR_C;
            break;
        case 68:
            letraaux = CHAR_D;
            break;
        case 69:
            letraaux = CHAR_E;
            break;
        case 70:
            letraaux = CHAR_F;
            break;
        case 71:
            letraaux = CHAR_G;
            break;
        case 72:
            letraaux = CHAR_H;
            break;
        case 73:
            letraaux = CHAR_I;
            break;
        case 74:
            letraaux = CHAR_J;
            break;
        case 75:
            letraaux = CHAR_K;
            break;
        case 76:
            letraaux = CHAR_L;
            break;
        case 77:
            letraaux = CHAR_M;
            break;
        case 78:
            letraaux = CHAR_N;
            break;
        case 79:
            letraaux = CHAR_O;
            break;
        case 80:
            letraaux = CHAR_P;
            break;
        case 81:
            letraaux = CHAR_Q;
            break;
        case 82:
            letraaux = CHAR_R;
            break;
        case 83:
            letraaux = CHAR_S;
            break;
        case 84:
            letraaux = CHAR_T;
            break;
        case 85:
            letraaux = CHAR_U;
            break;
        case 86:
            letraaux = CHAR_V;
            break;
        case 87:
            letraaux = CHAR_W;
            break;
        case 88:
            letraaux = CHAR_X;
            break;
        case 89:
            letraaux = CHAR_Y;
            break;
        case 90:
            letraaux = CHAR_Z;
            break;


        case 95:
            letraaux = CHAR_BARRABAJA;
            break;


        case 97:
            letraaux = CHAR_A;
            break;
        case 98:
            letraaux = CHAR_B;
            break;
        case 99:
            letraaux = CHAR_C;
            break;
        case 100:
            letraaux = CHAR_D;
            break;
        case 101:
            letraaux = CHAR_E;
            break;
        case 102:
            letraaux = CHAR_F;
            break;
        case 103:
            letraaux = CHAR_G;
            break;
        case 104:
            letraaux = CHAR_H;
            break;
        case 105:
            letraaux = CHAR_I;
            break;
        case 106:
            letraaux = CHAR_J;
            break;
        case 107:
            letraaux = CHAR_K;
            break;
        case 108:
            letraaux = CHAR_L;
            break;
        case 109:
            letraaux = CHAR_M;
            break;
        case 110:
            letraaux = CHAR_N;
            break;
        case 111:
            letraaux = CHAR_O;
            break;
        case 112:
            letraaux = CHAR_P;
            break;
        case 113:
            letraaux = CHAR_Q;
            break;
        case 114:
            letraaux = CHAR_R;
            break;
        case 115:
            letraaux = CHAR_S;
            break;
        case 116:
            letraaux = CHAR_T;
            break;
        case 117:
            letraaux = CHAR_U;
            break;
        case 118:
            letraaux = CHAR_V;
            break;
        case 119:
            letraaux = CHAR_W;
            break;
        case 120:
            letraaux = CHAR_X;
            break;
        case 121:
            letraaux = CHAR_Y;
            break;
        case 122:
            letraaux = CHAR_Z;
            break;


        case 209:
            letraaux = CHAR_NN;
            break;
        case 241:
            letraaux = CHAR_NN;
            break;

        case 191:
            letraaux = CHAR_ABRIRINTERROGACION;
            break;
        case 161:
            letraaux = CHAR_ABRIREXCLAMACION;
            break;
    }

    return letraaux;
}
