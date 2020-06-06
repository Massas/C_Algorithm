#include <stdio.h>
#include <stdlib.h>

#define NIL 100 // 最大の添え字

// リストとリストの次の要素を表す情報はint型
typedef int indextype;
typedef int infotype;

infotype infolist[NIL]; // リスト配列
indextype nextlist[NIL]; // 要素番号を持つ配列

// リストへの情報登録関数
infotype add_list(infotype info,indextype list)
{
    static indextype avail = 0;
    indextype index;

    index = avail++;

    if(index == NIL){
        printf("リストが満杯です\n");
        exit(EXIT_FAILURE);
    }

    // リストへの登録
    infolist[index] = info;
    nextlist[index] = list;

    // 登録したリストの要素番号を返す
    return index;
}

// リストの内容を表示する関数。
// 第一引数：リスト
void show_list(indextype list)
{
    while(list != NIL){
        printf(" %d", infolist[list]);
        list = nextlist[list];
    }
    printf("\n");
}

// リストを逆順に繋ぎなおす関数
// 第一引数：リスト
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

    // リストの初期化
    head = NIL;

    for(info = 1; info <= 9; info++){
        // リストへの登録
        head = add_list(info,head);
    }

    show_list(head);

    // リストを繋ぎなおす
    head = reverse_list(head);

    show_list(head);

    return EXIT_SUCCESS;
}