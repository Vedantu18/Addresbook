/*Project1: Address Book
  Date: 14-10-2025
  Author: Vedant Shivsharan
*/
#include "Header.h"

int main()
{

    struct addressbook details;
    details.contact_count = 0;
    int n;

    while (1)
    {
        printf("1.create_contact\n2.Search_contact\n3.Edit_contact\n4.Save_contact\n5.Delete_contact\n6.Display_contact\n7.Exit_contact\n");
        printf("Enter the Command for Operation : ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            create_contact(&details);
            break;
        case 2:
            search_contact(&details);
            break;
        case 3:
            edit_contact(&details);
            break;
        case 4:
            save_contact(&details);
            break;
        case 5:
            delete_contact(&details);
            break;
        case 6:
            display_contact(&details);
            break;
        default:
               exit_contact(&details);
            break;
        }
    }
    return 0;
}
