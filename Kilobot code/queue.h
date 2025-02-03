#include <stdlib.h>
#include <stdio.h>

/* Enum for boolean flags */
typedef enum {
    false = 0,
    true = 1,
} bool;

typedef struct option option;
typedef struct cell cell;
typedef struct queue queue;



struct option {
    unsigned int ID;
    unsigned int GPS_X;
    unsigned int GPS_Y;
    unsigned int Quality;
    unsigned int occurence;
};

struct cell{
    option option;
    cell * next;
};

struct queue{
    cell * front;
    cell * back;
};

queue InitQueue(){
    queue emptyqueue;
    emptyqueue.front = NULL;
    return emptyqueue;
}



void Enqueue(queue * q, option op){
    cell * p_nouveau;
    p_nouveau = (cell *) malloc(sizeof (cell));

    if (p_nouveau != NULL)
    {
        p_nouveau->next = NULL;
        p_nouveau->option = op;
        if (q->front == NULL){
            q->front = p_nouveau;
            q->back = p_nouveau;
        } else{
            q->back->next = p_nouveau;
            q->back = p_nouveau;
        }
    }
}


void Dequeue(queue * q){
    cell * tmp;
    if (q->front != NULL){
        tmp = q->front->next;
        free(q->front);
        q->front = tmp;
    }
}

void EmptyQueue(queue *q){
    while(q->front!=NULL){
        Dequeue(q);
    }
}


void EnqueueWithoutRepetition(queue * q, option op){
    cell * p_nouveau;
    p_nouveau = (cell *)malloc(sizeof (cell));

    if (p_nouveau != NULL){

        cell* tmp=q->front;

        while (tmp!=NULL) {
            if(tmp->option.ID==op.ID){
                break;
            }
            tmp=tmp->next;
        }

        if(tmp==NULL){
            p_nouveau->next = NULL;
            p_nouveau->option = op;
            p_nouveau->option.occurence=1;
            if (q->front == NULL){
                q->front = p_nouveau;
                q->back = p_nouveau;
            } else{
                q->back->next = p_nouveau;
                q->back = p_nouveau;
            }
        }
        else{
            tmp->option.occurence++;
        }

    }
}


void DequeueWithoutRepetition(queue * q, bool removecell){
    cell * tmp;
    if (q->front != NULL){
        tmp = q->front->next;

        if(removecell){
            free(q->front);
            q->front = tmp;
        }
        else{
            if(tmp->option.occurence==1){
                free(q->front);
                q->front = tmp;
            }
            else{
                tmp->option.occurence--;
            }
        }
    }
}

