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
void grep(int, int);

void back_array2(int x);

char command[MAX_SIZE];
char part[50][MAX_SIZE];
char b_arr[MAX_SIZE];
char copy[MAX_SIZE];

int main()
{
    gets(command);
    int length = strlen(command);
    //    printf("%d", length);

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
        multi_function(length, i, 3);
    else if (!(strcmp(part[0], "find")))
        findstr(length, i);
    else if (!(strcmp(part[0], "grep")))
        grep(length, i);
    else
        printf("Invalid command");
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
char str[MAX_SIZE];
int checker_end_line[MAX_SIZE];

void insertstr_(int l, int c, int d1_p) {
    back_array2(d1_p);
    

    //baraye nomre
    /*
    FILE* file;
    file = fopen(b_arr, "a+");
    for (int i = 0; i < strlen(str); i++)
    {
        fputc("%c", str[i]);
    }
    fclose(file);
    */
    FILE* file;
    back_array2(d1_p);
    file = fopen(b_arr, "r");
    char tmp = 'f';
    int cnt_of_endline = 0;
    while (tmp != EOF)
    {
        tmp = fgetc(file);
        printf("%c", tmp);
    }
//    if (side == 'f')
//    {
        while (tmp != EOF)
        {
            /*
            if (cnt_of_endline == l - 1)
            {
                printf("dvrbtnbfgnbgn");
                for (int i = 0; i < c; i++)
                {
                    fputc(str[i], file);
                }
            }
            */
            tmp = fgetc(file);
            fputc(file, tmp);
            if (tmp == '\n')
            {
                cnt_of_endline++;
            }
        }
        
//    }
    
    fclose(file);
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
    int count = 123;
    for (int  i = 0; i < count; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n"); return; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //printf("%s", str);
    i += 6;     //    printf("%c", command[i]);return;

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
    int llkl;
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

void findstr2(int d1_p)
{

    FILE* file = fopen(b_arr, "r");
    char tmp = '\0';
    int i = 0;
    while (tmp != EOF)
    {
        tmp = fgetc(file);
        if (tmp == str[0])
        {
            int  tmp_int = i;
            for (int x = 0; x < strlen(str); x++ && tmp_int++)
            {
                if (str[x] != command[tmp_int])
                {
                    i++;
                    break;
                }
                if (x == strlen(str) - 1)
                {
                    printf("%d", i);
                    //if()
                }
            }
        }
        i++;
    }
    
}

findstr(int length, int i) //find -–str "this is an expression containing white-space." -–file /root/dir1/dir2/file.txt BAG
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        str[i] = '\0';
    }
    
    i += 7;
    int checker = 0;
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
        for (int q = tmp; command[i + 2] != '-' || command[i + 3] != '-'; q++, i++) // in ghalateeeee!!!!!!!!!
        {
           str[q - tmp] = command[i];
        }

    }
    i += 9;    //printf("%c", command[i]);return;
    int d1_p = 0, d2_p = 0;
    checker = 0;
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
    /*
    for (int i = 0; i < d1_p; i++)
    {
        printf("%s", part[i]);
    }
    */
    {
    //check file exist
    //printf("%d", d1_p);
        for (int x = 1; x <= d1_p; x++)
        {
            back_array2(x);
            //printf("%s\n", b_arr);
            if (access(b_arr, F_OK)) //don"t exist
            {
                //printf("%s\n", b_arr);
                printf("This file dosn't exist\n");
                return;
            }
        }
    }
    findstr2(d1_p);
}


void grep(int length, int i) { //grep -c –-str "proj" –files main.txt text.txt project.txt
    i += 2;
    printf("%c", command[i + 2]);
}
