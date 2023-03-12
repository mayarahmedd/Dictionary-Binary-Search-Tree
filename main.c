#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char* data;
    struct node *left,*right;
} node;

node * newNode(char* val)
{
    node* n=malloc(sizeof(node));
    n->data=val;
    n->left=NULL;
    n->right=NULL;
    return n;
}

node* insert(node* node, char* key)
{


    if (node == NULL)
        return newNode(key);
    if (strcasecmp(key,node->data)==-1)
        node->left = insert(node->left, key);
    else if (strcasecmp(key,node->data)==1)
        node->right = insert(node->right, key);
    return node;

}

node* search( node *t, char* val)
{

    while (t!=NULL)
    {
        if (strcasecmp(val,t->data)==0)
        {
            return t;
        }
        else if (strcasecmp(val,t->data)==-1)
            t =t->left;
        else
            t = t->right;
    }
    return NULL;
}

int max(int a, int b)
{
    return a>b?a:b;
}

int height(node *root)
{
    if ( root == NULL)
        return -1;
    else
        return 1 + max(height(root->left), height(root->right));
}

int count(node *root)
{
    if ( root == NULL)
        return 0;
    else
        return 1 + count(root->left) + count(root->right);
}


int main()
{
    node*root=NULL;
    FILE *fp=fopen("EN-US-Dictionary.txt","r");
    if(fp==NULL)

        printf("File not found\n");
    else
    {
        printf("Dictionary Loaded Successfully...!\n");
    }
    printf("..................................\n");


    while(!feof(fp))
    {
        char*key=(char*)malloc(20);
        fscanf(fp,"%s\n",key);
        root= insert(root, key);
    }
    printf("size = %d\n",count(root));
    printf("..................................\n");
    printf("height = %d\n",height(root));
    printf("..................................\n");
    printf("Enter a sentence : ");
    char sentence[100];
    gets(sentence);
    char*token;
    token=strtok(sentence," ");
    while(token)
    {

        node*x= search( root,  token);
        printf("%s  -  ",token);
        if(x==NULL)
            printf("Incorrect\n");
        else
        {
            printf("CORRECT\n");
        }
        token=strtok(NULL," ");
    }
    fclose(fp);

    return 0;
}
