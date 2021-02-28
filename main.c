#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Member{
       int member_id;
       char family_name[40];
       char given_name[40];
       int member_age;
       char member_gender;
};

void Delete_member_Details_From_File();
void Search_members_in_the_file();
void SetPosition(int x_axis, int y_axis);
void Display_members_details();
void Display_options();
void Add_members_to_the_file();

int main() // main function
{
    Display_options();
    return 0;
}

void SetPosition(int x, int y) //for position the cursor when displaying details on the screen
{
     HANDLE h = NULL;
     if(!h)
      h = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD c = { x, y };
      SetConsoleCursorPosition(h,c);
}

void Display_options()
{
     int choice;
     printf("=========================\nMember Management Program\n=========================\n");
     printf("1) show members\n2) add member\n3) delete member\n4) search member\n0) exit program\n-------------------------\ncommand> ");
     scanf("%d",&choice);
     switch(choice)
	 {
         case 0:
         	 printf("Goodbye");exit(0);break;
         case 1:
         	 system("cls");
             Display_members_details();
             Display_options();break;
         case 2:
             printf("\n");
             Add_members_to_the_file();break;
         case 3:
         	 Delete_member_Details_From_File();
             break;
         case 4:
         	printf("\n");
         	Search_members_in_the_file();
         	Display_options();
            break;
         default:
             printf("Wrong choice\n\n");
             Display_options();
     }
}

void Display_members_details()
{
	 struct Member m;
     FILE *filePointer;
     int boolen = 1,i = 1,option;
     filePointer = fopen("Member.bin","rb");
     if (filePointer == NULL)
	 {
        printf("No records in the file");
        exit(-1);
     }
     printf("ID\t\tGivenName\t\tFamilyName\t\tAge\t\tGender\n");
         while (fread(&m,sizeof(m),1,filePointer))
		 {
            boolen = 0;
            printf("%d",m.member_id);
            SetPosition(16,i);printf("%s",m.given_name);
            SetPosition(40,i);printf("%s",m.family_name);
            SetPosition(64,i);printf("%d",m.member_age);
            SetPosition(82,i);printf("%c\n",m.member_gender);
            i++;
         }
         if (boolen == 1)
		 {
            SetPosition(42,3);printf("Member records not found\n");
         }
     fclose(filePointer);
     Display_options();
}

