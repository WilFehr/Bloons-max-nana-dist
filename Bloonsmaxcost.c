#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//the upgrade structure
typedef struct Upgrade{
    /* */
    int cost;
    struct Upgrade* next_upgrade;
    
} upgrade;

//points to the first element of an upgrade path
typedef struct upgrade0{
    upgrade* head;
}upgrade0;

//bst is binary search tree
typedef struct bst_bme_node{
    float bme;
    struct bst_bme_node* above;
    struct bst_bme_node* below;
}bme_bst_node;

typedef bme_bst_node* bsthead;

//the monkey's state
typedef struct upgrade_state{
    int p1;
    int p2;
    int p3;
} upgrade_state;

//the monkey structure
typedef struct Monkey
{
    /* */
    //the monkey cost
    int cost;

    //the different paths
    //arrows pointing to the first element of the linked list that desccribes each path
    upgrade0 path1;
    upgrade0 path2;
    upgrade0 path3;

} monkey;

//a function to calculate the cost of a monkey given the monky and the desired upgrade states
int cost_of_path(monkey* chimp, upgrade_state branches){
    int cost = 0;
    cost += chimp->cost;

    //upgrade path 1
    if(branches.p1 > 0){
        upgrade* pathcopy1 = chimp->path1.head;
        for(int i = 0; i < branches.p1; i += 1){
            //adds cost of upgrade to total cost
            cost += (pathcopy1)->cost;
            //next element of path
            pathcopy1 = pathcopy1->next_upgrade;
        }
    }
    //upgrade path 2
    if(branches.p2 > 0){
        upgrade* pathcopy2 = chimp->path2.head;
        for(int i = 0; i < branches.p2; i += 1){
            //adds cost of upgrade to total cost
            cost += (pathcopy2)->cost;
            //next element of path
            pathcopy2 = pathcopy2->next_upgrade;
        }
    }
    //upgrade path 3
    if(branches.p3 > 0){
        upgrade* pathcopy3 = chimp->path3.head;
        for(int i = 0; i < branches.p3; i += 1){
            //adds cost of upgrade to total cost
            cost += (pathcopy3)->cost;
            //next element of path
            pathcopy3 = pathcopy3->next_upgrade;
        }
    }
    return cost;
}

//gets the base monkey cost exquivenlent this will be the base unit for calculations
float getbme(monkey* chimp, upgrade_state branches){
    float bme = 0;
    bme = (cost_of_path(chimp, branches)*1.0)/(chimp->cost);
    return bme;
}

//I just forgot the stdlib.h header now I can do malloc stuff
void delete_list(upgrade0* header){
    //set the lagging element(the one that frees the malloc chain)
    upgrade* lagging = header->head;

    while(lagging != NULL){
        header->head = header->head->next_upgrade;
        free(lagging);
        lagging = header->head;
    }
}

void add_to_end_list(upgrade0* header, int upgrade_cost){
    upgrade* new = (upgrade*)malloc(sizeof(upgrade));
    if (new == NULL){
        printf("memory allocation error\n");
        exit(0);
    }else{
        new->cost = upgrade_cost;
        new->next_upgrade = NULL;
    }
    upgrade* next = header->head;

    //the case where add to end of list is empty
    if(next==NULL){
        header->head=&new;
    }else{//the not empty case
        while(next != NULL){
            next=next->next_upgrade;
        }

    }

}

//deletes the binary search tree
void delete_bst(bsthead header){

}

//use getbme to sort paths by bme cost 
void add_to_bst(bsthead header){

}

//given a header arrow to the first element of bst and an array move the bst into the array smallest to largest
//use recurrsion
void move_bst_to_array(bsthead header, float* destination){

}


