#include<stdio.h>
#include<stdlib.h>

/*Chiedo input ad un utente fin tanto che non viene inserito un numero negativo;
I numeri pari viene messi in una lista, i dispari in un'altra.
Alla fine riporto (printf) quale delle due liste sia la più grande, e la somma totale
dei valori di ciascuna*/

struct elem {
    int info;
    struct elem* next;
};
typedef struct elem Elem;

void printlist(Elem* head){
    Elem* tmp = head;
    if(head == NULL) printf("The list is empty.\n");
    else{
        while(tmp != NULL){
            printf("%d - ", tmp->info);
            tmp = tmp->next;
        }
    }
}

//funzione che crea due liste in base ad input da utente, fino a che non prenda un x<0
void funct(Elem** list1, Elem** list2){
    *list1 = NULL;
    *list2 = NULL;
    int x;
    int flag = 1;
    
    while(flag == 1){
        printf("Inserisci i numeri: ");
        scanf("%d", &x);
        
        if(x>=0){
            
            if(x%2 == 0){
                Elem* tmp1 = malloc(sizeof(Elem));
                tmp1->info = x;
                tmp1->next = *list1;
                *list1 = tmp1;
            }
            else{
                Elem* tmp2 = malloc(sizeof(Elem));
                tmp2->info = x;
                tmp2->next = *list2;
                *list2 = tmp2;
            }
            flag = flag;
        }
        else flag = 0;
    }
}

//funzione che conta e compara la lunghezza di due liste
void list_length(Elem* list1, Elem* list2){
    Elem* tmp1 = list1;
    Elem* tmp2 = list2;
    int count1 = 1, count2 = 1;
    
    while(tmp1 -> next != NULL){
        count1 ++;
        tmp1 = tmp1 -> next;
    }
    while(tmp2 -> next != NULL){
        count2 ++;
        tmp2 = tmp2 -> next;
    }
    if (count1 == count2){
        printf("Le liste contengono entrambe %d elementi\n", count1);
    }else if (count1 >= count2){
        printf("La lista pari è maggiore, contiene %d elementi\n", count1);
    }else{
        printf("La lista dispari è maggiore, contiene %d elementi\n", count2);
    }

}

//funzione che somma gli elementi di due liste e la restituisce come intero
int somma(Elem* list1, Elem* list2){
    Elem* tmp1 = list1;
    Elem* tmp2 = list2;
    int sum1 = 0, sum2 = 0;
    int tot_sum;
    
    while(tmp1 != NULL){
        sum1 = sum1 + tmp1->info;
        tmp1 = tmp1->next;
    }
    while(tmp2 != NULL){
        sum2 = sum2 + tmp2->info;
        tmp2 = tmp2->next;
    }
    tot_sum = sum1 + sum2;
    return tot_sum;
}

int main(){
    
    Elem* list1;
    Elem* list2;
    int somma_liste;

    funct(&list1, &list2); 

    printlist(list1);
    printf("\n-----------------------------\n");
    printlist(list2);
    printf("\n-----------------------------\n");
    list_length(list1, list2);
    printf("\n-----------------------------\n");
    somma_liste = somma(list1, list2);
    printf("%d", somma_liste);

return 0;
}
