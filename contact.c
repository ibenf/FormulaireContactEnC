
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
char nom[50];
char prenom[50];
char age[50];
char telephone[50];
char mail[50];
}CONTACT;


int main()

{
int j=0, i=0,k,z, menu = 0,choix = 0;

CONTACT contact[50];
CONTACT contactSup;
CONTACT contactmod;
CONTACT contactrech;
int n, cpt=1; ;

char nommod[50],nomrech[50];


char reponse;


FILE* fichier = NULL;
FILE* fichmod = NULL;
FILE* fichsup = NULL;
FILE* fichrech = NULL;


i=0;
fichier = fopen("contact.txt", "r+");

if (fichier != NULL)
{
while(fscanf(fichier, "%s %s %s %s %s\n", contact[i].nom, contact[i].prenom, contact[i].telephone, contact[i].age,contact[i].mail) ==5)
i++;

}
fclose(fichier);



do {
printf("\nBienvenue sur le programme!\n" );
printf("\nCe programme va permettre d'ajouter,afficher,modifier ou supprimer un contact\nd'un fichier\n\n\n\n" );
printf("1. Ajouter un contact\n");
printf("2. Afficher tout les contacts\n" );
printf("3. Modifier un contact\n");
printf("4. Supprimer un contact\n");
printf("5. Rechercher un contact\n");
printf("\n" );
printf("Votre choix : " );
scanf("%d",&menu);



switch (menu)

{

case 1 :
fichier = fopen("contact.txt", "r+");




if ((fichier != NULL) && (i < 50))
{
while(
fscanf(fichier, "%s %s %s %s %s\n", contact[i].nom, contact[i].prenom,contact[i].age,contact[i].telephone,contact[i].mail) == 5)
i++;

printf("\nNom :\n");
scanf("%s",contact[i].nom);
printf("Prenom:\n");
scanf("%s",contact[i].prenom);
printf("Age :\n");
scanf("%s",contact[i].age);
printf("Telephone :\n");
scanf("%s",contact[i].telephone);
printf("Mail:\n");
scanf("%s",contact[i].mail);



fprintf(fichier, "%s ",contact[i].nom);
fprintf(fichier, "%s ",contact[i].prenom);
fprintf(fichier, "%s ",contact[i].age);
fprintf(fichier, "%s ",contact[i].telephone);
fprintf(fichier, "%s ",contact[i].mail);

printf("Contact Ajoute dans le fichier");


fclose(fichier);
}
else
{
printf("\nLe carnet d'adresse est plein !!\n\n");
}

break;



case 2 : //afficher contact
fichier = fopen("contact.txt", "r+");





i=0;
while(
fscanf(fichier, "%s %s %s %s %s \n",contact[i].nom, contact[i].prenom, contact[i].age,contact[i].telephone,contact[i].mail) == 5)
i++;





for(j=0;j<i;j++)
{
printf("\nNom: %s\nPrenom: %s\nAge: %s\nTelephone: %s\nMail: %s\n", contact[j].nom, contact[j].prenom, contact[j].age,contact[j].telephone, contact[j].mail);
}

if( i == 0)
{
printf("Il n'y a pas de contact dans le carnet d'adresse !!!\n\n");
}

fclose(fichier);


;break;

case 3 :


fichsup = fopen("adresse.txt", "r+");
fichier=fopen("contact2.txt","w");
int i = 0, j = 0;
char supnom[50];

printf ("Nom du contact a supprimer ? \n");
scanf ("%s", supnom);

while(j + k < i)
{
fscanf(fichsup, "%s %s %s %s\n", contactSup.nom, contactSup.prenom, contactSup.telephone, contactSup.age);
if(strcmp(supnom, contactSup.nom) != 0)
{
fprintf(fichier,"%s ",contactSup.nom);
fprintf(fichier,"%s ",contactSup.prenom);
fprintf(fichier,"%s ",contactSup.telephone);
fprintf(fichier,"%s ",contactSup.age);
fprintf(fichier,"\n");
i++;
}
else
j++;
}
fclose(fichsup);
fclose(fichier);
fichsup = fopen("contact.txt", "w");
fichier=fopen("contact2.txt","r");
while(fscanf(fichier, "%s %s %s %s\n", contactSup.nom, contactSup.prenom, contactSup.telephone, contactSup.age)==4){
fprintf(fichsup,"%s ",contactSup.nom);
fprintf(fichsup,"%s ",contactSup.prenom);
fprintf(fichsup,"%s ",contactSup.telephone);
fprintf(fichsup,"%s ",contactSup.age);
fprintf(fichsup,"\n");}
fclose(fichsup);
fclose(fichier);


break;

case 4 :

 //supprimer un contact
fichsup = fopen("adresse.txt", "r+");
fichier=fopen("adresse2.txt","w");

printf ("Nom du contact a supprimer ? \n");
scanf ("%s", supnom);

while(j + k< i)
{
fscanf(fichsup, "%s %s %s %s\n", contactSup.nom, contactSup.prenom, contactSup.telephone, contactSup.age);
if(strcmp(supnom, contactSup.nom) != 0)
{
fprintf(fichier,"%s ",contactSup.nom);
fprintf(fichier,"%s ",contactSup.prenom);
fprintf(fichier,"%s ",contactSup.telephone);
fprintf(fichier,"%s ",contactSup.age);
fprintf(fichier,"\n");
j++;
}
else
k++;
}

fclose(fichsup);
fclose(fichier);
fichsup = fopen("contact.txt", "w");
fichier=fopen("contact2.txt","r");

while(fscanf(fichier, "%s %s %s %s\n", contactSup.nom, contactSup.prenom, contactSup.telephone, contactSup.age)==4){
fprintf(fichsup,"%s ",contactSup.nom);
fprintf(fichsup,"%s ",contactSup.prenom);
fprintf(fichsup,"%s ",contactSup.telephone);
fprintf(fichsup,"%s ",contactSup.age);
fprintf(fichsup,"\n");
printf("Contact Supprimé\n");
}

fclose(fichsup);
fclose(fichier);

break;

case 5:

fichier = fopen("contact.txt", "r+");
int trouve;
j = 0, k = 0;
char nomrech[50];

if( i == 0)
{
printf("Il n'y a pas de contact dans le carnet d'adresse donc rien a supprimer");
}

else
{

 printf ("Nom du contact a rechercher ? \n");
scanf ("%s",nomrech);
}

while(j + k < i)
{

fscanf(fichier, "%s %s %s %s %s\n",contactrech.nom, contact[i].prenom,contactrech.telephone,contactrech.age,contactrech.mail);
if(strcmp(nomrech,contactrech.nom)!= 0)
{
j++;
trouve=0;
}
else
{
printf("Nom:%s\n",contactrech.nom);
printf("Prenom:%s\n",contactrech.prenom);
printf("Telephone:%s\n",contactrech.telephone);
printf("Age:%s\n",contactrech.age);
printf("Mail:%s\n",contactrech.mail);
trouve=1;
k++;
}
}

if(trouve==0)
printf("Contact Non present dans le fichier");

fclose(fichier);

;break;
default:printf("Vous n'avez pas saisi un choix valable");
}


printf("\n\nVoulez vous continuez la gestion des contacts(o/n)");
scanf("%s",&reponse);

} while(reponse=='o');


return 0;
}




