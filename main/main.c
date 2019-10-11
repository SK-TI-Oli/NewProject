//Header file::
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
//Global variable
char name[20],name2[20],fnam[20],fname[20]="pas";
struct vari_able{
   char name[100];
   char id[100];
   char pass[100];
   char age[100];
   char mobile[100];
   int  account;
   char occupation[100];
   char taka[100];
   char date[100];
}var;
//Display() function for display menu::
void display()
{
    printf("\n\n\n\t\t\t\t\t==========\n");
    printf("\t\t\t\t\tWELCOME TO\n");
    printf("\t\t\t\t\t       RMCM BANK SYSTEM\n");
    printf("\t\t\t\t\t=========================\n");
    printf("\n\n\t\t\tENTER THE PASSWORD:: ");

}

//Display 2 for option sign up:
void display2()
{
    system("cls");
    printf("\n\n\n\n\t\t\t1.FILL THE INFORMATIONS::");
    printf("\n\n\t\t\t2.HOW TO FILL THE INFORMATION::");
    printf("\n\n\t\t\t\tPRESS HERE FOR CHOSE YOUR OPTION::");
}
void amount(char na[])
{

    char sa=".doc";
    strcat(na,sa);
    FILE *pf;
    pf=fopen(na,"w+");
    printf("\n\n\n\t\tENTER THE AMOUNT OF DEPOSIT:: $");
    scanf("%s",var.taka);
    fputs("\n\n\n\t\t\tAMOUNT INFORMATION:: ",pf);
    fputs("\n\n\t__________________________________________________________________",pf);
    fputs("\n\tDATE        |  NAME     |  WITHDREW  |  DEPOSIT  |  TOTAL AMOUNT |",pf);
    fputs("\n\t`````````````````````````````````````````````````````````````````",pf);
    fputs("\n",pf);
    fprintf(pf,"\t%s|  %s  |      %s    |     %s    |  %s    |",var.date,na,"0","0",var.taka);
}

//transaction part
void trans()
{
    char na[20],n[]=".doc",ch;
    printf("\n\n\t\tENTER THE ACCOUTN NAME:: ");
    scanf("%s",na);
    strcat(na,n);
    FILE *fp;
    fp=fopen(na,"r+");
    if(fp==NULL)
        printf("FILE COULD NOT FIND::");
    else
    {
        while (!feof(fp))
        {
            ch=fgetc(fp);
            printf("%c",ch);
        }
    }
}
//Fill the full form & store in the memory::
void information()
{
    system("cls");
    char name[20],name2[20],fnam[20],fname[20]="pas",num[20];
    FILE *fp;

    printf("\n\n\n\t\t\t\tENTER USER NAME::");
    scanf("%s",name);
    num[20]=name;
    strcpy(fnam,name);
    strcat(name,".txt");
    fp=fopen(name,"w+");
    strcat(fname,name);
    printf("\n\n\t\t\t\tENTER A PASSWORD::");
    scanf("%s",var.pass);
    fprintf(fp,"%s",var.pass);
    fflush(stdin);
    //set background for local file::
    fputs("\n\n\t\t\t============",fp);
    fputs("\n\t\t\t WELCOME TO \n",fp);
    fputs("\t\t\t     ACCOUT INFORMATION\n",fp);
    fputs("\t\t\t     ==================\n",fp);

    //store some information about client::
    fprintf(fp,"\n\n\t\tINFORMATION OF:: %s\n",fnam);

    fflush(stdin);
    printf("\n\n\n\t\tENTER FULL NAME::");

    scanf("%[^\n]s",var.name);
    fflush(stdin);
    fprintf(fp,"\n\n\tNAME:: %s",var.name);
    printf("\n\n\n\t\tENTER ID:: ");
    scanf("%s",var.id);
    fflush(stdin);
    fprintf(fp,"\n\n\tID:: %s",var.id);
    printf("\n\n\n\t\tENTER AGE:: ");
    scanf("%s",var.age);
    fflush(stdin);
    fprintf(fp,"\n\n\tAGE:: %s",var.age);
    printf("\n\n\n\t\tENTER OCCUPATION::");
    scanf("%s",var.occupation);
    fprintf(fp,"\n\n\tOCCUPATION:: %s",var.occupation);
    printf("\n\n\n\t\tENTER MOBILE:: ");
    scanf("%s",var.mobile);
    printf("\n\n\n\t\tENTER TODAY'S DATE:: ");
    scanf("%s",var.date);
    fprintf(fp,"\n\n\tMOBILE:: %s",var.mobile);
    fprintf(fp,"\n\n\tACCOUNT NO:: %d",var.mobile+10);
}

