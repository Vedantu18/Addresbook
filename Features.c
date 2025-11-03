#include "Header.h"

void create_contact(struct addressbook *details)
{
    /*In that Function calling for Name Validation*/
    char ch[20];
    while (1)
    {

        printf("Enter the Name : ");
        scanf("%s", ch);
        if (is_valid_Name(details, ch) == 1)
        {
            strcpy(details->arr[details->contact_count].name, ch);
            printf("Valid Name\n");
            break;
        }
        else
        {
            printf("Invalid Name\n");
        }
    }

    /*In that Function calling for Number Validation*/
    char Number[15];
    while (1)
    {
        printf("Enter the Number : ");
        scanf("%s", Number);
        if (is_valid_Number(details, Number) == 1)
        {
            strcpy(details->arr[details->contact_count].mobile, Number);
            printf("Valid Number\n");
            break;
        }
        else
        {
            printf("Invalid Number\n");
        }
    }

    /*In that Function calling for Email Validation*/

    char email[50];
    char str[50];
    while (1)
    {
        printf("Enter the email address : ");
        scanf("%s", email);
        strcpy(str, email);
        if (is_valid_Email(details, email) == 1)
        {
            strcpy(details->arr[details->contact_count].mail, str);
            printf("Valid Mail\n");
            break;
        }
        else
        {
            printf("Invalid mail\n");
        }
    }

    details->contact_count++;
}
/* This below function is created for the search contacts*/
void search_contact(struct addressbook *details)
{
    int i, n, find_flag = 0;
    char search_name[20];
    char search_number[20];
    char search_mail[30];
    while (1)
    {
        printf("1.Search_by_Name\n2.Search_by_Number\n3.Search_by_Email\n4.Go_back_to_Menu\n");
        printf("Enter the Search Method : ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter the Name to Search : ");
            scanf("%s", search_name);

            for (i = 0; i < details->contact_count; i++)
            {
                if (strcmp(details->arr[i].name, search_name) == 0)
                {
                    printf("Name : %s\n", details->arr[i].name);
                    printf("mobileno : %s\n", details->arr[i].mobile);
                    printf("mail : %s\n", details->arr[i].mail);
                    find_flag = 1;
                }
            }
            if (!find_flag)
            {
                printf("Invalid Name\n");
            }
            break;
        case 2:
            printf("Enter the Number to Search : ");
            scanf("%s", search_number);

            for (i = 0; i < details->contact_count; i++)
            {
                if (strcmp(details->arr[i].mobile, search_number) == 0)
                {
                    printf("Name : %s\n", details->arr[i].name);
                    printf("mobileno : %s\n", details->arr[i].mobile);
                    printf("mail : %s\n", details->arr[i].mail);
                    find_flag = 1;
                }
            }
            if (!find_flag)
            {
                printf("Invalid Number\n");
            }
            break;
        case 3:
            printf("Enter the mail to Search : ");
            scanf("%s", search_mail);

            for (i = 0; i < details->contact_count; i++)
            {
                if (strcmp(details->arr[i].mail, search_mail) == 0)
                {
                    printf("Name : %s\n", details->arr[i].name);
                    printf("mobileno : %s\n", details->arr[i].mobile);
                    printf("mail : %s\n", details->arr[i].mail);
                    find_flag = 1;
                }
            }
            if (!find_flag)
            {
                printf("Invalid mail\n");
            }
            break;
        case 4:
            printf("Return to menu\n");
            return;

        default:
            printf("Invalid Search Method\n");
            break;
        }
    }
}
/*This below function is created for the display the contact*/
void display_contact(struct addressbook *details)
{
    // int i;
    // for (i = 0; i < details->contact_count; i++)
    // {
    //     printf("Name : %s\n", details->arr[i].name);
    //     printf("mobileno : %s\n", details->arr[i].mobile);
    //     printf("mail : %s\n", details->arr[i].mail);
    // }
    printf("===========================================================\n");
    printf("| %-15s | %-15s | %-20s |\n", "Name", "Mobile number", "Email address");
    printf("===========================================================\n");
    for (int i = 0; i < details->contact_count; i++)
    {
        printf("| %-15s | %-15s | %-20s |\n", details->arr[i].name, details->arr[i].mobile, details->arr[i].mail);
        printf("-----------------------------------------------------------\n");
    }
}
/*This below function is created for the edit the contact*/
void edit_contact(struct addressbook *details)
{
    char name[20];
    int i;
    printf("Enter the name to edit : ");
    scanf("%s", name);
    int found_count = -1;

    for (i = 0; i < details->contact_count; i++)
    {
        if (strcmp(details->arr[i].name, name) == 0)
        {
            found_count = i;
            break;
        }
    }
    if (found_count == -1)
    {
        printf("Contact is not found\n");
        return;
    }

    printf("\nCurrent Contact\n");
    printf("Name :%s\n", details->arr[found_count].name);
    printf("Mobile :%s\n", details->arr[found_count].mobile);
    printf("Mail :%s\n", details->arr[found_count].mail);

    int choice;
    char temp_name[20], temp_mobile[20], temp_mail[20];

    printf("what do you want to edit\n");
    printf("1.Name\n2.Mobile\n3.Mail\n4.all details\n5.cancel\n");

    printf("Enter the option to edit : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter the name: ");
        scanf("%s", temp_name);
        if (is_valid_Name(details, temp_name))
        {
            strcpy(details->arr[found_count].name, temp_name);
            printf("Name changed\n");
        }
        else
        {
            printf("Invalid Name\n");
        }
        break;
    case 2:
        printf("Enter the mobile number: ");
        scanf("%s", temp_mobile);
        if (is_valid_Number(details, temp_mobile))
        {
            strcpy(details->arr[found_count].mobile, temp_mobile);
            printf("Mobile Number changed\n");
        }
        else
        {
            printf("Invalid Mobile Number\n");
        }
        break;
    case 3:
        printf("Enter the mail: ");
        scanf("%s", temp_mail);
        if (is_valid_Email(details, temp_mail))
        {
            strcpy(details->arr[found_count].mail, temp_mail);
            printf("mail changed\n");
        }
        else
        {
            printf("Invalid mail\n");
        }
        break;
    case 4:
        printf("Enter the name: ");
        scanf("%s", temp_name);
        printf("Enter the mobile number: ");
        scanf("%s", temp_mobile);
        printf("Enter the mail: ");
        scanf("%s", temp_mail);

        if ((is_valid_Name(details, temp_name)) && (is_valid_Number(details, temp_mobile) && (is_valid_Email(details, temp_mail))))
        {
            strcpy(details->arr[found_count].name, temp_name);
            strcpy(details->arr[found_count].mobile, temp_mobile);
            strcpy(details->arr[found_count].mail, temp_mail);
        }
        else
        {
            printf("Invalid all\n");
        }
        break;
    case 5:
        printf("Cancel operations\n");
        break;

    default:
        printf("Invalid choice\n");
        break;
    }
}
/*This below function is created for the deleting contacts*/
void delete_contact(struct addressbook *details)
{

    // char name[20];
    // printf("Enter the name: ");
    // scanf("%s", name);
    char name[20];
    int i;
    printf("Enter the name to delete : ");
    scanf("%s", name);
    int found_count = -1;

    for (i = 0; i < details->contact_count; i++)
    {
        if (strcmp(details->arr[i].name, name) == 0)
        {
            found_count = i;
            break;
        }
    }
    if (found_count == -1)
    {
        printf("Contact is not found\n");
        return;
    }

    printf("\nCurrent Contact\n");
    printf("Name :%s\n", details->arr[found_count].name);
    printf("Mobile :%s\n", details->arr[found_count].mobile);
    printf("Mail :%s\n", details->arr[found_count].mail);

    for (int i = 0; i < details->contact_count; i++)
    {
        if (strcmp(details->arr[i].name, name) == 0)
        {
            int choice;
            printf("1.Name_delete\n2.Number_delete\n3.mail_delete\n4.all_delete\n");
            printf("Enter the operation: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                strcpy(details->arr[i].name, "");
                printf("name deleted\n");
                break;
            case 2:
                strcpy(details->arr[i].mobile, "");
                printf("mobile number deleted\n");
                break;
            case 3:
                strcpy(details->arr[i].mail, "");
                printf("mail deleted\n");
                break;
            case 4:
                for (int j = i; j < details->contact_count - 1; j++)
                {
                    details->arr[j] = details->arr[j + 1];
                }
                details->contact_count--;
                printf("contact deleted\n");
                break;
            default:
                printf("Invalid operation\n");
            }
            return;
        }
    }
    printf("Contact not found\n");
}
/*This below function is created for the save all contacts*/
void save_contact(struct addressbook *details)
{
    FILE *file = fopen("Contacts.txt", "w");

    if(file == NULL)
    {
        printf("File Error\n");
        return;
    }

    for(int i = 0; i < details->contact_count; i++)
    {
        fprintf(file,"%s %s %s\n", details->arr[i].name, details->arr[i].mobile, details->arr[i].mail);
    }
    fclose(file);
    printf("Contacts Saved in File\n");
}
void exit_contact(struct addressbook *details)
{
    printf("Exit from contacts\n");
    exit(0);
}
