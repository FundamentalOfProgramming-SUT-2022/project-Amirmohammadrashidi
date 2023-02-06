#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#define MAX_SIZE 1000

void createfile(int, int);
void insert(int, int);
void cat(int, int);
void multi_function(int, int, int);
void copystr(int, int, int, char, int);
void cutstr(int, int, int, char, int);
void pastestr(int, int, int, char, int);
void findstr(int, int);
void replace(int, int);

void back_array2(int x);

char command[MAX_SIZE];
char part[50][MAX_SIZE];
char b_arr[MAX_SIZE];
char copy[MAX_SIZE];
char str[MAX_SIZE];
char str1[MAX_SIZE];
char str2[MAX_SIZE];
int checker_end_line[MAX_SIZE];

int main()
{
    while (1)
    {
        gets(command);
        int length = strlen(command);
        int i = 0;
        while (command[i] != ' ' && i < strlen(command))
        {
            part[0][i] = command[i];
            i++;
        }

        if (!(strcmp(part[0], "createfile")))
            createfile(length, i);
        else if (!(strcmp(part[0], "insertstr")))
            insert(length, i);
        else if (!(strcmp(part[0], "cat")))
            cat(length, i);
        else if (!(strcmp(part[0], "removestr")))
            multi_function(length, i, 1);
        else if (!(strcmp(part[0], "copystr")))
            multi_function(length, i, 2);
        else if (!(strcmp(part[0], "cutstr")))
            multi_function(length, i, 3);
        else if (!(strcmp(part[0], "pastestr")))
            multi_function(length, i, 4);
        else if (!(strcmp(part[0], "find")))
            findstr(length, i);
        else if (!(strcmp(part[0], "replace")))
            replace(length, i);
        else if (!(strcmp(command, "exit")))
            return 0;
        else
            printf("Invalid command");
    }
    //    access(command, F_OK) == 0
}


void back_array2(int x) {
    int cnt = 0;
    for (int z = 1, cnt = 0; z <= x; z++) {
        char b_a[MAX_SIZE];

        if(z != 1) {
            b_a[0] = '/';
            for(int q = 0; q <= strlen(part[z]); q++) {
                b_a[q + 1] = part[z][q];
            }
        }
        else {
            for(int q = 0; q <= strlen(part[z]); q++) {
                b_a[q] = part[z][q];
            }
        }
//        printf("\n%s\n", b_a);
        //printf("%d ", strlen(b_a));
        for (int i = 0; i < strlen(b_a); i++, cnt++)
        {
//            printf("%d | %d ", i, cnt);
            b_arr[cnt] = b_a[i];
        }
//        printf("\n");
    }
//    printf("%s", b_arr);
}

/*
void back_array(int x)
{
    b_arr[0] = 'c';
    b_arr[1] = 'd';
    b_arr[2] = ' ';
    for (int t = 0; t < strlen(part[x]); t++)
        b_arr[t + 3] = part[x][t];
    printf("%s\n", b_arr);
}
void back_array2(int x)
{
    b_arr2[0] = 'm';
    b_arr2[1] = 'k';
    b_arr2[2] = 'd';
    b_arr2[3] = 'i';
    b_arr2[4] = 'r';
    b_arr2[5] = ' ';
    for (int t = 0; t < strlen(part[x]); t++)
        b_arr2[t + 6] = part[x][t];
    printf("%s\n", b_arr2);
}*/

void createfile(int length, int i)
{                                        // createfile –-file /root/dir1/dir2/file.txt
    int checker = 0, d1_p = 0, d2_p = 1; // printf("dskc ");
    part[0][i] = command[i];
    i += 8;  //printf("%c", command[i]);return;
    if (command[i] == '"')
    {
        i++;
        checker = 1;
    }
    for (; i < length; i++)
    {
        if (checker == 1 && i == length - 1)
            break;
        else if (command[i] == '/')
        {
            command[i] = '\\';
            d1_p++;
            d2_p = 0;
            continue;
        }
        part[d1_p][d2_p] = command[i];
        d2_p++;
    }
/*
back_array2(3);
printf("%s", b_arr);
return;
*/
//    for (int x = 0; x < d1_p; x++) printf("%s| ", part[x]); return;
    for (int j = 1; j <= d1_p; j++)
    {
        if (j == d1_p)
        {
//             printf("%s\n", part[d1_p]);
            back_array2(j);
            if (access(b_arr, F_OK) != 0)
            { //                printf("cm");
                FILE *file;
                file = fopen(b_arr, "w");
                fclose(file);
            }
            else
                printf("This file already exist");
        }
        else
        {
            back_array2(j);
            //printf("%s\n", b_arr);
            if (access(b_arr, F_OK)) //don"t exist
            { //printf("%d ", i);
                // printf("%s\n", b_arr2);
                mkdir(b_arr);
            }
        }
    }
}
//


