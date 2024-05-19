#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)��
#define MAX 100 // ��󳤶�

// ��������
int count_characters(FILE* file);
int count_words(FILE* file);

int main() {
    char param[3]; // ����
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
int count_characters(FILE* file) {
    int char_count = 0; // �ַ�����
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        char_count++;
    }

    return char_count;
}

// ͳ�Ƶ�����
int count_words(FILE* file) {
    int word_count = 0; // ���ʸ���
    int flag = 0; // ���Ƶ��ʸ�������
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\t' || ch == ',') {
            flag = 0;
        }
        else if (flag == 0) {
            flag = 1;
            word_count++;
        }
    }

    return word_count;
}