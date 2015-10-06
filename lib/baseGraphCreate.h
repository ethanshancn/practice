/*
 * baseGraphCreate.h : 
 * author     : ethan
 * createTime : 15/10/2 下午3:32
 * description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./createPrime.h"
#include "./baseArrayCreat.h"

#ifndef PRACTICE_BASEGRAPHCREATE_H
#define PRACTICE_BASEGRAPHCREATE_H

/*散列表基础数据结构定义*/
struct listNode;
typedef struct listNode *position;
typedef position list;
struct hashTbl;
typedef struct hashTbl *hashTable;

/*邻接表基础数据结构定义*/
struct adjaNode;
typedef struct adjaNode *adjaPos;
typedef adjaPos *graph;

#define TOTAL_VNUM 200

graph createRandGraph(int graphSize);

#endif //PRACTICE_BASEGRAPHCREATE_H
