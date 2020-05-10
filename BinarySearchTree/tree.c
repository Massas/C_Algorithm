// 2���T���� binary search tree

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �T���Ɏg�p����L�[�̌^�錾
typedef char keytype[21];

// 2���؂̃m�[�h�̌^�錾
typedef struct node {
    struct node *left, *right;  // ���E�̎q�m�[�h�ւ̃|�C���^
    keytype key;                // �T���̃L�[
} *nodeptr;     // �m�[�h���w���|�C���^

struct node nil;    // �؂̖��[��\���m�[�h
nodeptr root = &nil;    // �����w���|�C���^

// �؂ւ̑}��(�o�^)�֐�
nodeptr insert(keytype insertkey){
    int cmp;
    nodeptr *p;     // �m�[�h���w���|�C���^
    nodeptr q;      // �m�[�h�̎���

    strncpy(nil.key,insertkey,sizeof(keytype));  // �Ԑl�̃L�[�Ɉ����̃L�[���R�s�[

    p = &root;  // ���̃|�C���^������ϐ��̃|�C���^�ɑ��

    // �L�[����v����܂Ń��[�v
    while((cmp = strncmp(insertkey, (*p)->key, sizeof(keytype))) != 0)
    {
        // insertkey���|�C���^���w���m�[�h�̃L�[��菬�����ꍇ�A�����̏������m�[�h�Ɉړ�����
        // insertkey���|�C���^���w���m�[�h�̃L�[���傫���ꍇ�A�E���̑傫���m�[�h�Ɉړ�����
        if(cmp < 0){
            // �|�C���^�����Ɉړ�����
            p = &((*p)->left);
        } 
        else{
            // �|�C���^���E�Ɉړ�����
            p = &((*p)->right);
        }
    }

    // ���łɃL�[���o�^����Ă���ꍇ
    if(*p != &nil){
        return NULL;
    }

    // �m�[�h���̃������̈���m�ۂ���
    if((q = malloc(sizeof(*q))) == NULL){
        printf("insert: �������s���ɂ�胁�����̈�m�ێ��s�B\n");
        exit(EXIT_FAILURE);
    }
    
    // �m�[�h�̃L�[���R�s�[����
    strncpy(q->key, insertkey, sizeof(keytype));

    q->left = &nil;
    q->right = *p;
    *p = q;

    // �o�^�����m�[�h��Ԃ�
    return q;

}

// �폜�֐�
// �폜�ł����0�A���s�Ȃ�1��Ԃ�
int delete(keytype deletekey){
    int cmp;

    nodeptr *p, *q;
    nodeptr r, s;

    strncpy(nil.key, deletekey, sizeof(keytype));   // �Ԑl

    p = &root;

    // �L�[����v����܂Ń��[�v
    while((cmp = strncmp(deletekey, (*p)->key, sizeof(keytype))) != 0)
    {
        // insertkey���|�C���^���w���m�[�h�̃L�[��菬�����ꍇ�A�����̏������m�[�h�Ɉړ�����
        // insertkey���|�C���^���w���m�[�h�̃L�[���傫���ꍇ�A�E���̑傫���m�[�h�Ɉړ�����
        if(cmp < 0){
            p = &((*p)->left);
        }
        else{
            p = &((*p)->right);
        }
    }

    // �L�[��������Ȃ��ꍇ
    if(*p == &nil){
        return 1;
    }

    r = *p;

    if(r->right == &nil){
        *p = r->right;
    }else if(r->left == &nil){
        *p = r->right;
    } else{
        q = &(r->left);
        
        while((*q)->right != &nil){
            q = &((*q)->right);
        }

        s = *q;
        *q = s->left;
        s->left = r->left;
        s->right = r->right;
        *p = s;
    }

    // �̈���������
    free(r);

    return 0;

}

// �����֐�
// �L�[�����������ꍇ�ɂ̓L�[�����m�[�h�̃|�C���^��Ԃ�
// ������Ȃ����NULL��Ԃ�
nodeptr search(keytype searchkey){
    int cmp;
    nodeptr p;

    strncpy(nil.key, searchkey, sizeof(keytype));
    p = root;

    while((cmp =strncmp(searchkey, p->key, sizeof(keytype))) != 0){
        if(cmp < 0){
            p = p->left;
        }else{
            p = p->right;
        }
    }
    
    if(p != &nil){
        // ���������ꍇ
        return p;
    }else{
        // ������Ȃ������ꍇ
        return NULL;
    }

}

void printtree(nodeptr p){
    static int depth = 0;

    // �����̃m�[�h��\������
    if((p->left) != &nil){
        depth++;
        // �ċA�Ăяo��
        printtree(p->left);
        depth--;
    }

    // �����Ŏ󂯂��m�[�h��\������
    printf("%*c%s\n", 5*depth, ' ', p->key);

    // �E���̃m�[�h��\������
    if(p->right != &nil){
        depth++;
        // �ċA�Ăяo��
        printtree(p->right);
        depth--;
    }
}

int main(void) {

    char buf[22];
    short count;

    printf( "����   Iabc:  abc��}��\n"
            "       Dabc:  abc���폜\n"
            "       Sabc:  abc������\n");
    
    for(;;){
        printf("���߂́H ");
        
        switch(count){
        	case 0:
        		memset(buf,0x00,sizeof(buf));
        		sprintf(buf, "Iabc");
                printf("%s",buf);
        		break;
        	case 1:
        		memset(buf,0x00,sizeof(buf));
        		sprintf(buf, "Sabc");
        		break;
        	case 2:
        		memset(buf,0x00,sizeof(buf));
        		sprintf(buf, "Dabc");
        		break;
        	case 3:
        		memset(buf,0x00,sizeof(buf));
        		sprintf(buf, "Sabc");
        		break;
        	default:
        		return EXIT_SUCCESS;
        	}

        // buf�T�C�Y���W�����͂���f�[�^���󂯎��
        if(scanf("%21s%*[^\n]", buf) != 1){
            break;
        }

        switch(buf[0]){
            // �}������
            case 'I': case'i':
                // �}���֐�
                if(insert(&buf[1])){
                    printf("%21s%*[^\n]�F�o�^���܂���\n",buf);
                }else{
                    printf("%21s%*[^\n]�F�o�^�ς݂ł�\n",buf);
                }

                break;

            // �폜����
            case 'D': case 'd':
                // �폜�֐�
                if(delete(&buf[1])){
                    printf("%21s%*[^\n]�F�폜����Ă��܂���\n",buf);
                }else{
                    printf("%21s%*[^\n]�F�폜���܂���\n",buf);
                }

                break;

            // ��������
            case 'S': case 's':
                // �폜�֐�
                if(search(&buf[1])){
                    printf("%21s%*[^\n]�F�o�^����Ă��܂�\n",buf);
                }else{
                    printf("%21s%*[^\n]�F�o�^����Ă��܂���\n",buf);
                }

                break;
            default:
                printf("�g�p�ł���̂� I, D, S �����ł�\n");
                break;
        }

        if(root != &nil){
            printf("\n");
            printtree(root);
            printf("\n");
        }

        count++;
        
    }

	// return EXIT_SUCCESS;
}
