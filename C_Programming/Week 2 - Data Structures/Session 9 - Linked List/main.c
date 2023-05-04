#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist.h"
#include "../../../Utilities/STD_TYPES.h"


void main(void)
{
    while(1)
    {
        printf("\n---------------------------------------------------------\n");
        
        printf("To Add Node At Tail Enter 0\n");
        printf("To Add Node At Head Enter 1\n");
        printf("To Add Node At Certain Index Enter 2\n");
        printf("To Delete Node Enter 3\n");
        printf("To Search For Node Enter 4\n");
        printf("To Print The Linked List Enter 5\n");
        printf("To Exit Enter 6\n");

        u8 Choice;
        printf("\nYour Choice: ");
        scanf("%d", &Choice);
        printf("\n");

        u32 NodeData;
        
        switch (Choice)
        {
        case 0:
            printf("Please Enter Node Value: ");
            scanf("%d", &NodeData);
            LinkedList_voidInsertNodeAtTail(NodeData);
            printf("Node Added Thank You\n");
            
            break;
        case 1:
            printf("Please Enter Node Value: ");
            scanf("%d", &NodeData);
            LinkedList_voidInsertNodeAtHead(NodeData);
            printf("Node Added Thank You\n");
            break;
        case 2:
            printf("Please Enter Node Value: ");
            scanf("%d", &NodeData);
            u32 Index;
            printf("Please Enter Node Index: ");
            scanf("%d", &Index);
            LinkedList_voidInsertNodeAtIndex(NodeData, Index);
            printf("Node Added Thank You\n");
            break;
        case 3:
            printf("Please Enter Node Value: ");
            scanf("%d", &NodeData);
            LinkedList_voidDeleteNode(NodeData);
            printf("Node Deleted Thank You\n");
            break;
        case 4:
            printf("Please Enter Node Value: ");
            scanf("%d", &NodeData);
            LinkedList_voidSearchForNode(NodeData);
            break;
        case 5:
            LinkedList_voidTraverse();
            break;
        case 6:
            printf("Thank You Good Bye\n");
            break;
        
        default:
            printf("Invalid Choice Please Try Again\n");
            break;
        }
    
    }
    
    
    
}


