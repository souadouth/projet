#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Date
{ int jj;
  int mm;
  int aa;
} date;

typedef struct Voiture
{ int idVoiture;
  char marque[15];
  char nomVoiture[15];
  char couleur[7];
  int nbplaces;
  int prixJour;
  char EnLocation[4];
} voiture;

typedef struct contratLocation
{ float numContrat;
  int idVoiture;
  int idClient;
   date debut;
   date fin;
   int cout;
} contrat;
typedef struct Client
{ int idClient;
   char nom[20];
   char prenom[20];
   int cin;
   char adresse[15];
   int telephone;
} client;

void affichage_voiture()    /* la fonction afficher voiture qui permet d'afficher les informations des voitures déja enregistrés dans le fichier */
{ voiture ch[1000];
  FILE* Fichier=NULL;
  Fichier=fopen("Voitures.txt","r");
  if(Fichier!=NULL)
    {
        while(fgets(ch,1000,Fichier)!=NULL)
        {
            printf("%s",ch);
        }

       fclose(Fichier);
    }
   else printf("erreur,fichier introuvable!");
  }

void Ajoute_voiture()  /* la fonction ajoute voiture permet d'ajouter une nouvelle voiture dans le fichier aprés la demande des information srelative a cette voiture */
{  voiture ch;
    printf("saisir l'id du voiture :\n");
    scanf("%d",&ch.idVoiture);
    printf("saisir la marque du voiture :\n");
    scanf("%s",ch.marque);
    printf("saisir le nom du voiture :\n");
    scanf("%s",ch.nomVoiture);
    printf("saisir la couleur du voiture :\n");
    scanf("%s",ch.couleur);
    printf("saisir le nombre de places :\n");
    scanf("%d",&ch.nbplaces);
    printf("saisir le prix pour jour :\n");
    scanf("%d",&ch.prixJour);
    printf("saisir si en location (oui|non):\n ");
    scanf("%s",ch.EnLocation);
    FILE* Fichier=fopen("Voitures.txt","a");
     if(Fichier!=NULL)
     {  fprintf(Fichier,"%d     %s      %s       %s       %d         %d         %s\n",ch.idVoiture,ch.marque,ch.nomVoiture,ch.couleur,ch.nbplaces,ch.prixJour,ch.EnLocation);
         fclose(Fichier);
     }
     else
        printf("erreur!\n");
}

void Modifier_voiture() /* la fonction modifier voiture est utile lorsque l'utilisateur veut modifier une information conçernant une voiture */
{ int i,id,n;
   voiture vt[1000];
FILE* fichier=NULL;
FILE* fichierv=NULL;
fichier=fopen("Voitures.txt","r");
fichierv=fopen("filev.txt","w");
 if(fichier==NULL)
 {
    printf("erreur!\n");
 }
  else
  {  printf("saisir l'id du voiture que vous voulez modifier :\n");
       scanf("%d",&id);
       while(i<1000 && !feof(fichier))
           { fscanf(fichier,"\n  %d    %s     %s     %s     %d      %d      %s",&vt[i].idVoiture,vt[i].marque,vt[i].nomVoiture,vt[i].couleur,&vt[i].nbplaces,&vt[i].prixJour,vt[i].EnLocation );
               if(vt[i].idVoiture==id)
                  {   printf("tapez ce que vous voulez modifier\t 1 modifier l'idvoiture\t 2 modifier la marque\t3 modifier le nom\t4 modifier la couleur\t5 modifier nbreplaces\t6 modifier le prix\t7 modifier la location :\n");
                      scanf("%d",&n);
                         switch(n)
                            { case 1: printf("saisir l'id du voiture que vous voulez mettre :\n");
                                      scanf("%d",&vt[i].idVoiture);
                                      break;
                              case 2: printf("saisir la marque que vous voulez mettre :\n");
                                      scanf("%s",vt[i].marque);
                                      break;
                               case 3: printf("saisir le nom que vous voulez mettre :\n");
                                       scanf("%s",vt[i].nomVoiture);
                                       break;
                               case 4: printf("saisir la couleur que vous voulez mettre :\n");
                                     scanf("%s",vt[i].couleur);
                                       break;
                                case 5: printf("saisir le nombre de place que vous voulez mettre :\n");
                                         scanf("%d",&vt[i].nbplaces);
                                         break;
                                 case 6: printf("saisir le prix que vous voulez mettre :\n");
                                         scanf("%d",&vt[i].prixJour);
                                         break;
                                  case 7: printf("saisir oui si la voiture est loué non sinon");
                                         scanf("%s",vt[i].EnLocation);
                                          break;
                                   default: printf("valeur incorrect entrer un entier entre 1 et7 \n");
                                   break;
                                }
            }
       fprintf(fichierv," \n %d    %s     %s     %s     %d     %d     %d \n",vt[i].idVoiture,vt[i].marque,vt[i].nomVoiture,vt[i].couleur,vt[i].nbplaces,vt[i].prixJour,vt[i].EnLocation ) ;
         i++;
        }
     fclose(fichier);
     fclose(fichierv);
     remove("Voitures.txt");
     rename("filev.txt","Voitures.txt");
  }
}

