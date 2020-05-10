/* 後置記法 postfix notation */
/* 逆ポーランド記法ともいう */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int ch;


// 1文字読込する関数
// 半角スペースとタブは読み飛ばす
void readchar(void){
    do {
        if((ch = getchar()) == EOF){
            return;
        } 
    } while(ch == ' ' || ch == '\t');
}

void expression(void);

// 数学における"因子"を表す関数
void factor(void){
    // chの値が'('か')'の場合
    if(ch == '('){
        readchar();
        expression();
        ch == ')' ? readchar() : putchar('?');
    } 
    // 文字が空白 (' ') を除く表示文字 (printing character)の場合
    else if(isgraph(ch)){
		// 1文字書き出す
        putchar(ch);
        readchar();
    } else{
        putchar('?');
    }
}

// 数学における"項"を表す関数
void term(void){
    factor();
    for(;;){
        if (ch == '*'){
            readchar();
            factor();
    
            // *を書き出す
            putchar('*');
    
        } else if (ch == '/'){
            readchar();
            factor();
    
    		// /を書き出す
            putchar('/');
    
        } else{
            break;
        }
    }
}

// 数学における"式"を表す関数
void expression(void){

    term();

    // +か-の場合にはもう一文字読み込んでからputcharする
    for(;;){
        if(ch == '+'){
            readchar();
            term();
            
            // +を書き出す
            putchar('+');
            
        }else if(ch == '-'){
            readchar();
            term();
            
            // -を書き出す
            putchar('-');
            
        }else{
            break;
        }
    }
}

int main(void) {
    // 終端までループ
	do {
		readchar();
        expression();

        //  改行文字か終端までループ
        while(ch != '\n' && ch != EOF){
            putchar('?');
            readchar();
        }
        // 改行文字を入れる
        putchar('\n');

	} while(ch != EOF);
	
	return EXIT_SUCCESS;
}
