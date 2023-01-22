#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#define MAX_SIZE 1000

void createfile(int, int);
void insertstr(int, int);
void cat(int, int);
void removestr(int, int);
void copystr(int, int);
void cutstr(int, int);
void pastestr(int, int);
void findstr(int, int);

char command[MAX_SIZE];
char part[50][MAX_SIZE];
char b_arr[1000];

int main()
{
    gets(command);
    int length = strlen(command);
//    printf("%d", length);
/*
    char *token = strtok(command, " ");
    printf("%s", token);
    while(1) printf("%s", strtok(command, " "));
    return 0;
*/
    int i = 0;
    while(command[i] != ' ' && i < strlen(command)) {
        part[0][i] = command[i];
        i++;
    }

    if (!(strcmp(part[0], "createfile"))) createfile(length, i);
    else if (!(strcmp(part[0], "insertstr"))) insertstr(length, i);
    else if (!(strcmp(part[0], "cat"))) cat(length, i);
    else if (!(strcmp(part[0], "removestr"))) removestr(length, i);
    else if (!(strcmp(part[0], "copystr"))) copystr(length, i);
    else if (!(strcmp(part[0], "cutstr"))) cutstr(length, i);
    else if (!(strcmp(part[0], "pastestr"))) pastestr(length, i);
    else printf("Invalid command");
//    access(command, F_OK) == 0

}

/*
void back_array2(int x) {
    int cnt = 0;
    for (int z = 1; z <= x; z++) {
        char b_a[1000];
        b_a[0] = '/';
        for(int q = 0; q <= strlen(part[z]); q++) {
            b_a[q + 1] = part[z][q];
        }
        if (z != 1) cnt += strlen(part[z - 1]);
        for (int h = 0; h < strlen(b_a); h++) {
            b_arr[h + cnt] = b_a[h];
        }                                                       //     printf("%s ", b_a);
    }                                                           //printf("%s", b_arr);

}
*/

void back_array(int x) {
    b_arr[0] = 'c';
    b_arr[1] = 'd';
    b_arr[2] = ' ';
    for (int t = 0; t < strlen(part[x]); t++) b_arr[t+3] = part[x][t];
}

void createfile(int length, int i) {//createfile --file /dff/dfvm/fdi/fld
    int checker = 0, d1_p = 0, d2_p = 0;                       //printf("dskc ");
    part[0][i] = command[i];
    i+=8;                                                      //printf("%c", command[i]);
    if (command[i] == '"') { i++; checker = 1; }
    for(; i < length; i++) {
        if (checker == 1 && i == length - 1) break;
        else if (command[i] == '/') { d1_p++; d2_p = 0; continue; }
        part[d1_p][d2_p] = command[i];
        d2_p++;
    }
//part[1] = root
/*for (int j = 1; j <= d1_p; j++) { back_array(j); printf("%s| ", b_arr); }
return;*/
    for(int j = 1; j <= d1_p; j++) {
        if (j == d1_p) {
                                                            //printf("%d", access(part[d1_p], F_OK));
            if (access(part[d1_p], F_OK)) {                 //                printf("cm");
                FILE *file;
                file = fopen(b_arr, "w");
                fclose(file);
            }
            else printf("This file already exist");
        }
        else {                                              //            printf("%d . %d ",j, access(part[j], F_OK));
            if (access(part[j], F_OK)) {                    //                printf("%d ", i);
                printf("%s\n", part[j]);
                mkdir(part[j]);
                back_array(j);
                system(b_arr);
            }
            else { back_array(j); system(b_arr); }
        }
  }
}
//
void insertstr(int length, int i) {//insertstr --file /root/fvd --str Salam --pos 1:3
    int checker = 0, d1_p = 0, d2_p = 0;                       //printf("dskc ");
    part[0][i] = command[i];
    i+=8;
    {                                                      //printf("%c", command[i]);
        if (command[i] == '"') {
            i++;
            for(; i < length && command[i] != '"'; i++) {
                if (command[i] == '/') { d1_p++; d2_p = 0; }
                part[d1_p][d2_p] = command[i];
                d2_p++;
            }
            i+=15;
        }
        else {
            for(; i < length && command[i] != ' '; i++) {
                if (command[i] == '/') { command[i] = '\\'; d1_p++; d2_p = 0;}
                part[d1_p][d2_p] = command[i];
                d2_p++;
            }
            i+=7;
        }
    }//now command[i] == (str[0] || ") //printf("%c", command[i]);
    for(int x = 1; x <= d1_p; x++) {
        if (access(part[x], F_OK)) { printf("This file dosn't exist"); return; }
        else { back_array(x); system(b_arr); }
    }

    char str[1000];
    for (int q = i; i < length; q++) { str[q - i] = command[i]; i++; }

    int checker_end_line[strlen(str)], cnt = -1;
    for (int q = 0; q < strlen(str); q++) checker_end_line[q] = 0;
    printf("%s", str);
/*    if (command[i] == '"') {
//        for (; command[i] != '"' || (command[i] == '"' && command[i - 1] == '\\'))
        while(cnt++) {
            if (str[cnt] == '\\') {
                if (command[cnt + 1] == 'n') {
                    checker_end_line[cnt] = 1;
                }
                else /*if(command[cnt + 1] == '\\')/ cnt++;
            }
            else if(str[cnt] == '"') {
                if ()
            }
        }
    }*/
}

void cat(int length, int i) {//cat --file dsv
    i += 8;
    //printf("%c", command[i]);
    char file[1000];
    for(int j = 0; j < 1000; j++) file[j] = NULL;
    file[0] = 't';
    file[1] = 'y';
    file[2] = 'p';
    file[3] = 'e';
    file[4] = ' ';
    int cnt = 5;
    for(;i < length; i++ && cnt++) /*printf("%d ", i+cnt-3);*/file[cnt] = command[i];
    //printf("%s", file);
    system(file);
}

void removestr(int length, int i) {

}

void copystr(int length, int i) {

}

void cutstr(int length, int i) {

}

void pastestr(int length, int i) {

}

void findstr(int length, int i) {

}