void Supprimer_voiture()/* la fonction supprimer voiture est chargé de la suppression d'un evoiture déja enregistrés dans le fichier */
{ int id_v;
  voiture vt[1000];
   int i;
   FILE* fichier=NULL;
   FILE* fichierv=NULL;
   fichier=fopen("Voitures.txt","r");
   fichierv=fopen("filev.txt","w");

   if(fichier==NULL)
   { printf("erreue!\n");
   }
   else
   {  printf("tapez l'id du voiture que vous voulez suprimer :\n");
      scanf("%d",&id_v);

       while (i<1000 && !feof(fichier))
          {  fscanf(fichier,"\n %d        %s          %s           %s           %d           %s",&vt[i].idVoiture,vt[i].marque,vt[i].nomVoiture,vt[i].couleur,&vt[i].nbplaces,&vt[i].prixJour,vt[i].EnLocation );
                if(vt[i].idVoiture!=id_v)
                  {
                      fprintf(fichierv,"\n %d  %s  %s  %s  %d %d %s",vt[i].idVoiture,vt[i].marque,vt[i].nomVoiture,vt[i].couleur,vt[i].nbplaces,vt[i].prixJour,vt[i].EnLocation );
                  }
            i++;
       }
       fclose(fichier);
       fclose(fichierv);
       remove("Voitures.txt");
       rename("filev.txt","Voitures.txt");

   }

}



void Afficher_client()/* la fonction afficher client qui affiche l'ensembles des données des clients déja enregistrées dans le fichier */
{ voiture ch[1000];
    FILE* Fclient=NULL;
  Fclient=fopen("Clients.txt","r");
  if(Fclient!=NULL)
  {
      while(fgets(ch,1000,Fclient)!=NULL)
      {
          printf("%s",ch);
      }
     fclose(Fclient);
  }
  else
    printf("erreur! fichier introuvable\n");
}

void Ajoute_client() /* cette fonction met en évident l'ajout d'un nouveau client dans le fichier clients on demandant ces information */
{ client ch;
    printf("saisir l'id de client :\n");
    scanf("%d",&ch.idClient);
    printf("saisir le nom de client :\n");
    scanf("%s",ch.nom);
    printf("saisir le prenom de client :\n");
    scanf("%s",ch.prenom);
    printf("saisir le cin de client :\n");
    scanf("%d",&ch.cin);
    printf("saisir l'adresse de client :\n");
    scanf("%s",ch.adresse);
    printf("saisir le numéro de telephone de client :\n");
    scanf("%d",&ch.telephone);
    FILE* Fclient=NULL;
     Fclient=fopen("Clients.txt","a");
     if(Fclient!=NULL)
     { fprintf(Fclient,"%d         %s          %s         %d          %s          %d \n",ch.idClient,ch.nom,ch.prenom,ch.cin,ch.adresse,ch.telephone);
       fclose(Fclient);
     }
     else
        printf("erreur!\n");
}

