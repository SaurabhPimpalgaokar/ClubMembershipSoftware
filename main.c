#include<stdio.h>
#include<stdlib.h>
#include "ClubApi.h"
int main()
{
    readInfoFromTxt();
    printf("Here is the list of actions you can perform: \n");
    printf("1:Add new Club Member record\n2:Delete old member record\n:");
    printf("3:Serach & Update existing Club member record\n4:Display required Club member details\n");
    printf("5:Display all club member with payment remaing\n6:Display all Club member\n");
    printf("7:Exit...");
    int applicationFlag = 1;
    char ch;
    while(applicationFlag==1)
    {
        printf("\nEnter action to be performed:\t");
        scanf("%c",&ch);
        switch(ch)
        {
        case '1':   addMemberToClub();
                    break;
        case '2':   deleteMemberFromClub();
                    break;
        case '3':   searchAndUpdate();
                    break;
        case '4':   displayRequiredMemberDetails();
                    break;
        case '5':   displayMembersWithPaymentPending();
                    break;
        case '6':   displayAllClubMemberDetails();
                    break;
        case '7':   applicationFlag=0;
                    storeBackUp();
                    break;
        default: printf("Enter valid choice");

        }/*End switch*/

    }/*End while*/

    return 0;

}/*End main()*/
