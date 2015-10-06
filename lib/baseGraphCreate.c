/*
 * baseGraphCreate.c : 产生随机图
 * author     : ethan
 * createTime : 15/10/2 下午3:32
 * description:
 */

#include "baseGraphCreate.h"

/************ HASH TABLE START ************/
struct listNode{
    int vNum;
    char * content;
    position next;
};
struct hashTbl{
    int tableSize;
    list *theList;  //此处指针的指针是为形成一个数组
};

//散列函数
unsigned int hash(char * content, int tableSize){
    unsigned int hashVal = 0;
    while (content != '\0'){
        hashVal = (hashVal << 5) + *content++;
        return hashVal%tableSize;
    }
}

hashTable initHashTable(int tableSize){
    hashTable H;
    int i;
    H = malloc(sizeof(struct hashTbl));
    if(H == NULL){
        printf("Out of space!\n");
        return NULL;
    }
    H->tableSize = getCloseinLargerNum(tableSize);

    H->theList = malloc(sizeof(list) * H->tableSize);
    if(H->theList == NULL){
        printf("Out of space!\n");
        return NULL;
    }

    for (int i = 0; i < H->tableSize; ++i) {
        H->theList[i] = malloc(sizeof(struct listNode));
        if(H->theList[i] == NULL){
            printf("Out of space!\n");
            return NULL;
        }else{
            H->theList[i]->next = NULL;
        }
    }
    return H;
}

position find(char * content, hashTable H){
    position P;
    list L;
    L = H->theList[hash(content,H->tableSize)];
    P = L->next;
    while (P != NULL && strcmp(P->content,content) != 0)
        P = P->next;
    return P;
}

position insert(char * newContent, int newVNum, hashTable H){
    position pos,newCell;
    list L;
    pos = find(newContent,H);
    if(pos != NULL)
        return NULL;

    newCell = malloc(sizeof(struct listNode));
    if(newCell == NULL){
        printf("Out of space!\n");
        return NULL;
    }
    L = H->theList[hash(newContent, H->tableSize)];
    newCell->next = L->next;
    newCell->content = newContent;
    newCell->vNum = newVNum;
    L->next = newCell;
    return newCell;
}

void delete(char * oldContent,hashTable H){
    position preCell,oldCell;
    list L;

    L = H->theList[hash(oldContent, H->tableSize)];
    preCell = L;
    while (preCell->next != NULL && strcmp(preCell->next->content,oldContent) != 0)
        preCell = preCell->next;
    if(preCell->next)
        return;
    oldCell = preCell->next;
    preCell->next = preCell->next->next;
    free(oldCell);
}
/************ HASH TABLE END ************/
//生成随机字符串
char* createRandString(){
    int i = 0, length = creatRandomInt(1,15);
    char *string;
    string = (char *)malloc(sizeof(char) * (length + 1));
    for (int i = 0; i < length; ++i) {
        string[i] = creatRandomInt(97,122);
    }
    string[length] = '\0';
    return string;
};

/************ GRAPHY START ************/

struct adjaNode{
    int thisNum;
    adjaPos next;
};

graph initGraph(int graphSize){
    graph totalGraph = malloc(sizeof(adjaPos) * graphSize);
    int i;
    for (int i = 0; i < graphSize; ++i) {
        totalGraph[i] = malloc(sizeof(struct adjaNode));
        totalGraph[i]->thisNum = -1;
        totalGraph[i]->next = NULL;
    }
    return totalGraph;
}

void addAdjaNode(graph G, int vNum, int newKey){
    adjaPos tmp,newCell;
    tmp = G[vNum];
    while (tmp->next != NULL){
        if(tmp->thisNum != -1 && tmp->thisNum == newKey)
            return;
        tmp = tmp->next;
    }
    newCell = malloc(sizeof(struct adjaNode));
    newCell->thisNum = newKey;
    newCell->next = NULL;
    tmp->next = newCell;
}

//由数字索引查名称
list *globalContent;
//由名称查数字索引
hashTable vertexTable;

//主程序
graph createRandGraph(int graphSize){
    int vNum = 1;
    hashTable vertexTable = initHashTable(1024);




    /*
     * 1、递增vNum
     * 2、查找hash表是否已存在
     * 3、插入hash表
     * 4、增加数组
     * 5、随机创建连接以创建图
     * 6、返回图
     */




}

//返回实际名称
char * getContent(int vNum){

}