void insertstr_(int l, int c, int d1_p) {
    back_array2(d1_p);
    FILE* file = fopen(b_arr, "a");
    fputs(str, file);
    fclose(file);
    /*int line = 0, i = 0;
    char tmp = '\0';
    char file_input[MAX_SIZE][MAX_SIZE];
    FILE* file = fopen(b_arr, "r");
    while (file_input[line][i] != EOF)
    {
        i++;
        file_input[line][i] = fgetc(file);
        printf("%s", file_input[line]);
        if (tmp == '\n')
        {
            i = 0;
            line++;
        }
        printf("%s", file_input[line]);
    }
    fclose(file);
    printf("%s", file_input[1]);
    for (int i = 0; i < line; i++)
    {
        printf("%s", file_input[i]);
    }
    */
}

void insert(int length, int i) // insertstr –-file /root/dir1/dir2/file.txt –-str Salam –pos 2:5
{
    int checker = 0, d1_p = 0, d2_p = 1;
    i += 8; //printf("%c", command[i]);
    if (command[i] == '"')
    {
        i++;
        checker = 1;
    }
    for (; i < length; i++)
    {
        if (checker == 1 && command[i] == '"')
        {
            i++;
            break;
        }
        else if (checker == 0 && command[i] == ' ')
            break;
        else if (command[i] == '/')
        {
            d1_p++;
            d2_p = 0;
            continue;
        }
        part[d1_p][d2_p] = command[i];
        d2_p++;
    }
    i+= 7;  // printf("%c", command[i]); return 0; // now command[i] == (str[0] || '"')

    {
    //check file exist
        for (int x = 1; x <= d1_p; x++)
        {
            back_array2(x);
    //        printf("%s\n", b_arr);
            if (access(b_arr, F_OK)) //don"t exist
            {
                //printf("%s\n", b_arr);
                printf("This file dosn't exist\n");
                return;
            }
        }
    }

    checker = 0;
    if (command[i] == '"')
    { 
        i++; 
        checker = 1;
    }
    int tmp = i;
    if (checker == 0)
    {
        for (int q = tmp; command[i] != ' ' ; q++, i++)
        {
           str[q - tmp] = command[i];
        }
    }
    else
    {
        int checker2 = 0;
        for (int q = tmp; ; q++, i++)
        {
            if (command[i] == '"')
            {
                if (checker2 == 1)
                {
                    checker2 = 0;
                }
                else
                {
                    for (int w = i; w < length; w++)
                    {
                        //printf("%c ", command[w]);
                        if (command[w] == '"')
                        {
                            str[w - tmp] = command[w]; //??
                            checker2 = 1;
                            break;
                        }
                    }
                }
            }
            str[q - tmp] = command[i];
            break;
        }
    }
    /*int count = 123;
    for (int  i = 0; i < count; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n"); return; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //printf("%s", str);
    */i += 6;     //    printf("%c", command[i]);return;

    char line[10] = {0};
    int counter = 0;
    while(command[i] != ':')
    {
//        printf("%c %d", command[i], counter);
        line[counter] = command[i];
        i++;
        counter++;
    }
    i++; //now command[i] = first int of line
//    printf("%c", command[i]); return;
//    printf("%s", line);

    int l = 0; // line of pos
    for (int i = 0; i < strlen(line); i++) {
        l *= 10;
        //printf("%c ", line[i]);
        l += ((int)line[i] - 48); // '0' = 48
    }
//    printf("%d", l); return;

    char character[MAX_SIZE];
    counter = 0;
    while(i < length) {
        character[counter] = command[i];
        i++;
        counter++;
    }
//    printf("%s", character);return;
    int c = 0; //charachter of pos
    for (int i = 0; i < strlen(character); i++) {
        c*=10;
//        printf("%c ", character[i]);
        c += ((int)character[i] - 48); // '0' = 48
    }
//    printf("%d", c);return;
    //str deleted from code
    insertstr_(l, c, d1_p);

}