void Modifier_client()  /* cette fonction permet de modifier les information concernant un client déja enregistré dans le fichier */
{ int i=0,id,n;
  client cl[1000];
  FILE* fichierc=NULL;
  FILE* fiche=NULL;
  fichierc=fopen("Clients.txt","r");
  fiche=fopen("filecl.txt","w");
  if(fichierc==NULL)
  {
      printf("erreur! fichhier introuvable\n");
  }
  else
    {  printf("saisir l'id du client que vous voulez modifier :\n");
       scanf("%d",&id);
        while(i<1000 && !feof(fichierc))
             { fscanf(fichierc,"%d  %s  %s  %d  %s  %d \n",&cl[i].idClient,cl[i].nom,cl[i].prenom,&cl[i].cin,cl[i].adresse,&cl[i].telephone);
                 if(cl[i].idClient==id)
                    {  printf("tapez ce que vous voulez modifier : 1 le nom  2 le prenom  3 cin  4 adresse 5 telephone \n");
                       scanf("%d",&n);
                        switch(n)
                          { case 1: printf("saisir le nom  que vous voulez mettre:\n");
                                    scanf("%s",cl[i].nom);
                                    break;
                            case 2: printf("saisir le prenom que vous voulez mettre:\n");
                                    scanf("%s",cl[i].prenom);
                                    break;
                             case 3: printf("saisir le cin que vous voulez mettre :\n");
                                     scanf("%d",&cl[i].cin);
                                     break;
                             case 4: printf("saisir l'adresse  que vous :\n");
                                     gets(cl[i].adresse);
                                     break;
                            case 5: printf("saisir le numéro de telephone :\n");
                                    scanf("%d",&cl[i].telephone);
                                    break;
                            default:printf("valeur incorrect tapez une valeur entre 1 et 5 :\n");
                                    break;
                         }

                 }
       fprintf(fiche,"\n %d  %s  %s  %d  %d  %d",cl[i].idClient,cl[i].nom,cl[i].prenom,cl[i].cin,cl[i].adresse,cl[i].telephone);
           i++;
          }
       fclose(fichierc);
       fclose(fiche);
       remove("Clients.txt");
       rename("filecl.txt","Clients.txt");
     }

}

void supprimer_client()  /* cette fonction permet de supprimer les données d'un client du fichier on demandant son id */
{ int id_c,i;
  client cl[1000];
  FILE* fichierc=NULL;
  FILE* fichierc2=NULL;
  fichierc=fopen("Clients.txt","r");
  fichierc2=fopen("fileclt.txt","w");
  printf("saisir l'id du client que vous voulez supprimer :\n");
  scanf("%d",&id_c);
  if(fichierc==NULL)
  {
    printf("erreur! fichier innexistant \n");
  }
  else
  { while(i<1000 && !feof(fichierc))
       {   fscanf(fichierc,"\n %d  %s   %s  %d  %s  %d",&cl[i].idClient,cl[i].nom,cl[i].prenom,&cl[i].cin,cl[i].adresse,&cl[i].telephone);
                if(cl[i].idClient!=id_c)
                 { fprintf(fichierc2,"\n %d  %s   %s  %d  %s  %d",cl[i].idClient,cl[i].nom,cl[i].prenom,cl[i].cin,cl[i].adresse,cl[i].telephone);
                 }
                 i++;

      }
     fclose(fichierc);
     fclose(fichierc2);
     remove("Clients.txt");
     rename("fileclt.txt","Clients.txt");
}
}

void Visualiser_contrat( ) /* cette fonction affiche les information du contrat a partir de son numéro qui doit être saisie par l'utilisateur */
{ float numctrt;
  int i;
  contrat ch[1000];
   printf("saisir le numero de contrat que vous voulez visualisez ;\n");
    scanf("%f",&numctrt);
    FILE* Fcontrat=NULL;
    Fcontrat=fopen("ContratsLocations.txt","r");
     if(Fcontrat!=NULL)
     {
         while(i<1000 || !feof(Fcontrat))
         { fscanf(Fcontrat,"\n %f %d %d  %d/%d/%d  %d/%d/%d  %d",&ch[i].numContrat,&ch[i].idVoiture,&ch[i].idClient,&ch[i].debut.jj,&ch[i].debut.mm,&ch[i].debut.aa,&ch[i].fin.jj,&ch[i].fin.mm,&ch[i].fin.aa,&ch[i].cout);
             if(ch[i].numContrat==numctrt)
             {
            printf("\n %f    %d      %d      %d/%d/%d      %d/%d/%d      %d",ch[i].numContrat,ch[i].idVoiture,ch[i].idClient,ch[i].debut.jj,ch[i].debut.mm,ch[i].debut.aa,ch[i].fin.jj,ch[i].fin.mm,ch[i].fin.aa,ch[i].cout);
             }
              i++;
         }
       fclose(Fcontrat);
     }
     else
        printf("erreur! fichier innexistant\n");

}

