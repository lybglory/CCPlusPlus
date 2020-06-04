#pragma once
#define stackMax 1024
typedef struct{
	void *dataArr[stackMax];		//data area
	int stackCount;					//count
}OrderStack;
typedef void *v_Stack;			
extern v_Stack SkInit();								//initial
extern  void PushStack(v_Stack v_stk,void *pushData);	//push
extern  void PopStack(v_Stack v_stk);	//pop
extern v_Stack GetTopStk(v_Stack v_stk);				//return top stack
extern int GetStkCount(v_Stack v_stk);				//return top stack
extern int IsStkNull(v_Stack v_stk);				//is null?
extern void DestroyStk(v_Stack v_stk);				//destrory