void cat(int length, int i)                             // cat –-file /root/dir1/dir2/file.txt
{ 
    int checker = 0, d1_p = 0, d2_p = 0;
    i += 8;
    if (command[i] == '"')
    {
        i++;
        checker = 1;
    }
    for (; i < length; i++)
    {
        if (checker == 1 && i == length - 1)
            break;
        else if (command[i] == '/')
        {
            d1_p++;
            d2_p = 0;
            continue;
        }
        //printf("%c", command[i]);
        part[d1_p][d2_p] = command[i];
        d2_p++;
    }
    
    for (int x = 1; x <= d1_p; x++) 
    {
        back_array2(x);
        if (access(b_arr, F_OK)) //don"t exist
        {
            printf("This file dosn't exist");
            return;
        }
    }
    FILE* file;
    back_array2(d1_p);
    file = fopen(b_arr, "r");
    char tmp = 'f';
    while (tmp != EOF)
    {
        tmp = fgetc(file);
        printf("%c", tmp);
    } 
    fclose(file);
}


void removestr(int l, int c, int size, char side, int d1_p) //bag dare (putc)
{
    back_array2(d1_p);
    //
    char file_input[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
    {
        file_input[i][0] = '\0'; // for not be '\0'
    }
    FILE* file;
    file = fopen(b_arr, "r");
    int cnt_of_endline = 1;
    if (side == 'f')
    {
        //get
        int i = 0;
        
        while (1)
        {   
            if (cnt_of_endline == l && i == c)
            {
                for (int i = 0; i < size; i++)
                {
                    fgetc(file);
                }
                i = 0;
                cnt_of_endline++;
                continue;
            }
            
            file_input[cnt_of_endline][i] = fgetc(file);
            
            {
                if (file_input[cnt_of_endline][i] == EOF)
                {
                    break;
                }
            }
            if (file_input [cnt_of_endline][i] == '\n')
            {
                i = 0;
                cnt_of_endline++;
                continue;
            }
            i++;
        }
    }
    fclose(file);
    
    //put
    file = fopen(b_arr, "w");
    for (int i = 1; i <= cnt_of_endline; i++)
    {
        for (int j = 0; file_input[i][j] != '\0' && file_input[i][j] != EOF; j++) 
        {
            fputc(file_input[i][j], file);
        }
    }
    fclose(file);
}

void copystr(int l, int c, int size, char side, int d1_p)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        copy[i] = '\0';
    }
    

    back_array2(d1_p);
    
    char tmp;

    FILE* file;
    file = fopen(b_arr, "r");
    int cnt_of_endline = 1;
    if (side == 'f')
    {
        while (1)
        {
            if (cnt_of_endline == l)
            {
                int i = 0;
                while (tmp != EOF && i < c)
                {
                    tmp = fgetc(file);
                    i++;
                }
                for (int i = 0; i < size; i++)
                {
                    copy[i] = fgetc(file);
                }
                break;
            }
            
            tmp = fgetc(file);
            
            {
                if (tmp == EOF)
                {
                    break;
                }
            }

            if (tmp == '\n')
            {
                cnt_of_endline++;
                continue;
            }
        }
    }
    fclose(file);

    //printf("%s", copy);
}

void pastestr(int l, int c, int size, char side, int d1_p)
{
    
}


void multi_function(int length, int i, int type) //remove(1) & copy(2) & cut(3)//removestr --file /root/dir1/dir2/file.txt -–pos 2:1 -size 3 -b || -f
{
    int checker = 0, d1_p = 0, d2_p = 1;
    i += 8; //printf("%c", command[i]);
    if (command[i] == '"')
    {
        i++;
        checker = 1;
    }
    for (; i < length; i++)
    {
        if (checker == 1 && command[i] == '"')
        {
            i++;
            break;
        }
        else if (checker == 0 && command[i] == ' ')
            break;
        else if (command[i] == '/')
        {
            d1_p++;
            d2_p = 0;
            continue;
        }
        part[d1_p][d2_p] = command[i];
        d2_p++;
    }
    i+= 7;   //printf("%c", command[i]); return 0; // now command[i] == (first of line)
    for (int x = 1; x <= d1_p; x++) 
        {
        back_array2(x);
        if (access(b_arr, F_OK)) //don"t exist
        {
            printf("This file dosn't exist");
            return;
        }
    }
    if (type == 4)
    {
        FILE* file = fopen(b_arr, "a");
        fputs(copy, file);;
        fclose(file);
        return;
    }
    
    int l = 0, c = 0; //line and character
    while ((char)command[i] != ':')
    {
        l *= 10;
        l += ((int)command[i] - 48); //'0' = 48
        i++;
    }
    i++;
    while (command[i] != ' ')
    {
        c *= 10;
        c += ((int)command[i] - 48); //'0' = 48
        i++;
    }
    
    int size = command[i + 7] - 48; //'0' = 48
    
    i+=10;
    char side;
    side = command[i];
    //printf(" %d %d %c", l, c, side);

    if (type == 1)
    {
        removestr(l, c, size, side, d1_p);
    }
    else if (type == 2)
    {
        copystr(l, c, size, side, d1_p);
    }
    else
    {
        copystr(l, c, size, side, d1_p);
        removestr(l, c, size, side, d1_p);
    }
}