void Louer_voiture()     /*qui est chargée de faire deux vérifications, la premiere  concerne l'existance d'un client dans le fichier des clients, on demandant forcément le numéro de client s'il est existe bien si non on demande les informations personnel de client pour l'ajouter,
                                                                      la deuxiéme vérification est en relation de la disponibilité de la voiture choisi par le client s'il est disponible alors automatiquement un nouvau contrat sera ajouter si non un message sera afficher. */
{ int i=0,id_c,durloc,id_v,rep,findc=0;
 client cl[1000];
 voiture vt[1000];
 contrat ct;
 FILE* fichier=NULL;
 FILE* fiche=NULL;
 printf("saisir l'id du client :\n");
 scanf("%d",&id_c);
 fichier=fopen("Clients.txt","r");
 if(fichier!=NULL)
 {  while(i<1000 && !feof(fichier))
    {   fscanf(fichier,"\n %d    %s    %s     %d     %s    %d",&cl[i].idClient,cl[i].nom,cl[i].prenom,&cl[i].cin,cl[i].adresse,&cl[i].telephone);
          if(cl[i].idClient==id_c)
           findc=1;
      i++;
    }
    fclose(fichier);
    if(findc==0)
    {   printf("vous voullez ajouter un client? si oui tappez 1 si non tappez 0:\n ");
        scanf("%d",&rep);
          if(rep==1)
            Ajoute_client();
    }
 }
 else { printf("erreur! fichier introuvable \n"); }
 fiche=fopen("Voitures.txt","r");
 if(fiche!=NULL)
 {  while(i<1000 && !feof(fiche))
     {  fscanf(fiche,"\n %d  %s   %s   %s    %d    %d  %s",&vt[i].idVoiture,vt[i].marque,vt[i].nomVoiture,vt[i].couleur,&vt[i].nbplaces,&vt[i].prixJour,vt[i].EnLocation);
     if(strcmp(vt[i].EnLocation,"non")==0)
       {
           printf("\n  %d  %s   %s   %s    %d    %d  %s",vt[i].idVoiture,vt[i].marque,vt[i].nomVoiture,vt[i].couleur,vt[i].nbplaces,vt[i].prixJour,vt[i].EnLocation);
       }
        i++;
     }
    fclose(fiche);
     printf("saisir l'id du voiture que vous choisissez :\n");
     scanf("%d",&ct.idVoiture);
     printf("saisir  le numéro de contrat :\n");
     scanf("%d",& ct.numContrat);
     printf("saisir la durée de location :\n");
     scanf("%d",&durloc);
     ct.idClient=id_c;
     printf("saisir la date du jour de location sous forme jour/moi/année :\n ");
     scanf("%d %d %d",&ct.debut.jj,&ct.debut.mm,&ct.debut.aa);
     ct.fin.jj=ct.debut.jj+durloc;
     if(ct.fin.jj>30)
     {ct.fin.mm=ct.debut.mm+1;
      ct.fin.jj=ct.fin.jj-30;
     }
     else
        { ct.fin.mm=ct.debut.mm;
        }
     ct.fin.aa=ct.debut.aa;
    ct.cout=300*durloc;

     FILE* fichectrt=NULL;
     fichectrt=fopen("ContratsLocations.txt","a");
    fprintf(fichectrt,"\n %f     %d      %d     %d/%d/%d     %d/%d/%d      %d",ct.numContrat,ct.idVoiture,ct.idClient,ct.debut.jj,ct.debut.mm,ct.debut.aa,ct.fin.jj,ct.fin.mm,ct.fin.aa,ct.cout);
    fclose(fichectrt);
}
}

