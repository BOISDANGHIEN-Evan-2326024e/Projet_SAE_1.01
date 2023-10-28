#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

vector<string> litUnFichier (const string & chemin)
{
    vector<string> toutesLesLignes;
    ifstream ifs (chemin);
    if (!ifs) return toutesLesLignes;
    for (string uneLigne;getline(ifs, uneLigne);)
        toutesLesLignes.push_back(uneLigne);
    return toutesLesLignes;
}

template <typename T>
void afficheVecteur (const vector<T> & V)
{
    for (const T & val : V)
        cout << val << endl;
    cout << endl;
}

string motAuHasard(const vector<string> & V){
    string motHasard;
    int nombreHasard;
    srand(time(0));
    nombreHasard = 0+rand()%(size(V)-0);
    motHasard = V[nombreHasard];
    return motHasard;
}

string motDefiniEquipe1(const vector<string> & Fichier){
    string motjouer;
    return motjouer;
}

string motDefiniEquipe2(const vector<string> & Fichier){
    string motjouer;
    return motjouer;
}

int longueurMot(const string motHasard){
    int longueurmot;
    longueurmot=size(motHasard);
    cout << longueurmot << endl;
    return longueurmot;
}

vector<vector<string>> creeTableau(const int & longueurTab){
    vector<vector<string>> tableauDeTableau;
    vector<string> essai1;
    vector<string> essai2;
    vector<string> essai3;
    vector<string> essai4;
    vector<string> essai5;
    vector<string> essai6;
    for(int i=0;i<longueurTab;i=i+1){
        essai1.push_back("_");
        essai2.push_back("_");
        essai3.push_back("_");
        essai4.push_back("_");
        essai5.push_back("_");
        essai6.push_back("_");
    }
    tableauDeTableau.push_back(essai1);
    tableauDeTableau.push_back(essai2);
    tableauDeTableau.push_back(essai3);
    tableauDeTableau.push_back(essai4);
    tableauDeTableau.push_back(essai5);
    tableauDeTableau.push_back(essai6);
    return tableauDeTableau;
}

void afficherTableau(const vector<vector<string>> & tableauDeTableau){
    for(int i=0;i<size(tableauDeTableau);i=i+1){
        for(int j=0;j<size(tableauDeTableau[0]);j=j+1){
            cout<< tableauDeTableau[i][j];
        }
        cout << endl;
    }
}

vector<string> motChercheEnListe(string & motHasard){
    vector<string> tableauMotCherche(size(motHasard));
    string lettre;
    for(int i=0;i<size(motHasard);i=i+1){
        lettre=motHasard[i];
        tableauMotCherche[i]=lettre;
    }
    for(int j=0;j<size(tableauMotCherche);j=j+1){
        cout << tableauMotCherche[j];

    }
    cout << endl;
    return tableauMotCherche;
}

string essai_mot(const int & longueur){
    string nouveauMot;
    cout<< "Rentrez votre mot"<<endl;
    cin >> nouveauMot;
    while(size(nouveauMot)!=longueur){
        cout<<"Votre mot n'a pas la bonne longueur veuillez en rentré un nouveau"<<endl;
                    cin >> nouveauMot;
    }
    return nouveauMot;
}

string recuperer_mot_essai(const int & longueur){
    string motAUtiliser;
    return motAUtiliser;
}

vector<vector<string>> ajouteNouveauMot(vector<vector<string>> Tableau,const int & longueur,int ligne,string nouveauMot){
    for(int j=0;j<longueur;++j){
        Tableau[ligne][j]=nouveauMot[j];
    }
    return Tableau;
}

int CombienLigne(vector<vector<string>> Tableau){
    int ligne;
    ligne=6;
    for(int i=0;i<size(Tableau);++i){
        if(Tableau[i][0]=="_"){
            return i;
        }
    }
    return ligne;
}

