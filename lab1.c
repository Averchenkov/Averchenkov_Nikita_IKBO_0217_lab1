#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float c_to_f(float c){              //Перевод из Целсии в Фаренгейты
    float f = c*9/5+32;
    return (f);
}

float c_to_k(float c){              //Перевод из Целсии в Кельвины
    float k = c+273.15;
    return k;
}

float f_to_c(float f){              //Перевод из Фаренгейт в Целсии
    float c = (f-32)*5/9;
    return c;
}

float f_to_k(float f){              //Перевод из Фаренгейт в Кельвины
    float k = c_to_k(f_to_c(f));
    return k;
}

float k_to_c(float k){              //Перевод из Кельвин в Целсии
    float c = k-273.15;
    return c;
}

float k_to_f(float k){              //Перевод из Кельвин в Фаренгейты
    float f = c_to_f(k_to_c(k));
    return f;
}



int main(int argc,char *argv[])
{
    if (argc == 1){                         //Проверка на наличие какмх-либо вводимых значений
        printf("Enter the values");
        return 1;
    }else{
        float i = atof(argv[1]);            //Перевод в числа в тип float

        switch(argc){                          //Смотрим сколько преданно аргументов



            case 2:                        //Если 2 то число представляем в трех шкалах и делаем конвертацию
                if (c_to_k(i) < 0) printf("Can't be such a temperature in Celsius\n\n");  //Проверка абсолютного нуля
                else{
                    printf("%.2f F\n",i);       //Конвертация для Цельсии
                    printf("%.2f C\n",c_to_f(i));
                    printf("%.2f K\n\n",c_to_k(i));
                }

                if (f_to_k(i) < 0) printf("Can't be such a temperature in Fahrenheit\n\n");  //Проверка абсолютного нуля
                else{
                    printf("%.2f F\n",i);       //Конвертация для Фаренгейт
                    printf("%.2f C\n",f_to_c(i));
                    printf("%.2f K\n\n",f_to_k(i));
                }
                if (i < 0) printf("Can't be such a temperature in Kelvin\n"); //Проверка абсолютного нуля
                else{
                    printf("%.2f K\n",i);       //Конвертация для Кельвин
                    printf("%.2f C\n",k_to_c(i));
                    printf("%.2f F\n",k_to_f(i));
                }
                break;



            case 3:                     //Если 2 то смотрим в какой шкале заданно число
            if (strlen(argv[2])==1){    //Проверка то, что ползователь ввел один символ
               switch(*argv[2]){


                    case 'C':           //Если в Цельсии то делаем конвертацию для Цельсии
                        if (c_to_k(i) < 0) printf("Can't be such a temperature\n"); //Проверка абсолютного нуля
                        else {
                            printf("%.2f C\n",i);
                            printf("%.2f F\n",c_to_f(i));
                            printf("%.2f K\n",c_to_k(i));
                        }
                        break;


                    case 'F':           //Если в Фаренгейтах то делаем конвертацию для Фаренгейт
                        if (c_to_k(i) < 0) printf("Can't be such a temperature\n"); //Проверка абсолютного нуля
                        else{
                            printf("%.2f F\n",i);
                            printf("%.2f,C\n"),f_to_k(i);
                            printf("%.2f,K\n",f_to_c(i));
                        }
                        break;


                    case 'K':           //Если в Кельвинах то делаем конвертацию для Кельвин
                        if (c_to_k(i) < 0) printf("Can't be such a temperature\n"); //Проверка абсолютного нуля
                        else{
                            printf("%.2f K\n",i);
                            printf("%.2f,C\n",k_to_c(i));
                            printf("%.2f,F\n"),k_to_f(i);
                        }
                        break;


                    default:printf("Enter number and C,F or K");    //Если не заданна шкала
                }
            } else printf("Enter number and C,F or K\n");
            break;


            default:printf("Enter number and scale\n");               //Если заданно болеше 2 аргументов
        }
    }
    return 0;
}

