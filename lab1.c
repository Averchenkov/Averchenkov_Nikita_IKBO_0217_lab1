#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float c_to_f(float c){              //������� �� ������ � ����������
    float f = c*9/5+32;
    return (f);
}

float c_to_k(float c){              //������� �� ������ � ��������
    float k = c+273.15;
    return k;
}

float f_to_c(float f){              //������� �� ��������� � ������
    float c = (f-32)*5/9;
    return c;
}

float f_to_k(float f){              //������� �� ��������� � ��������
    float k = c_to_k(f_to_c(f));
    return k;
}

float k_to_c(float k){              //������� �� ������� � ������
    float c = k-273.15;
    return c;
}

float k_to_f(float k){              //������� �� ������� � ����������
    float f = c_to_f(k_to_c(k));
    return f;
}



int main(int argc,char *argv[])
{
    if (argc == 1){                         //�������� �� ������� �����-���� �������� ��������
        printf("Enter the values");
        return 1;
    }else{
        float i = atof(argv[1]);            //������� � ����� � ��� float

        switch(argc){                          //������� ������� �������� ����������



            case 2:                        //���� 2 �� ����� ������������ � ���� ������ � ������ �����������
                if (c_to_k(i) < 0) printf("Can't be such a temperature in Celsius\n\n");  //�������� ����������� ����
                else{
                    printf("%.2f F\n",i);       //����������� ��� �������
                    printf("%.2f C\n",c_to_f(i));
                    printf("%.2f K\n\n",c_to_k(i));
                }

                if (f_to_k(i) < 0) printf("Can't be such a temperature in Fahrenheit\n\n");  //�������� ����������� ����
                else{
                    printf("%.2f F\n",i);       //����������� ��� ���������
                    printf("%.2f C\n",f_to_c(i));
                    printf("%.2f K\n\n",f_to_k(i));
                }
                if (i < 0) printf("Can't be such a temperature in Kelvin\n"); //�������� ����������� ����
                else{
                    printf("%.2f K\n",i);       //����������� ��� �������
                    printf("%.2f C\n",k_to_c(i));
                    printf("%.2f F\n",k_to_f(i));
                }
                break;



            case 3:                     //���� 2 �� ������� � ����� ����� ������� �����
            if (strlen(argv[2])==1){    //�������� ��, ��� ����������� ���� ���� ������
               switch(*argv[2]){


                    case 'C':           //���� � ������� �� ������ ����������� ��� �������
                        if (c_to_k(i) < 0) printf("Can't be such a temperature\n"); //�������� ����������� ����
                        else {
                            printf("%.2f C\n",i);
                            printf("%.2f F\n",c_to_f(i));
                            printf("%.2f K\n",c_to_k(i));
                        }
                        break;


                    case 'F':           //���� � ����������� �� ������ ����������� ��� ���������
                        if (c_to_k(i) < 0) printf("Can't be such a temperature\n"); //�������� ����������� ����
                        else{
                            printf("%.2f F\n",i);
                            printf("%.2f,C\n"),f_to_k(i);
                            printf("%.2f,K\n",f_to_c(i));
                        }
                        break;


                    case 'K':           //���� � ��������� �� ������ ����������� ��� �������
                        if (c_to_k(i) < 0) printf("Can't be such a temperature\n"); //�������� ����������� ����
                        else{
                            printf("%.2f K\n",i);
                            printf("%.2f,C\n",k_to_c(i));
                            printf("%.2f,F\n"),k_to_f(i);
                        }
                        break;


                    default:printf("Enter number and C,F or K");    //���� �� ������� �����
                }
            } else printf("Enter number and C,F or K\n");
            break;


            default:printf("Enter number and scale\n");               //���� ������� ������ 2 ����������
        }
    }
    return 0;
}

