#include <bits/stdc++.h>
using namespace std;
typedef struct Treenode
{
    vtree val;
    struct Treenode *pre = NULL, *next = NULL;
    
}treenode;

typedef struct Tree
{
    treenode *root;
    int size;
}tree;

void createtree(tree *Root)
{
    Root->root = NULL;
    Root->size = 0;
}

bool push(vtree v, tree *Root)
{
    treenode *q;
    if(Root->root == NULL)
    {
        
        if(q = (treenode*) malloc(sizeof(treenode)))
        {
            q->val = v;
            Root->root = q;
            Root->size++;
            return 1;
        }
        return 0;
    }else
    {
        if(q = (treenode*) malloc(sizeof(treenode)))
        {
            q->val = v;
            treenode *ch = Root->root;
            int test = 1;
            while (test)
            {
                if(ch->val >= v)
                {
                    if(ch->pre == NULL)
                    {
                        test = 0;
                    }else
                    {
                        ch = ch->pre;
                    }
                    
                }else
                {
                    if(ch->next == NULL)
                    {
                        test = 0;
                    }else
                    {
                        ch = ch->next;
                    }
                }
                
            }
            if(ch->val >= v) ch->pre = q;
            else ch->next = q;
            Root->size++;
            return 1;
        }
        return 0;
    }
    
}
void clear(treenode *ch)
{
    if(ch == NULL) return;
    clear(ch->pre);
    clear(ch->next);
    free(ch);
}
void cleartree(tree *Root)
{
    treenode *ch = Root->root;
    clear(ch);
    Root->size = 0;
    Root->root = NULL;
}

bool isempty(tree *Root)
{
    return (Root->size == 0);
}
bool isfull(tree *Root)
{
    return 0;
}
int sizetree(tree *Root)
{
    return Root->size;
}
void pprin(treenode *ch, void(*pf)(vtree))
{
    if(ch == NULL) return;
    (*pf)(ch->val);
    pprin(ch->pre, pf);
    pprin(ch->next, pf);

}
void prept(tree *Root, void(*pf)(vtree))
{
    treenode *ch = Root->root;
    pprin(ch, pf);
}
void iprin(treenode *ch, void(*pf)(vtree))
{
    if(ch == NULL) return;
    iprin(ch->pre, pf);
    (*pf)(ch->val);
    iprin(ch->next, pf);

}
void irept(tree *Root, void(*pf)(vtree))
{
    treenode *ch = Root->root;
    iprin(ch, pf);
}

void poprin(treenode *ch, void(*pf)(vtree))
{
    if(ch == NULL) return;
    poprin(ch->pre, pf);
    poprin(ch->next, pf);
    (*pf)(ch->val);
}
void porept(tree *Root, void(*pf)(vtree))
{
    treenode *ch = Root->root;
    poprin(ch, pf);
}

bool searcht(tree *Root, vtree v)
{
    treenode *ch = Root->root;
    int test = 1;
    while (test && ch != NULL)
    {
        if(ch->val == v)
        {
            test = 0;
            break;
        }else if(v < ch->val) ch = ch->pre;
        else ch = ch->next;
        
    }
    if(test) return 0;
    else return 1;
    
}
vtree maxt(tree *Root)
{
    treenode *ch = Root->root->next, *c = Root->root;
    while (ch != NULL)
    {
        c = ch;
        ch = ch->next;
    }
    
    return c->val;
}
vtree mint(tree *Root)
{
    treenode *ch = Root->root->pre, *c = Root->root;
    while (ch != NULL)
    {
        c = ch;
        ch = ch->pre;
    }
    
    return c->val;
}
bool deletet(tree *Root, vtree v)
{
    treenode *ch = Root->root, *c = NULL;
    int test = 1;
    while (test && ch != NULL)
    {
        if(ch->val == v)
        {
            test = 0;
            c = ch;
            break;
        }else if(v < ch->val) {c = ch;ch = ch->pre;}
        else {c = ch;ch = ch->next;}
        
    }
    if(test) return 0;
    else{
        if((ch->pre == NULL) && (ch->next == NULL)) free(ch);
        else if(ch->next != NULL)
        {
            treenode *chh = ch->next->pre, *c = ch->next;
            while (chh != NULL)
            {
                c = chh;
                chh = chh->pre;
            }
            ch->val = c->val;
            if(c->next == NULL)
            {
                free(c);
            }else
            {
                c->val = c->next->val;
                free(c->next);
            }
            
            
        }else{
            treenode *chh = ch->pre->next, *c = ch->pre;
            while (chh != NULL)
            {
                c = chh;
                chh = chh->next;
            }
            ch->val = c->val;
            if(c->pre == NULL)
            {
                free(c);
            }else
            {
                c->val = c->pre->val;
                free(c->pre);
            }
        }
        Root->size--;
        return 1;
    }
}

void level_or(tree *Root, void(*pf)(vtree))
{
    if(Root == NULL) return;

    queue<treenode *> q;
    q.push(Root->root);
    while (!q.empty())
    {
        treenode * cur = q.front();
        if(cur->pre != NULL) q.push(cur->pre);
        if(cur->next != NULL) q.push(cur->next);
        (*pf)(cur->val);
        q.pop();
    }
    
}