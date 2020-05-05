/* �u���b�N�ړ� block move */

#include <stdio.h>
#include <stdlib.h>

char sentense[] = "PROGRAMMINGPRINCIPLES";

int main(void) {
	
	printf("%s\n",sentense);

	// ������ړ��֐����Ăяo��
	rotate(0, 10, 20);
		
	printf("%s\n", sentense);

	return EXIT_SUCCESS;
}

// �����񔽓]�֐�
// �����񒷂���̏ꍇ�ɂ́A�����̕��������͔��]���Ȃ�
void reverse(int i,int j){
	// �u�����邽�߂�tmp�ϐ�
	int t;
	while(i < j){
		t = sentense[i];
		sentense[i] = sentense[j];
		sentense[j] = t;
		
		// �������镶����ʒu��������炷
		i++;
		j--;
		
		printf("%s i=%d j=%d (reverse)\n", sentense, i, j);
	}
}

// ������ړ��֐�
// reverse�֐����Ăяo��
// �������F����ւ��镶����̍��������̊J�n�ʒu
// �������F����ւ��镶����̉E�������̊J�n�ʒu
// ��O�����F����ւ��镶����S�̂̕�����
void rotate(int left, int mid, int right){
	reverse(left, mid);
	reverse(mid + 1,right);
	reverse(left, right);
}
