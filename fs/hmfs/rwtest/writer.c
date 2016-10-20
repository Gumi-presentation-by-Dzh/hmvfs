#include <stdio.h>

/*
 *  Usage: ./a.out file 5
 *  file: "AAA...AAA\nBBB...BBB\nCCC...CCC\nDDD...DDD\nEEE...EEE\n" with 1023 copies of each character
 *  thus, file size = 5*1024 = 5KB in this case
 *  argv[1] = address of the file
 *  argv[2] = size of the file in KB, default = 4
 */

int main(int argc, char* argv[]){
    int filesize = 4;
    int i=0;
    int count=0;
    char c = 'A';
    if (argc == 3) filesize = atoi(argv[2]);
    FILE *fp;
    fp = fopen(argv[1],"w");
    while (count<filesize) {
        for (i=0;i<1023;++i) fputc(c, fp);
        fputc('\n', fp);
        if (c=='Z') c='A'; else c=c+1;
        count++;
    }
    fclose(fp);
    return 0;
}