// 2分探索木 binary search tree

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 探索に使用するキーの型宣言
typedef char keytype[21];

// 2分木のノードの型宣言
typedef struct node {
    struct node *left, *right;  // 左右の子ノードへのポインタ
    keytype key;                // 探索のキー
} *nodeptr;     // ノードを指すポインタ

struct node nil;    // 木の末端を表すノード
nodeptr root = &nil;    // 根を指すポインタ

// 木への挿入(登録)関数
nodeptr insert(keytype insertkey){
    int cmp;
    nodeptr *p;     // ノードを指すポインタ
    nodeptr q;      // ノードの実体

    strncpy(nil.key,insertkey,sizeof(keytype));  // 番人のキーに引数のキーをコピー

    p = &root;  // 根のポインタを内部変数のポインタに代入

    // キーが一致するまでループ
    while((cmp = strncmp(insertkey, (*p)->key, sizeof(keytype))) != 0)
    {
        // insertkeyがポインタが指すノードのキーより小さい場合、左側の小さいノードに移動する
        // insertkeyがポインタが指すノードのキーより大きい場合、右側の大きいノードに移動する
        if(cmp < 0){
            // ポインタを左に移動する
            p = &((*p)->left);
        } 
        else{
            // ポインタを右に移動する
            p = &((*p)->right);
        }
    }

    // すでにキーが登録されている場合
    if(*p != &nil){
        return NULL;
    }

    // ノード分のメモリ領域を確保する
    if((q = malloc(sizeof(*q))) == NULL){
        printf("insert: メモリ不足によりメモリ領域確保失敗。\n");
        exit(EXIT_FAILURE);
    }
    
    // ノードのキーをコピーする
    strncpy(q->key, insertkey, sizeof(keytype));

    q->left = &nil;
    q->right = *p;
    *p = q;

    // 登録したノードを返す
    return q;

}

// 削除関数
// 削除できれば0、失敗なら1を返す
int delete(keytype deletekey){
    int cmp;

    nodeptr *p, *q;
    nodeptr r, s;

    strncpy(nil.key, deletekey, sizeof(keytype));   // 番人

    p = &root;

    // キーが一致するまでループ
    while((cmp = strncmp(deletekey, (*p)->key, sizeof(keytype))) != 0)
    {
        // insertkeyがポインタが指すノードのキーより小さい場合、左側の小さいノードに移動する
        // insertkeyがポインタが指すノードのキーより大きい場合、右側の大きいノードに移動する
        if(cmp < 0){
            p = &((*p)->left);
        }
        else{
            p = &((*p)->right);
        }
    }

    // キーが見つからない場合
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

    // 領域を解放する
    free(r);

    return 0;

}

// 検索関数
// キーが見つかった場合にはキーを持つノードのポインタを返す
// 見つからなければNULLを返す
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
        // 見つかった場合
        return p;
    }else{
        // 見つからなかった場合
        return NULL;
    }

}

void printtree(nodeptr p){
    static int depth = 0;

    // 左側のノードを表示する
    if((p->left) != &nil){
        depth++;
        // 再帰呼び出し
        printtree(p->left);
        depth--;
    }

    // 引数で受けたノードを表示する
    printf("%*c%s\n", 5*depth, ' ', p->key);

    // 右側のノードを表示する
    if(p->right != &nil){
        depth++;
        // 再帰呼び出し
        printtree(p->right);
        depth--;
    }
}

int main(void) {

    char buf[22];
    short count;

    printf( "命令   Iabc:  abcを挿入\n"
            "       Dabc:  abcを削除\n"
            "       Sabc:  abcを検索\n");
    
    for(;;){
        printf("命令は？ ");
        
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

        // bufサイズ分標準入力からデータを受け取る
        if(scanf("%21s%*[^\n]", buf) != 1){
            break;
        }

        switch(buf[0]){
            // 挿入処理
            case 'I': case'i':
                // 挿入関数
                if(insert(&buf[1])){
                    printf("%21s%*[^\n]：登録しました\n",buf);
                }else{
                    printf("%21s%*[^\n]：登録済みです\n",buf);
                }

                break;

            // 削除処理
            case 'D': case 'd':
                // 削除関数
                if(delete(&buf[1])){
                    printf("%21s%*[^\n]：削除されていません\n",buf);
                }else{
                    printf("%21s%*[^\n]：削除しました\n",buf);
                }

                break;

            // 検索処理
            case 'S': case 's':
                // 削除関数
                if(search(&buf[1])){
                    printf("%21s%*[^\n]：登録されています\n",buf);
                }else{
                    printf("%21s%*[^\n]：登録されていません\n",buf);
                }

                break;
            default:
                printf("使用できるのは I, D, S だけです\n");
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
