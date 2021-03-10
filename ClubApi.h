#ifndef REQUIREDFUNCTIONS_H_INCLUDED
#define REQUIREDFUNCTIONS_H_INCLUDED
#include "memberInfo.h"
#include<string.h>
#include<ctype.h>

int linkListLength;
int getMemberId();
char* getName();
int getAge();
char* getCity();
char* getGender();
int getLockNumber();
int getPaidAmount();
int getDay();
int getMonth();
int getYear();
void readInfoFromTxt();

struct linkList
{
    struct linkList *pNext;
    struct memberInfo member;
};
struct linkList *headNode=NULL;
struct linkList *newNode=NULL;
struct linkList *tempNode=NULL;

void readInfoFromTxt()
{
    FILE *pfilePointer=NULL;
    pfilePointer = fopen("ClubMemberData.txt","r+");
    char delimeter[2]= ",";
    char chunk[2000];
    char *line=NULL;
    tempNode = headNode;
    int lineNumber = 0;
    while(((line = ((char*)fgets(chunk,100,pfilePointer))) !=NULL))
    {
        lineNumber += 1;
        if(lineNumber==1)
            continue;
        newNode=(struct linkList*)malloc(sizeof(struct linkList));
        newNode->pNext = NULL;
        if(headNode==NULL)
        {
            headNode = newNode;
            tempNode = headNode;
        }
        else
        {
                tempNode->pNext = newNode;
                tempNode = newNode;
        }
        char *pTokenPointer = strtok(line,delimeter);
        int tokenCounter = 1;
        while(pTokenPointer!=NULL)
        {
            if(tokenCounter==1)
            {
                 tempNode->member.memberId=atoi(pTokenPointer);
            }
            if(tokenCounter==2)
            {
                strcpy(tempNode->member.name,pTokenPointer);

            }
            if(tokenCounter==3)
            {
                tempNode->member.age=atoi(pTokenPointer);
            }
            if(tokenCounter==4)
            {
                strcpy(tempNode->member.city,pTokenPointer);
            }
            if(tokenCounter==5)
            {
                strcpy(tempNode->member.gender,pTokenPointer);
            }
            if(tokenCounter==6)
            {
                tempNode->member.lockNumber=atoi(pTokenPointer);
            }
            if(tokenCounter==7)
            {
                tempNode->member.paidAmount=atoi(pTokenPointer);
            }
            if(tokenCounter==8)
            {
                tempNode->member.remainingAmount=atoi(pTokenPointer);
            }
            if(tokenCounter==9)
            {
                tempNode->member.day=atoi(pTokenPointer);
            }
            if(tokenCounter==10)
            {
                tempNode->member.month=atoi(pTokenPointer);
            }
            if(tokenCounter==11)
            {
                tempNode->member.year=atoi(pTokenPointer);
            }
            tokenCounter += 1;
            pTokenPointer = strtok(NULL,delimeter);
        }/*End inner while*/

    }/*End outer while */
    fclose(pfilePointer);
    pfilePointer=NULL;
}/*End readInfoFromTxt()*/

void addMemberToClub()
{
    char ch1 ;
    int flag = 1;
    while(flag == 1 && (linkListLength!=10))
    {

        printf("You want to add member..? y/n");
        scanf(" %c",&ch1);
        if(ch1 == 'y')
        {
            if(headNode == NULL)
                {
                headNode = (struct linkList*)malloc(sizeof(struct linkList));
                tempNode = headNode;
                tempNode->pNext = NULL;
                }/*End if*/
            else
                {
                newNode=(struct linkList*)malloc(sizeof(struct linkList));
                tempNode->pNext = newNode;
                tempNode = newNode;
                tempNode->pNext = NULL;
                }/*End else*/
                tempNode->member.memberId = getMemberId();
                strcpy(tempNode->member.name, getName());
                tempNode->member.age = getAge();
                strcpy(tempNode->member.city, getCity());
                strcpy(tempNode->member.gender, getGender());
                tempNode->member.lockNumber = getLockNumber();
                tempNode->member.paidAmount = getPaidAmount();
                tempNode->member.remainingAmount = 1000-(tempNode->member.paidAmount) ;
                tempNode->member.month = getMonth();
                tempNode->member.day = getDay();
                tempNode->member.year = getYear();
                linkListLength += 1;

        }/*End inner if*/
        else
        {
                    break;
        }/*End inner else*/
    }/*End while loop*/
}/*End addMemberToClub()*/

