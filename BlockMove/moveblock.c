/* ブロック移動 block move */

#include <stdio.h>
#include <stdlib.h>

char sentense[] = "PROGRAMMINGPRINCIPLES";

int main(void) {
	
	printf("%s\n",sentense);

	// 文字列移動関数を呼び出す
	rotate(0, 10, 20);
		
	printf("%s\n", sentense);

	return EXIT_SUCCESS;
}

// 文字列反転関数
// 文字列長が奇数の場合には、中央の文字だけは反転しない
void reverse(int i,int j){
	// 置換するためのtmp変数
	int t;
	while(i < j){
		t = sentense[i];
		sentense[i] = sentense[j];
		sentense[j] = t;
		
		// 処理する文字列位置を一つずつずらす
		i++;
		j--;
		
		printf("%s i=%d j=%d (reverse)\n", sentense, i, j);
	}
}

// 文字列移動関数
// reverse関数を呼び出す
// 第一引数：入れ替える文字列の左側部分の開始位置
// 第二引数：入れ替える文字列の右側部分の開始位置
// 第三引数：入れ替える文字列全体の文字列
void rotate(int left, int mid, int right){
	reverse(left, mid);
	reverse(mid + 1,right);
	reverse(left, right);
}
