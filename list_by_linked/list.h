#include <stdio.h>
#include <cstdlib>
typedef struct listnode
{
    entrylist entry;
    struct listnode *next = NULL, *pre = NULL;
    
}listnode;

typedef struct list
{
    listnode *current, * first;
    int size, currpos;
}list;


void createlist(list *ps)
{
    ps->first = ps->current = NULL; ps->currpos = ps->size = 0;
}

bool insert(int pos, entrylist e, list *ps)
{
    listnode* q; listnode *p;
    
    int i;
    
    if(q = (listnode*) malloc(sizeof(listnode)))
    {
        q->entry = e;
        q->next = NULL;
        if(pos == 0)
        {
            q->next =  ps->first;
            if(ps->first)
                ps->first->pre = q;
            ps->first = q;
            ps->currpos = 0;
            ps->current = ps->first;
        }else
        {
            if(pos == ps->currpos)
            {
                ps->currpos--;
                ps->current = ps->current->pre;
            }
            if(ps->currpos < pos)
            {
                for (p = ps->current, i = ps->currpos; i < pos-1;i++)
                {
                    p = p->next;
                }
                q->next = ps->current->next;
                ps->current->next = q;
                q->pre = ps->current;
                ps->current = q;
                ps->currpos++;
            }else
            {
                for (p = ps->current, i = ps->currpos; i > pos;i--)
                {
                    p = p->pre;
                }
                q->pre = ps->current->pre;
                ps->current->pre = q;
                q->next = ps->current;
                ps->current = q;
                ps->currpos--;
            }
            
        }
        ps->size++;
        return 1;
    }
    return 0;
}

void remove(int pos, entrylist *e, list *ps)
{
    listnode *q, *tmp;
    int i;
    if(pos == 0)
    {
        *e = ps->first->entry;
        tmp = ps->first;
        ps->first = ps->first->next;
        ps->current = ps->first;
        ps->currpos = 0;
        free(tmp);
        
    }else
    {
        while(ps->currpos < pos)
        {
            ps->current = ps->current->next;
            ps->currpos++;
        }
        while(ps->currpos > pos)
        {
            ps->current = ps->current->pre;
            ps->currpos--;
        }
        if(pos == ps->currpos)
        {
            *e = ps->current->entry;
            tmp = ps->current;
            ps->current = ps->current->pre;
            ps->current->next = tmp->next;
            if(tmp->next)
                tmp->next->pre = ps->current;
            ps->currpos--;
            free(tmp);
        }
    }
    ps->size--;
}

void replace(int pos, entrylist e, list * ps)
{
    while(ps->currpos < pos)
    {
        ps->current = ps->current->next;
        ps->currpos++;
    }
    while(ps->currpos > pos)
    {
        ps->current = ps->current->pre;
        ps->currpos--;
    }
    if(pos == ps->currpos)
    {
        ps->current->entry = e;
    }
}
entrylist getitem(int pos, list * ps)
{
    while(ps->currpos < pos)
    {
        ps->current = ps->current->next;
        ps->currpos++;
    }
    while(ps->currpos > pos)
    {
        ps->current = ps->current->pre;
        ps->currpos--;
    }
    
    return ps->current->entry;
    
}
int size(list *ps)
{
    return ps->size;
}

bool listempty(list *ps)
{
    return ps->size == 0;
}

bool listfull(list *ps)
{
    return 0;
}

void clearlist(list *ps)
{
    listnode *pn;
    while(ps->first)
    {
        pn = ps->first;
        ps->first = ps->first->next;
        free(pn);
    }
    ps->currpos = ps->size = 0; ps->current = NULL;
}

void prints(list *ps, void(*pf)(entrylist))
{
    int i = 0;
    for (listnode *pn = ps->first; pn && i < ps->size; i++, pn = pn->next)
        (*pf)(pn->entry);
    
}