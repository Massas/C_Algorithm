/* ��u�L�@ postfix notation */
/* �t�|�[�����h�L�@�Ƃ����� */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int ch;


// 1�����Ǎ�����֐�
// ���p�X�y�[�X�ƃ^�u�͓ǂݔ�΂�
void readchar(void){
    do {
        if((ch = getchar()) == EOF){
            return;
        } 
    } while(ch == ' ' || ch == '\t');
}

void expression(void);

// ���w�ɂ�����"���q"��\���֐�
void factor(void){
    // ch�̒l��'('��')'�̏ꍇ
    if(ch == '('){
        readchar();
        expression();
        ch == ')' ? readchar() : putchar('?');
    } 
    // �������� (' ') �������\������ (printing character)�̏ꍇ
    else if(isgraph(ch)){
		// 1���������o��
        putchar(ch);
        readchar();
    } else{
        putchar('?');
    }
}

// ���w�ɂ�����"��"��\���֐�
void term(void){
    factor();
    for(;;){
        if (ch == '*'){
            readchar();
            factor();
    
            // *�������o��
            putchar('*');
    
        } else if (ch == '/'){
            readchar();
            factor();
    
    		// /�������o��
            putchar('/');
    
        } else{
            break;
        }
    }
}

// ���w�ɂ�����"��"��\���֐�
void expression(void){

    term();

    // +��-�̏ꍇ�ɂ͂����ꕶ���ǂݍ���ł���putchar����
    for(;;){
        if(ch == '+'){
            readchar();
            term();
            
            // +�������o��
            putchar('+');
            
        }else if(ch == '-'){
            readchar();
            term();
            
            // -�������o��
            putchar('-');
            
        }else{
            break;
        }
    }
}

int main(void) {
    // �I�[�܂Ń��[�v
	do {
		readchar();
        expression();

        //  ���s�������I�[�܂Ń��[�v
        while(ch != '\n' && ch != EOF){
            putchar('?');
            readchar();
        }
        // ���s����������
        putchar('\n');

	} while(ch != EOF);
	
	return EXIT_SUCCESS;
}
