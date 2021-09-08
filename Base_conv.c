#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

#define MAX_SIZE_BIN 65 
#define MAX_SIZE_OCT 23
#define MAX_SIZE_HEX 17

void main_menu();
void print_header(const char* notice);
void select_data_type();
void init_data();
void decimal_to_cnv_select_base();
void data_to_cnv_decimal();
bool isHex(const char hexchar);
int char_to_int(const char data);

struct conv_data{
    char input[65];
    char output[65];
    unsigned long long dec;
    int base_of_data;
};
struct conv_data data;

int main()
{
    main_menu();
    return 0;
}

void main_menu(const char* message)
{
    system("clear");
    print_header("");
    printf("                  ▄   ▄  ▄▄   ▄ ▄▄▄   ▄▄▄▄   ▄▄  ▄▄▄  ▄  ▄                   \n");
    printf("                  █▀▄▀█ █  █  ▄ █  █  █ █ █ █▄▄█ █  █ █  █                   \n");
    printf("                  █   █ ▀▄▄▀▄ █ █  █  █ █ █ ▀▄▄  █  █ ▀▄▄▀▄                  \n");
    printf("                  -----------------------------------------                  \n");
    printf("                          <1> Conversion Binary                              \n");
    printf("                          <2> Conversion Octal                               \n");
    printf("                          <3> Conversion Deciaml                             \n");
    printf("                          <4> Conversion Hexadecimal                         \n");
    printf("                                 <0> EXIT                                    \n");
    printf("                  -----------------------------------------                  \n");
    printf("                  입력: ");

    switch(getchar()){
        case '1':
            conv_dec();
    //         conv_bin();
    //     case '2':
    //         conv_oct();
    //     case '3':
    //         conv_dec();
    //     case '4':
    //         conv_hex();
    //     case '0':
    //         exit(0);
    }
}

void decimal_data_to_cnv_select_base()
{
    while(data.dec > 0){
        {
            mod = data.dec % data.base_of_cnv;
            if(mod < 10){
                data.output[i] = 48 + mod;
            }
            else{
                data.output[i] = 65 + (mod - 1);
            }
        }
        data.dec /= data.base_of_cnv;
        i++;
}

void data_to_cnv_decimal()
{
    select_data_type();

    int tmp = 0, indices = 0;

    if(data.base_of_data >= 2 && data.base_of_data <= 16){
        for(int i = strlen(data.input) - 1; i >= 0; --i){
            if(isHex(data.input[i])){
                tmp = char_to_int(data.input[i]);
                data.dec += tmp * pow(data.base_of_data, indices);
            }
            else{
                tmp = char_to_int(data.input[i]);
                data.dec += tmp * pow(data.base_of_data, indices);
            }
            indices++;
        }
    }
}

void binary_data_to_cnv_select_base()
{
    size_t size = 0;
    size = strlen(data.input);

    switch(data.base_of_cnv){
        case 8:
            
            break;
        case 16:

            break;
    }
}

void octal_data_to_cnv_select_base()
{
    size_t size = 0;
    size = strlen(data.input);

    switch(data.base_of_cnv){
        case 2:
            break;
        case 16:

            break;
    }
}

void hexa_data_to_cnv_select_base()
{
    size_t size = 0;
    size = strlen(data.input);

    switch(data.base_of_cnv){
        case 2:
            break;
        case 8:

            break;
    }
}

void select_base_of_data()
{
    print_header("");
    printf("                  변환할 데이터의 진법을 입력하세요\n");
    printf("                  <1> Binary <2> Octal <3> Decimal <4> Hexa\n");
    printf("                  <0> return Main menu\n");
    printf("                  입력: ");
    fflush(stdin);
    switch(getchar()){
        case '1':
            data.base_of_data = 2;
            init_data();     
            if(strlen(data.input) > MAX_SIZE_BIN){main_menu("2진수의 최대 입력 자리수는 64자리입니다");}
            break;
        case '2':
            data.base_of_data = 8;
            init_data();
            if(strlen(data.input) > MAX_SIZE_BIN){main_menu("8진수의 최대 입력 자리수는 22자리입니다");}
            break;
        case '3':
            data.base_of_data = 10;
            init_data();
            if(data.dec > ULLONG_MAX ){main_menu("10진수의 최대 입력값은 18,446,744,073,709,551,615입니다");}
            break;
        case '4':
            data.base_of_data = 16;
            init_data();
            if(strlen(data.input) > MAX_SIZE_HEX){main_menu("16진수의 최대 입력 자리수는 16자리입니다");}
            break;
        case '0':
            main_menu("");
            break;
    }
}

void init_data()
{
    printf("                  변환할 데이터를 입력하세요");
    printf("                  ");
    printf("                  입력: ");
    fflush(stdin);
    scanf("%s", data.input);
}

bool isHex(const char hexchar)
{
    bool is_hex_char;

    if(hexchar >= 'a' && hexchar <= 'f' 
    || hexchar >= 'A' && hexchar <= 'F'){is_hex_char = true;}

    return is_hex_char;
}

int char_to_int(const char data)
{
    int value;

    switch(data){
        case 'a': // [[fallthrough]]
        case 'A':
            value = 10;
            break;
        case 'b': // [[fallthrough]]
        case 'B':
            value = 11;
            break;
        case 'c': // [[fallthrough]]
        case 'C':
            value = 12;
            break;
        case 'd': // [[fallthrough]]
        case 'D':
            value = 13;
            break;
        case 'e': // [[fallthrough]]
        case 'E':
            value = 14;
            break;
        case 'f': // [[fallthrough]]
        case 'F':
            value = 15;
            break;
        default:
            value = data - 48;
    }

    return value;
}

void print_header(const char* notice)
{
    system("clear");
    printf("                  -----------------------------------------                  \n");
    printf("                           Base Conversion Program                           \n");
    printf("                  -----------------------------------------                  \n");
    printf("%s", notice);
} 
