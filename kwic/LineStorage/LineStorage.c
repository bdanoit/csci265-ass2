/********** LineStorage module---implementation **********/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kwic.h"
#include "LineStorage.h"
#include "Exceptions.h"

/***** local constants *****/
#define DefaultLineCapacity 8
#define DefaultWordCapacity 10

/***** local types *****/
/*The LineStorage module stores a list of LineNodes*/
typedef struct LineNode {
    int capacity;
	int count;
    char** words;
} LineNode;
typedef LineNode* LineNodePtr;

typedef struct LineStorage{
    int capacity;
    int count;
    LineNode** lines;
} LineStorage;

/***** local variables *****/

static LineStorage* LS;
//static LineNodePtr headLinePtr, tailLinePtr;
//static int lineCount;

/***** state invariant *****

1. if lineCount == 0 then
	headlinePtr == NULL
	taillinePtr == NULL
   else
	headLinePtr points to a null-terminated linked list of LineNodes.
	tailLinePtr points to the last LineNode in this list.
	There are lineCount LineNodes in this list.

2. for every LineNode allocated by LineStorage
	if wordCount == 0 then
	    headWordPtr == NULL
	    tailWordPtr == NULL
	else
	    headWordPtr points to a null-terminated linked list of WordNodes.
	    tailWordPtr points to the last WordNode in this list.
	    There are wordCount WordNodes in this list.

3. For every WordNode allocated word is a null-terminated array of characters.

4. All of the dynamic memory allocated by LineStorage (and not yet freed)
   is in the list structure headed by headLinePtr.
*/

/***** local functions *****/

/*
* if headLinePtr contains at least i+1 LineNodes then
*	return the address of the ith LineNode
* else
*	return NULL
* Assumed: the state invariant holds
*/
static LineNodePtr getLine(int i)
{
    if(LS == NULL){
        return NULL;
    }
    
    if(i < 0 || i >= LS->count){
        return NULL;
    }
    
    return LS->lines[i];
}

/***** exported functions *****/

void LSInit(void)
{
    LS = calloc(1, sizeof(LineStorage));
    if(LS == NULL){
        THROW(KWMEMORYERROR);
    }
    LS->capacity = DefaultLineCapacity;
    LS->count = 0;
    LS->lines = (LineNode**)calloc(LS->capacity, sizeof(LineNode*));
}

void LSReset(void)
{
    int i, k;
	for (i = 0; i < LS->count; i++) {
        LineNode* LN = LS->lines[i];
        for(k = 0; k < LN->count; k++){
            free(LN->words[k]);
        }
        free(LN->words);
        free(LS->lines[i]);
    }
    free(LS->lines);
    
    /* RE-INITIALIZE */
    LS->capacity = DefaultLineCapacity;
    LS->count = 0;
    LS->lines = (LineNode**)calloc(LS->capacity, sizeof(LineNode*));
}

KWStatus LSAddLine(void)
{
    
    if(LS == NULL){
        LSInit();
    }
    /* INITIATE LineNode */
    LineNode* newLine;
    newLine = calloc(1, sizeof(LineNode));
    if(newLine == NULL){
        //LineNode CALLOC FAILED
		return KWMEMORYERROR;
    }
    newLine->capacity = DefaultWordCapacity;
    newLine->count = 0;
    newLine->words = (char**)calloc(newLine->capacity, sizeof(char*));
    
	/* REALLOCATE IF SIZE GREATER THAN CAPACITY */
    if(LS->capacity == LS->count){
        LS->capacity*= 2;
	    LineNode** tmp;
        tmp = (LineNode**)realloc(LS->lines, LS->capacity * sizeof(LineNode*));
        if(tmp == NULL){
            //LineStorage REALLOC FAILED
            return KWMEMORYERROR;
        }
        LS->lines = tmp;
    }
    LS->lines[LS->count++] = newLine;
	return KWSUCCESS;
}

KWStatus LSAddWord(char* word)
{
    
    if(LS->count == 0){
        return KWRANGEERROR;
    }
    
    /* GET CURRENT LineNode */
    LineNode* LN = LS->lines[LS->count-1];
    
	/* REALLOCATE IF SIZE GREATER THAN CAPACITY */
    if(LN->capacity == LN->count){
        LN->capacity*= 2;
	    char** tmp;
        tmp = (char**)realloc(LN->words, LN->capacity * sizeof(char*));
        if(tmp == NULL){
            //LineNode REALLOC FAILED
            return KWMEMORYERROR;
        }
        LN->words = tmp;
    }
    
    /* WORD NODE FOR STORING WORD */
    char* WN = malloc(strlen(word)+1);
    if(!WN){
        //WordNode MALLOC FAILED
        return KWMEMORYERROR;
    }
    strcpy(WN, word);
    LN->words[LN->count++] = WN;
	return KWSUCCESS;
}

const char* LSGetWord(int lineNum,int wordNum)
{
	LineNodePtr LN;
    char* word;

	if (lineNum >= LS->count)
		return NULL;

	/* find line LineNum */
	LN = getLine(lineNum);
	if (LN == NULL)
		return NULL;

	/* find word wordNum */
	if (wordNum < 0 || wordNum >= LN->count)
		return NULL;
        
	return LN->words[wordNum];
}

int LSNumWords(int lineNum)
{
	LineNodePtr LN;

	/* find line lineNum */
	LN = getLine(lineNum);
	if (LN == NULL) {
		return KWRANGEERROR;
	}
	/* count the words in line lineNum */
	return LN->count;
}

int LSNumLines(void)
{
	return LS->count;
}

void LSPrintState(void)
{
	printf("lineCount:%d\n",LS->count);
    int i, k;
	for (i = 0; i < LS->count; i++) {
        LineNode* LN = LS->lines[i];
		printf("\twordCount:%d\n\t",LN->count);
        for(k = 0; k < LN->count; k++){
			printf("!%s",LN->words[k]);
		}
		printf("!\n");
	}
}
