#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float c_to_f(float c){              //Celsius -> Fahrenheit
    float f = c*9/5+32;
    return (f);
}

float c_to_k(float c){              //Celsius -> Kelvin
    float k = c+273.15;
    return k;
}

float f_to_c(float f){              //Fahrenheit -> Celsius
    float c = (f-32)*5/9;
    return c;
}

float f_to_k(float f){              //Fahrenheit -> Kelvin
    float k = c_to_k(f_to_c(f));
    return k;
}

float k_to_c(float k){              //Kelvin -> Celsius
    float c = k-273.15;
    return c;
}

float k_to_f(float k){              //Kelvin -> Fahrenheit
    float f = c_to_f(k_to_c(k));
    return f;
}



int main(int argc,char *argv[])
{
    if (argc == 1){                         //Check for input values
        printf("Enter the values");
        return 1;
    }else{
        float i = atof(argv[1]);            //Conversion to float

        switch(argc){                          //How many values



            case 2:                        //If 2 then translate for 3 scales
                if (c_to_k(i) < 0) printf("Can't be such a temperature in Celsius\n\n");  //Check for absolute zero
                else{
                    printf("%.2f F\n",i);       //Translate from Celsius
                    printf("%.2f C\n",c_to_f(i));
                    printf("%.2f K\n\n",c_to_k(i));
                }

                if (f_to_k(i) < 0) printf("Can't be such a temperature in Fahrenheit\n\n");  //Check for absolute zero
                else{
                    printf("%.2f F\n",i);       //Translate from Fahrenheit
                    printf("%.2f C\n",f_to_c(i));
                    printf("%.2f K\n\n",f_to_k(i));
                }
                if (i < 0) printf("Can't be such a temperature in Kelvin\n"); //Check for absolute zero
                else{
                    printf("%.2f K\n",i);       //Translate from Kelvin
                    printf("%.2f C\n",k_to_c(i));
                    printf("%.2f F\n",k_to_f(i));
                }
                break;



            case 3:                     //If 3 then checking 2 values
            if (strlen(argv[2])==1){    //Check for 1 symbol
               switch(*argv[2]){


                    case 'C':           //Translate from Celsius
                        if (c_to_k(i) < 0) printf("Can't be such a temperature\n"); //Check for absolute zero
                        else {
                            printf("%.2f C\n",i);
                            printf("%.2f F\n",c_to_f(i));
                            printf("%.2f K\n",c_to_k(i));
                        }
                        break;


                    case 'F':           //Translate from Fahrenheit
                        if (c_to_k(i) < 0) printf("Can't be such a temperature\n"); //Check for absolute zero
                        else{
                            printf("%.2f F\n",i);
                            printf("%.2f,C\n"),f_to_k(i);
                            printf("%.2f,K\n",f_to_c(i));
                        }
                        break;


                    case 'K':           //Translate from Kelvin
                        if (c_to_k(i) < 0) printf("Can't be such a temperature\n"); //Check for absolute zero
                        else{
                            printf("%.2f K\n",i);
                            printf("%.2f,C\n",k_to_c(i));
                            printf("%.2f,F\n"),k_to_f(i);
                        }
                        break;


                    default:printf("Enter number and C,F or K");    //If not scale is entered
                }
            } else printf("Enter number and C,F or K\n");
            break;


            default:printf("Enter number and scale\n");               //If entered more then 2 values
        }
    }
    return 0;
}