vector<vector<string>>comparerMotRentrer(vector<vector<string>>Tableau,const vector<string> & motHasardListe,const int & Ligne,const int longueur){
    for(int i=0;i<longueur;++i){
        if(Tableau[Ligne][i]==motHasardListe[i]){
            Tableau[Ligne][i]="\033[31m"+Tableau[Ligne][i]+"\033[0m";

        }
    }
    for(int k=0;k<longueur;++k){
        for(int h=0;h<longueur;++h){
            if(Tableau[Ligne][k]==motHasardListe[h] & Tableau[Ligne][k]!=motHasardListe[k]){
                Tableau[Ligne][k]="\033[33m"+Tableau[Ligne][k]+"\033[0m";
            }
        }
    }
    return Tableau;
}

int jeuEnCours(vector<vector<string>>Tableau,const vector<string> & motHasardListe,const int & longueur_mot){
    vector<vector<string>>Tableau_copie_pour_test=Tableau;
    int ligne_vide=CombienLigne(Tableau);
    int ligne_dernier_mot=0;
    int compteur=0;
    while(ligne_vide<6){
        compteur=0;
        for(int i=0;i<longueur_mot;i=i+1){
            compteur=compteur+1;
            if (Tableau_copie_pour_test[ligne_dernier_mot][i]!= motHasardListe[i]){
                break;
            }
        }
        if (compteur==longueur_mot){
            return ligne_vide;
        }
        string nouveauMot=essai_mot(longueur_mot);
        Tableau=ajouteNouveauMot(Tableau,longueur_mot,ligne_vide,nouveauMot);
        Tableau_copie_pour_test=ajouteNouveauMot(Tableau,longueur_mot,ligne_vide,nouveauMot); //probleme avec le deuxieme tableau qui redemande un parametre , il faut possiblement changer la fonction rajouter un mot
        ligne_vide=CombienLigne(Tableau);
        ligne_dernier_mot=CombienLigne(Tableau)-1;
        Tableau=comparerMotRentrer(Tableau,motHasardListe,ligne_dernier_mot,longueur_mot);
        afficherTableau(Tableau);
    }
    return ligne_vide;
}

int renvoieResultatJeu(){
    //initialisation du jeu
    vector<string> dicoFR (litUnFichier("../Tusmo/liste_francais.txt"));
    string motHasard=motAuHasard(dicoFR);
    int longueur_mot=longueurMot(motHasard);
    vector<vector<string>> Tableau=creeTableau(longueur_mot);
    vector<string>motHasardListe=motChercheEnListe(motHasard);
    //partie en cours
    int resultat=jeuEnCours(Tableau,motHasardListe,longueur_mot);
    return resultat;
}

int renvoieResultatEquipe1cherche(){
    //initialisation du jeu
    vector<string> dicoFR (litUnFichier("../Tusmo/liste_francais.txt"));
    string motHasard=motAuHasard(dicoFR);
    int longueur_mot=longueurMot(motHasard);
    vector<vector<string>> Tableau=creeTableau(longueur_mot);
    vector<string>motHasardListe=motChercheEnListe(motHasard);
    //partie en cours
    int resultat=jeuEnCours(Tableau,motHasardListe,longueur_mot);
    return resultat;
}

int renvoieResultatEquipe2cherche(){
    //initialisation du jeu
    vector<string> dicoFR (litUnFichier("../Tusmo/liste_francais.txt"));
    string motHasard=motAuHasard(dicoFR);
    int longueur_mot=longueurMot(motHasard);
    vector<vector<string>> Tableau=creeTableau(longueur_mot);
    vector<string>motHasardListe=motChercheEnListe(motHasard);
    //partie en cours
    int resultat=jeuEnCours(Tableau,motHasardListe,longueur_mot);
    return resultat;
}
//faire fonction pour récupérer le mot rentrez par l'utilisateur
//Faire fonction pour comparer le mot rentrer
int resultat(){
    int resultatEquipe1=renvoieResultatEquipe1cherche();
    int resultatEquipe2=renvoieResultatEquipe2cherche();
    return min(resultatEquipe1,resultatEquipe2);
}

int main()
{
    return resultat();
}
