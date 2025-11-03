#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Contact
{
    char name[20];
    char mobile[11];
    char mail[30];
};
struct addressbook
{
    struct Contact arr[100];
    int contact_count;
};
void create_contact(struct addressbook *details);
void search_contact(struct addressbook *details);
void edit_contact(struct addressbook *details);
void save_contact(struct addressbook *details);
void delete_contact(struct addressbook *details);
void display_contact(struct addressbook *details);
void exit_contact(struct addressbook *details);
int is_valid_Name(struct addressbook *details, char* ch);
int is_valid_Number(struct addressbook *details, char *Number);
int is_valid_Email(struct addressbook *details, char *email);
