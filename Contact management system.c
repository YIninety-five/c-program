#include <stdio.h>
#include <stdlib.h>


struct Member {
    int Num;
    char Name[10];
    char Sexual[5];
    char Tel[15];

};

struct Node {
    struct Member data;
    struct Node* next;
};

struct Node* creatList ();
struct Node* creatMember (struct Member data);
struct Node* insertMember(struct Node* headNode,struct Member data);

void login ();
void addMember (struct Node* headNode);
void printInfo (struct Node* headNode);
void changeInfo (struct Node* headNode);
void deleteMember(struct Node* headNode);

int loadInfo (struct Node* headNode);
int saveInfo (struct Node* headNode);


int main ()
{

    struct Node* List = creatList();
    int choice = 0;

    FILE *fp;
    if ((fp = fopen ("D:\\contact","r")) == NULL)
    {
         printf ("This is your first use the system.\n");
         printf ("Please initialization.\nPress any key to continue.\n");
         getch ();
         addMember (List);
    }
    else
        loadInfo (List);

    login ();

    while (1)
    {
        system ("cls");
        printf ("\n");
        printf ("~~~*~~~~~~*~~~~~~*~~~~~~*~~~~~~*~~~\n");
        printf ("Please input the number to choice the function that you want.\n");
        printf ("1: Add a new member.\n2: Check the information of member.\n");
        printf ("3: Change the information of a member.\n4: Delete a member's information from list.\n" );
        printf ("9: Exit\n");
        printf ("\n");
        printf ("~~~*~~~~~~*~~~~~~*~~~~~~*~~~~~~*~~~\n");

        fflush (stdin);
        scanf ("%d",&choice);

        switch (choice)
        {
            case 1: addMember (List);
                    break;
            case 2: system ("cls");
                    printInfo (List);
                    break;
            case 3: system ("cls");
                    changeInfo (List);
                    break;
            case 4: system ("cls");
                    deleteMember(List);
                    break;
            case 9: saveInfo (List);
                    return 0;
            default : printf ("You have inputed wrong date.Please check it again.\n");
                      getch();
                      break;
        }
    }

}

struct Node* creatList ()
{
    struct Node* headNode = ((struct Node*)malloc(sizeof(struct Node)));
    headNode -> next = NULL;
    return headNode;
};

struct Node* creatMember (struct Member data){
    struct Node* newMember = ((struct Node*)malloc(sizeof(struct Node)));
    newMember -> data = data;
    newMember -> next = NULL;
    return newMember;

};

struct Node* insertMember(struct Node* headNode,struct Member data){

    struct Node* newMember = creatMember(data);

    newMember -> next = headNode -> next;
    headNode -> next = newMember;

};

void addMember (struct Node* headNode)
{
    struct Node* Pmove = headNode;
    struct Member data;
    int tempNum;
    char choice;
    while (1)
    {
        while (Pmove)
        {
            system ("cls");
            printf ("Please input the number of this member.\n");
            fflush (stdin);
            scanf ("%d",&tempNum);
            while (Pmove)
            {
                if (tempNum == Pmove -> data.Num)
                {
                    printf ("The number has existed,please check it and input the number again.\n");
                    printf ("Press any key to continue.\n");
                    getch ();
                    break;
                }
                Pmove = Pmove ->next;

            }
            if (NULL == Pmove)
                break;

        }
    Pmove = headNode;
    data.Num = tempNum;

    printf ("Please input the name of this member.\n");
    fflush (stdin);
    scanf ("%s",&data.Name);
    printf ("Please input the sexual of this member.\n");
    fflush (stdin);
    scanf ("%s",&data.Sexual);
    printf ("Please input the telephone number of this member.\n");
    fflush (stdin);
    scanf ("%s",&data.Tel);
    insertMember (headNode,data);
    printf ("Do you want to add anther member?(Y/N).\n");
    fflush (stdin);
    choice = getchar ();
    if (choice == 'Y' || choice  == 'y')
            continue;
    else
        break;

    }
}


void printInfo (struct Node* headNode)
{
    struct Node* pMove = headNode -> next;
    printf ("Student-number\tName\tSexual\tTelephone_number\n\n");
    while (pMove)
    {
        printf("%d\t%s\t%s\t%s\t\n\n",pMove -> data.Num,pMove -> data.Name,pMove -> data.Sexual,pMove -> data.Tel);
        pMove = pMove -> next;
    }
    printf ("Press any key to continue.");
    getch();
}

