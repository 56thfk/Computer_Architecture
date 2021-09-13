#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define IS_ERR -1

struct data{
    char* char_base_of_from;
    char* char_base_of_to;
    int int_base_of_from;
    int int_base_of_to;
}
struct data data;

void print_help(bool is_err);

int main(const int argc, char *argv[])
{
    int option, in_flag, to_flag;
    in_flag = to_flag = 0;

    if(argc == 1){
        //TODO 인터렉티브 모드
    }

    while((option = getopt(argc, argv, "i:o:h")) != -1){
        switch(option){
            case 'h':
                print_help(!IS_ERR);
                return 0;
            case 'i':
                base_of_from = optarg;
                in_flag = 1;
                break;
            case 'o':
                base_of_to = optarg;
                to_flag = 1;
                break;
            case '?':
                if(){printf("error: %c option is requires an argument");}
                else if(isprint(optopt)){printf("error: unknown option -%c", optopt);}
                else{printf("error: unknown chracter -%x");}
                return 1;
            default:
                return 1;
        }
    }

    if(in_flag != 1 || to_flag != 1){
        fprintf(stderr, "error: must be enter [in to <base>]\n");
    }

}

int opt_arg_scan(const char* from_or_to_base, const char* keys[])
{
    int idx = 0;
    while(strcmp(from_or_to_base, keys[idx]) != 0 && !(strcmp(keys[idx], "\0") == 0))
        idx++;

    return idx;
}

void set_base(const char* from, const char* to){
    const char* keys[] = {
        "b", "o", "d", "h", 
        "bin", "oct", "dec", "hex", "\0"};
    enum{ARG_B, ARG_O, ARG_D, ARG_H, ARG_BIN, ARG_OCT, ARG_DEC, ARG_HEX};
    
    data.int_base_of_from = opt_arg_scan(from, keys);
    data.int_base_of_to = opt_arg_scan(to, keys);

    int buff = 0;

    for(int i = 1; i <= 2; ++i){
        if(i != 1)
            buff = data.int_base_of_from;
        else
            buff = data.int_base_of_to;

        switch(buff){
            case ARG_B: case ARG_BN:
                buff = BIN;
                break;
            case ARG_O: case ARG_OCT:
                buff = OCT;
                break;
            case ARG_D: case ARG_DEC:
                buff = DEC;
                break;
            case ARG_H: case ARG_HEX:
                buff = HEX;
                break;
        }
        if(i != 1)
            data.int_base_of_from = buff;
        else
            data.int_base_of_to = buff;
    }
}

void print_help(bool is_err)
{
    if(is_err)
		puts("use `base_converter -h` for help");
	else {
		puts("usage: base_converter [-h] [-i <from base>] [-o <to base>] [<value>]");
		puts("options:");
		puts("  -h         print help message");
		puts("  -i <base>  set input number base");
		puts("  -o <base>  set input number base");
		puts("  <value>    input number value\n");
		puts("  b, bin");
		puts("  o, oct");
		puts("  d, dec");
		puts("  h, hex");
    }
}