void Retourner_voiture()/*la fonction retourner voiture comme rôle de supprimé les contrats des voitures qui ont retourné par les clients et aussi modifier une information concernant la disponibilité de la voiture retourner c'est à dire la voiture devient disponible. */
{ int i=0,id_vr;
   voiture ch[1000];
   contrat ct[1000];
   FILE* fichierv=NULL;
   FILE* fichierc=NULL;
   FILE* fichiercs=NULL;
   FILE* fichier=NULL;
   printf("saisir l'id de voiture retourner :\n");
   scanf("%d",&id_vr);
   fichierv=fopen("Voitures.txt","r");
   fichier=fopen("filevr.txt","w");
   if(fichierv!=NULL)
   {   while(i<1000 && !feof(fichierv))
        {   fscanf(fichierv,"\n %d  %s  %s  %s  %d  %d  %s",&ch[i].idVoiture,ch[i].marque,ch[i].nomVoiture,ch[i].couleur,&ch[i].nbplaces,&ch[i].prixJour,ch[i].EnLocation);
             if(ch[i].idVoiture==id_vr)
                   {
                         strcpy(ch[i].EnLocation,"non");
                   }
               fprintf(fichier,"\n %d  %s  %s  %s  %d  %d  %s",ch[i].idVoiture,ch[i].marque,ch[i].nomVoiture,ch[i].couleur,ch[i].nbplaces,ch[i].prixJour,ch[i].EnLocation);
            i++;
        }
    fclose(fichierv);
    fclose(fichier);
    remove("Voitures.txt");
    rename("filevr.txt","Voitures.txt");
   }
   else
   { printf("erreur! fichier introuvable\n ");
   }
 fichierc=fopen("ContratsLocations.txt","r");
 fichiercs=fopen("filectrt1.txt","w");
 if(fichierc!=NULL)
 {  while(i<1000 && !feof(fichierc))
      {
          fscanf(fichierc,"\n %f %d %d %d/%d/%d  %d/%d/%d  %d",&ct[i].numContrat,&ct[i].idVoiture,&ct[i].idClient,&ct[i].debut.jj,&ct[i].debut.mm,&ct[i].debut.aa,&ct[i].fin.jj,&ct[i].fin.mm,&ct[i].fin.aa,&ct[i].cout);
          if(ct[i].idVoiture!=id_vr)
          {
              fprintf(fichiercs,"\n %f %d %d %d/%d/%d  %d/%d/%d  %d",ct[i].numContrat,ct[i].idVoiture,ct[i].idClient,ct[i].debut.jj,ct[i].debut.mm,ct[i].debut.aa,ct[i].fin.jj,ct[i].fin.mm,ct[i].fin.aa,ct[i].cout);
          }
          i++;
      }
      fclose(fichierc);
      fclose(fichiercs);
      remove("ContratsLocations.txt");
      rename("filectrt1.txt","ContratsLocations.txt");

 }
 else
    {
      printf("erreur ! fichier introuvable");
   }


}





void Modifier_contratLocation()/*  la fonction modifier contrat qui met en évidence la modification des informations de contrats de location au cas ou le client veut modifié quelque donner comme la date de retour de la voiture.*/
{ int i=0,n;
  float id_ct;
  contrat ct[1000];
   FILE* Location=NULL;
   FILE* modif=NULL;
   Location=fopen("ContratsLocations.txt","r");
   modif=fopen("filemodif.txt","w");
   if(Location==NULL)
   {
       printf("erreur! fichier introuvable :\n");
   }
   else
   { printf("saisir l'id du contrat que vous voulez modifier :\n");
      scanf("%f",&id_ct);
      while(i<1000 && !feof(Location))
      {  fscanf(Location,"\n %f  %d  %d  %d/%d/%d   %d/%d/%d   %d ",&ct[i].numContrat,&ct[i].idVoiture,&ct[i].idClient,&ct[i].debut.jj,&ct[i].debut.mm,&ct[i].debut.aa,&ct[i].fin.jj,&ct[i].fin.mm,&ct[i].fin.aa,&ct[i].cout);
            if(ct[i].numContrat==id_ct)
            { printf("saisir ce que vous voulez modifier:\n 1 id de Voiture \n2 id de Client\n 3 date de debut \n 4 date de fin \n 5 le cout \n ");
              scanf("%d",&n);
              switch(n)
                 {  case 1: printf("saisir L'id du voiture que vous voullez mettre :\n");
                            scanf("%d",&ct[i].idVoiture);
                            break;
                     case 2: printf("entrer l'id du client que vous voullez mettre :\n");
                             scanf("%d",&ct[i].idClient);
                             break;
                      case 3: printf("saisir le jour de debut de location :\n");
                              scanf("%d",&ct[i].debut.jj);
                               printf("saisir le moi de debut de location :\n");
                              scanf("%d",&ct[i].debut.mm);
                               printf("saisir l'année de debut de location :\n");
                              scanf("%d",&ct[i].debut.aa);
                              break;
                       case 4:  printf("saisir le jour de la fin de location :\n");
                                scanf("%d",&ct[i].fin.jj);
                               printf("saisir le moi de la fin de location :\n");
                               scanf("%d",&ct[i].fin.mm);
                               printf("saisir l'année de la fin de location :\n");
                               scanf("%d",&ct[i].fin.aa);
                              break;
                        case 5: printf("saisir le cout :\n");
                                scanf("%d",&ct[i].cout);
                                break;
                         default : printf("entrer une valeur entre 1 et 5 :\n");
                                   break;
                       }
            }
        fprintf(modif,"\n %f    %d    %d    %d/%d/%d    %d/%d/%d   %d",ct[i].numContrat,ct[i].idVoiture,ct[i].idClient,ct[i].debut.jj,ct[i].debut.mm,ct[i].debut.aa,ct[i].fin.jj,ct[i].fin.mm,ct[i].fin.aa,ct[i].cout);
            i++;
      }
      fclose(Location);
      fclose(modif);
      remove("ContratsLocations.txt");
      rename("filemodif.txt","ContratsLocations.txt");

   }

}




