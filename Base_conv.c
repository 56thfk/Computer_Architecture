#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

#define MAX_SIZE_BIN 64 
#define MAX_SIZE_OCT 22
#define MAX_SIZE_HEX 16

void main_menu();
void print_header(const char* notice);
void input_data();
void conv_bin();
void conv_oct();
void conv_dec();
void conv_hex();
bool isHex(const char hexchar);
int char_to_int(const char data);

struct conv_data{
    char input[64];
    char bin[64];
    char oct[22];
    char hex[16];
    unsigned long long dec;
    int base_of_data;
};
struct conv_data data;

int main()
{
    main_menu();
    return 0;
}

void main_menu()
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
            break;
    //         conv_bin();
    //         break;
    //     case '2':
    //         conv_oct();
    //         break;
    //     case '3':
    //         conv_dec();
    //         break;
    //     case '4':
    //         conv_hex();
    //         break;
    //     case '0':
    //         exit(0);
    //         break;
    }

void conv_bin()
{

}

void conv_oct()
{
   
}

void conv_dec()
{
    input_data();
}

void conv_hex()
{

}

void input_data()
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
            printf("                  변환할 데이터를 입력하세요(예: 0101)\n");
            printf("                  입력: ");
            scanf("%s", data.input);
            if(sizeof(data.input) > MAX_SIZE_BIN) {main_menu();}
            break;
        case '2':
            data.base_of_data = 8;
            printf("                  변환할 데이터를 입력하세요(예: 174)\n");
            printf("                  입력: ");
            scanf("%s", data.input);
            if(!(sizeof(data.input) > MAX_SIZE_OCT)) {main_menu();}
            break;
        case '3':
            data.base_of_data = 10;
            printf("                  변환할 데이터를 입력하세요(예: 981)\n");
            printf("                  입력: ");
            scanf("%llu", &data.dec);
            if(!(sizeof(data.dec) > ULONG_LONG_MAX)) {main_menu();}
            break;
        case '4':
            data.base_of_data = 16;
            printf("                  변환할 데이터를 입력하세요(예: f234)\n");
            printf("                  입력: ");
            scanf("%s", data.input);
            if(sizeof(data.input) > MAX_SIZE_HEX) {main_menu();}
            break;
        case '0':
            main_menu();
            break;
    }
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
        case 'a':
        case 'A':
            value = 10;
            break;
        case 'b':
        case 'B':
            value = 11;
            break;
        case 'c':
        case 'C':
            value = 12;
            break;
        case 'd':
        case 'D':
            value = 13;
            break;
        case 'e':
        case 'E':
            value = 14;
            break;
        case 'f':
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