void findstr2(int d1_p, char flag, int at_count)
{
    FILE* file = fopen(b_arr, "r");
    char tmp = '\0', tmp1 = '\0';
    
    int i = 0;
    int count = 0; //at, all, count
    int tedad = 0;
    
    while (tmp != EOF)
    {
        //printf("%c1\n", tmp1);
        if (tmp == str[0] || tmp1 == str[0])
        {
            //return;
            //printf("%c2", tmp1);
            for (int x = 0; x < strlen(str); x++)
            {
                /*if (tmp == ' ' || tmp == '\n') //\n ؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟حسابه؟
                {
                    tedad++;
                }*/
                tmp = fgetc(file);
                //printf("%c ", command[tmp_int]);
                //printf("|tmp %c tmp1 %c|", tmp, tmp1);
                if (str[x] != tmp && tmp1 != str[x] && tmp1 != '\0')
                {
                    i++;
                    tmp1 = tmp;
                    //printf("\nNULL%d\n", x);
                    break;
                }
                /*else {
                    printf("\ni = %d\n", i);
                    return;
                }*/
                if (x == strlen(str) - 1)
                {
                    if (flag == '\0')
                    {
                        printf("%d", i);
                        fclose(file);
                        return;
                    }
                    else if (flag == 'h') //all
                    {
                        
                        if (count)
                        {
                            printf(", %d", i);
                        }
                        else
                        {
                            printf("%d", i);
                        }
                        count++;
                        i++;
                    }
                    else if (flag == 'c') //count
                    {
                        count++;
                        i++;
                    }
                    else if (flag == 'a') //at
                    {
                        count++;
                        if (count == at_count)
                        {
                            printf("%d", i);
                            fclose(file);
                            return;
                        }
                        i++;
                    }
                    else if (flag == 'b')
                    {
                        printf("%d", tedad);
                        fclose(file);
                        return;
                    }
                    
                }
            }
        }
        i++;
        tmp = fgetc(file);
    }
    if (flag == '\0')
    {
        printf("%d", -1);
    }
    
    if (flag == 'a')
    {
        printf("%d", -1);
    }
    else if (flag == 'c') //count
    {
        printf("%d", count);
    }
    fclose(file);
    return;
}

void findstr(int length, int i) //find -–str sb -–file /root/dir1/dir2/file.txt BAG
{
    i += 7;   //printf("%c", command[i]);
    int checker1 = 0; // check str
    if (command[i] == '"')
    {
        checker1 = 1;
    }
    
    for (int i = 0; i < MAX_SIZE; i++)
    {
        str[i] = '\0';
    }

    int tmp = 0;
    if (checker1 == 0)
    {
        while(command[i] != ' ')
        {
            str[tmp] = command[i];
            i++;
            tmp++;
        }
    }

    int checker = 0, d1_p = 0, d2_p = 1; // check file
    part[0][i] = command[i];
    i += 8;  //printf("%c", command[i]);return;
    if (command[i] == '"')
    {
        i++;
        checker = 1;
    }

    int temp = i;
    int checker_flag = 1;
    if (checker == 0)
    {
        while (command[temp] != ' ' && temp < length && temp++)
        {
            continue;
        }
        if (temp == length)
        {
            checker_flag = 0;
        }
    }
    else
    {
        while (command[temp] != '"' && temp < length && temp++)
        {
            continue;
        }
        if (temp == length - 1)
        {
            checker_flag = 0;
        }
    }
    //printf("%d", checker_flag);
    //return;
    // part-part
    if (!checker_flag)
    {
        for (; i < length; i++)
        {
            if (checker == 1 && i == length - 1)
                break;
            else if (command[i] == '/')
            {
                command[i] = '\\';
                d1_p++;
                d2_p = 0;
                continue;
            }
            part[d1_p][d2_p] = command[i];
            d2_p++;
        }
    }
    else
    {
        for (; i < length; i++)
        {
            if (checker == 1 && command[i] == '"')
                break;
            else if (checker == 0 && command[i] == ' ')
                break;
            else if (command[i] == '/')
            {
                command[i] = '\\';
                d1_p++;
                d2_p = 0;
                continue;
            }
            part[d1_p][d2_p] = command[i];
            d2_p++;
        }
    }
    /*back_array2(d1_p);
    printf("%d | %s",checker_flag, b_arr);
    return;*/
    //check file exist
    {
        for (int x = 1; x <= d1_p; x++)
        {
            back_array2(x);
            if (access(b_arr, F_OK)) //don"t exist
            {
                printf("This file dosn't exist\n");
                return;
            }
        }
    }
    char flag = '\0';
    int at_count = -1; 
    if (checker_flag)
    {
        i+=2;
        if (command[i] == 'a' && command[i + 1] == 'l')
        {
            flag = 'h'; //hame
        }
        else if (command[i] == 'a')
        {
            flag = command[i];
            at_count = command[i + 3] - 48;
        }
        
        else
        {
            flag = command[i];
        }
    }
    findstr2(d1_p, flag, at_count);
}