int getMemberId()
{
    int id;
    int whileFlag=1;
    struct linkList *searchIdInList=NULL;
    printf("Enter id:\t");
    scanf("%d",&id);
    while(whileFlag==1)
    {
    int searchFlag=0;
    for(searchIdInList=headNode;searchIdInList!=NULL;searchIdInList=searchIdInList->pNext)
    {
        if(id==searchIdInList->member.memberId)
        {
            searchFlag=1;
            break;
        }
    }/*End for*/
    if(searchFlag==1)
    {
        printf("\nThis is is already used...please choose another one..\n");
        scanf(" %d",&id);
        whileFlag = 1;
    }
    else if(searchFlag==0)
          whileFlag = 0;

    }/*End while*/
    return id;
}/*End getMemberId()*/

char* getName()
{
    char name[15];
    char *pNamePointer=NULL;
    printf("Please Enter name:\t");
    scanf("%s",name);
    for (int i=0;i<strlen(name)-1;i++)
    {
        if(!(isalpha(name[i])))
        {
            printf("Please Enter name in terms of characters only:\t");
            scanf("%s",name);
        }
    }
    pNamePointer = name;
    return pNamePointer;
}/*End getName()*/

int getAge()
{
    int age;
    printf("Please enter age:\t");
    scanf("%d",&age);
    while(age<=0)
    {
        printf("\nEnter valid age:\t");
        scanf("%d",&age);
    }
    return age;
}/*End getAge()*/

char* getCity()
{
    char city[15];
    char *pCityPointer=NULL;
    printf("Please enter city:\t");
    scanf("%s",city);
    for (int i=0;i<strlen(city)-1;i++)
    {
        if(!isalpha(city[i]))
        {
            printf("Please Enter city in terms of characters only:\t");
            scanf("%s",city);
        }
    }
    pCityPointer = city;
    return pCityPointer;
}/*End getCity()*/

char* getGender()
{
    char gender[7];
    char *pGenderPointer=NULL;
    char male[]={'m','a','l','e'};
    char female[]={'f','e','m','a','l','e'};
    char other[]={'o','t','h','e','r'};
    int whileFlag=1;
    while(whileFlag==1)
    {
        int maleFlag = 1;
        int femaleFlag = 1;
        int otherFlag = 1;
        printf("Please select Gender:\t male/female/other :\t");
        scanf("%s",gender);
        for(int i=0,j=0;i<strlen(male) && j<strlen(gender);i++,j++)
        {
            if(male[i]==gender[j])
            {
                ;
            }
            else
            {
                maleFlag = 0;
                break;
            }
        }/*End for*/
        for(int i=0,j=0;i<strlen(female) && j<strlen(gender);i++,j++)
        {
            if(female[i]==gender[j])
            {
                continue;
            }
            else
            {
                femaleFlag = 0;
                break;
            }
        }/*End for*/
        for(int i=0,j=0;i<strlen(other);i++,j++)
        {
            if(other[i]==gender[j])
            {
                continue;
            }
            else
            {
                otherFlag = 0;
                break;
            }
        }/*End for*/
        if(maleFlag==1 || femaleFlag==1 || otherFlag==1)
        {
            whileFlag=0;
        }
    }/*End while loop*/
    pGenderPointer = gender;
    return pGenderPointer;
}/*End getGender()*/

int getLockNumber()
{
    int lockNumber;
    printf("Please enter lock number:\t");
    scanf("%d",&lockNumber);
    return lockNumber;
}/*End getLockNumber()*/

int getPaidAmount()
{
    int amount;
    printf("Required Entry amount is 1000rs...how much you pay ? :\t");
    scanf("%d",&amount);
    while( amount<0 || amount>1000)
    {
        printf("Please enter amount in range of 0-1000rs only:\t");
        scanf("%d",&amount);
    }
    return amount;
}/*End getPaidAmount()*/

int getDay()
{
    int day;
    int tempMonth = tempNode->member.month;
    printf("Please enter day\t: ");
    scanf("%d",&day);
    if(tempMonth==1 || tempMonth==3 || tempMonth==5 || tempMonth==7 || tempMonth==8 || tempMonth==10 || tempMonth==12 )
    {
        while(day<0 || day>31)
        {
           printf("Enter day between 1 to 31\n");
           scanf("%d",&day);
        }
    }
    else if(tempMonth==4 || tempMonth==6 || tempMonth==9 || tempMonth==11)
    {
        while(day<0 || day>30)
        {
           printf("Enter day between 1 to 30\n");
           scanf("%d",&day);
        }
    }
    else if(tempMonth==2)
    {
        while(day<0 || day>28)
        {
            printf("Enter day between 1 to 28\n");
            scanf("%d",&day);
        }
    }
    return day;
}/*End getDay()*/