//Menu which is present in the login option::
void menu()
{
    system("cls");
    printf("\n\n\t\t\t---------------------------------\n");
    printf("\t\t\t  ## WELCOME TO CUSTOMER MENU ##\n");
    printf("\t\t\t`````````````````````````````````\n");
    printf("\n\n\n\t\t 1.ADD NEW ACCOUNT.");
    printf("\n\n\t\t 2.UPDATE EXISTING ACCOUNT.");
    printf("\n\n\t\t 3.FOR TRANSISTOR.");
    printf("\n\n\t\t 4.CHECK THE DETAILS OF EXISTING ACCOUNT.");
    printf("\n\n\t\t 5.REMOVE THE ACCOUNT.");
    printf("\n\n\t\t 6.EXIT.");
    printf("\n\n\t\t\t ENTER YOUR CHOSE::: ");
}

//Remove an existing account::
void remove_ac(char na[])
{
    system("cls");
    char ex[20]=".txt";
    strcat(na,ex);
    int rev=remove(na);
    if(rev==0)
        printf("\n\n\t\tFILE DELETE SUCCESSFULLY..");
    else
        printf("\n\n\t\tNO FILE PRESENT IN SUCH NAME");
}

void login()
{
    system("cls");
    int num,num2;
    char nam[20],na[20]=".txt",pas[20],data[20],ch,nama[20];
    FILE *fp;
    back:
    printf("\n\n\t\tENTER YOUR USER NAME:: ");
    scanf("%s",nam);
    strcat(nam,na);
    fp=fopen(nam,"r+");
    if(fp==NULL)
        printf("\n\n  WRONG USER NAME!!!!!");
    else
    {
        printf("\n\t\tENTER YOUR PASSWORD::");
        scanf("%s",pas);
        fscanf(fp,"%s",data);
        if(strcmp(pas,data)==0){
                system("cls");
                while(!feof(fp)){
                ch=fgetc(fp);
                printf("%c",ch);
                }
              }
        else{
            printf("\n\n\t\tYOUR ENTERED PASSWORD IS WRONGGG!!!!!");
            printf("\n\n\t\tTRY AGAIN PRESS 1:: ");
            scanf("%d",&num);
            if(num==1)
            goto back;
            else
                exit(0);
    }


}
}



//Main() function start::
int main()
{
    char pas[20],pas2[20]="projectc",fnam[20];
    int option,option2,num,num2;
    system("COLOR 3E");
    back2:
    back:
    display();
    scanf("%[^\n]s",pas);
    if(strcmp(pas2,pas)==0)
    {
    menu();
    scanf("%d",&option);
    switch(option)
    {
       system("cls");
      case 1:
             information();
             amount(name);
             printf("\n\n\n\t\tBACK TO MAIN MENU PRESS 1:: ");
             scanf("%d",&num2);
             if(num2==1)
                goto back;
             else
                exit(0);
             break;
      case 2:
             information();
             printf("\n\n\n\t\tBACK TO MAIN MENU PRESS 1:: ");
             scanf("%d",&num2);
             if(num2==1)
                goto back;
             else
                exit(0);
             break;
      case 3:
             trans();
             printf("\n\n\n\t\tBACK TO MAIN MENU PRESS 1:: ");
             scanf("%d",&num2);
             if(num2==1)
                goto back;
             else
                exit(0);
      case 4:
         login();
         printf("\n\n\n\t\tBACK TO MAIN MENU PRESS 1:: ");
             scanf("%d",&num2);
             if(num2==1)
                goto back;
             else
                exit(0);
         break;
      case 5:
        printf("\n\n\n\t\tENTER THE FILE NAME:: ");
        scanf("%s",fnam);
        remove_ac(fnam);
        printf("\n\n\n\t\tBACK TO MAIN MENU PRESS 1:: ");
             scanf("%d",&num2);
             if(num2==1)
                goto back;
             else
                exit(0);
        break;
      case 6:
        printf("\n\n\n\t\tTHANKS FOR VISITING OUR BANK......");
        exit(0);

    }
    }
    else
    {
    printf("YOUR ENTERED PASSWORD IS WRONG!!!!!\n");
    printf("PRESS 1 FOR TRY AGAIN:: ");
    scanf("%d",&num2);
    if(num2==1)
        goto back2;
    else
        exit(0);
    }

}

