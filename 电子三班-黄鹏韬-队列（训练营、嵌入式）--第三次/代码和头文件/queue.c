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
//ѭ�����нṹ
typedef struct Aqueue        	
{
    void *data[MAXQUEUE];  	//������
    int front;
    int rear;
	size_t data_size;		//�������ڴ��С
} AQueue;

//��ʽ���нṹ
typedef struct node     	  	
{
    void* data;       			//������ָ��
    struct node *next;			//ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
    Node *front;       			//��ͷ
    Node *rear;        			//��β
	size_t data_size;			//�������ڴ��С
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
 *	@description : ��ʼ������
 *	@param		 : ����ָ��Q
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
 *	@description : ��ʼ������
 *	@param		 : ����ָ��Q
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
 *	@description : ���ٶ���
 *	@param		 : ����ָ��Q
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
 *	@description : ���ٶ���
 *	@param		 : ����ָ��Q
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
 *	@description : �������Ƿ�����
 *	@param		 : ����ָ��Q
 *	@return		 : ��-TRUE; δ��-FLASE
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
 *	@description : �������Ƿ�Ϊ��
 *	@param		 : ����ָ��Q
 *	@return		 : ��-TRUE; δ��-FLASE
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
 *	@description : �������Ƿ�Ϊ��
 *	@param		 : ����ָ��Q
 *	@return		 : ��-TRUE; δ��-FLASE
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
 *	@description : �鿴��ͷԪ��
 *	@param		 : ����ָ��Q�����Ԫ��e
 *	@return		 : �ɹ�-TRUE; ʧ��-FLASE
 *  @notice      : �����Ƿ��
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
 *	@description : �鿴��ͷԪ��
 *	@param		 : ����ָ��Q�����Ԫ��e
 *	@return		 : �ɹ�-TRUE; ʧ��-FLASE
 *  @notice      : �����Ƿ��
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
 *	@description : ȷ�����г���
 *	@param		 : ����ָ��Q
 *	@return		 : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
	return (Q->rear - Q->front+MAXQUEUE)%MAXQUEUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *	@description : ȷ�����г���
 *	@param		 : ����ָ��Q
 *	@return		 : ���г���count
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
 *	@description : ��Ӳ���
 *	@param		 : ����ָ��Q,�������ָ��data
 *	@return		 : �ɹ�-TRUE; ʧ��-FLASE
 *  @notice      : �����Ƿ����˻�Ϊ��
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
 *	@description : ��Ӳ���
 *	@param		 : ����ָ��Q,�������ָ��data
 *	@return		 : �ɹ�-TRUE; ʧ��-FLASE
 *  @notice      : �����Ƿ�Ϊ��
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
 *	@description : ���Ӳ���
 *	@param		 : ����ָ��Q
 *	@return		 : �ɹ�-TRUE; ʧ��-FLASE
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
 *	@description : ���Ӳ���
 *	@param		 : ����ָ��Q
 *	@return		 : �ɹ�-TRUE; ʧ��-FLASE
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
 *	@description : ��ն���
 *	@param		 : ����ָ��Q
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
 *	@description : ��ն���
 *	@param		 : ����ָ��Q
 *	@return		 : None
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	struct node *p,*q;    
  Q->rear=Q->front;    
  p=Q->front->next;    
  Q->front->next;    //ֻ����ͷ���     
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
 *	@description : ������������
 *	@param		 : ����ָ��Q����������ָ��foo
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
 *	@description : ������������
 *	@param		 : ����ָ��Q����������ָ��foo
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
 *	@description : ��������
 *	@param		 : ָ��q
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
 *	@description : ��������
 *	@param		 : ָ��q
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

