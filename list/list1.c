#include <stdio.h>
#include <stdlib.h>

#define NIL 100 // �ő�̓Y����

// ���X�g�ƃ��X�g�̎��̗v�f��\������int�^
typedef int indextype;
typedef int infotype;

infotype infolist[NIL]; // ���X�g�z��
indextype nextlist[NIL]; // �v�f�ԍ������z��

// ���X�g�ւ̏��o�^�֐�
infotype add_list(infotype info,indextype list)
{
    static indextype avail = 0;
    indextype index;

    index = avail++;

    if(index == NIL){
        printf("���X�g�����t�ł�\n");
        exit(EXIT_FAILURE);
    }

    // ���X�g�ւ̓o�^
    infolist[index] = info;
    nextlist[index] = list;

    // �o�^�������X�g�̗v�f�ԍ���Ԃ�
    return index;
}

// ���X�g�̓��e��\������֐��B
// �������F���X�g
void show_list(indextype list)
{
    while(list != NIL){
        printf(" %d", infolist[list]);
        list = nextlist[list];
    }
    printf("\n");
}

// ���X�g���t���Ɍq���Ȃ����֐�
// �������F���X�g
indextype reverse_list(indextype list)
{
    indextype index;
    indextype tmp;

    index = NIL;

    while(list != NIL){
        tmp = index;
        index = list;
        list = nextlist[list];
        nextlist[index] = tmp;
    }

    return index;
}

int main()
{
    infotype info;
    indextype head;

    // ���X�g�̏�����
    head = NIL;

    for(info = 1; info <= 9; info++){
        // ���X�g�ւ̓o�^
        head = add_list(info,head);
    }

    show_list(head);

    // ���X�g���q���Ȃ���
    head = reverse_list(head);

    show_list(head);

    return EXIT_SUCCESS;
}