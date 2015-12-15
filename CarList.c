/*链表打印列车进站问题
打印总的列车车厢数
正序和逆序打印车厢号
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
typedef struct Node* List;

void order(List p)
{
    if(p == NULL)
        return;
    order(p->next);
    printf("%d ",p->data);
}

int main()
{
    List L;
    List p,s;
    int dat;int cnt=0;
    L = malloc(sizeof(struct Node));
    L->next = NULL;
    p = L;
    while(scanf("%d",&dat) && (dat != 0))
    {
        s = malloc(sizeof(struct Node));
        s->data = dat;
        s->next = p->next;
        p->next = s;
        p=s;
        cnt++;
    }    
    printf("%d\n",cnt);
    p =L;
    do
    {
        p = p->next;
        printf("%d ",p->data);
    }while(p->next != NULL);
    printf("\n");
    order(L->next);
    printf("\n\n");
    return 0; 
}
