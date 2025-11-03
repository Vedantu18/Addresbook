#include "Header.h"

/*Created Validation for Name*/
int is_valid_Name(struct addressbook *details, char *ch)
{
    int i;
    for (i = 0; ch[i] != '\0'; i++)
    {
        if (!(isalpha(ch[i]) && islower(ch[i])))
        {
            return 0;
        }
    }
    return 1;
}

/*Created Validation for Number*/
int is_valid_Number(struct addressbook *details, char *Number)
{
    int j;
    int length = strlen(Number);
    if (length != 10)
    {
        return 0;
    }
    for (j = 0; Number[j] != '\0'; j++)
    {
        if (!isdigit(Number[j]))
        {
            return 0;
        }
    }
    return 1;
}

/*Created Validation for Email*/
int is_valid_Email(struct addressbook *details, char *email)
{
    int i;
    int at_flag = 1;
    int dot_flag = 1;
    int at_position = -1;

    for (i = 0; email[i] != '\0'; i++)
    {
        if (email[i] == '@')
        {
            at_flag = 0;
            at_position = i; 
        }

        if (email[i] == '.')
        {
            dot_flag = 0;  
        }
    }
    
    if (at_flag == 1 || dot_flag == 1)
    {
        return 0;
    }
    
    if(!(isalpha(email[0]) && islower(email[0])))
    {
        return 0;
    }
    
    if(at_position == 0)
    {
        return 0;
    }
    
    int dot_after_at = 0;
    for(i = at_position + 1; email[i] != '\0'; i++)
    {
        if(email[i] == '.')
        {
            dot_after_at = 1;
            break;
        }
    }
    if(!dot_after_at)
    {
        return 0;
    }
    
    return 1;
}