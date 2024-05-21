#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)��
#define MAX 100 // ��󳤶�

// ��������
int count_characters(FILE* file);
int count_words(FILE* file);

int main() {
    char param[2]; // ����
    char file_name[MAX]; // �ļ���
    scanf("%s %s", param, file_name);

    //���ļ�
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: Unable to open file\n");
        return 1;
    }
    else if (strcmp(param, "-c") == 0) {
        int char_count = count_characters(file);
        printf("�ַ�����%d\n", char_count);
    }
    else if (strcmp(param, "-w") == 0) {
        int word_count = count_words(file);
        printf("��������%d\n", word_count);
    }

    // �ر��ļ�
    fclose(file);

    return 0;
}

// ͳ���ַ���
int count_characters(File* file){
     int totalCharacter;
     if(fgetc(file) != EOF){
         totalCharacter++;
     }
     return totalCharacter;
}

int count_words(File* file){
    int totalwords;
    while(true){
       if(fgetc(file) == " "||fgetc(file) == ","||fgetc(file) == "/t" ||fgetc(file) == "n"){
         totalwords++;
       }
    }
    return totalwords;
}