int getMonth()
{
    printf("Please enter date like Month/Day/Year:\n");
    int month;
    printf("Please enter month\t: ");
    scanf("%d",&month);
    while( month<1 || month>12)
    {
        printf("Enter valid input: \t");
        scanf("%d",&month);
    }
    return month;
}/*End getMonth()*/

int getYear()
{
    int year;
    printf("Please enter year\t: ");
    scanf("%d",&year);
    return year;
}/*End getYear()*/

void deleteMemberFromClub()
{
    struct linkList *travel = NULL;
    struct linkList *previousNode = NULL;
    int idOfMemberToBeDeleted;
    char ch;
    int whileFlag = 1;
    while(whileFlag==1)
    {
        printf("Please enter id of member to be deleted\t");
        scanf("%d",&idOfMemberToBeDeleted);
        travel = headNode;
        if(travel!=NULL &&travel->member.memberId==idOfMemberToBeDeleted)
        {
            headNode=travel->pNext;
            free(travel);
            linkListLength = linkListLength - 1;
        }
        while(travel!=NULL && travel->member.memberId!=idOfMemberToBeDeleted)
        {
                previousNode =travel;
                travel=travel->pNext;
        }
        if(travel==NULL)
            printf("sorry..record not found\n");
        if(travel!=NULL)
        {
            previousNode->pNext = travel->pNext;
            free(travel);
            linkListLength = linkListLength - 1;
        }

        printf("want to continue with delete action? y/n \t");
        scanf(" %c",&ch);
        if(ch=='y')
        {
            continue;
        }
        else
        {
            whileFlag = 0;
        }
    }/*End while*/
    travel=NULL;
    previousNode=NULL;
}/*End deleteMemberFromClub()*/

void searchAndUpdate()
{
    struct linkList *travelNode=NULL;
    int whileFlag = 1;
    int idForRecordToUpdate;
    char ch;
    while(whileFlag==1)
    {
        int searchFlag=0;
        printf("Enter id for member whose record need to update");
        scanf("%d",&idForRecordToUpdate );
        for(travelNode=headNode;travelNode!=NULL;travelNode=travelNode->pNext)
        {
            if(travelNode->member.memberId==idForRecordToUpdate)
            {
                searchFlag = 1;
                break;
            }
        }/*End for*/
        if(searchFlag==1)
        {
        travelNode->member.memberId = getMemberId();
        strcpy(travelNode->member.name, getName());
        travelNode->member.age = getAge();
        strcpy(travelNode->member.city, getCity());
        strcpy(travelNode->member.gender, getGender());
        travelNode->member.lockNumber = getLockNumber();
        travelNode->member.paidAmount = getPaidAmount();
        tempNode->member.remainingAmount = 1000-(tempNode->member.paidAmount) ;
        travelNode->member.month = getMonth();
        travelNode->member.day = getDay();
        travelNode->member.year = getYear();
        }/*End if*/
        else if(searchFlag==0)
        {
            printf("\nSorry...record not found...\n");
        }
        printf("Want to continue update action?y/n\t");
        scanf(" %c",&ch);
        if(ch=='y')
        {
            continue;
        }
        else
        {
            whileFlag=0;
        }
    }/*End while*/
}/*End searchAndUpdate()*/

void displayRequiredMemberDetails()
{
    int idToDisplayDetails;
    int whileFlag = 1;
    char ch;
    struct linkList *travelNode = NULL;
    while(whileFlag==1)
    {
        int searchFlag = 0;
        printf("Enter required member's id: ");
        scanf("%d",&idToDisplayDetails);

        for(travelNode=headNode;travelNode!=NULL;travelNode=travelNode->pNext)
        {
            if(travelNode->member.memberId==idToDisplayDetails)
            {
                searchFlag=1;
                break;
            }
        }/*End for*/
        if(searchFlag==0)
        {
            printf("Sorry....Record not found");
        }

        if(searchFlag==1)
        {
        printf("\nId\tName\t\tCity\tAge\tGender\tLockNumber\tPaidAmount\tRemainingAmount \tJoiningDate");
        printf("\n");
        printf("%d\t",travelNode->member.memberId);
        printf("%s\t",travelNode->member.name);
        printf("\t%s\t",travelNode->member.city);
        printf("%d\t",travelNode->member.age);
        printf("%s\t",travelNode->member.gender);
        printf("%d\t",travelNode->member.lockNumber);
        printf("\t %d\t",travelNode->member.paidAmount);
        printf("\t%d\t\t ",travelNode->member.remainingAmount);
        printf("\t %d %d %d",travelNode->member.day,travelNode->member.month,travelNode->member.year);
        }
        printf("\nWant to continue this action y/n:\t");
        scanf(" %c",&ch);
        if(ch=='y')
            whileFlag=1;
        else
            whileFlag=0;
    }/*End while*/
}/*End displayRequiredMemberDetails()*/