int MenuPrincipal()
{
    int choix;

	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Menu Principal  \xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

    printf("\n\n");

    printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n               \xba                                              \xba");
    printf("\n               \xba    Location..............................1   \xba");
    printf("\n               \xba    Gestion voitures......................2   \xba");
    printf("\n               \xba    Gestion clients.......................3   \xba");
    printf("\n               \xba    Quitter...............................4   \xba");
    printf("\n               \xba                                              \xba");
    printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    printf("\n\n                                Votre choix  :  ");

    scanf("%d",&choix);

    return choix;
}

/*2eme fonction */

 int Location_v()
 { int choix;

	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Location voiture \xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

    printf("\n\n");

    printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n               \xba                                              \xba");
    printf("\n               \xba    Visualiser contrat.......................1\xba");
    printf("\n               \xba    Louer voiture............................2\xba");
    printf("\n               \xba    Retourner voiture........................3\xba");
    printf("\n               \xba    Modifier contrat.........................4\xba");
    printf("\n               \xba    Retour...................................5\xba");
    printf("\n               \xba                                              \xba");
    printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
     printf("\n\n                                Votre choix  :  ");

    scanf("%d",&choix);
    return choix;

}
/*3eme fonction */

int Gestion_v()
{     int choix;

	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Gestion des voitures \xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

    printf("\n\n");

    printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n               \xba                                              \xba");
    printf("\n               \xba    Liste des voiture........................1\xba");
    printf("\n               \xba    Ajouter voiture..........................2\xba");
    printf("\n               \xba    Modifier voiture.........................3\xba");
    printf("\n               \xba    Supprimer voiture........................4\xba");
    printf("\n               \xba    Retour...................................5\xba");
    printf("\n               \xba                                              \xba");
    printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    printf("\n\n                                Votre choix  :  ");

    scanf("%d",&choix);
    return choix;

}

/*4eme fonction */

int Gestion_c()
{ int choix;
	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Gestion des clients  \xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

    printf("\n\n");

    printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n               \xba                                              \xba");
    printf("\n               \xba    Liste des clients........................1\xba");
    printf("\n               \xba    Ajouter client...........................2\xba");
    printf("\n               \xba    Modifier client..........................3\xba");
    printf("\n               \xba    Supprimer client.........................4\xba");
    printf("\n               \xba    Retour...................................5\xba");
    printf("\n               \xba                                              \xba");
    printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    printf("\n\n                                Votre choix  :  ");

    scanf("%d",&choix);
    return choix;

}
int main()
{ int n1,n2,n3,n4;
   n1=MenuPrincipal();
  switch(n1)
  { case 1: n2=Location_v();
                 switch(n2)
                       { case 1: Visualiser_contrat();
                                 break;
                         case 2: Louer_voiture();
                                 break;
                         case 3: Retourner_voiture();
                                 break;
                          case 4:Modifier_contratLocation();
                                 break;
                          case 5:MenuPrincipal();
                                  break;

                            default :printf("valeur invalide! saisir un entier entre 1 et 6 \n");
                        }
            break;
    case 2:  n3= Gestion_v();
                  switch(n3)
                       { case 1: affichage_voiture();
                                   break;
                          case 2: Ajoute_voiture();
                                   break;
                          case 3: Modifier_voiture();
                                   break;
                          case 4: Supprimer_voiture();
                                   break;
                          case 5: MenuPrincipal();
                                   break;
                           default :printf("valeur invalide! saisir un entier entre 1 et 5 \n");
                       }
            break;
    case 3: n4=Gestion_c();
                   switch(n4)
                       {  case 1: Afficher_client();
                                    break;
                           case 2: Ajoute_client();
                                     break;
                           case 3: Modifier_client();
                                    break;
                            case 4: supprimer_client();
                                      break;
                            case 5: MenuPrincipal();
                                       break;
                             default :printf("valeur invalide! saisir un entier entre 1 et 5");
                        }
            break;
    case 4: printf("                        Quitter\n ");
             break;
       default : printf("valeur erroneé entrer une valeur entre 1 et 4");
  }


   return 0;
}

