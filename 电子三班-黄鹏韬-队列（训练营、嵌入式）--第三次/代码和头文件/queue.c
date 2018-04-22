/***************************************************************************************
 *	File Name				:	queue.h
 *	CopyRight				:
 *
 *	SYSTEM					:   win10
 *	Create Data				:	2018.4.21
 *	Author/Corportation		:
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

 /**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

/**************************************************************
*	Macro Define Section
**************************************************************/
#define MAXQUEUE 10

/**************************************************************
*	Struct Define Section
**************************************************************/
//循环队列结构
typedef struct Aqueue        	
{
    void *data[MAXQUEUE];  	//数据域
    int front;
    int rear;
	size_t data_size;		//数据域内存大小
} AQueue;

//链式队列结构
typedef struct node     	  	
{
    void* data;       			//数据域指针
    struct node *next;			//指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node *front;       			//队头
    Node *rear;        			//队尾
	size_t data_size;			//数据域内存大小
} LQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;

/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *	@description : 初始化队列
 *	@param		 : 队列指针Q
 *	@return		 : None
 *  @notice      : None
 */
void InitAQueue(AQueue *Q)
{
    Q->front=0;
	Q->rear=0;
	return; 
}

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *	@description : 初始化队列
 *	@param		 : 队列指针Q
 *	@return		 : None
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
	 Q->front=Q->rear=(Node)malloc(sizeof(Node));  
     if(!(Q->front))  
        return;  
     Q->front->next=0;  
 } 

/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *	@description : 销毁队列
 *	@param		 : 队列指针Q
 *	@return		 : None
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q)
{
    if(Q->front==Q->rear)
        return;
    else
        free(Q->data);
        Q->front=(Q->front+1)%MAXQUEUE;
        return;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *	@description : 销毁队列
 *	@param		 : 队列指针Q
 *	@return		 : None
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
	if(Q->front==Q->rear)  
     {  
        return;  
     }  
    else while(Q->front)  
     {  
        Q->rear=Q->front->next;  
        free((Q->front));  
        Q->front=Q->rear;  
        if(!Q->rear)  
            free(Q->rear);  
     }  
     free(Q->front);  
}

/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *	@description : 检查队列是否已满
 *	@param		 : 队列指针Q
 *	@return		 : 满-TRUE; 未满-FLASE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q)
{
	if((Q->rear+1)%MAXQUEUE==Q->front)
	    return TRUE;
	else
	    return FALSE;
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *	@description : 检查队列是否为空
 *	@param		 : 队列指针Q
 *	@return		 : 空-TRUE; 未空-FLASE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q)
{
	if(Q->front==Q->rear)
	    return TRUE;
	else
	    return FALSE; 
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *	@description : 检查队列是否为空
 *	@param		 : 队列指针Q
 *	@return		 : 空-TRUE; 未空-FLASE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q->front==Q->rear)
		return TRUE;
	else
	    return FALSE;
}

/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *	@description : 查看队头元素
 *	@param		 : 队列指针Q，存放元素e
 *	@return		 : 成功-TRUE; 失败-FLASE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e)
{
	if(Q->front=Q->rear)
	    return FALSE;
	else
	     void *e=Q->front[Q->data];
		return TRUE;       

}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *	@description : 查看队头元素
 *	@param		 : 队列指针Q，存放元素e
 *	@return		 : 成功-TRUE; 失败-FLASE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
	if(Q->front==Q->rear)
	    return FALSE;
	else
	    void *e=Q->front->data;
	    return TRUE;
}

/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *	@description : 确定队列长度
 *	@param		 : 队列指针Q
 *	@return		 : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
	return (Q->rear - Q->front+MAXQUEUE)%MAXQUEUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *	@description : 确定队列长度
 *	@param		 : 队列指针Q
 *	@return		 : 队列长度count
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
	int i=0;
	while(Q->front->next)
	{
		Q->front=Q->front->next;
		i++;
	}
	return i;
}

/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *	@description : 入队操作
 *	@param		 : 队列指针Q,入队数据指针data
 *	@return		 : 成功-TRUE; 失败-FLASE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data)
{
	if((Q->rear+1)%MAXQUEUE==Q->front)
	    return FALSE;
	else
	    Q->data[Q->rear]=data;
	    return TRUE;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *	@description : 入队操作
 *	@param		 : 队列指针Q,入队数据指针data
 *	@return		 : 成功-TRUE; 失败-FLASE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data)
{
	if(Q->front==Q->rear)
	    return FALSE;
	else
        Q->rear=Q->rear->next;
	    Q->data[Q->rear]=data;
	    return TRUE;
}

/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *	@description : 出队操作
 *	@param		 : 队列指针Q
 *	@return		 : 成功-TRUE; 失败-FLASE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q)
{
	if(Q->front==Q->rear)
	   return FALSE;
	else
	   Q->front=(Q->front+1)%MAXQUEUE;
	   return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *	@description : 出队操作
 *	@param		 : 队列指针Q
 *	@return		 : 成功-TRUE; 失败-FLASE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
	if(Q->front==Q->rear)
	    return FALSE;
	else
        Q->front=Q->front->next;
	    return TRUE;
}

/**
 *  @name        : void ClearAQueue(Queue *Q)
 *	@description : 清空队列
 *	@param		 : 队列指针Q
 *	@return		 : None
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
	Q->front=Q->rear=0;
	return;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *	@description : 清空队列
 *	@param		 : 队列指针Q
 *	@return		 : None
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	struct node *p,*q;    
  Q->rear=Q->front;    
  p=Q->front->next;    
  Q->front->next;    //只留下头结点     
  while(p)    
  {    
    q=p;    
    p=p->next;    
    free(q);    
  }    
  return;  
}

/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *	@description : 遍历函数操作
 *	@param		 : 队列指针Q，操作函数指针foo
 *	@return		 : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
	if(Q->front==Q->rear)
	    return;
	else
	    foo(Q->front[Q->data]);
	    Q->front=(Q->front+1)%MAXQUEUE;
	    return;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *	@description : 遍历函数操作
 *	@param		 : 队列指针Q，操作函数指针foo
 *	@return		 : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
	if(Q->front==Q->rear)
	    return FALSE;
	else
	    int i=Q->front;
	    foo=Q->data[i];
	    i++;
	    return TRUE;
}

/**
 *  @name        : void APrint(void *q)
 *	@description : 操作函数
 *	@param		 : 指针q
 *	@return		 : None
 *  @notice      : None
 */
 void APrint(void *q)
 { 
    if(q->front == q->rear)  
        return;  
    else if(q->rear < q->front)  
    {  
        for(int i = q->front;i < MAXSIZE;++i)  
            printf("%d ",q->data[i]);  
        for(int i = 0;i < q->rear;++i)  
            printf("%d ",q->data[i]);  
        printf("\n");  
    }  
    else{  
        for(int i = q->front;i < q->rear;++i)  
            printf("%d ",q->data[i]);  
        printf("\n");  
    }  
 }
 
/**
 *  @name        : void LPrint(void *q)
 *	@description : 操作函数
 *	@param		 : 指针q
 *	@return		 : None
 *  @notice      : None
 */
 void LPrint(void *q)
 {
 	q=Q->front;
 	if(Q->front==Q->rear)
 	    return;
 	else
 	    while(q!=Q->rear)
 	    {
 	    	q=q->next;
		 }
 }
 
 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif // QUEUE_H_INCLUDED