void displayMembersWithPaymentPending()
{
    struct linkList *travelNode=NULL;
    printf("All club members with payment remaining:\n");
    printf("Name\t\tRemaining Amount\tPaid Amount\tJoining Date\n");
    int searchFlag=0;
    for(travelNode=headNode;travelNode!=NULL;travelNode=travelNode->pNext)
    {
        if(travelNode->member.remainingAmount!=0)
        {
            printf("%s\t\t",travelNode->member.name);
            printf("%d\t\t",travelNode->member.remainingAmount);
            printf("\t%d\t\t",travelNode->member.paidAmount);
            printf("%d %d %d\t",travelNode->member.day,travelNode->member.month,travelNode->member.year);
            searchFlag = 1;
        }
        printf("\n");
    }/*End for*/

    if(searchFlag == 0)
    {
        printf("All members have paid required amount.");
    }
}/*End displayMembersWithPaymentPending()*/

void displayAllClubMemberDetails()
{
 struct linkList *travelNode=NULL;
 printf("All club member details:\n");
 printf("MemberId\tName\tAge\tCity\tGender\tlockNumber\tPaidAmount\tRemainingAmount\tJoiningDate\n");
 for(travelNode=headNode;travelNode!=NULL;travelNode=travelNode->pNext)
 {
        printf("%d\t",travelNode->member.memberId);
        printf("\t%s\t",travelNode->member.name);
        printf("%d\t",travelNode->member.age);
        printf("%s\t",travelNode->member.city);
        printf("%s\t",travelNode->member.gender);
        printf("%d\t",travelNode->member.lockNumber);
        printf("\t\t%d",travelNode->member.paidAmount);
        printf("\t%d\t",travelNode->member.remainingAmount);
        printf("\t%d %d %d",travelNode->member.month,travelNode->member.day,travelNode->member.year);
        printf("\n");
 }/*End for*/
}/*End displayAllClubMemberDetails()*/

void storeBackUp()
{
    struct linkList *travelNode=NULL;
    struct linkList *pDelete=NULL;
    FILE *pFileWriter=NULL;
    pFileWriter = fopen("ClubMemberData.txt","w+");
    fputs("MemberId",pFileWriter);
    fputs(",",pFileWriter);
    fputs("Name",pFileWriter);
    fputs(",",pFileWriter);
    fputs("Age",pFileWriter);
    fputs(",",pFileWriter);
    fputs("City",pFileWriter);
    fputs(",",pFileWriter);
    fputs("Gender",pFileWriter);
    fputs(",",pFileWriter);
    fputs("lockNumber",pFileWriter);
    fputs(",",pFileWriter);
    fputs("PaidAmount",pFileWriter);
    fputs(",",pFileWriter);
    fputs("RemainingAmount",pFileWriter);
    fputs(",",pFileWriter);
    fputs("JoiningDate",pFileWriter);
    fputs("\n",pFileWriter);
    for(travelNode=headNode;travelNode!=NULL;travelNode=travelNode->pNext)
    {
        fprintf(pFileWriter,"%d",travelNode->member.memberId);
        fputs(",",pFileWriter);
        fputs(travelNode->member.name,pFileWriter);
        fputs(",",pFileWriter);
        fprintf(pFileWriter,"%d",travelNode->member.age);
        fputs(",",pFileWriter);
        fputs(travelNode->member.city,pFileWriter);
        fputs(",",pFileWriter);
        fputs(travelNode->member.gender,pFileWriter);
        fputs(",",pFileWriter);
        fprintf(pFileWriter,"%d",travelNode->member.lockNumber);
        fputs(",",pFileWriter);
        fprintf(pFileWriter,"%d",travelNode->member.paidAmount);
        fputs(",",pFileWriter);
        fprintf(pFileWriter,"%d",travelNode->member.remainingAmount);
        fputs(",",pFileWriter);
        fprintf(pFileWriter,"%d",travelNode->member.day);
        fputs(",",pFileWriter);
        fprintf(pFileWriter,"%d",travelNode->member.month);
        fputs(",",pFileWriter);
        fprintf(pFileWriter,"%d",travelNode->member.year);
        fputs("\n",pFileWriter);
    }
    travelNode = headNode;
    while(travelNode!=NULL)
    {
        pDelete = travelNode;
        travelNode = travelNode->pNext;
        free(pDelete);
    }
    fclose(pFileWriter);
    pFileWriter=NULL;
}/*End storeBackUp()*/
#endif // REQUIREDFUNCTIONS_H_INCLUDED