/*void replace_str()
{
    FILE* file = fopen(b_arr, "r");
    char tmp = '\0', tmp1 = '\0';
    
    int i = 0;
    int tmmmmmp = 0;
    while (tmp != EOF)
    {
        //printf("%c1\n", tmp1);
        if (tmp == str[0] || tmp1 == str[0])
        {
            //return;
            //printf("%c2", tmp1);
            for (int x = 0; x < strlen(str); x++)
            {
                /*if (tmp == ' ' || tmp == '\n') //\n ؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟؟حسابه؟
                {
                    tedad++;
                }
                tmp = fgetc(file);
                //printf("%c ", command[tmp_int]);
                //printf("|tmp %c tmp1 %c|", tmp, tmp1);
                if (str[x] != tmp && tmp1 != str[x] && tmp1 != '\0')
                {
                    i++;
                    tmp1 = tmp;
                    break;
                }

                if (x == strlen(str) - 1)
                {
                    tmmmmmp = 1;
                    break;
                }
            }
        }
        if (tmmmmmp == 1)
        {
            break;
        }
        
        i++;
        tmp = fgetc(file);
    }
    if (tmmmmmp == 1)
    {
        printf("%d", -1);
        fclose(file);
        return;
    }
    char file_string[MAX_SIZE][MAX_SIZE];
    fopen(b_arr, "r");
    while (tmp != EOF)
    {
        
    }
    
    fopen(b_arr, a+);
    

}
*/
void replace(int length, int i) //replace -–str1 df -–str2 dvf -–file /root/dir1/dir2/file.txt 
{
    i += 8;   //printf("%c", command[i]); return;
    int checker1 = 0; // check str1
    if (command[i] == '"')
    {
        checker1 = 1;
    }
    
    for (int i = 0; i < MAX_SIZE; i++)
    {
        str1[i] = '\0';
    }
    
    int tmp = 0;
    if (checker1 == 0)
    {
        while(command[i] != ' ')
        {
            str1[tmp] = command[i];
            i++;
            tmp++;
        }
    }
    i += 8;
    int checker2 = 0; // check str2
    if (command[i] == '"')
    {
        checker2 = 1;
    }
    
    for (int i = 0; i < MAX_SIZE; i++)
    {
        str2[i] = '\0';
    }
    
    tmp = 0;
    if (checker2 == 0)
    {
        while(command[i] != ' ')
        {
            str2[tmp] = command[i];
            i++;
            tmp++;
        }
    }
    i+= 8;//printf("%c", command[i + 8]); return;
    
    int checker = 0, d1_p = 0, d2_p = 1;
    if (command[i] == '"')
    {
        i++;
        checker = 1;
    }
    for (; i < length; i++)
    {
        if (checker == 1 && command[i] == '"')
        {
            i++;
            break;
        }
        else if (checker == 0 && command[i] == ' ')
            break;
        else if (command[i] == '/')
        {
            d1_p++;
            d2_p = 0;
            continue;
        }
        part[d1_p][d2_p] = command[i];
        d2_p++;
    }

    {
    //check file exist
        for (int x = 1; x <= d1_p; x++)
        {
            back_array2(x);
    //        printf("%s\n", b_arr);
            if (access(b_arr, F_OK)) //don"t exist
            {
                //printf("%s\n", b_arr);
                printf("This file dosn't exist\n");
                return;
            }
        }
    }
    //replace_str();
}