void Search_members_in_the_file()
{
	 struct Member m;int option;
     FILE *file_pointer;
     char given_name[30];char family_name[30];
     int all_numbes_of_members = 0,age,boolean = 1,i=5;char gender;
     printf("=========================\nMember Management Program: search member\n=========================\n");
     printf("1) by GivenName\n2) by FamilyName\n3) by Age\n4) by Gender\n-------------------------\ncommand> ");
     scanf("%d",&option);system("cls");
     switch(option)
	 {
         case 1:
		    {
		    printf("=========================\nMember Management Program: search member by GivenName\n=========================\nGivenName> ");
            scanf("%s",given_name);
            file_pointer = fopen("Member.bin","rb");
            if (file_pointer == NULL)
			{
                printf("No records in the file");exit(-1);
            }
            printf("ID\t\tGivenName\t\tFamilyName\t\tAge\t\tGender\n");
            while (fread(&m,sizeof(m),1,file_pointer))
			{
                if (strcmpi(given_name,m.given_name) == 0)
				{
                    boolean = 0;
                    printf("%d",m.member_id);
                    SetPosition(16,i);printf("%s",m.given_name);
                    SetPosition(40,i);printf("%s",m.family_name);
                    SetPosition(64,i);printf("%d",m.member_age);
                    SetPosition(82,i);printf("%c\n",m.member_gender);
                    i++;
                }
            }
            if (boolean == 1)
			{
                SetPosition(42,i+1);printf("Record not found\n");
            }
            fclose(file_pointer);
            break;
         }
         case 2:
		 {
            printf("=========================\nMember Management Program: search member by FamilyName\n=========================\nFamilyName> ");
            scanf("%s",family_name);
            file_pointer = fopen("Member.bin","rb");
            if (file_pointer == NULL)
			{
                printf("No records in the file");exit(-1);
            }
            printf("ID\t\tGivenName\t\tFamilyName\t\tAge\t\tGender\n");
            while (fread(&m,sizeof(m),1,file_pointer))
			{
                if (strcmpi(family_name,m.family_name) == 0)
				{
                    boolean = 0;
                    printf("%d",m.member_id);
                    SetPosition(16,i);printf("%s",m.given_name);
                    SetPosition(40,i);printf("%s",m.family_name);
                    SetPosition(64,i);printf("%d",m.member_age);
                    SetPosition(82,i);printf("%c\n",m.member_gender);
                    i++;
                }
            }
            if (boolean == 1)
			{
                SetPosition(42,i+1);printf("Record not found\n");
            }
            fclose(file_pointer);
            break;
         }
         case 3:
		    {
            printf("=========================\nMember Management Program: search member by Age\n=========================\nAge> ");
            scanf("%d",&age);
            file_pointer = fopen("Member.bin","rb");
            if (file_pointer == NULL)
			{
                printf("No records in the file");exit(-1);
            }
            printf("ID\t\tGivenName\t\tFamilyName\t\tAge\t\tGender\n");
            while (fread(&m,sizeof(m),1,file_pointer))
			{
                if (age == m.member_age)
				{
                    boolean = 0;
                    printf("%d",m.member_id);
                    SetPosition(16,i);printf("%s",m.given_name);
                    SetPosition(40,i);printf("%s",m.family_name);
                    SetPosition(64,i);printf("%d",m.member_age);
                    SetPosition(82,i);printf("%c\n",m.member_gender);
                    i++;
                }
            }
            if (boolean == 1)
			{
                SetPosition(42,i+1);printf("Record not found\n");
            }
            fclose(file_pointer);
            break;
         }
         case 4:
		 {
            printf("=========================\nMember Management Program: search member by Gender\n=========================\nGender> ");
            scanf("%s",&gender);
            file_pointer = fopen("Member.bin","rb");
            if (file_pointer == NULL)
			{
                printf("No records in the file");exit(-1);
            }
            printf("ID\t\tGivenName\t\tFamilyName\t\tAge\t\tGender\n");
            while (fread(&m,sizeof(m),1,file_pointer))
			{
                if (gender == m.member_gender)
				{
                    boolean = 0;
                    printf("%d",m.member_id);
                    SetPosition(16,i);printf("%s",m.given_name);
                    SetPosition(40,i);printf("%s",m.family_name);
                    SetPosition(64,i);printf("%d",m.member_age);
                    SetPosition(82,i);printf("%c\n",m.member_gender);
                    i++;
                }
            }
            if (boolean == 1)
			{
                SetPosition(42,i+1);printf("Record not found\n");
            }
            fclose(file_pointer);
            break;
         }
         default:
             printf("Wrong choice\n");
     }
}

void Delete_member_Details_From_File()
{
	 struct Member m;
     int member_id;
     FILE *file_pointer,*temporay_file;
     int boolean = 1;
     file_pointer = fopen("Member.bin","rb");
     temporay_file = fopen("Temp.bin","ab");
     if (file_pointer == NULL)
	 {
        printf("No records in the file");
        exit(-1);
     }
     if (temporay_file == NULL)
	 {
        printf("No records in the file");
        exit(-1);
     }
     printf("=========================\nMember Management Program: delete member\n=========================\nid> ");
     scanf("%d",&member_id);
     rewind(file_pointer); // setting the file pointer at the begginig of the file
     while (fread(&m,sizeof(m),1,file_pointer)){
        if (member_id != m.member_id){
         fwrite(&m,sizeof(m),1,temporay_file);
        }
        if (member_id == m.member_id){
           boolean = 0;
           printf("%s %s is deleted\n\n",m.given_name,m.family_name);
        }
    }
    if (boolean == 1){
    	printf("Member record not found");
    }
    fclose(file_pointer);fclose(temporay_file);
    remove("Member.bin");rename("Temp.bin","Member.bin");
}

void Add_members_to_the_file(){
	 printf("\n=========================\nMember Management Program: add member\n=========================\n");
	 struct Member m;
     int option;
     int boolen = 1;
	 int all_numbes_of_members = 0;
     FILE *filePointer;
     filePointer = fopen("Member.bin","ab+");
     if (filePointer == NULL){
        perror("Cant open the file\n");exit(-1);
     }
     while (fread(&m,sizeof(m),1,filePointer)){
        boolen = 0;
        all_numbes_of_members++;
     }
     if (boolen == 1){
            all_numbes_of_members = 1;
            m.member_id = all_numbes_of_members;goto start;
     }
     all_numbes_of_members = all_numbes_of_members + 1;
     m.member_id = all_numbes_of_members;start:
     printf("GivenName: ");scanf("%s",m.given_name);
     printf("FamilyName: ");scanf("%s",m.family_name);
     printf("Age: ");scanf("%d",&m.member_age);
     printf("Gender: ");scanf("%s",&m.member_gender);
     fwrite(&m,sizeof(m),1,filePointer);
     fclose(filePointer);
     system("cls");
     Display_members_details();
}