int main(){
    //create the upgrades
    int PATH1[5] = {0};
    int PATH2[5] = {0};
    int PATH3[5] = {0};
    int money = 0;
    int buy[6][6][6]= {0};

    upgrade_state blank = {0};


    //placeholder 'til I figure out Malloc in vscode
    
    //path1 
        //upgrade 5
        upgrade p1u5;
        p1u5.cost = 0;
        p1u5.next_upgrade = NULL;
        //upgrade 4
        upgrade p1u4;
        p1u4.cost = 0;
        p1u4.next_upgrade = &p1u5;
        //upgrade 3
        upgrade p1u3;
        p1u3.cost = 0;
        p1u3.next_upgrade = &p1u4;
        //upgrade 2
        upgrade p1u2;
        p1u2.cost = 0;
        p1u2.next_upgrade = &p1u3;
        //upgrade 1
        upgrade p1u1;
        p1u1.cost = 0;
        p1u1.next_upgrade = &p1u2;

    //path2 
        //upgrade 5
        upgrade p2u5;
        p2u5.cost = 0;
        p2u5.next_upgrade = NULL;
        //upgrade 4
        upgrade p2u4;
        p2u4.cost = 0;
        p2u4.next_upgrade = &p2u5;
        //upgrade 3
        upgrade p2u3;
        p2u3.cost = 0;
        p2u3.next_upgrade = &p2u4;
        //upgrade 2
        upgrade p2u2;
        p2u2.cost = 0;
        p2u2.next_upgrade = &p2u3;
        //upgrade 1
        upgrade p2u1;
        p2u1.cost = 0;
        p2u1.next_upgrade = &p2u2;


    //path3
        //upgrade 5
        upgrade p3u5;
        p3u5.cost = 0;
        p3u5.next_upgrade = NULL;
        //upgrade 4
        upgrade p3u4;
        p3u4.cost = 0;
        p3u4.next_upgrade = &p3u5;
        //upgrade 3
        upgrade p3u3;
        p3u3.cost = 0;
        p3u3.next_upgrade = &p3u4;
        //upgrade 2
        upgrade p3u2;
        p3u2.cost = 0;
        p3u2.next_upgrade = &p3u3;
        //upgrade 1
        upgrade p3u1;
        p3u1.cost = 0;
        p3u1.next_upgrade = &p3u2;
    
    //end of malloc fill in stuff


    //create inital monkey
    monkey ref;
    ref.cost = 0;

    ref.path1.head = NULL;
    ref.path2.head = NULL;
    ref.path3.head = NULL;  

    //malloc placeholders
    ref.path1.head = &p1u1;
    ref.path2.head = &p2u1;
    ref.path3.head = &p3u1; 
    //end of malloc placeholders

    //no overflow protection
    printf("Please type the available money, then press enter when you are done. Example:\n2000\n");
    scanf("%d", &money);

    //no overflow protection
    printf("Please type the cost of monkey, then press enter when you are done. Example:\n260\n");
    scanf("%d", &ref.cost);

    //no overflow protection
    printf("Please type the cost of first path upgrades starting with the first and ending with the fifth separated by space, then press enter when you are done. Example:\n130 245 630 3000 19000\n");
    for(int i = 0; i < 5; i++){
        scanf("%d", &PATH1[i]);
    }

    //no overflow protection
    printf("Please type the cost of second path upgrades starting with the first and ending with the fifth separated by space, then press enter when you are done. Example:\n85 120 500 1200 8000\n");
    for(int i = 0; i < 5; i++){
        scanf("%d", &PATH2[i]);
    }

    //no overflow protection
    printf("Please type the cost of third path upgrades starting with the first and ending with the fifth separated by space, then press enter when you are done. Example:\n290 600 1250 5000 26000\n");
    for(int i = 0; i < 5; i++){
        scanf("%d", &PATH3[i]);
    }
    //variables

    //move array in linked list
    upgrade* pathcopy1 = ref.path1.head;
    for(int i = 0; i < 5; i += 1){
        //adds cost of upgrade to the path
        pathcopy1->cost = PATH1[i];
        //next element of path
        pathcopy1 = pathcopy1->next_upgrade;
    }
    //at the end of this for loop pathcopy1 is a NULL pointer
    upgrade* pathcopy2 = ref.path2.head;
    for(int i = 0; i < 5; i += 1){
        //adds cost of upgrade to the path
        pathcopy2->cost = PATH2[i];
        //next element of path
        pathcopy2 = pathcopy2->next_upgrade;
    }
    //at the end of this for loop pathcopy2 is a NULL pointer
    upgrade* pathcopy3 = ref.path3.head;
    for(int i = 0; i < 5; i += 1){
        //adds cost of upgrade to the path
        pathcopy3->cost = PATH3[i];
        //next element of path
        pathcopy3 = pathcopy3->next_upgrade;
    }
    //at the end of this for loop pathcopy3 is a NULL pointer
    //end of move array in linked list

    int mincost = cost_of_path(&ref, blank);

    //gives the maximum amount of monkeys that could possibly be used 
    int maxmonkeynum =  money/mincost;

    //base monkey equivants
    float maxbme = (money*1.0)/ref.cost;

    //array to store bme of each path
    float towerbme[5][5][5] = {0};

    //loops to put bme into array
    //this for is a (main-side-side path)
    for(int i = 0; i < 5; i++){
        upgrade_state maxtopj = {0};
        for(int j = 0; j < 2; j++){
            maxtopj.p1 = i;
            maxtopj.p2 = j;
            maxtopj.p3 = 0;
            towerbme[i][j][0] = getbme(&ref, maxtopj);
        }
        upgrade_state maxtopk = {0};
        for(int k = 0; k < 2; k++){
            maxtopk.p1 = i;
            maxtopk.p2 = 0;
            maxtopk.p3 = k;
            towerbme[i][0][k] = getbme(&ref, maxtopk);
        }
    }

    //this for is a (side-main-side path)
    for(int j = 0; j < 5; j++){
        upgrade_state maxmidi = {0};
        for(int i = 0; i < 2; i++){
            maxmidi.p1 = i;
            maxmidi.p2 = j;
            maxmidi.p3 = 0;
            towerbme[i][j][0] = getbme(&ref, maxmidi);
        }
        upgrade_state maxmidk = {0};
        for(int k = 0; k < 2; k++){
            maxmidk.p1 = 0;
            maxmidk.p2 = j;
            maxmidk.p3 = k;
            towerbme[0][j][k] = getbme(&ref, maxmidk);
        }
    }

    //this for is a (side-side-main path)
    for(int k = 0; k < 5; k++){
        upgrade_state maxbotj = {0};
        for(int j = 0; j < 2; j++){
            maxbotj.p1 = 0;
            maxbotj.p2 = j;
            maxbotj.p3 = k;
            towerbme[0][j][k] = getbme(&ref, maxbotj);
        }
        upgrade_state maxboti = {0};
        for(int i = 0; i < 2; i++){
            maxboti.p1 = i;
            maxboti.p2 = 0;
            maxboti.p3 = k;
            towerbme[i][0][k] = getbme(&ref, maxboti);
        }
    }
    //at this point the towerbme array has the bme values of the towers

    //a loop that goes through all elements of a 5x5x5 array
    int number_of_counting_bme = 0;
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            for(int k = 0; k<5; k++){
                if(towerbme[i][j][k] != 0){
                    (number_of_counting_bme +=1);
                }
            }
        }
    }

    printf("%d\n", number_of_counting_bme);

    return 0;
}