void deleteMember(struct Node* headNode)
{
    int Num = 0;
    char choice;
    struct Node* posNode;
    struct Node* posNodefront ;
    posNode = headNode -> next;
    posNodefront = headNode;
    while (1)
    {
            while (posNode)
        {
            printf ("%d %s\n",posNode -> data.Num,posNode -> data.Name);
            posNode = posNode -> next;
        }
        posNode = headNode -> next;
        printf ("Which member do you want to delete?\n");
        printf ("Please input the number of it\n");
        fflush (stdin);
        scanf("%d",&Num);
        if (posNode == NULL)
        {
            printf("There is a wrong.\n");
            return;
        }
        while (posNode -> data.Num != Num)
        {
            posNodefront = posNode;
            posNode = posNodefront -> next;
            if (NULL == posNode)
            {
                printf ("You have input wrong number.\n");
                printf ("Please check it and input right number again.\n");
                scanf("%d",&Num);
                posNode = headNode -> next;
                posNodefront = headNode;
                continue;
            }
        }
        posNodefront -> next = posNode -> next;
        free (posNode);
        printf("This member is deleted?\nDo you want to delete the information of others?(Y/N)\n");
       fflush (stdin);
        choice = getchar();
        if (choice == 'Y' || choice == 'y')
            continue;
        else
            break;
    }

}


void changeInfo (struct Node* headNode)
{
    int Num;
    char choice;
    struct Node* posNode = headNode -> next;
    printf ("Here are list of contacts.\n\n");
    while (1)
    {
            while (posNode)
        {
            printf ("%d %s\n",posNode -> data.Num,posNode -> data.Name);
            posNode = posNode -> next;
        }

        posNode = headNode -> next;

        printf ("\nWhich member's information do you want to change?\n");
        printf ("Please input the number of it.\n");
        fflush (stdin);
        scanf("%d",&Num);
        if (posNode == NULL)
        {
            printf("There is a wrong.\n");
            return;
        }

        while (posNode -> data.Num != Num)
        {
            posNode = posNode -> next;
            if (NULL == posNode)
            {
                printf ("You have input wrong number.\n");
                printf ("Please check it and input right number again.\n");
                scanf("%d",&Num);
                posNode = headNode -> next;
                continue;
            }

        }

        while (1)
        {
            printf ("what information do you want to change?\n");
            printf ("1: number.\n2: name\n3: sexual\n4: telephone number.\n9: Exit\n");
            fflush (stdin);
            scanf("%d",&choice);
            switch (choice)
            {
                case 1: printf ("Please input the number that you want to change.\n");
                       fflush (stdin);
                        scanf ("%d",&posNode -> data.Num);
                        printf ("The number is changed to %d\n",posNode -> data.Num);
                        break;
                case 2: printf ("Please input the name that you want to change.\n");
                       fflush (stdin);
                        scanf ("%s",posNode -> data.Name);
                        printf ("The name is changed to %s\n",posNode -> data.Name);
                        break;
                case 3: printf ("Please input the Sexual that you want to change.\n");
                       fflush (stdin);
                        scanf ("%s",posNode -> data.Sexual);
                        printf ("The Sexual is changed to %s\n",posNode -> data.Sexual);
                        break;
                case 4: printf ("Please input the telephone number that you want to change.\n");
                       fflush (stdin);
                        scanf ("%s",posNode -> data.Tel);
                        printf ("The telephone number is changed to %s\n",posNode -> data.Tel);
                        break;
                case 9: choice = 9;
                        break;
                default : printf ("You have input wrong data,please check it again");
                          getch ();
                          break;
            }
            if (choice == 9)
                break;
        }
        posNode = headNode -> next;
        system ("cls");
        printf ("Do you want to change others information?(Y/N)\n");
        fflush (stdin);
        choice = getchar();
        if (choice == 'Y' || choice == 'y')
            continue;
        else
            break;
    }

}

int saveInfo (struct Node* headNode)
{
    struct Node* pMove = headNode -> next;
    struct Member temp;
    FILE* fp;
    if ((fp = fopen ("D:\\contact","wb+")) == NULL)
    {
        printf ("Open file error!\nPress any key to continue.\n");
        getch ();
        return 0;
    }

    while (pMove)
    {

        temp = pMove -> data;
        if (fwrite (&temp,sizeof (temp),1,fp) != 1)
        {
            printf ("Write error!\nPress any key to continue.\n");
            getch ();
        }
        pMove = pMove -> next;
    }
    fclose (fp);
    return 0;
}

int loadInfo (struct Node* headNode)
{
    FILE *fp;
    struct Member temp;
    struct Node* posNode = headNode ->next ;
    if ((fp = fopen ("D:\\contact","r")) == NULL)
    {
         printf ("File open error!\n");
         printf ("press any key to continue.\n");
         getch ();
         return 0;
    }

    while (fread (&temp,sizeof (temp),1,fp))
    {
        insertMember (headNode,temp);
    }

    fclose (fp);
    return 0;


}


void login ()
{
    system ("cls");
    printf ("        *****************************************\n");
    printf ("        *                                       *\n");
    printf ("        *   Welcome to contact manager system!  *\n");
    printf ("        *                                       *\n");
    printf ("        *****************************************\n");
    printf ("                     ---Press any key to continue.\n");
    getch ();
}
